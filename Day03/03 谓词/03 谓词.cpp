#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

class GreaterThen20
{
public:
    bool operator()(int v)
    {
        return v > 20;
    }
};

//一元谓词
void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(70);

    //需求 找大于20 的第一个数字
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());
    if (pos != v.end())
    {
        cout << "找到大于20 的数字 " << *pos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

//二元谓词
void test02()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(70);

    sort(v.begin(), v.end(), MyCompare());
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
}

int main()
{
    //test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}