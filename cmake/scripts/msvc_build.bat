@call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"
SET PATH=%PROJECT_PATH%\3rdparty\bin;%MYSQL_CONNECTOR_PATH%\lib;%MYSQL_PATH%\bin;%PYTHON_PATH%\Scripts;%PATH%

REM cp "%MYSQL_CONNECTOR_PATH%\lib\libmysql.dll" "%PROJECT_PATH%\build\bin\%CONFIGURATION%
cp "%MYSQL_CONNECTOR_PATH%\lib\libmysql.dll" "%PROJECT_PATH%\build\bin\"
%PROJECT_PATH%\cmake\scripts\robocopy.bat "%PROJECT_PATH%\scripts" "%PROJECT_PATH%\build\bin\scripts" "*.lua"

cmake -GNinja -D%CONFIGURATION%=TRUE -DCMAKE_BUILD_TYPE=%CONFIGURATION% ..
cmake --build . --config %CONFIGURATION%