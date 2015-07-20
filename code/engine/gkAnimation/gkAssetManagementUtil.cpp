/* 
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's 
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok. 
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2011 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement. 
 */

#include "StableHeader.h"
#include "gkAssetManagementUtil.h"

#include <fstream>
using namespace std;

//#include <Common/Base/System/Io/IStream/hkIStream.h>

//#define NEED_PLATFORM_SPECIFIC_EXTENSION

const char* gkAssetManagementUtil::getFileEnding(gkStdString& e, uint8_t rules)
{
    return "";
//	hkStructureLayout l;
//	e.printf("_L%d%d%d%d", 
//		rules.m_bytesInPointer,
//		rules.m_littleEndian? 1 : 0,
//		rules.m_reusePaddingOptimization? 1 : 0,
//		rules.m_emptyBaseClassOptimization? 1 : 0);
//	return e;
}

static bool _fileExists( const char* filename )
{
	// Open
    std::ifstream file;
	
    file.open(filename, std::ifstream::in);
	// Check
    file.get();
    return file.good();

}

const char* gkAssetManagementUtil::getFilePath( gkStdString& filename )
{
    return getFilePath( filename, 0/*hkStructureLayout::HostLayoutRules*/ );
}

const char* HK_CALL gkAssetManagementUtil::getFilePath( gkStdString& filename, uint8_t rules )
{
#ifdef NEED_PLATFORM_SPECIFIC_EXTENSION
	if (! _fileExists( filename ) )
	{
		// Try platform extension
		int extn = filename.lastIndexOf('.');
		if (extn != -1)
		{
			hkStringBuf fe; getFileEnding(fe, rules); 
			filename.insert(extn, fe);
		}
	}
#endif
	
//#ifdef HK_DEBUG
//	{
//		int a0 = filename.lastIndexOf('\\');
//		int a1 = filename.lastIndexOf('/');
//		int aLen = filename.getLength() - 1; // last index
//		int mD0 = a0 >= 0? a0 : 0;
//		int mD1 = a1 >= 0? a1 : 0;
//		int maxSlash = mD0 > mD1? mD0 : mD1;
//		if ( (aLen - maxSlash) > 42 )
//		{
//			hkStringBuf w;
//			w.printf("Your file name [%s] is longer than 42 characters. May have issues on some consoles (like Xbox360).", filename.cString() );
//			HK_WARN(0x04324, w.cString() );
//		}
//	}
//#endif
	return filename.c_str();
}



const char* HK_CALL gkAssetManagementUtil::getFilePath( const char* pathIn, gkStdString& pathOut)
{
	pathOut = pathIn;
	return getFilePath( pathOut, 0/*hkStructureLayout::HostLayoutRules*/ );
}

/* 
 * Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20110913) 
 *  
 * Confidential Information of Havok.  (C) Copyright 1999-2011 
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok 
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership 
 * rights, and intellectual property rights in the Havok software remain in 
 * Havok and/or its suppliers. 
 *  
 * Use of this software for evaluation purposes is subject to and indicates 
 * acceptance of the End User licence Agreement for this product. A copy of 
 * the license is included with this software and is also available at www.havok.com/tryhavok. 
 *  
 */
