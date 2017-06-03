#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include "MyArray.h"
using namespace std;

void test()
{
    MyArray arr(20);
    for (int i = 0; i < arr.capacity(); i++)
    {
        arr.pushBack(10 + i);
    }
    arr.foreach();

    arr.popBack();
    arr.foreach();

    arr.popFront();
    arr.foreach();

    cout << arr.getData(10) << endl;
    int&  data = arr.getData(10);
    data = 132;
    cout << arr.getData(10) << endl;

    arr.insert(12, 1234);
    arr.foreach();

}
int main()
{
    test();
    system("pause");
    return 0;
}