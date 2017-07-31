#include <iostream>

void fun1(int a, int b)
{
	std::cout << "void fun1(int a,int b)" << std::endl;
}

//函数模版编译时发现当前文件中没有被调用，，因此不会二次编译，在外部文件中是无法使用的
template<class T> void fun2(T a, T b)
{
	std::cout << "void fun2(T a, T b)" << std::endl;
}