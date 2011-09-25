
REM @echo off
call "D:\Softwares\Siemens\Teamcenter8\tc_menu\tc9_MYDB.bat"
for /f "tokens=1-4 delims=:." %%a in ("%TIME%") do (
    set /a start_total=%%a*3600 + %%b*60 + %%c
)
:: Run your command
"D:\Projects\RunQuery\Release\RunQuery.exe"
for /f "tokens=1-4 delims=:." %%a in ("%TIME%") do (
    set /a end_total=%%a*3600 + %%b*60 + %%c
)
set /a elapsed=end_total-start_total
echo Execution time: %elapsed% seconds

pause
