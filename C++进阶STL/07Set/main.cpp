#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <set>

using namespace std;
/*
1 ：元素会自动去重
2：添加重复元素编译不报错，但不能添加成功
3：默认从小到大排序，（用仿函数 指定排序规则）可重载从大到小排序
 */
void test01()
{
    pair<string, int> p1("姓名1", 19);
    pair<string, int> p2("姓名2", 25);
    cout << p1.first << p1.second << endl;
    cout << p2.first << p2.second << endl;
    p1.swap(p2);
    cout << p1.first << p1.second << endl;
    cout << p2.first << p2.second << endl;
}

void test_insert(set<int> &s1)
{
    pair< set<int>::iterator, bool > ret = s1.insert(10);
    if (ret.second)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }

    ret = s1.insert(10);
    if (ret.second)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }

    multiset<int>s2; //成功 可以插入重复的key值
    s2.insert(10);
    s2.insert(10);
}
void test_count(set<int> & se, int delVal)
{
    //计数  count 对于set而言 要么0 要么1
    int num = se.count(delVal);
    cout << delVal << "的个数为：" << num << endl;
    cout << (num ? "查找到" : "未查找到") << endl;
}

void test_empty_size(set<int> & se)
{
    if (se.empty())
    {
        cout << "se为空" << endl;
    }
    else
    {
        cout << "size = " << se.size() << endl;
    }
}

void test_foreach(const set<int> & se)
{
    for (set<int>::iterator i = se.begin(); i != se.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;
}

void test_foreach(set<int> & se)
{
    for (set<int>::iterator i = se.begin(); i != se.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;
}

void test_bound(set<int> & s1)
{
    //lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    set<int>::iterator it = s1.lower_bound(30);
    if (it != s1.end())
    {
        cout << "找到了lower_bound的值" << *it << endl;
    }

    //upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    set<int>::iterator it2 = s1.upper_bound(30);
    if (it2 != s1.end())
    {
        cout << "找到了upper_bound的值" << *it2 << endl;
    }

    //equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    pair<set<int>::iterator, set<int>::iterator> it3 = s1.equal_range(30);
    if (it3.first != s1.end())
    {
        cout << "找到equal_range中lower_bound的值：" << *(it3.first) << endl;
    }

    if (it3.second != s1.end())
    {
        cout << "找到equal_range中upper_bound的值：" << *(it3.second) << endl;
    }
}

void test_find(set<int> & se, int val)
{
    set<int>::iterator pos = se.find(val);
    if (pos != se.end())
    {
        cout << "找到该值 为：" << *pos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

void test_clear_erase(set<int> & se)
{
    //se.clear();//删除所有元素
    se.erase(se.begin());//删除第一个元素
    se.erase(5); //删除所有等于的元素
    se.erase(se.begin(), se.end());//删除所有
}

void test02()
{
    set<int> se;
    se.insert(2);
    se.insert(5);
    se.insert(6);
    se.insert(1);
    se.insert(3);
    se.insert(15);
    se.insert(9);
    se.insert(5);
    se.insert(11);
    se.insert(8);
    se.insert(11);
    se.insert(19);
    se.insert(16);

    test_foreach(se);
}

class myCompare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
void test03()
{
    set<int, myCompare> s;
    s.insert(2);
    s.insert(7);
    s.insert(1);
    s.insert(6);
    for (set<int, myCompare>::iterator i = s.begin(); i != s.end(); i++)
    {
        cout << *i << endl;
    }
}

class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }
public:
    string mName;
    int mAge;
};
class myPersonCompare
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.mAge > p2.mAge;
    }
};
void test04()
{
    set<Person, myPersonCompare> sp;
    Person p4("爷爷", 50);
    Person p2("三娃", 10);
    Person p3("六娃", 6);
    Person p1("大娃", 20);

    sp = { p1,p2,p3 };
    sp.insert(p4);

    for (set<Person, myPersonCompare>::iterator i = sp.begin(); i != sp.end(); i++)
    {
        cout << i->mName << "   " << (*i).mAge << endl;
    }
}

int main()
{
    test04();

    system("pause");
    return 0;
}