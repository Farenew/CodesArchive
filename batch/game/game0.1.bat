@echo off

set /A cursor_x=5
set /A cursor_y=5


::background
:background
cls
echo y is %cursor_y% x is %cursor_x%
echo -------------------------------------------------------------
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

pause