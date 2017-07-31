#include<iostream>
//C++标准库的头文件是没有.h扩展
//自己写的C++头文件要加上.h
using namespace std;
//C++引入头文件，默认是引入命名空间，命名空间默认是关闭的，需要手动打开
//C++所有的符号 类 函数 变量，都是放在std命名空间

int main()
{
	//cout 标准输入流对象
	//endl是个函数 输出换行并且刷新缓冲区
	cout << "hello C++" << endl;

	system("pause");
	return 0;
}