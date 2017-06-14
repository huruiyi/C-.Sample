#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
/*
 1:不支持随机访问
    //list<int>::const_iterator itx;
    //itx + 2;//不支持随机访问
 2:自定义元素不能直接remove,要重载后才可以
 3:元素可重复出现
 4:删除元素会删除所有满足条件的值
 */
class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }
    bool operator==(const Person p) const
    {
        if (p.mName == this->mName&&p.mAge == this->mAge)
        {
            return true;
        }
        return false;
    }

public:
    string mName;
    int mAge;
};
class Cmpare
{
public:
    bool operator()(const Person p1, const Person  p2) const
    {
        return p1.mAge < p2.mAge;
    }
};
bool myCompare(const int v1, const int v2)
{
    //从大到小
    return v1 > v2;
}
void test_foreach(const list<int>& L)
{
    //list<int>::const_iterator itx;
    //itx + 2;//不支持随机访问
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test_empty_size_resize(list<int>& L)
{
    if (L.empty())
    {
        cout << "为空" << endl;
    }
    else
    {
        cout << "不为空  L4 大小： " << L.size() << endl;
    }

    L.resize(10);
    L.resize(10, 100);
}
void test_front_front(list<int>& L)
{
    cout << "第一个元素：" << L.front() << " 最后一个元素： " << L.back() << endl;
    L.pop_back();//尾删
    L.pop_front();//头删
    L.push_front(90);
    L.push_back(110);
}
void test_reverse(list<int>& L)
{
    L.reverse();
}

void test01()
{
    list<int> li;
    li.push_back(18);
    li.push_back(12);
    li.push_back(11);
    li.push_back(16);
    li.push_back(13);
    li.push_back(12);

    //li.sort();//默认从小到大
    //li.sort([](int a, int b) {return a < b; });//从小到大
    //li.sort([](int a, int b) {return a > b; });//从大到下
    li.sort(myCompare);
    test_foreach(li);

    for_each(li.begin(), li.end(), [](int a) {cout << a << endl; });

    cout << "移除12前大小" << li.size() << endl;
    li.remove(12);
    cout << "移除12后大小" << li.size() << endl;
}

void test02()
{
    list<Person> lip;
    Person p1("A", 20);
    Person p2("B", 29);
    Person p3("C", 25);
    Person p4("D", 22);
    Person p5("E", 27);
    Person p6("F", 21);
    lip.push_back(p1);
    lip.push_back(p2);
    lip.push_back(p3);
    lip.push_back(p4);
    lip.push_back(p5);
    lip.push_back(p6);

    //自定义数据类型需要重载“==”运算符，才能remove
    lip.remove(p4);

    lip.sort(Cmpare()); //自定义类型不支持排序

    //lip.sort([](Person p1, Person p2) {return p1.mAge > p2.mAge; });
    for_each(lip.begin(), lip.end(), [](Person p)
    {
        cout << "name：" << p.mName << "，ag：" << p.mAge << endl;
    });
}

int main()
{
    test__Nodeptr();
    system("pause");
    return 0;
}