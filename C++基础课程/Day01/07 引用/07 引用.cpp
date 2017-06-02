#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1. 引用基本语法
void test01()
{
    //从语法角度：引用的语法就是给一个已有变量取一个别名
    int a = 10;
    int &b = a;
    int &d = b;

    d = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "d = " << d << endl;

    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    cout << "d = " << &d << endl;

    double c = 3.14;
    double &ref = c;
}

//2. 使用引用注意点
void test02()
{
    //1. 引用一旦初始化，不能修改
    int a = 10;
    int c = 20;
    int &b = a;
    b = c; //赋值

    //2. 引用一定要引用一块合法的内存，切记不能返回局部变量的引用
    //3. 不能创建空引用
    //4. 建立对数组的引用
    int arr[10];
    int(&pArr)[10] = arr;
    pArr[0] = 100;
    cout << "Arr[0]:" << arr[0] << endl;

    typedef int(ARR_TYPE)[10];
    ARR_TYPE &arrRef = arr;
    cout << arrRef[0] << endl;
}

int main() {
    //test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}