#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <queue>
using namespace std;

void test01()
{
    queue<int>q;

    q.push(10);
    q.push(30);
    q.push(20);
    q.push(40);
    q.push(60);

    while (!q.empty())
    {
        cout << "队头元素： " << q.front() << endl;
        cout << "队尾元素： " << q.back() << endl;
        //移除队伍头
        q.pop();
    }

    cout << "size = " << q.size() << endl;;
}

int main()
{
    test01();

    system("pause");
    return 0;
}