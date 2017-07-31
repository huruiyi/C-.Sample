#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//using namespace std; using指令 指定命名空间所有的符号在当前的作用域内有效
void test01()
{
	using namespace std;
	cout << "hello world!" << endl;
}

void test02()
{
	std::cout << "hello test02" << std::endl;
}

namespace A
{
	int a = 10;
}

namespace B
{
	int a = 100;
}

void test03()
{
	//using指令打开连个命名空间容易产生明明冲突
	using namespace A;
	using namespace B;

	std::cout << "a = " << A::a << std::endl;

	//如果局部符号和命名空间的中符号冲突，编译器默认就近匹配符号
	//int a = 20;
	//cout << "a = " << a << endl;
}

//2. using声明，指定命名空间中某个符号有效
namespace C
{
	int a = 10;
}
void test04()
{
	//using声明和局部变量名冲突会编译错误
	using std::cout;
	using std::endl;
	cout << "hello world" << endl;

	using C::a;
	//int a = 100;

	cout << "a = " << a << endl;
}

int main() {
	test03();

	system("pause");
	return EXIT_SUCCESS;
}