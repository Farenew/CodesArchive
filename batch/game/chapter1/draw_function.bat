:x_draw
::prototype call :type
set /a type=%~1
if %type%==0 (
set /p p="# "<nul
exit /b 0
)
set /a condition=type/20
if %condition%==1 (
set /a condition_result=type %% 20
if %condition_result%==1 (set /p p="~"<nul && exit /b 0)
if %condition_result%==2 (set /p p="~"<nul && exit /b 0)
if %condition_result%==3 (set /p p="?"<nul && exit /b 0)
if %condition_result%==4 (set /p p="?"<nul && exit /b 0)
if %condition_result%==6 (set /p p="?"<nul && exit /b 0)
if %condition_result%==7 (set /p p="?"<nul && exit /b 0)
if %condition_result%==8 (set /p p="?"<nul && exit /b 0)
if %condition_result%==9 (set /p p="?"<nul && exit /b 0)
if %condition_result%==11 (set /p p="?"<nul && exit /b 0)
if %condition_result%==12 (set /p p=""<nul && exit /b 0)
if %condition_result%==14 (set /p p="?"<nul && exit /b 0)
)