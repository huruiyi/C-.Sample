#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
    const int *p = NULL;
    int *pp = const_cast<int *>(p); //int *pp = (int *)p;
    const int *cp = const_cast<const int *>(pp);
}

//强制类型转换
void test02()
{
    int a = 10;
    int *p = reinterpret_cast<int *>(a);
}

int main() {
    system("pause");
    return EXIT_SUCCESS;
}