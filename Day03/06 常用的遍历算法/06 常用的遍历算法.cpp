#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <functional>

void myPrint(int v)
{
    cout << v << " ";
}

class myPrint01
{
public:
    void operator()(int v)
    {
        cout << v << " ";
        count++;
    }
    int count = 0;
};

//for_each
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //for_each(v.begin(), v.end(), myPrint);
    for_each(v.begin(), v.end(), myPrint01());
}

//有返回值
void test02()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    myPrint01 myP = for_each(v.begin(), v.end(), myPrint01());
    cout << endl;
    //cout << "使用次数" << myP.count << endl;;
}

class myPrint03 :public binary_function<int, int, void>
{
public:
    void operator()(int v, int start) const
    {
        cout << v + start << " ";
    }
};
//绑定参数输出
void test03()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), bind2nd(myPrint03(), 1000));
}

/*
transform算法 将指定容器区间元素搬运到另一容器中
注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
@param beg1 源容器开始迭代器
@param end1 源容器结束迭代器
@param beg2 目标容器开始迭代器
@param _cakkback 回调函数或者函数对象
@return 返回目标容器迭代器
*/

class myTransform
{
public:
    int operator()(int v)
    {
        return v + 1000;
    }
};

void test04()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //目标容器
    vector<int>vTarget;
    vTarget.resize(v.size());

    transform(v.begin(), v.end(), vTarget.begin(), myTransform());

    for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}

int main() {
    //	test01();

    //	test02();

    //	test03();

    test04();
    system("pause");
    return EXIT_SUCCESS;
}