@echo off
rem -- Set all environment variables used by Hammer and Omaha. --
set OMAHA_NET_DIR=%WINDIR%\Microsoft.NET\Framework\v2.0.50727
set OMAHA_WTL_DIR=C:\dev\WTL\include
set OMAHA_WIX_DIR=C:\dev\wix
set OMAHA_VISTASDK_DIR=C:\Program Files\Microsoft SDKs\Windows\v6.1
set OMAHA_PSEXEC_DIR=C:\dev\PSTools
set OMAHA_PYTHON_DIR=C:\Python24
set SCONS_DIR=%OMAHA_PYTHON_DIR%\Lib\site-packages\scons-1.3.1
set SCT_DIR=C:\dev\swtoolkit
rem -- Add Visual Studio and Python to our path, and set VC env variables. --
call "C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\vcvarsall.bat"
path %OMAHA_PYTHON_DIR%;%PATH%
rem -- Add ATLServer headers to the Visual C++ include path. --
set INCLUDE=%INCLUDE%C:\dev\atlserver\include;

