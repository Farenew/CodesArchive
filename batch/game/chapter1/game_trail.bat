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
echo ---       ����ط����Ѿ�����Ϥ�ˣ�������һ��ð�հ�        ---
echo -------------------------------------------------------------
(timeout 2)>nul  
echo ---   ��Ļ�Ϸ�ָʾ����Ļ������ԣ����ߣ��Լ�λ��          ---
echo -------------------------------------------------------------
(timeout 2)>nul  
echo ---  ע�������ֻ��Я��һ������Ϊ��������ڴ�̫С��       ---
echo -------------------------------------------------------------
(timeout 2)>nul 
echo ---  �����������������㿴���ɣ���������������         ---
echo -------------------------------------------------------------
(timeout 2)>nul 
echo ---       ���Խ�����һ������ʱһ��״̬���ᱻ���          ---
echo -------------------------------------------------------------
choice /c 1 /m "[1]�õģ���ʼ��
if %errorlevel%==1 goto start_trail

:start_trail
:start_trail

::background
:background
cls
echo -------------------------------------------------------------
echo --Ѫ��%blood:~1,3%^|^|ԭ��%magic:~1,2%^|^|����%assult:~1,2%^|^|����%defence:~1,2%^|^|���� %life%^|^|%tools%^|^|x:%cursor_x% y:%cursor_y%
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

