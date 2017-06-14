#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;
/*
    插入重复元素不会报错，但数据不会添加到map集合中
    []用法  ，如果保证 key存在，可以用[]进行访问数据，否则会多插入一个数据的
    lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
 **/

void test00_insert(map<int, int> &mp)
{
    // call insert(ValTy&&) version
    mp.insert(make_pair(2, 20));
    mp[5] = 50;
    // call insert(const value_type&) version
    mp.insert({ 1, 10 });
    mp.insert(map<int, int>::value_type(4, 40));
    mp.insert(pair<int, int>(3, 30));
    cout << "mp size:" << mp.size() << endl;
}
void test01_empty(map<int, int> &mp)
{
    if (mp.empty())
    {
        cout << "map为空" << endl;
    }
    else
    {
        cout << "map非空" << endl;
    }
}
void test02_foreach(map<int, int> &mp)
{
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
    {
        cout << i->first << " : " << (*i).second << "--------------" << mp[i->first] << endl;
    }
    cout << endl;
}
void test03_clear_erase(map<int, int> &mp)
{
    //mp.clear();//删除所有元素
    //mp.erase(3); //删除key为3的元素
    //mp.erase(mp.begin());//删除第一个元素
    mp.erase(mp.begin(), mp.end());//从头删到尾
}
void test04_find(map<int, int> &mp, int val)
{
    map<int, int>::iterator pos = mp.find(val);
    if (pos != mp.end())
    {
        cout << "找到了  key = " << (*pos).first << " value = " << (*pos).second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}
void test05_cout(map<int, int> &mp)
{
    int num = mp.count(8);
    cout << num << endl;
    if (num)
    {
        cout << "存在" << endl;
    }
    else
    {
        cout << "不存在" << endl;
    }
}
void test06_bound(map<int, int> &m)
{
    //lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    map<int, int>::iterator it = m.lower_bound(3);
    if (it != m.end())
    {
        cout << "找到 lower_bound key = " << (*it).first << " value = " << (*it).second << endl;
    }

    //upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    map<int, int>::iterator it2 = m.upper_bound(3);
    if (it2 != m.end())
    {
        cout << "找到 upper_bound key = " << (*it2).first << " value = " << (*it2).second << endl;
    }

    //equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    pair<map<int, int>::iterator, map<int, int>::iterator> it3 = m.equal_range(3);
    if (it3.first != m.end())
    {
        cout << "找到 equal_range中的lower_bound key =  " << it3.first->first << " value = " << it3.first->second << endl;
    }

    if (it3.second != m.end())
    {
        cout << "找到 equal_range中的upper_bound key =  " << it3.second->first << " value = " << it3.second->second << endl;
    }
}

void test01()
{
    map<int, int> mp;
    test00_insert(mp);
    //test02_foreach(mp);
    //test04_find(mp, 6);
    test06_bound(mp);

}

class myCompareMap
{
public:
    bool operator()(const int & v1, const int & v2)const
    {
        return v1 > v2;
    }
};
void test02()
{
    map<int, int, myCompareMap> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;
    //按照key做从大到小
    for (map<int, int, myCompareMap>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}
int main()
{
    test02();
    system("pause");
    return 0;
}