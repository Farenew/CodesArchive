@echo off
:newgame
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---           有人吗？！                                  ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---            help！！！！                               ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---         天呐怎么会这样！！！！                        ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---           救命啊！！！！                              ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---          我被困住了！                                 ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---       有人能看到我发的消息吗？！                      ---
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 1)>nul
choice /c 12 /m "[1]你是计算机吗？ [2]你怎么了？"
if %errorlevel%==2 goto how_are_you
if %errorlevel%==1 goto are_you_computer

:how_are_you
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---        我被困到计算机里面了！！！！                   ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---           快救我！！！！                              ---
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 1)>nul
choice /c 12 /m "[1]我怎样才能救你啊？ [2]你怎么被困到计算机里面了呢？"
if %errorlevel%==2 goto how_you_get_traped
if %errorlevel%==1 goto how_can_i_save_you

:are_you_computer
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---          不不不，我当然不是！                         ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---      见鬼！我怎么会是着该死的计算机！！               ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---      留在这里不要走，拜托一定要救我出去！！           ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---          我叫江枫，是一个程序员，                     ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---     昨天晚上我写程序太累了，趴在电脑桌上睡着了        ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---        谁知道醒来之后只剩下一副眼镜了！！！！         ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---        见鬼！！你知道吗！！！一副眼镜！！！！         ---
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 1)>nul
choice /c 12 /m "[1]什么意思？ [2]那我要怎么救你？
if %errorlevel%==2 goto how_can_i_save_you
if %errorlevel%==1 goto what_do_you_mean

:what_do_you_mean
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---             我也很难解释。。。。。。                  ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---          大概就是我被“代码化”了？                     ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---    所幸这里可以用UTF-8字符集，也就是说我可以用中文表达---
echo -------------------------------------------------------------
(timeout 2)>nul
echo --- 但我自己只能用ASCII码表示。。。而且只剩下一副眼镜！！ ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---    听起来很恐怖吧。。。我也觉得，简直太不可思议了     ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---    你愿意等我一下吗？我可以慢慢把这件事情说给你听     ---
echo -------------------------------------------------------------
(timeout 1)>nul
choice /c 12 /m "[1]算了，你快告诉我怎么救你好了 [2]好的，你慢慢说吧
if %errorlevel%==2 goto how_you_get_traped
if %errorlevel%==1 goto how_can_i_save_you



:how_you_get_traped
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 2)>nul
echo --- 是这样的，我昨天正在写程序，太累了，就趴在电脑上睡着了---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---       也许是我不小心按到了什么？                      ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo --- 当然不是！！！见鬼！！！按到什么也不会把我困进来啊！！---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---     总之我意识清醒的时候就这么是这个情况了            ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---      现在我搞明白了我可以使用这个电脑的一部分         ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---          （幸亏我的电脑学的不错！）                   ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---        你想听我描述下我的情况吗？                     ---
echo -------------------------------------------------------------
(timeout 1)>nul
choice /c 12 /m "[1]我不喜欢听故事，快告诉我怎么救你 [2]好的，这简直太不可思议了！
if %errorlevel%==2 goto this_is_amazing
if %errorlevel%==1 goto how_can_i_save_you

:this_is_amazing
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---    多谢你的慷慨，我现在正处在代码之中                 ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---  这很难描述，因为很难向一个三维生物描述这种四维的场景 ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---   大概就是身边都是字符吧，其中的一部分我能看懂        ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---       所以我就具有操纵它们的能力                      ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---         比如我发现我可以与外界交互                    ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---       我有两套交互系统可以使用，一是屏幕，二是键盘    ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---         是的，竟然连鼠标都不能用                      ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---         如果这是个电脑游戏的话，我想作者一定很笨      ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---        见鬼，我怎么会想到电脑游戏上面了               ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---        对不起我现在四维有些乱，你愿意耐心听下去吗？   ---
echo -------------------------------------------------------------
(timeout 1)>nul
choice /c 12 /m "[1]烦死了，快说怎么救你 [2]我去，如果真是游戏的话作者也太有想象力了
if %errorlevel%==2 goto auther_is_so_awesome
if %errorlevel%==1 goto how_can_i_save_you

:auther_is_so_awesome
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---        有吗？你竟然这样想，简直蠢啊！                 ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---      对不起，无意冒犯，虽然我并不知道谁写的这东西     ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---       不过要真能把人困到程序里，那就真的好厉害了！！  ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---       啊，sorry， 我继续说周围的情况                  ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---    你看过<黑客帝国>吗？这里很像最后的那个machine city ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---     所以我想，我应该也能顺利走出这里的！              ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---         当然，需要你的帮助                            ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---          如果说我是Neo，那你就是Trinity喽！           ---
echo -------------------------------------------------------------
choice /c 12 /m "[1]哈哈哈，好有趣 [2]天呐你废话怎么这么多！快！说！怎！么！救！你！
if %errorlevel%==2 goto how_can_i_save_you
if %errorlevel%==1 goto that_is_funny

:that_is_funny
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---    多谢你陪我这么久啦，我真的很高兴                   ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---    虽然在这种可怕的地方，但和你聊天让我很有动力了！   ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---    我一定会努力出去的！等着瞧吧！！                   ---
echo -------------------------------------------------------------
(timeout 1)>nul
echo ---    好啦，我和你仔细说说我现在的情况吧                 ---
echo -------------------------------------------------------------
(timeout 1)>nul
choice /c 12 /m "[1]没关系啦，不要担心 [2]好的，你快讲讲吧
if %errorlevel%==2 goto how_can_i_save_you
if %errorlevel%==1 goto dont_worry

:dont_worry
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---             欸？这是什么东西？                        ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---             看上去。。。。好像某种特殊道具？          ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---           哇哦！看上去是可以让人死而复生的东西！！    ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---            哈哈哈，好开心啊，                         ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---          【【系统提示，生命+1】】                     ---
echo -------------------------------------------------------------
(timeout 2)>nul
echo ---           哇，还真像游戏啊！！让我们一起冒险吧！      ---
echo -------------------------------------------------------------
(timeout 1)>nul
goto how_can_i_save_you

:how_can_i_save_you
cls
echo -------------------------------------------------------------
echo -------------------------------------------------------------
(timeout 2)>nul   
echo ---      如你所见，我被困在这个54*23大小的方框里了        ---
echo -------------------------------------------------------------
(timeout 2)>nul   
echo ---       但凭借我的能力，我可以利用这里的一些资源        ---
echo -------------------------------------------------------------
(timeout 1)>nul   
echo ---       正如我之前说过的，我现在只剩下一副眼镜了        ---
echo -------------------------------------------------------------
(timeout 1)>nul   
echo --- 也许是材质问题，所以我的眼镜可以保留，并且存储我的思维---
echo -------------------------------------------------------------
(timeout 1)>nul   
echo ---   所以类似“=”这种钛合金材料，可以为我加血             ---
echo -------------------------------------------------------------
(timeout 1)>nul   
echo ---   而如果是“。”这类酸性物质，会损害我的能力            ---
echo -------------------------------------------------------------
(timeout 1)>nul   
echo ---   此外还会有其它很多材料，以及与计算机的卫兵战斗      ---
echo -------------------------------------------------------------
(timeout 1)>nul   
echo ---              遇到时候再告诉你吧！                     ---
echo -------------------------------------------------------------
(timeout 1)>nul   
pause

