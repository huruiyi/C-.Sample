#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    void setReadWrite(string param)
    {
        mReadWrite = param;
    }

    string getReadWrite()
    {
        return mReadWrite;
    }

    string getOnlyRead()
    {
        return mOnlyRead;
    }

    void setOnlyWrite(string param)
    {
        mOnlyWtite = param;
    }

private:
    string mReadWrite;
    string mOnlyRead;
    string mOnlyWtite;
};

//可以控制成员的读写访问权限
//对成员的赋值操作有效性校验

int main() {
    system("pause");
    return EXIT_SUCCESS;
}