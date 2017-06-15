#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include <iterator>

using namespace std;

class Person
{
public:
    string mName;
    int mAge;
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
};
class MyPrint
{
public:
    void operator()(int num)
    {
        cout << num << endl;
        count++;
    }
    int count = 0; //统计MyPring调用次数
};

void test_foreach_vector_int(vector<int> &v)
{
    for_each(v.begin(), v.end(), [](int val) {cout << val << "\t"; });
    cout << endl;
}
void MyPrint2(int num)
{
	cout << num << endl;
}

void test01()
{
    //函数对象 仿函数 是一个类，而不是函数
    MyPrint myPrint;
    myPrint(100);
}

//仿函数 超出普通函数概念，内部可以维护一些状态
void test02()
{
    MyPrint myPrint;
    myPrint(100);
    myPrint(100);
    myPrint(100);
    myPrint(100);

    cout << "count = " << myPrint.count << endl;
}

//仿函数可以作为参数

void doWork(MyPrint print, int num)
{
    print(num);
}

void test03()
{
    doWork(MyPrint(), 1000); //MyPrint()
}
//二院谓词
class VectorCompareInt
{
public:
    bool operator()(const int a, const int b) const
    {
        return a > b;
    }
};
void test04()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    sort(v.begin(), v.end(), VectorCompareInt());
    sort(v.begin(), v.end(), [](const int a, const int b) { return a < b; });//lamba 表达式，，，从小到大
    for_each(v.begin(), v.end(), [](int val) {cout << val << "\t"; });
}

//自定义类型排序
struct MyStruct
{
    MyStruct(int i) : mInt(i) {}

    bool operator < (const MyStruct & rhs) const
    {
        return mInt < rhs.mInt;
    }
    bool operator > (const MyStruct & rhs) const
    {
        return mInt > rhs.mInt;
    }
    int mInt;
};

void foreach_MyStruct(vector<MyStruct> &strct)
{
    for_each(strct.begin(), strct.end(), [](MyStruct  stru) {cout << stru.mInt << "\t"; });
    cout << endl;
}

void test_sort1()
{
    using namespace std;
    vector <MyStruct> v1;

    for (int i = 0; i < 7; i++)
    {
        v1.push_back(MyStruct(rand()));
    }

    foreach_MyStruct(v1);

    //sort(v1.begin(), v1.end(), less<MyStruct>());
    sort(v1.begin(), v1.end(), greater<MyStruct>());

    foreach_MyStruct(v1);
}

void test_sort2()
{
    int data[] = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    std::vector<int> v(data, data + 10);

    int target1 = 3;
    int target2 = 5;
    int num_items1 = std::count(v.begin(), v.end(), target1);
    int num_items2 = std::count(v.begin(), v.end(), target2);

    std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
    std::cout << "number: " << target2 << " count: " << num_items2 << '\n';
}
//防函数
//一元谓词
class GradeThan20
{
public:

    bool operator()(int val)
    {
        return val > 20;
    }
};

bool fun_GradeThan20(int val)
{
    return val > 20;
}

void test_find()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(80);
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(30);
    v.push_back(70);

    //简单类型只需要提供查找的函数
    vector<int>::iterator pos1 = find_if(v.begin(), v.end(), [](int a) {return a > 20; });
    vector<int>::iterator pos2 = find_if(v.begin(), v.end(), GradeThan20());
    vector<int>::iterator pos3 = find_if(v.begin(), v.end(), fun_GradeThan20);
    vector<int>::iterator pos4 = find(v.begin(), v.end(), 20);
    if (pos3 != v.end())
    {
        cout << "找到值：" << (*pos3) << endl;
    }
    else
    {
        cout << "未找到值" << endl;
    }

    cout << "所有值：";
    test_foreach_vector_int(v);
    cout << "便利大于20的所有值" << endl;
    vector<int>::iterator pos = find_if(v.begin(), v.end(), fun_GradeThan20);
    while (pos != v.end())
    {
        cout << "找到值：" << (*pos) << "\t";
        pos = pos + 1;
        pos = find_if(pos, v.end(), fun_GradeThan20);
    }
    cout << endl;
}

void test_find_if()
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

    //自定义类型需要重载才能查找
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

void test_find_if_p()
{
    vector<Person*> v =
    {
        new Person("A",20),
        new Person("B",21),
        new Person("C",22),
        new Person("D",23),
        new Person("E",24)
    };

    Person * p = new Person("D", 23);
    vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare03(), p));
    if (pos != v.end())
    {
        cout << "找到值：" << (*pos)->mName << endl;
    }
    else
    {
        cout << "未找到值" << endl;
    }
}

//内建函数对象  头文件：functional
void test05()
{
    negate<int> n;
    cout << n(10) << endl;
}

void test06()
{
    plus<int> p;
    cout << p(123, 456) << endl;
}

void test07()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    //sort(v.begin(), v.end()); //默认的从小到大  _STD sort(_First, _Last, less<>());
    //sort(v.begin(), v.end(), greater<int>()); //从大到小
    sort(v.begin(), v.end(), less<int>());//默认的从小到大
    for_each(v.begin(), v.end(), [](int v) {cout << v << "\t"; });
}


class PrintVectorInt :public binary_function<int, int, void>
{
public:
    void operator()(int val, int start) const
    {
        cout << "val:" << val << "  start:" << start << " sum" << val + start << endl;
    }
};
//函数对象适配器
void test09()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //建议使用：bind2nd
    for_each(v.begin(), v.end(), bind2nd(PrintVectorInt(), 100));

    for_each(v.begin(), v.end(), bind1st(PrintVectorInt(), 100));
}

void MyPrint10(int value, int ano)
{
    cout << value << "\t";
}

void test10()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint10), 100));
}

void test11()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> vDesc;
    vDesc.resize(v.size());
    transform(v.begin(), v.end(), vDesc.begin(), [](int n) {return n; });
    for_each(v.begin(), v.end(), [](int n) {cout << n << endl; });
    for_each(vDesc.begin(), vDesc.end(), [](int n) {cout << n << endl; });
}

void test_bianary_serarch()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //查找的必须是有序序列
    bool b = binary_search(v.begin(), v.end(), 9);
    cout << (b ? "找到" : "未找到") << endl;
}

void test_cout()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int num = count(v.begin(), v.end(), 9);
}

class Cout_if
{
public:
    bool operator()(int a)
    {
        return a > 5;
    }
};

bool cout_if_gt5(int a)
{
    return a > 5;
}
void test_cout_if()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int num1 = count_if(v.begin(), v.end(), [](int val) {return val > 5; });
    int num2 = count_if(v.begin(), v.end(), Cout_if());
    int num3 = count_if(v.begin(), v.end(), cout_if_gt5);


    int data[] = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    std::vector<int> v2(data, data + 10);

    int num4 = std::count_if(v2.begin(), v2.end(), [](int i) {return i % 3 == 0; });

    std::cout << "number divisible by three: " << num4 << '\n';
}

void test_random_shuffle()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
}
void test_merge()
{
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2 = { 6,7,8,9 };

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    //必须是有序序列
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
}
void test_reverse()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
}

void test_accumulate()
{
    //numeric
    vector<int> v;
    for (int i = 1; i <= 100; i++)
    {
        v.push_back(i);
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    //int sum = accumulate(v.begin(), v.end(), 1000);//6050
    cout << "总和:" << sum << endl;
}

void test_fill()
{
    vector<int> v;
    v.resize(100);
    for (int i = 1; i <= 100; i++)
    {
        //v.push_back(i);
    }

    fill(v.begin(), v.end(), 123);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "  "));
}

void test_intersection()
{
    vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 5,6,7,8,9,10,11,12,13 };

    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, "  "));
}

void test_union()
{
    vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 5,6,7,8,9,10,11,12,13 };

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, "  "));
}

void test_difference()
{
    vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 5,6,7,8,9,10,11,12,13 };

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    //set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); //1,2,3,4
    set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());//11,12,13
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, "  "));
}



template<class InputIt, class T>
InputIt find1(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first)
    {
        if (*first == value) {
            return first;
        }
    }
    return last;
}

template<class InputIt, class UnaryPredicate>
InputIt find_if1(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first) {
        if (p(*first)) {
            return first;
        }
    }
    return last;
}

template<class InputIt, class UnaryPredicate>
InputIt find_if_not1(InputIt first, InputIt last, UnaryPredicate q)
{
    for (; first != last; ++first) {
        if (!q(*first)) {
            return first;
        }
    }
    return last;
}

template<class InputIt, class UnaryPredicate>
InputIt find_if_not2(InputIt first, InputIt last, UnaryPredicate q)
{
    return find_if1(first, last, not1(q));
}

template<class InputIt, class ForwardIt>
InputIt find_first_of1(InputIt first, InputIt last,
    ForwardIt s_first, ForwardIt s_last)
{
    for (; first != last; ++first) {
        for (ForwardIt it = s_first; it != s_last; ++it) {
            if (*first == *it) {
                return first;
            }
        }
    }
    return last;
}

template<class InputIt, class ForwardIt, class BinaryPredicate>
InputIt find_first_of2(InputIt first, InputIt last,
    ForwardIt s_first, ForwardIt s_last,
    BinaryPredicate p)
{
    for (; first != last; ++first) {
        for (ForwardIt it = s_first; it != s_last; ++it) {
            if (p(*first, *it)) {
                return first;
            }
        }
    }
    return last;
}

void test_find_first2()
{
    std::vector<int> v{ 0, 2, 3, 25, 5 };
    std::vector<int> t{ 3, 19, 10, 2 };

    auto result = std::find_first_of(v.begin(), v.end(), t.begin(), t.end());

    if (result == v.end()) {
        std::cout << "no elements of v were equal to 3, 19, 10 or 2\n";
    }
    else {
        std::cout << "found a match at "
            << std::distance(v.begin(), result) << "\n";
    }
}
void test_find2()
{
    int n1 = 3;
    int n2 = 5;

    vector<int> v{ 0, 1, 2, 3, 4 };

    auto result1 = find1(v.begin(), v.end(), n1);
    auto result2 = find1(v.begin(), v.end(), n2);

    if (result1 != v.end()) {
        cout << "v contains: " << n1 << '\n';
    }
    else {
        cout << "v does not contain: " << n1 << '\n';
    }

    if (result2 != v.end()) {
        cout << "v contains: " << n2 << '\n';
    }
    else {
        cout << "v does not contain: " << n2 << '\n';
    }
}



int main()
{
    test_find2();

    system("pause");
}

//not1 对一元函数对象取反
//not2 对二元函数对象取反
//ptr_fun( )把一个普通的函数指针适配成函数对象