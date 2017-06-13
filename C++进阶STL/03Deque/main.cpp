#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

void printDeque(const deque<int> d)
{
    for (deque<int>::const_iterator i = d.begin(); i < d.end(); i++)
    {
        cout << *i << "\t";
        //*i = 123;  值不可以修改
    }
    cout << endl;
}
void test01()
{
    deque<int> d{ 1,2,3,4,5 };
    d.push_back(6);
    d.push_back(7);
    printDeque(d);

    cout << d.front() << endl;
    cout << d.back() << endl;
    d.pop_front();
    d.pop_back();

    printDeque(d);

    //清空deque
    //d.clear();

    //新增
    d.insert(d.begin(), 11);
    printDeque(d);

    //删除
    d.erase(d.begin() + 2);

    printDeque(d);
}

class Person
{
public:
    string mName;
    int mScore;
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mScore = age;
    }
};

void test04()
{
    Person p1("A", 50);
    Person p2("B", 90);
    Person p3("C", 75);
    Person p4("D", 88);
    Person p5("E", 60);
    Person p6("F", 68);
    Person p7("G", 102);
    Person p8("H", 91);
    Person p9("I", 78);
    Person p10("J", 63);

    vector<Person> vp = { p1,p2,p3,p4,p5 };
    vp.push_back(p6);
    vp.push_back(p7);
    vp.push_back(p8);
    vp.push_back(p9);
    vp.push_back(p10);

    deque<Person> de;
    for (vector<Person>::iterator i = vp.begin(); i < vp.end(); i++)
    {
        de.push_back(*i);
    }
    //deque<Person> de = { p1 ,p2,p3,p4,p5,p6 };
    cout << "排序前：....................." << endl;
    for_each(de.begin(), de.end(), [](Person p) {cout << p.mName << " " << p.mScore << endl; });
    cout << "排序后：....................." << endl;
    sort(de.begin(), de.end(), [](Person p1, Person p2) {return p1.mScore > p2.mScore; });
    de.pop_front();
    de.pop_back();
    for_each(de.begin(), de.end(), [](Person p) {cout << p.mName << " " << p.mScore << endl; });

    int sumSocore = 0;
    for (deque<Person>::iterator i = de.begin(); i < de.end(); i++)
    {
        sumSocore += (*i).mScore;
    }

    cout << "平均分：" << sumSocore / de.size() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}