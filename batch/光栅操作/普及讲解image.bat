@echo off
title image Tool By Byaidu
echo 下面是image命令行工具的演示程序
pause>nul
cls
echo 1.2增加了/d清空图片选项
echo.
echo image [/?] [/d] [bmpfile] X Y [Width] [Height] [/BLACKNESS] [/DSTINVERT] [/MERG
echo EECOPY] [/MERGEPAINT] [/NOTSRCCOPY] [/NOTSRCERASE] [/PATCOPY] [/PATPAINT] [/PAT
echo INVERT] [/SRCAND] [/SRCCOPY] [/SRCERASE] [/SRCINVERT] [/SRCPAINT] [/WHITENESS]
echo.
echo         X       指定目标矩形区域左上角的X轴逻辑坐标（也可以为/s选项指定）
echo         Y       指定目标矩形区域左上角的Y轴逻辑坐标（也可以为/s选项指定）
echo         Width   为/s选项指定源和目标矩形区域的逻辑宽度。
echo         Height  为/s选项指定源和目标矩形区域的逻辑高度。
echo         /s      清空当前窗口指定大小中显示的图片
echo         /d      清空当前窗口中显示的图片
echo.        /?      查看帮助
echo         /BLACKNESS      表示使用与物理调色板的索引0相关的色彩来填充目标矩形区域
echo ，（对缺省的物理调色板而言，该颜色为黑色）
echo         /DSTINVERT      表示使目标矩形区域颜色取反
echo         /MERGECOPY      表示使用布尔型的AND（与）操作符将源矩形区域的颜色与特定
echo 模式组合一起
echo         /MERGEPAINT     通过使用布尔型的OR（或）操作符将反向的源矩形区域的颜色
echo 与目标矩形区域的颜色合并
echo         /NOTSRCCOPY     将源矩形区域颜色取反，于拷贝到目标矩形区域
echo         /NOTSRCERASE    使用布尔类型的OR（或）操作符组合源和目标矩形区域的颜色
echo 值，然后将合成的颜色取反
echo         /PATCOPY        将特定的模式拷贝到目标位图上
pause>nul
echo         /PATPAINT       通过使用布尔OR（或）操作符将源矩形区域取反后的颜色值与
echo 特定模式的颜色合并然后使用OR（或）操作符将该操作的结果与目标矩形区域内的颜色合
echo 并
echo         /PATINVERT      通过使用XOR（异或）操作符将源和目标矩形区域内的颜色合并
echo         /SRCAND 通过使用AND（与）操作符来将源和目标矩形区域内的颜色合并
echo         /SRCCOPY        将源矩形区域直接拷贝到目标矩形区域
echo         /SRCERASE       通过使用AND（与）操作符将目标矩形区域颜色取反后与源矩形
echo 区域的颜色值合并
echo         /SRCINVERT      通过使用布尔型的XOR（异或）操作符将源和目标矩形区域的颜
echo 色合并  /SRCPAINT       通过使用布尔型的OR（或）操作符将源和目标矩形区域的颜色
echo 合并
echo         /WHITENESS      使用与物理调色板中索引1有关的颜色填充目标矩形区域（对于
echo 缺省物理调色板来说，这个颜色就是白色）
echo 
echo 如直接使用image abc.bmp 10 50 不加后面的参数，默认使用/SRCCOPY
echo 本工具可以用来在批处理里显示1000*1000以内的大图
echo 注意，X,Y所构成的坐标由0起算
pause>nul
cls
echo 下面是功能演示1：
echo image gold.bmp 200 0
image gold.bmp 200 0
pause
cls
echo 下面是功能演示2：
echo image gold.bmp 200 160
image gold.bmp 200 160
pause
cls
echo 清空画面显示：
echo BUG：此方法当窗口失去焦点后命令无效
echo image /d
image /d
pause
cls
echo image开发的一个小鸭子动画：
echo.
echo 按任意键查看
pause>nul
set del=no
set /a a-=60
for /l %%i in (200,-1,0) do (
setlocal EnableDelayedExpansion >nul 2>nul
cls
echo 还有%%i帧
ping 127.1 zzzz >nul
if !del!==no set /a a+=10 & image 1.bmp !a! 200
if !del!==ok set /a a-=10 & image 2.bmp !a! 200
if !a!==510 set del=ok
if !a!==-60 set del=no
)
pause >nul
image /d
cls
echo 演示结束，谢谢使用！
pause >nul