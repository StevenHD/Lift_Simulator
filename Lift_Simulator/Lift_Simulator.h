#include <iostream>
#include <iomanip> //io�������������manip��manipulator��������������д
//���磺setw(n)
#include <list>
#include <windows.h>
#pragma comment(lib, "winmm.lib")//lib��һ��Ԥ����ı�ʶ����ָ��ע�͵����ͣ�
//����lib���⣬����compiler, exestr, linker�����
//"winmm.lib"��һ��Ϊlib�ṩ������Ϣ���ַ���
//winnmm.dll��windows��ý�����Ӧ�ó���ӿڣ����ڵ͵�����Ƶ����Ϸ�ֱ�

//���ȶ�����ݵ�����ط�Χ
#define MIN_MAXLOAD 5
#define MAX_MAXLOAD 20

//Ȼ����¥����
#define MIN_FLOOR_NUMS 2 //Ϊʲô¥����������Ϊ1�أ�
						 //���Ǻ�����˵
#define MAX_FLOOR_NUMS 40

//���Ŷ�����ݵ����� 
#define MIN_LIFT_NUMS 1
#define MAX_LIFT_NUMS 13

//��Ϊ���ǻ��õ����ɷֲ�������Ҫ���岴�ɲ����ķ�Χ
#define MIN_LAMBDA 0.1
#define MAX_LAMBDA 20

//����һЩ�������
//�����³��ֵĳ˿��������ֵ(100��)����λΪs
#define MAX_NEW_PASSENGER 100

//���а������Ǵ˴�ģ����Ҫ�õ����ʱ��,400s(�����ʱ��ָ���ǵ���ģ����������ʱ�䣬��������ʵʱ�䣬
//����ʲô�������Ǻ�����˵)
#define MAX_PASSTIME 400

//���������Ƕ���һ�²�ͬ״̬ʱ�����ɫ
#define NORMAL 0
#define INFO 1
#define BLANK 2
#define DOWN 3
#define UP 4
#define OPEN 5
#define BUTTON 6
#define TABLE 7

//�����һ����ʾ���ڵĴ�С
#define SCREEN_WIDTH 168 //��Ļ���
#define SCREEN_HEIGHT 57 //��Ļ�߶�
#define WINDOW_WIDTH 167 //���ڿ��
#define WINDOW_HEIGHT 43 //���ڸ߶�

//���Ŷ���һ��ʱ�䣬����Ļ�����ʵ���أ�
//����İ�
#define SECONDS_PER_HOUR 3600.0

using namespace std;
