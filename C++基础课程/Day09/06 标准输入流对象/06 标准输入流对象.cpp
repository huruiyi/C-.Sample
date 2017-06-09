#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
*/

void test01()
{

#if 0
	char ch;
	cin.get(ch);
	cout << "ch = " << ch << endl;
	cin.get(ch);
	cout << "ch = " << ch << endl;
	ch = cin.get();
	if (ch == '\n')
	{
		cout << "最后一个字符是换行！" << endl;
	}
#endif

	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	cout << buf;

	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "最后一个字符是换行！" << endl;
	}

	//cin.get读取一行数据，但是不读走换行，换行字符仍然留在缓冲区
}
/*
cin.getline()
*/

void test02()
{
	char buf[1024] = { 0 };
	cin.getline(buf,1024);
	cout << buf;
	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "最后一个字符是换行！" << endl;
	}

	//cin.getline读取一行数据，并且扔掉换行字符
}

/*
cin.ignore()
cin.peek()
cin.putback()
*/

void test03()
{
	//忽略当前字符，扔掉当前字符 asd
	cin.ignore(2);
	char ch = cin.get();
	cout << "ch = " << ch << endl;
}

void test04()
{
	//偷窥，看下当前字符是什么，但是并取走数据 asd
	char ch = cin.peek();
	cout << "ch = " << ch << endl;
	ch = cin.get();
	cout << "ch = " << ch << endl;

}

void  test05()
{
	char ch = cin.get();
	//将ch字符再放回缓冲区当前位置 asd
	cin.putback(ch);

	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	cout << buf << endl;
}
int main(){

	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	system("pause");
	return EXIT_SUCCESS;
}