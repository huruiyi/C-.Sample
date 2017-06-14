#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include<stack>
using namespace std;

void test01()
{
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(9);
    s.push(6);
    s.push(2);
    s.push(8);

    while (!s.empty())
    {
        cout << "Õ»¶¥ÔªËØ" << s.top() << endl;
        //µ¯³öÕ»¶¥ÔªËØ
        s.pop();
    }
    cout << "size = " << s.size() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}