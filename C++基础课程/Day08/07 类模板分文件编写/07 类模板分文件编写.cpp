#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#include "MyArray1.hpp"
#include "MyArray2.hpp";
#include "MyArray3.hpp"
//类模板不能分文件编写
//C++独立编译
//模板二次编译

void test0()
{
    MyArray2<int> *arr = new MyArray2<int>;
    arr->mSize = 100;
    int a = 123;
    int *p = &a;
    arr->pAddress = p;
    cout << arr;
}

void test1()
{
    MyArray1<int> arr(5);
    arr.Push(11);
    arr.Push(12);
    arr.Push(13);
    arr.Push(14);
    arr.Push(15);
    arr.Push(16);

    try
    {
        int arrItem2 = arr[2];
        cout << arrItem2 << endl;

        int arrItem5 = arr[5];
        cout << arrItem5 << endl;
    }
    catch (const string &str)
    {
        cout << str << endl;
    }

    cout << arr;
    showArray(arr);
}

void test2()
{
    MyArray3<int> arr1;
    MyArray3<int> arr2("Name", 123);
    //ShowArray1(arr2);
    //ShowArray2(arr2);
    //ShowArray3(arr2);

    cout << arr2;
}
int main()
{
    test2();
    system("pause");
    return EXIT_SUCCESS;
}