/*
		˵˵�������^������һ���������á�
		�������㷽����һ�����������㣺
		1^1=0
		0^0=0
		1^0=1
		0^1=1

		�������Ϊ0,����Ϊ1.

		�������Ƿ��ֽ�������������ֵʱ���Բ��õ�����������
		��a=11,b=9.�����Ƕ�����
		a=a^b=1011^1001=0010;
		b=b^a=1001^0010=1011;
		a=a^b=0010^1011=1001;
		����һ��a=9,b=13�ˡ�

		��һ�����ã� ��һ����ť��������mc��λ�ÿ���������

		mybt.onPress=function()
		{
			mc1._x=mc1._x^mc2._x;
			mc2._x=mc2._x^mc1._x;
			mc1._x=mc1._x^mc2._x;

			mc1._y=mc1._y^mc2._y; 
			mc2._y=mc2._y^mc1._y;
			mc1._y=mc1._y^mc2._y;
		}

		�����Ϳ��Բ�ͨ����ʱ�����������ˡ�

		���Ҫ������ֻ������������

		vertex[0].position = vec2( -width/2, height/2 );
		vertex[1].position = vec2( width/2, height/2 );
		vertex[2].position = vec2( width/2, -height/2 );
		vertex[3].position = vec2( -width/2, -height/2 );
*/
//#include "StdAfx.h"
//#include "global.h"
#include "Image.h"

#ifdef OS_APPLE

inline void gkLogWarning( const TCHAR *format,... )
{
    // Fran: we need these guards for the testing framework to work
//    if (gEnv && gEnv->pSystem)
//    {
//        va_list args;
//        va_start(args,format);
//        gEnv->pLog->LogV(ILog::eWarning, format, args );
//        va_end(args);
//    }
    
    printf( format );
}

#endif

Image::Image(void)
{
}

Image::~Image(void)
{
}

bool Image::loadTGA( TexImage* texture, LPCSTR filename )
{
	if ( filename == NULL )
		return FALSE;
		
	Header uTGAcompare = { 0,0,2,0,0,0,0,0};		//2Ϊ��ѹ��RGB��ʽ		3  -  δѹ���ģ��ڰ�ͼ��
	Header cTGAcompare = { 0,0,10,0,0,0,0,0};		//10Ϊѹ��RGB��ʽ

	TGAHeader header;
	FILE* file = fopen( filename, "rb" );
	if ( !file ){
		gkLogWarning("Openf file %s failed!\n", filename );
		return FALSE;
	}
	
	if ( fread( &header, 1, sizeof(TGAHeader), file ) != sizeof( TGAHeader ) ){		//��ȡTGA����ͷ�ṹ��
		if ( file )
			fclose( file );
		gkLogWarning("Read data failed\n");
		return FALSE;
	}
	
	texture->width = header.width;
	texture->height = header.height;
	texture->bpp = header.bpp;

	if ( header.bpp == 32 )
		texture->imageType = GL_RGBA;
	else if ( header.bpp = 24 )
		texture->imageType = GL_RGB;
	else{
		gkLogWarning("Image type error!\n");
		return FALSE;
	}
		

	if ( memcmp( &uTGAcompare, &header.head, sizeof(header.head) )== 0 ){		//δѹ��TGA
		texture->bCompressed = FALSE;
		if ( !loadUncompressedTGA( texture, file ) ){
			gkLogWarning("Load uncompressed TGA failed!\n");
			return FALSE;
		}
	}else if ( memcmp( &cTGAcompare, &header.head ,sizeof(header.head) ) == 0 ){	//ѹ��TGA
		texture->bCompressed = TRUE;
		if ( !loadCompressedTGA( texture, file ) ){
			gkLogWarning("Load compressed TGA failed!\n");
			return FALSE;
		}
	}else{
		gkLogWarning("Error TGA type!\n");
		return FALSE;
	}

	return TRUE;
}

bool Image::loadUncompressedTGA( TexImage* texture, FILE* file )
{
	//ASSERT( file != NULL && texture!=NULL );

	uint32 bytePerPixel = texture->bpp/8;
	uint32 imgSize = texture->width*texture->height*bytePerPixel;				//ͼ�����ֽ���
	texture->imageData = new uint8[ imgSize ];

	if ( fread( texture->imageData, 1, imgSize, file ) != imgSize  )
	{
		gkLogWarning("Read texture imagedata failed!\n");
		return FALSE;
	}

	//TGA��������OpenGL�ĸ�ʽ,Ҫ��BGRת����ΪRGB
	// Go through all of the pixels and swap the B and R values since TGA
	// files are stored as BGR instead of RGB (or use GL_BGR_EXT verses GL_RGB)
	for( int i = 0; i < (int)imgSize; i+=bytePerPixel ){
		/*GLushort temp = texture->imageData[i];
		texture->imageData[i] = texture->imageData[i+2];
		texture->imageData[i+2] = temp;*/
		texture->imageData[i] ^= texture->imageData[i+2] ^= texture->imageData[i] ^= texture->imageData[ i+2 ];		//λ��������ٶ�,����B,R����
	}

	::fclose( file );
	return TRUE;
}

bool Image::loadCompressedTGA( TexImage* texture, FILE* file )
{
	//ASSERT( file != NULL && texture!=NULL );
	
	uint32 bytePerPixel = texture->bpp/8;
	uint32 imgSize = texture->width*texture->height*bytePerPixel;
	texture->imageData = new uint8[ imgSize ];

	uint32 pixelcount = texture->width * texture->height;
	uint32 currentPixel = 0;		//��ǰ���ڶ�ȡ������
	uint32 currentByte = 0;			//��ǰ������ͼ����д�������
	uint8 *colorbuffer = (uint8 *)malloc( bytePerPixel );	// һ�����صĴ洢�ռ�s

	do
	{
		uint8 chunkHeader  = 0;		//�洢ID��ֵ�ı���
		if ( !fread( &chunkHeader,1, sizeof( uint8 ), file ) ){
			return FALSE;
		}
		if ( chunkHeader < 128 )			//RAW��
		{
			chunkHeader++;				// ����ֵ��1�Ի�ȡRAW���ص�����

			for( int i = 0; i < chunkHeader; i++ ){
				if ( fread( colorbuffer, 1,sizeof( bytePerPixel ), file ) != sizeof( bytePerPixel ) ){
					gkLogWarning("Read pixel failed!\n");
					return FALSE;
				}
				texture->imageData[currentByte] = colorbuffer[ 2 ];
				texture->imageData[currentByte+1] = colorbuffer[1];
				texture->imageData[currentByte+2] = colorbuffer[0];
				if ( bytePerPixel == 4 )
					texture->imageData[ currentByte+3] = colorbuffer[3];

				currentPixel++;
				currentByte += bytePerPixel;
			}
		}
		 //��һ�δ�������RLE�εġ��顱ͷ���������ǽ�chunkheader��ȥ127���õ���ȡ��һ����ɫ�ظ��Ĵ����� 
		else		
		{
			chunkHeader -= 127;			//��ȥ127���ID bit ��rid	��ʼѭ���������Ƕ�ζ����ڴ��е����أ�����RLEͷ�е�ֵ�涨��

			if ( fread( colorbuffer,1, sizeof( bytePerPixel ), file ) != sizeof( bytePerPixel ) ){
				gkLogWarning("Read pixel failed!\n");
				return FALSE;
			}
			
			for( int i = 0; i < chunkHeader; i++ ){
				texture->imageData[ currentByte ] = colorbuffer[ 2 ];				// ������R���ֽ�
				texture->imageData[ currentByte +1 ] = colorbuffer[ 1 ];			// ������G���ֽ�
				texture->imageData[ currentByte + 2 ] = colorbuffer[ 0 ];			// ������B���ֽ�
				if ( bytePerPixel == 4 )
					texture->imageData[ currentByte+3 ] = colorbuffer[ 3 ];			// ������A���ֽ�

				currentPixel++;
				currentByte += bytePerPixel;
			}
		}
	}while( currentPixel < pixelcount );

	free( colorbuffer );
	::fclose( file );
	return TRUE;
}

bool Image::release( TexImage* texture )
{
	if ( !texture )
		return FALSE;
	
	if ( texture->imageData )
		delete[] texture->imageData;
	//glDeleteTextures( 1, &texture->texID );
	return TRUE;
}
