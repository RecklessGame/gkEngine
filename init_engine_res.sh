#!/bin/sh

echo :: shadercache folder ::
mkdir ./exec/engine/shaders/d3d9/shadercache
mkdir ./code/thirdparty
mkdir ./exec/media


echo :: copy config file ::
mkdir ./exec/media/config
cp -f ./exec/tools/default_cfg/startup.cfg ./exec/media/config


echo :: texture process ::
cd ./exec/tools/resource_task
sh ./desktop_tga2dds_engine.sh
sh ./sgx_tag2pvr_engine.sh
sh ./adreno_tga2pvr_engine.sh

