#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <functional> //内建函数对象的 头文件
#include <vector>
#include <algorithm>
//template<class T> T negate<T>//取反仿函数
void test01()
{
    negate<int>n;

    cout << n(10) << endl;
}

//template<class T> T plus<T>//加法仿函数
void test02()
{
    plus<int> p;
    cout << p(1, 1) << endl;
}

//template<class T> bool greater<T>//大于
void test03()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(70);

    sort(v.begin(), v.end(), greater<int>());

    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
    cout << endl;
}

int main()
{
    test03();
    system("pause");
    return EXIT_SUCCESS;
}