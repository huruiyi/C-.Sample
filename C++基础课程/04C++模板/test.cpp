#include <iostream>

void fun1(int a, int b)
{
	std::cout << "void fun1(int a,int b)" << std::endl;
}

//����ģ�����ʱ���ֵ�ǰ�ļ���û�б����ã�����˲�����α��룬���ⲿ�ļ������޷�ʹ�õ�
template<class T> void fun2(T a, T b)
{
	std::cout << "void fun2(T a, T b)" << std::endl;
}