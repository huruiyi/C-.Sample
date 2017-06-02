#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:
    explicit MyString(int num)
    {
    }

    MyString(const char *str)
    {
    }
};

void test()
{
    //MyString str1 = 10;
    MyString str2 = "hello world";
}

int main() {
    system("pause");
    return EXIT_SUCCESS;
}