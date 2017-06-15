#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
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

namespace ke
{
    enum
    {
        CAIWU, RENLI, YANFA
    };

    class Worker
    {
    public:
        string mName; //姓名
        int mMoney; //工资
    };

    void createWorker(vector<Worker>&v)
    {
        string nameSeed = "ABCDE";
        for (int i = 0; i < 5; i++)
        {
            string name = "员工";
            name += nameSeed[i];

            Worker w;
            w.mName = name;
            w.mMoney = rand() % 10000 + 10000; // 10000 ~ 19999

                                               //将员工放入到容器中
            v.push_back(w);
        }
    }

    void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
    {
        for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
        {
            //随机产生部门编号
            int departmentId = rand() % 3; // 0 1 2
            //将员工放入到 m容器中
            m.insert(make_pair(departmentId, *it));
        }
    }

    void showGroup(multimap<int, Worker>&m)
    {
        // 0  A  0  B   1 C   2 D  2 E 假数据

        cout << "财务部门员工如下：" << endl;

        multimap<int, Worker>::iterator pos = m.find(CAIWU);
        int countNum = m.count(CAIWU);
        int num = 0;
        for (; pos != m.end(), num < countNum; pos++, num++)
        {
            cout << "姓名： " << pos->second.mName << " 工资： " << pos->second.mMoney << endl;
        }

        cout << "-----------------------" << endl;

        cout << "人力部门员工如下：" << endl;

        pos = m.find(RENLI);
        countNum = m.count(RENLI);
        num = 0;
        for (; pos != m.end(), num < countNum; pos++, num++)
        {
            cout << "姓名： " << pos->second.mName << " 工资： " << pos->second.mMoney << endl;
        }

        cout << "-----------------------" << endl;

        cout << "研发部门员工如下：" << endl;
        pos = m.find(YANFA);
        countNum = m.count(YANFA);
        num = 0;
        for (; pos != m.end(), num < countNum; pos++, num++)
        {
            cout << "姓名： " << pos->second.mName << " 工资： " << pos->second.mMoney << endl;
        }

        cout << "-----------------------" << endl;
    }
    int main()
    {
        //创建员工
        vector<Worker>v;
        createWorker(v);

        //将员工放入到各个部门中
        //容器multimap 存放部门 以及相应的人员
        multimap<int, Worker> m;
        setGroup(v, m);

        //分部门显示员工
        showGroup(m);

        //测试容器
        /*for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
        {
        cout << "姓名： " << it->mName << " 工资： " << it->mMoney << endl;
        }*/

        system("pause");
        return EXIT_SUCCESS;
    }
}

template <typename A, typename B> void print_elem(const pair<A, B>& p)
{
    cout << "(" << p.first << ", " << p.second << ") ";
}

template <typename T> void print_collection(const T& t)
{
    cout << t.size() << " elements: ";

    for (const auto& p : t)
    {
        print_elem(p);
    }
    cout << endl;
}

template <typename C, class T> void findit(const C& c, T val)
{
    cout << "Trying find() on value " << val << endl;
    auto result = c.find(val);
    if (result != c.end())
    {
        cout << "Element found: "; print_elem(*result); cout << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

void test07_multimap()
{
    multimap<int, string> m1({ { 40, "Zr" },{ 45, "Rh" } });
    cout << "The starting multimap m1 is (key, value):" << endl;
    print_collection(m1);

    vector<pair<int, string>> v;
    v.push_back(make_pair(43, "Tc"));
    v.push_back(make_pair(41, "Nb"));
    v.push_back(make_pair(46, "Pd"));
    v.push_back(make_pair(42, "Mo"));
    v.push_back(make_pair(44, "Ru"));
    v.push_back(make_pair(44, "Ru")); // attempt a duplicate

    cout << "Inserting the following vector data into m1:" << endl;
    print_collection(v);

    m1.insert(v.begin(), v.end());

    cout << "The modified multimap m1 is (key, value):" << endl;
    print_collection(m1);
    cout << endl;
    findit(m1, 45);
    findit(m1, 6);
}
int main()
{
    ke::main();

    test07_multimap();

   
    system("pause");
    return 0;
}