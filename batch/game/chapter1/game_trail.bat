@echo off
::some_global_variables
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
echo -------------------------------------------------------------
(timeout 2)>nul  
echo ---       这个地方我已经很熟悉了，让我们一起冒险吧        ---
echo -------------------------------------------------------------
(timeout 2)>nul  
echo ---   屏幕上方指示了你的基本属性，道具，以及位置          ---
echo -------------------------------------------------------------
(timeout 2)>nul  
echo ---  注意道具你只能携带一个，因为你的载体内存太小了       ---
echo -------------------------------------------------------------
(timeout 2)>nul 
echo ---  首先在这个房间里随便看看吧，这个房间是虚拟的         ---
echo -------------------------------------------------------------
(timeout 2)>nul 
echo ---       所以进入下一个房间时一切状态都会被清除          ---
echo -------------------------------------------------------------
choice /c 1 /m "[1]好的，开始吧
if %errorlevel%==1 goto start_trail

:start_trail
:start_trail

::background
:background
cls
echo -------------------------------------------------------------
echo --血量%blood:~1,3%^|^|原力%magic:~1,2%^|^|攻击%assult:~1,2%^|^|防御%defence:~1,2%^|^|生命 %life%^|^|%tools%^|^|x:%cursor_x% y:%cursor_y%
echo -------------------------------------------------------------

set /a y_counter=1
:y_draw
if %y_counter% lss %cursor_y% (
echo --                                                         --
set /a y_counter=y_counter+1
goto y_draw)


set /p p="--" < nul

set /a x_counter=1
:x_draw
if %x_counter% lss %cursor_x% (
set /p p="@"<nul
set /p p=" "<nul
set /a x_counter=x_counter+1
goto x_draw)

set /p p="@_@" <nul

set /a x_counter=%cursor_x%
:x_draw2
if %x_counter% lss 55 (
set /p p="@"<nul
set /p p=" "<nul
set /a x_counter=x_counter+1
goto x_draw2)

echo --

set /a y_counter=%cursor_y%
:y_draw2
if %y_counter% lss 19 (
echo --                                                         --
set /a y_counter=y_counter+1
goto y_draw2)

echo -------------------------------------------------------------
echo -------------------------------------------------------------

::move
:move
choice /c wasd /n
if %errorlevel% equ 4 goto d
if %errorlevel% equ 3 goto s
if %errorlevel% equ 2 goto a
if %errorlevel% equ 1 goto w

:w
set /A cursor_y=cursor_y-1
if %cursor_y% lss 1 (set /A cursor_y=1)
goto background

:a
set /A cursor_x=cursor_x-1
if %cursor_x% lss 1 (set /a cursor_x=1)
goto background

:s
set /A cursor_y=cursor_y+1
if %cursor_y% gtr 19 (set /A cursor_y=19)
goto background

:d
set /A cursor_x=cursor_x+1
if %cursor_x% gtr 55 (set /a cursor_x=55)
goto background

