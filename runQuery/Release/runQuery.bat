
@echo off
call "D:\Softwares\Siemens\Teamcenter8\tc_menu\tc9_MYDB.bat"
set start=%TIME%

:: Run your command here
"D:\VS_WS\runQuery\Release\runQuery.exe"

set end=%TIME%

:: Extract hours, minutes, seconds, and milliseconds
for /f "tokens=1-4 delims=:." %%a in ("%start%") do set start_h=%%a&set start_m=%%b&set start_s=%%c&set start_ms=%%d
for /f "tokens=1-4 delims=:." %%a in ("%end%") do set end_h=%%a&set end_m=%%b&set end_s=%%c&set end_ms=%%d

:: Calculate elapsed time
set /a elapsed_h=end_h-start_h
set /a elapsed_m=end_m-start_m
set /a elapsed_s=end_s-start_s
set /a elapsed_ms=end_ms-start_ms

echo Execution time: %elapsed_h%:%elapsed_m%:%elapsed_s%.%elapsed_ms% seconds
pause
