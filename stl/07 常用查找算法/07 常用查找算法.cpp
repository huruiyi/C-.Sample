#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置
*/
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //查找5
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos != v.end())
    {
        cout << "找到了5" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

//查找自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }

    bool operator==(const Person&p)
    {
        if (this->mName == p.mName && this->mAge == p.mAge)
        {
            return true;
        }
        return false;
    }

    string mName;
    int mAge;
};

void test02()
{
    vector<Person>v;
    Person p1("aaa", 11);
    Person p2("bbb", 20);
    Person p3("ccc", 31);
    Person p4("ddd", 41);
    Person p5("eee", 51);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    vector<Person>::iterator pos = find(v.begin(), v.end(), p3);
    if (pos != v.end())
    {
        cout << "找到了p3 姓名为：" << (*pos).mName << " 年龄 " << pos->mAge << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

class MyCompare03 :public binary_function<Person*, Person*, bool>
{
public:
    bool operator()(Person* p1, Person* p2) const
    {
        if (p1->mName == p2->mName && p1->mAge == p2->mAge)
        {
            return true;
        }
        return false;
    }
};

void test03()
{
    vector<Person*>v;
    Person p1("aaa", 11);
    Person p2("bbb", 20);
    Person p3("ccc", 31);
    Person p4("ddd", 41);
    Person p5("eee", 51);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    Person * p = new Person("ccc", 3);
    vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare03(), p));

    if (pos != v.end())
    {
        cout << "找到了 姓名：" << (*pos)->mName << " 年龄：  " << (*pos)->mAge << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

/*
adjacent_find算法 查找相邻重复元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
@return 返回相邻元素的第一个位置的迭代器
*/
void test04()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(2);
    v.push_back(4);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos != v.end())
    {
        cout << "查到了相邻重复元素 " << *pos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

/*
binary_search算法 二分查找法
注意: 在无序序列中不可用
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return bool 查找返回true 否则false
*/

void test05()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    bool ret = binary_search(v.begin(), v.end(), 9);
    if (ret)
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/
/*
count_if算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/
class GreaterThenFour
{
public:
    bool operator()(int v)
    {
        return v > 4;
    }
};

void test06()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(2);
    v.push_back(4);

    int num = count(v.begin(), v.end(), 4);
    cout << "num = " << num << endl;

    //查找大于4的个数
    int num2 = count_if(v.begin(), v.end(), GreaterThenFour());
    cout << "大于4的个数为： " << num2 << endl;
}

int main() {
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();

    system("pause");
    return EXIT_SUCCESS;
}