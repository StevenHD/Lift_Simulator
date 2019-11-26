#include <iostream>
#include <iomanip> //io代表输入输出，manip是manipulator（操纵器）的缩写
//例如：setw(n)
#include <list>
#include <windows.h>
#pragma comment(lib, "winmm.lib")//lib是一个预定义的标识符，指定注释的类型，
//除了lib以外，还有compiler, exestr, linker这仨个
//"winmm.lib"是一个为lib提供附加信息的字符串
//winnmm.dll是windows多媒体相关应用程序接口，用于低档的音频和游戏手柄

//首先定义电梯的最大负载范围
#define MIN_MAXLOAD 5
#define MAX_MAXLOAD 20

//然后定义楼层数
#define MIN_FLOOR_NUMS 2 //为什么楼层数不定义为1呢？
						 //我们后面再说
#define MAX_FLOOR_NUMS 40

//接着定义电梯的数量 
#define MIN_LIFT_NUMS 1
#define MAX_LIFT_NUMS 13

//因为我们会用到泊松分布，所以要定义泊松参数的范围
#define MIN_LAMBDA 0.1
#define MAX_LAMBDA 20

//安排一些特殊情况
//例如新出现的乘客人数最大值(100人)，单位为s
#define MAX_NEW_PASSENGER 100

//还有安排我们此次模拟所要用到的最长时间,400s(这里的时间指的是电梯模拟器的虚拟时间，并不是现实时间，
//二者什么区别？我们后面再说)
#define MAX_PASSTIME 400

//接下来我们定义一下不同状态时候的颜色
#define NORMAL 0
#define INFO 1
#define BLANK 2
#define DOWN 3
#define UP 4
#define OPEN 5
#define BUTTON 6
#define TABLE 7

//最后定义一下演示窗口的大小
#define SCREEN_WIDTH 168 //屏幕宽度
#define SCREEN_HEIGHT 57 //屏幕高度
#define WINDOW_WIDTH 167 //窗口宽度
#define WINDOW_HEIGHT 43 //窗口高度

//记着定义一下时间，虚拟的还是现实的呢？
//虚拟的吧
#define SECONDS_PER_HOUR 3600.0

using namespace std;
