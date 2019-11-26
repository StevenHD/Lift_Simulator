//数据结构与算法实习值电梯模拟器
//输入方式：键盘读入数据
//输出方式：win32控制台界面输出

//此电梯的基本功能：

#include "Lift_Simulator.h"

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


//定义完函数后，我们要定义一些class
class PASSENGER
{
public:
	int _from_which_floor;//乘客在哪层楼出现
	int _to_which_floor;//乘客的目的楼层
	int _ppl_appear_time;//乘客出现的时间
	int _in_lift_time;//乘客进电梯的时间
	int _out_lift_time;//乘客出电梯的时间

	//ctor
	PASSENGER(const int f, const int t, const int a)//定义成const int的含义我们后面解释
	{
		_from_which_floor = f;
		_to_which_floor = t;
		_ppl_appear_time = a;//init各种参数

		_in_lift_time = _out_lift_time = 0;
	}

	//初始化
	void init()
	{
		_in_lift_time = _out_lift_time = 0;//为什么要把这个初始化时间多写一遍呢？
	}
};

class FLOOR
{
	//对楼层进行初始化
	list<int> _num_ppl_wait;//该变量记录在该楼层FLOOR等待的乘客的序号
	
	void init()
	{
		_num_ppl_wait.clear();//人进人出，不断地更新这个序号值
	}
};

class LIFT
{
public:
	bool _stop_which_Floor[MAX_FLOOR_NUMS + 1];//该变量表示电梯是否需要在某层楼停下
	int _current_Floor;
	int _target_Floor;
	int _former_Floor;//表示电梯之前所在的楼层

	list<int> _num_in_Lift; //表示该电梯内乘客的序号

	LIFT()
	{
		_target_Floor = _former_Floor = 0;
		
		for (int i = 1; i <= MAX_FLOOR_NUMS; i++)//电梯需要从1楼开始上，起码有2楼
		{
			_stop_which_Floor[i] = 0;//先初始化成0，表示不在该楼层停
		}
	}

	void init()
	{
		//为什么每个class中都要用一个init函数？
		_num_in_Lift.clear();
		_target_Floor = _former_Floor = 0;//而且target的这些初始化在这个init中还要重新写一次

		for (int j = 1; j <= MAX_FLOOR_NUMS; j++)
		{
			_stop_which_Floor[j] = 0;//意义同上
		}
	}
};

HANDLE hOut;//这个需要windows.h
			//输出句柄




