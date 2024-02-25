@echo OFF

cl /c /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\shared" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\um" /I "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.37.32822\include" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\ucrt" main.c server.c

echo "error level %errorlevel%"

if NOT %errorlevel% == 0 exit
echo "compilation DONE"
echo "----------------"

link main.obj server.obj /LIBPATH:"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.37.32822\lib\x64" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\um\x64" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\ucrt\x64" /OUT:".\dist\main.exe" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\um\x64" WS2_32.Lib

if NOT %errorlevel% == 0 exit

echo "linking DONE"
echo "----------------"