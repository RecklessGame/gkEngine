cd ../global_task/
source set_global_env.sh

foreachd(){
# 遍历参数1
for file in $1/*
do
# 如果是目录就打印处理，然后继续遍历，递归调用
if [ -d $file ]
then
#echo $file"是目录"
foreachd $file
elif [ -f $file ]
then
#echo $file pvr process



if [ "${file##*.}" = "tga" ];
then

if [ -f "${file%.*}.dds"  ]
then
echo "${file%.*}.dds exist.";
else
$GKENGINE_HOME/tools/nvcompress -bc3 -silent $file ${file%.*}.dds
fi

fi


fi
done
}

foreachd "$GKENGINE_HOME/media"

#   	%GKENGINE_HOME%\tools\pvrtextool -m -fOGL8888 -yflip0 -square -silent -i %%~fA
