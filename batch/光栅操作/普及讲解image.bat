@echo off
title image Tool By Byaidu
echo ������image�����й��ߵ���ʾ����
pause>nul
cls
echo 1.2������/d���ͼƬѡ��
echo.
echo image [/?] [/d] [bmpfile] X Y [Width] [Height] [/BLACKNESS] [/DSTINVERT] [/MERG
echo EECOPY] [/MERGEPAINT] [/NOTSRCCOPY] [/NOTSRCERASE] [/PATCOPY] [/PATPAINT] [/PAT
echo INVERT] [/SRCAND] [/SRCCOPY] [/SRCERASE] [/SRCINVERT] [/SRCPAINT] [/WHITENESS]
echo.
echo         X       ָ��Ŀ������������Ͻǵ�X���߼����꣨Ҳ����Ϊ/sѡ��ָ����
echo         Y       ָ��Ŀ������������Ͻǵ�Y���߼����꣨Ҳ����Ϊ/sѡ��ָ����
echo         Width   Ϊ/sѡ��ָ��Դ��Ŀ�����������߼���ȡ�
echo         Height  Ϊ/sѡ��ָ��Դ��Ŀ�����������߼��߶ȡ�
echo         /s      ��յ�ǰ����ָ����С����ʾ��ͼƬ
echo         /d      ��յ�ǰ��������ʾ��ͼƬ
echo.        /?      �鿴����
echo         /BLACKNESS      ��ʾʹ���������ɫ�������0��ص�ɫ�������Ŀ���������
echo ������ȱʡ�������ɫ����ԣ�����ɫΪ��ɫ��
echo         /DSTINVERT      ��ʾʹĿ�����������ɫȡ��
echo         /MERGECOPY      ��ʾʹ�ò����͵�AND���룩��������Դ�����������ɫ���ض�
echo ģʽ���һ��
echo         /MERGEPAINT     ͨ��ʹ�ò����͵�OR���򣩲������������Դ�����������ɫ
echo ��Ŀ������������ɫ�ϲ�
echo         /NOTSRCCOPY     ��Դ����������ɫȡ�����ڿ�����Ŀ���������
echo         /NOTSRCERASE    ʹ�ò������͵�OR���򣩲��������Դ��Ŀ������������ɫ
echo ֵ��Ȼ�󽫺ϳɵ���ɫȡ��
echo         /PATCOPY        ���ض���ģʽ������Ŀ��λͼ��
pause>nul
echo         /PATPAINT       ͨ��ʹ�ò���OR���򣩲�������Դ��������ȡ�������ɫֵ��
echo �ض�ģʽ����ɫ�ϲ�Ȼ��ʹ��OR���򣩲��������ò����Ľ����Ŀ����������ڵ���ɫ��
echo ��
echo         /PATINVERT      ͨ��ʹ��XOR����򣩲�������Դ��Ŀ����������ڵ���ɫ�ϲ�
echo         /SRCAND ͨ��ʹ��AND���룩����������Դ��Ŀ����������ڵ���ɫ�ϲ�
echo         /SRCCOPY        ��Դ��������ֱ�ӿ�����Ŀ���������
echo         /SRCERASE       ͨ��ʹ��AND���룩��������Ŀ�����������ɫȡ������Դ����
echo �������ɫֵ�ϲ�
echo         /SRCINVERT      ͨ��ʹ�ò����͵�XOR����򣩲�������Դ��Ŀ������������
echo ɫ�ϲ�  /SRCPAINT       ͨ��ʹ�ò����͵�OR���򣩲�������Դ��Ŀ������������ɫ
echo �ϲ�
echo         /WHITENESS      ʹ���������ɫ��������1�йص���ɫ���Ŀ��������򣨶���
echo ȱʡ�����ɫ����˵�������ɫ���ǰ�ɫ��
echo 
echo ��ֱ��ʹ��image abc.bmp 10 50 ���Ӻ���Ĳ�����Ĭ��ʹ��/SRCCOPY
echo �����߿�������������������ʾ1000*1000���ڵĴ�ͼ
echo ע�⣬X,Y�����ɵ�������0����
pause>nul
cls
echo �����ǹ�����ʾ1��
echo image gold.bmp 200 0
image gold.bmp 200 0
pause
cls
echo �����ǹ�����ʾ2��
echo image gold.bmp 200 160
image gold.bmp 200 160
pause
cls
echo ��ջ�����ʾ��
echo BUG���˷���������ʧȥ�����������Ч
echo image /d
image /d
pause
cls
echo image������һ��СѼ�Ӷ�����
echo.
echo ��������鿴
pause>nul
set del=no
set /a a-=60
for /l %%i in (200,-1,0) do (
setlocal EnableDelayedExpansion >nul 2>nul
cls
echo ����%%i֡
ping 127.1 zzzz >nul
if !del!==no set /a a+=10 & image 1.bmp !a! 200
if !del!==ok set /a a-=10 & image 2.bmp !a! 200
if !a!==510 set del=ok
if !a!==-60 set del=no
)
pause >nul
image /d
cls
echo ��ʾ������ллʹ�ã�
pause >nul