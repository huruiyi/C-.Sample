#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1. C语言中的const被理解为"只读的变量"，既然是变量，总是分配内存

//2. C++中的const全局变量是内部连接的，默认只能在当前文件内访问
void test01()
{
	extern const int a;
	cout << "a = " << a << endl;
}
//3. C++中的const是否分配内存，要看怎么使用
//如果是const int a = 10;
const int num = 10; //常量区
//1.需要知道num的地址
//2.当const变量设置为extern，会分配内存
void test02()
{
	int* p = (int*)& num;
	//常量不可以修改
	*p = 100;
}

int b = 10;
const int c = b; //全局静态区
//3.分配内存
void test03()
{
	cout << "c = " << c << endl;
	int* p = (int*)& c;
	*p = 100;

	cout << "c = " << c << endl;
}

void test04()
{
	//栈区
	volatile const int a = 10;

	int* p = (int*)& a;
	*p = 100;
	//*p其实已经改变了变量a的值，编译器对a的访问做了优化处理
	//volatile关键字告诉编译器，不要对a变量做优化，每次访问a的时候，从a内存中访问

	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;
}

int main() {
	test04();

	system("pause");
	return EXIT_SUCCESS;
}