#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#include"MyArr.hpp";

#include"MyArray.hpp" //boost
#include<vector>

//类模板不能分文件编写
//C++独立编译
//模板二次编译

void test0()
{
    MyArr<int> *arr = new MyArr<int>;
    arr->mSize = 100;
    int a = 123;
    int *p = &a;
    arr->pAddress = p;
    cout << arr;
}
void test1()
{
    MyArray<int> arr(5);
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

int main()
{
    test1();

    system("pause");
    return EXIT_SUCCESS;
}