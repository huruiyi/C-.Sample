#include <iostream>
#include <string.h>

using namespace std;

namespace MyNameSpace1
{
    int a = 10;
    const int b = 123;
    struct  Person
    {
        int a;
        string Name;
    };

    void func();
    void func()
    {
    }
}

namespace MyNamespace2
{
    void PrintInfo()
    {
        printf("MyNameSpace1::a=%d", MyNameSpace1::a);
    }
}