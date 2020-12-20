@echo off
set /a life=1
set /a blood=1100
set /a magic=100
set /a assult=110
set /a defence=110
set /a luck=0
set /a cursor_x=5
set /a cursor_y=5
set "tools=*    "
cls

echo -------------------------------------------------------------
echo --血量%blood:~1,3%^|^|原力%magic:~1,2%^|^|攻击%assult:~1,2%^|^|防御%defence:~1,2%^|^|生命 %life%^|^|%tools%^|^|x:%cursor_x% y:%cursor_y%
echo -------------------------------------------------------------

::some macros
set /a end_of_array=0
set /a end_of_raw=25
set /a raw_count=1
:item_initilize
set /a n=1
set /a item[1]=0

:draw_background
setlocal EnableDelayedExpansion
if !item[%n%]!==%end_of_array% (
if %raw_count%==%end_of_raw% (goto end_of_draw)

:draw_whole_line
if %raw_count% lss %end_of_raw% (
echo --                                                         -- 
set /a raw_count=raw_count+1 
goto draw_whole_line
)
goto end_of_draw
)
:end_of_draw
echo -------------------------------------------------------------
goto control
setlocal DisableDelayedExpansion

:main
:control
exit /b 0

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
if %condition_result%==1 (set /p p="～"<nul && exit /b 0)
if %condition_result%==2 (set /p p="～"<nul && exit /b 0)

)