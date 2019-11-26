//数据结构与算法实习值电梯模拟器
//输入方式：键盘读入数据
//输出方式：win32控制台界面输出

//此电梯的基本功能：

#include <iostream>
#include <iomanip> //io代表输入输出，manip是manipulator（操纵器）的缩写
				   //例如：setw(n)
#include <list>
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

//----接下来我们定义一系列子函数
double maximum(double, double);
double minimum(double, double);
double average(double, double);

double poisson(double, int);//计算泊松分布的概率值,第一个参数为λ，第二个参数为k，返回exp(-λ)*(λ^k)/(k!)

void _play_Music(int);//播放音乐的函数，参数为0-17的整数(为啥是0-17)
					  //参数为0为不播放，参数不为0则播放某一频率
void _calculate_Pk(double, double[]);//计算每一秒钟新增的乘客的人数的概率值
									 //第一个参数为λ，将计算后的结果保存在第二个参数的double型数组中
int _appear_Passengers(int, int, double[]);//根据上面算出的概率值产生新出现的乘客，
										   //第一个参数为楼层总数，第二个参数为此前的乘客总人数
										   //第三个参数为之前计算的概率值，返回值为之后的乘客总人数

void _calc_Data(int); //计算总等待时间、客流量等各个数据，参数为当前的乘客总人数

void _print_Result(int, int, int, int, int, int[], int[], int[]);//输出函数，参数依次是
																 //输出状态、采用的算法、楼层总数
																 //电梯总数、当前乘客总人数、每层楼新增的乘客人数
																 //每层楼离开的乘客人数，每层楼上电梯的乘客数量
void _on_Lift(int, int, int, int[], list<int>::iterator);//令乘客上电梯，参数依次是
														 //电梯序号、所在楼层、乘客序号、每层楼上电梯的乘客人数
														 //每层楼等待的乘客序列的迭代器
void _operate_Lift(int, int, int, int, int[], int[]);//调度电梯的函数，参数依次是
													 //采用的算法、楼层总数、电梯总数、电梯最大负载
													 //每层楼上电梯的乘客人数、每层楼离开的乘客人数

void _set_Color(int); //改变背景颜色和字体颜色，参数为颜色方案

void _clear_Screen(int, int, int, double);//在每次演示前清屏，参数依次是
										  //楼层总数、电梯总数、电梯最大负载、泊松参数λ







