 @echo off
 	rem this file made by yikaiming 2012/12/13

    rem batch gammar reference
    
    rem echo %%~dpnA disk + dir + name
    rem echo %%~sA name+ext
    rem echo %%~nA name
    rem echo %%~fA abspathname
    rem echo %%~xA ext
    rem echo %%~pA dik

call ..\global_task\set_global_env.bat
	
for /R %GKENGINE_HOME%\paks %%A in (*.gpk) do (
    echo [clean file] %%~nxA
    del %%A
)

rem pause
