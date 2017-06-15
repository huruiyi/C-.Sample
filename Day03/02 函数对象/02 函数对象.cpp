#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyPrint
{
public:
    void operator()(int num)
    {
        cout << num << endl;
        count++;
    }
    int count = 0; //统计MyPring调用次数
};

void MyPrint2(int num)
{
    cout << num << endl;
}

void test01()
{
    //函数对象 仿函数 是一个类，而不是函数
    MyPrint myPrint;
    myPrint(100);
}

//仿函数 超出普通函数概念，内部可以维护一些状态
void test02()
{
    MyPrint myPrint;
    myPrint(100);
    myPrint(100);
    myPrint(100);
    myPrint(100);

    cout << "count = " << myPrint.count << endl;
}

//仿函数可以作为参数
void doWork(MyPrint print, int num)
{
    print(num);
}

void test03()
{
    doWork(MyPrint(), 1000); //MyPrint()
}

int main()
{
    test03();

    system("pause");
    return EXIT_SUCCESS;
}