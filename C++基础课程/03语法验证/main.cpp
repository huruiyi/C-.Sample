#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

void test0()
{
    int a = 123;
    int *p = &a;
    int &r = a;
}
void test1()
{
    //2017-05-29 15:39:57

    const char const *  const p1 = "Hello World";
    const char const *p2 = "Hello World";
    const char *p3 = "Hello World";
    char *p4 = "Hello World";

    printf("%p-%s\n", p1, p1);
    printf("%p-%s\n", p2, p2);
    printf("%p-%s\n", p3, p3);
    printf("%p-%s\n", p4, p4);
}

void test2()
{
    int a = 123;
    int &ra = a;
    int b = ra;
    cout << b;
}
int main()
{
    test0();
    system("pause");
    return 0;
}