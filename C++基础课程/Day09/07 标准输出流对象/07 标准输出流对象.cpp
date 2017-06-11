#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cout.flush() //刷新缓冲区
cout.put() //向缓冲区写字符
cout.write() //从buffe中写num个字节到当前输出流中。
*/

void test01()
{
    //输出单个字符
    cout.put('a').put('b').put('\n');
    cout.write("hello", 6).write("world", 6);

    cout << "************" << endl;
    //输出字符串
    char buf[] = "hello world!";
    cout.write(buf, strlen(buf));

    cout << endl;
    cout << "***************************************" << endl;
    int len = strlen(buf);
    for (int i = 0; i < len; i++)
    {
        cout << i << "：";
        cout.write(buf, i);
        cout << endl;
    }
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}