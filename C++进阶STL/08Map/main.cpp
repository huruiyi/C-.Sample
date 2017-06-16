#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#if 1 /*函数声明*/
void test_map_value_comp();
void test_multimap6();
void test_multimap7();
void test_multimap8();
void test_multimap9();
#endif
using namespace std;
/*
 *注意事项：
 *multimap不可以用m[4] = 40; 赋值
 *map可以用m[4] = 40; 赋值
 *
    插入重复元素不会报错，但数据不会添加到map集合中
    []用法  ，如果保证 key存在，可以用[]进行访问数据，否则会多插入一个数据的
    lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
 **/

void test_insert(map<int, int> &mp)
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
void test_empty(map<int, int> &mp)
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
void test_foreach(map<int, int> &mp)
{
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
    {
        cout << i->first << " : " << (*i).second << "--------------" << mp[i->first] << endl;
    }
    cout << endl;
}
void test_clear_erase(map<int, int> &mp)
{
    //mp.clear();//删除所有元素
    //mp.erase(3); //删除key为3的元素
    //mp.erase(mp.begin());//删除第一个元素
    mp.erase(mp.begin(), mp.end());//从头删到尾
}
void test_find(map<int, int> &mp, int val)
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
void test_cout(map<int, int> &mp)
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
void test_bound(map<int, int> &m)
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

namespace Multimap_Sample
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

    void showGroup1(multimap<int, Worker>&m)
    {
        // 0  A  0  B   1 C   2 D  2 E 假数据

        multimap<int, Worker>::iterator cPos = m.find(CAIWU);
        multimap<int, Worker>::iterator rPos = m.find(RENLI);
        multimap<int, Worker>::iterator yPos = m.find(YANFA);

        int cNum = m.count(CAIWU);
        int rNum = m.count(RENLI);
        int yNum = m.count(YANFA);

        cout << "财务部门员工如下：" << endl;
        for (int num = 0; cPos != m.end(), num < cNum; cPos++, num++)
        {
            cout << "姓名： " << cPos->second.mName << " 工资： " << cPos->second.mMoney << endl;
        }
        cout << "-----------------------" << endl;

        cout << "人力部门员工如下：" << endl;
        for (int num = 0; rPos != m.end(), num < rNum; rPos++, num++)
        {
            cout << "姓名： " << rPos->second.mName << " 工资： " << rPos->second.mMoney << endl;
        }
        cout << "-----------------------" << endl;

        cout << "研发部门员工如下：" << endl;
        for (int num = 0; yPos != m.end(), num < yNum; yPos++, num++)
        {
            cout << "姓名： " << yPos->second.mName << " 工资： " << yPos->second.mMoney << endl;
        }
        cout << "-----------------------" << endl;
    }

    void showGroup2(multimap<int, Worker>&m)
    {
        multimap<int, Worker>::iterator cPos = m.find(CAIWU);
        multimap<int, Worker>::iterator rPos = m.find(RENLI);
        multimap<int, Worker>::iterator yPos = m.find(YANFA);
        int cNum = m.count(CAIWU);
        int rNum = m.count(RENLI);
        int yNum = m.count(YANFA);

        cout << "财务部门员工如下：" << endl;
        while (cPos != m.end() && cNum)
        {
            cout << "姓名： " << cPos->second.mName << " 工资： " << cPos->second.mMoney << endl;
            cPos++;
            cNum--;
        }
        cout << "-----------------------" << endl;

        cout << "人力部门员工如下：" << endl;
        while (rPos != m.end() && rNum)
        {
            cout << "姓名： " << rPos->second.mName << " 工资： " << rPos->second.mMoney << endl;
            rPos++;
            rNum--;
        }
        cout << "-----------------------" << endl;

        cout << "研发部门员工如下：" << endl;
        while (yPos != m.end() && yNum)
        {
            cout << "姓名： " << yPos->second.mName << " 工资： " << yPos->second.mMoney << endl;
            yPos++;
            yNum--;
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
        showGroup1(m);
        showGroup2(m);

        //测试容器
        /*for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
        {
        cout << "姓名： " << it->mName << " 工资： " << it->mMoney << endl;
        }*/

        system("pause");
        return EXIT_SUCCESS;
    }
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

void test_multimap1()
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

template <typename M> void print(const M& m)
{
    cout << m.size() << " elements: ";

    for (const auto& p : m)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    cout << endl;
}

void test_multimap2()
{
    // insert single values
    multimap<int, int> m1;
    // call insert(const value_type&) version
    m1.insert({ 1, 10 });
    // call insert(ValTy&&) version
    m1.insert(make_pair(2, 20));

    cout << "The original key and mapped values of m1 are:" << endl;
    print(m1);

    // intentionally attempt a duplicate, single element
    m1.insert(make_pair(1, 111));

    cout << "The modified key and mapped values of m1 are:" << endl;
    print(m1);

    // single element, with hint
    m1.insert(m1.end(), make_pair(3, 30));
    cout << "The modified key and mapped values of m1 are:" << endl;
    print(m1);
    cout << endl;

    // The templatized version inserting a jumbled range
    multimap<int, int> m2;
    vector<pair<int, int>> v;
    v.push_back(make_pair(43, 294));
    v.push_back(make_pair(41, 262));
    v.push_back(make_pair(45, 330));
    v.push_back(make_pair(42, 277));
    v.push_back(make_pair(44, 311));

    cout << "Inserting the following vector data into m2:" << endl;
    print(v);

    m2.insert(v.begin(), v.end());

    cout << "The modified key and mapped values of m2 are:" << endl;
    print(m2);
    cout << endl;

    // The templatized versions move-constructing elements
    multimap<int, string>  m3;
    pair<int, string> ip1(475, "blue"), ip2(510, "green");

    // single element
    m3.insert(move(ip1));
    cout << "After the first move insertion, m3 contains:" << endl;
    print(m3);

    // single element with hint
    m3.insert(m3.end(), move(ip2));
    cout << "After the second move insertion, m3 contains:" << endl;
    print(m3);
    cout << endl;

    multimap<int, int> m4;
    // Insert the elements from an initializer_list
    m4.insert({ { 4, 44 },{ 2, 22 },{ 3, 33 },{ 1, 11 },{ 5, 55 } });
    cout << "After initializer_list insertion, m4 contains:" << endl;
    print(m4);
    cout << endl;
}

template <typename A, typename B> void print_elem(const pair<A, B>& p)
{
    cout << "(" << p.first << ", " << p.second << ") ";
}

typedef pair<int, int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs)
{
    if (lhs.first == rhs.first)
    {
        return lhs.second < rhs.second;
    }
    else
    {
        return lhs.first > rhs.first;
    }
}

struct CmpByValue
{
    bool operator()(const PAIR& lhs, const PAIR& rhs)
    {
        if (lhs.first == rhs.first)
        {
            return lhs.second < rhs.second;
        }
        else
        {
            return lhs.first > rhs.first;
        }
    }
};

//只通过值来排序
bool cmp_only_by_value(const PAIR& lhs, const PAIR& rhs)
{
    return lhs.second > rhs.second;
}

void test_multimap3()
{
    multimap<int, int>a;
    a.insert(make_pair(7, 6));
    a.insert(make_pair(3, 4));
    a.insert(make_pair(1, 2));
    a.insert(make_pair(3, 2));
    a.insert(make_pair(3, 1));
    a.insert(make_pair(4, 2));
    a.insert(make_pair(9, 10));
    a.insert(make_pair(11, 2));
    a.insert(make_pair(14, 6));
    a.insert(make_pair(4, 2));
    vector<PAIR> nsv(a.begin(), a.end());
    // sort(nsv.begin(), nsv.end(), CmpByValue());
    //sort(nsv.begin(), nsv.end(), cmp_by_value);
    sort(nsv.begin(), nsv.end(), cmp_only_by_value);
    for (int i = 0; i != nsv.size(); ++i)
    {
        cout << nsv[i].first << "    " << nsv[i].second << endl;
    }
}

struct cmp
{
    bool operator() (const string& str1, const string& str2)
    {
        return str1.length() < str2.length();
    }
};

void test_multimap4()
{
    multimap<string, int, cmp>mp;
    mp.insert(make_pair("中国共产党", 2));
    mp.insert(make_pair("中国", 1));
    mp.insert(make_pair("中华人民共和国", 4));
    mp.insert(make_pair("中华人民", 3));
    mp.insert(make_pair("中国人", 5));
    cout << "按照key的长度排序：" << endl;
    for (map<string, int, cmp>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << "  " << iter->second << endl;
    }
}

class myCompareMap
{
public:
    bool operator()(const int & v1, const int & v2)const
    {
        return v1 > v2;
    }
};

void test_multimap5()
{
    multimap<int, int, myCompareMap> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    //m[4] = 40; //multimap不可以用此方式赋值
    //按照key做从大到小
    for (map<int, int, myCompareMap>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

/*
 在映射包含的全部元素之间 value_types 的 value_compare 提供的比较条件从在单个元素的键之间的一种比较会导致辅助由类构造。
 成员函数在 value_compare 运算符提供的函数对象使用对象存储的 key_compare 类型 组件 比较两元素 SORT 键组件。

对于设置和多集，是简单容器的键值与值元素相同， value_compare 等效于 key_compare;
对于映射和 multimaps 没有，因为 pair 类型元素的值与元素的键的值不相同。

示例
 */

 /*
 template<class value_type>
 class value_compare : public binary_function<value_type, value_type, bool>
 {
 public:
     bool operator()(const value_type& _Left, const value_type& _Right) const;
     value_compare(key_compare _Pred) : comp(_Pred);
 protected:
     key_compare comp;
 };
 */
 /*
  value_compare value_comp( ) const;
 value_compare value_comp( ) const;

 返回值
 --------------------------------------------------------------------------------

 返回映射使用对其元素进行比较函数对象。

 备注
 --------------------------------------------------------------------------------

 对于映射 m，如果两个元素 e1( k1, d1) 和 e2( k2, d2) 类型的对象， value_type, where k1 and k2 类型自己的键 key_type and d1 and d2 类型的数据， mapped_type, then m. value_comp( e1, e2) 等效于 m. key_comp (k1, k2)。 一个存储的对象成员函数定义

 bool operator value_type&  value_type& (_Left，_Right);

 后者返回 true，如果关键 _Left 值前面并与键值不相等在排序顺序的 _Right。

  */

void test_map_value_comp()
{
    // compile with: /EHsc

    map <int, int, less<int> > m1;
    map <int, int, less<int> >::value_compare vc1 = m1.value_comp();
    pair< map<int, int>::iterator, bool > pr1, pr2;

    pr1 = m1.insert(map <int, int> ::value_type(1, 10));
    pr2 = m1.insert(map <int, int> ::value_type(2, 5));

    if (vc1(*pr1.first, *pr2.first) == true)
    {
        cout << "The element ( 1,10 ) precedes the element ( 2,5 )." << endl;
    }
    else
    {
        cout << "The element ( 1,10 ) does not precede the element ( 2,5 )." << endl;
    }

    if (vc1(*pr2.first, *pr1.first) == true)
    {
        cout << "The element ( 2,5 ) precedes the element ( 1,10 )." << endl;
    }
    else
    {
        cout << "The element ( 2,5 ) does not precede the element ( 1,10 )." << endl;
    }
}

struct cstrcmp_less
{
    bool operator () (const char* a, const char* b)
    {
        return strcmp(a, b) == -1 ? 1 : 0;
    }
};

void test_multimap6()
{
    multimap<const char*, const char*, cstrcmp_less> xx;
    xx.insert(make_pair("12", "22"));
    xx.insert(make_pair("23", "22"));
    xx.insert(make_pair("14", "22"));
    xx.insert(make_pair("11", "22"));

    for (multimap<const char*, const char*>::iterator it = xx.begin(); it != xx.end(); ++it)
        cout << it->first << endl;
}
/*
    C++ STL中标准关联容器set, multiset, map, multimap内部采用的就是一种非常高效的平衡检索二叉树：红黑树，也成为RB树(Red-Black Tree)。
    map和set的树建立之时就会自动排好序，之前使用map，觉得按value排序很麻烦，要建一个multimap将原map倒置存储。
    如何只用一个map实现value的排序呢？将key 和 value建一个结构体，再将结构体作为key建一个map。
    而排序当然要写比较函数，这个又如何解决呢？之前没去想map构造map<T1, T2>时，
    其实是有个默认的比较函数 map<T1, T2, less<T1>> ,即按key的升序排列，
    我们可以重写比较函数来实现我们想要的排序(value)。假设string是key, int是value;
    */

struct Data
{
    string s;
    int n;
};
class KeyCompA
{
public:
    bool operator()(const Data& a1, const Data& a2) const
    {
        return (a1.n < a2.n || (a1.n == a2.n && a1.s < a2.s));
    }
};
void test_multimap7()
{
    map<Data, int, KeyCompA> m;
    Data d1 = { "123",1 };
    Data d2 = { "234",2 };
    Data d3 = { "789",7 };
    Data d4 = { "890",8 };
    Data d5 = { "345",3 };
    Data d6 = { "234",2 };
    Data d7 = { "678",6 };
    Data d8 = { "567",5 };
    m.insert(make_pair(d1, 1));
    m.insert(make_pair(d2, 2));
    m.insert(make_pair(d3, 7));
    m.insert(make_pair(d4, 8));
    m.insert(make_pair(d5, 3));
    m.insert(make_pair(d6, 2));
    m.insert(make_pair(d7, 6));
    m.insert(make_pair(d8, 5));
    //Data rec;
    //while (cin >> rec.s >> rec.n)
    //{
    //    m[rec]++;
    //}
    for (map<Data, int, KeyCompA>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first.s << " " << it->first.n << " " << it->second;
        cout << endl;
    }
}

struct B
{
    string s;
    int n;
};
class KeyCompB
{
public:
    bool operator()(const B& a1, const B& a2) const
    {
        return (a1.n < a2.n || (a1.n == a2.n && a1.s < a2.s));
    }
};
void test_multimap8()
{
    map<B, int, KeyCompB> m;

    B d1 = { "123",1 };
    B d2 = { "234",2 };
    B d3 = { "789",7 };
    B d4 = { "890",8 };
    B d5 = { "345",3 };
    B d6 = { "234",2 };
    B d7 = { "678",6 };
    B d8 = { "567",5 };

    m.insert(make_pair(d1, 1));
    m.insert(make_pair(d2, 2));
    m.insert(make_pair(d3, 7));
    m.insert(make_pair(d4, 8));
    m.insert(make_pair(d5, 3));
    m.insert(make_pair(d6, 2));
    m.insert(make_pair(d7, 6));
    m.insert(make_pair(d8, 5));
    /*  B rec;
      while (cin >> rec.s >> rec.n)
      {
          m[rec]++;
      }*/
    for (map<B, int, KeyCompB>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first.s << " " << it->first.n << " " << it->second;
        cout << endl;
    }
}

void test_multimap9()
{
    multimap <int, int, less<int> > m1;
    multimap <int, int, less<int> >::key_compare kc1 = m1.key_comp();
    bool result1 = kc1(2, 3);
    if (result1 == true)
    {
        cout << "kc1( 2,3 ) returns value of true, " << "where kc1 is the function object of m1." << endl;
    }
    else
    {
        cout << "kc1( 2,3 ) returns value of false " << "where kc1 is the function object of m1." << endl;
    }
    multimap <int, int, greater<int>> m2;
    multimap <int, int, greater<int>>::key_compare kc2 = m2.key_comp();
    bool result2 = kc2(2, 3);
    if (result2 == true)
    {
        cout << "kc2( 2,3 ) returns value of true, " << "where kc2 is the function object of m2." << endl;
    }
    else
    {
        cout << "kc2( 2,3 ) returns value of false, " << "where kc2 is the function object of m2." << endl;
    }
}

int main()
{
    test_multimap3();
    system("pause");
    return 0;
}