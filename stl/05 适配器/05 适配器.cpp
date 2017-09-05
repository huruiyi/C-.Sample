#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

//函数对象适配器
class MyPrint : public binary_function<int, int, void>
{
public:
    void operator()(int val, int start) const
    {
        cout << "val = " << val << " start = " << start << " sum =" << val + start << endl;
    }
};

void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << "请输入起始值：" << endl;
    int start;
    cin >> start;

    for_each(v.begin(), v.end(), bind2nd(MyPrint(), start));

    //for_each(v.begin(), v.end(), bind1st(MyPrint(), start));
}

//1 利用bind2nd 进行数据绑定
//2 需要继承  二元 binary_function<参数类型，参数类型，返回值类型>  一元 unary_function<参数类型，返回值类型>
//3 加const

class GreaterThenFive :public unary_function<int, bool>
{
public:
    bool operator()(int v)const
    {
        return v > 5;
    }
};
//取反适配器
void test02()
{
    //一元取反
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //找小于5的数字，仿函数不改

    vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(GreaterThenFive()));
    if (pos != v.end())
    {
        cout << "找到了" << *pos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    //二元取反
    sort(v.begin(), v.end(), not2(less<int>())); //从大到小
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
}

//函数指针适配器
void myPrint3(int v, int start)
{
    cout << v + start << endl;
}
void test03()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //将函数指针 适配成函数对象
    //利用 ptr_fun
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint3), 100));
}

//成员函数适配器
class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }
    //成员函数
    void printPerson()
    {
        cout << "成员函数打印：： 姓名： " << mName << " 年龄：" << mAge << endl;
    }

    void plusAge()
    {
        this->mAge++;
    }

    string mName;
    int mAge;
};

//void myPrint4(Person & p)
//{
//	cout << "姓名： " << p.mName << " 年龄：" << p.mAge << endl;
//}
void test_mem_fun_ref()
{
    vector<Person>v;
    Person p1("张三", 10);
    Person p2("李四", 20);
    Person p3("老王", 30);
    Person p4("法师", 18);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //成员函数适配 mem_fun_ref
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::printPerson));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::printPerson));
}

class StoreVals
{
    int val;
public:
    StoreVals() { val = 0; }
    StoreVals(int j) { val = j; }

    bool display() { cout << val << " "; return true; }
    int squareval() { val *= val; return val; }
    int lessconst(int k) { val -= k; return val; }
};

struct Compare : public binary_function<int, int, bool>
{
    bool operator() (int a, int b)
    {
        return (a == b);
    }
};

void test_binary_function()
{
    Compare Compare_object;
    Compare::first_argument_type input1;
    Compare::second_argument_type input2;
    Compare::result_type result;

    cout << "Please enter first number: ";
    cin >> input1;
    cout << "Please enter second number: ";
    cin >> input2;

    result = Compare_object(input1, input2);

    cout << "Numbers " << input1 << " and " << input2;

    cout << (result ? "相等" : "不相等") << endl;
}

void test_mem_fun1()
{
    vector <string*> numbers;

    numbers.push_back(new string("one"));
    numbers.push_back(new string("two"));
    numbers.push_back(new string("three"));
    numbers.push_back(new string("four"));
    numbers.push_back(new string("five"));

    vector <int> lengths(numbers.size());

    transform(numbers.begin(), numbers.end(), lengths.begin(), mem_fun(&string::length));

    for (int i = 0; i < 5; i++)
    {
        cout << *numbers[i] << " has " << lengths[i] << " letters.\n";
    }

    // deallocate strings:
    for (vector<string*>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        delete *it;
    }
}

void test_mem_fun2()
{
    vector<StoreVals *> v1;

    StoreVals sv1(5);
    StoreVals sv2(10);
    StoreVals sv3(15);
    StoreVals sv4(20);
    StoreVals sv5(25);
    StoreVals *sv6 = new StoreVals(30);
    v1.push_back(&sv1);
    v1.push_back(&sv2);
    v1.push_back(&sv3);
    v1.push_back(&sv4);
    v1.push_back(&sv5);
    v1.push_back(sv6);

    cout << "The original values stored are: ";
    for_each(v1.begin(), v1.end(), mem_fun<bool, StoreVals>(&StoreVals::display));
    cout << endl;

    for_each(v1.begin(), v1.end(), mem_fun<int, StoreVals>(&StoreVals::squareval));
    cout << "The squared values are: ";
    for_each(v1.begin(), v1.end(), mem_fun<bool, StoreVals>(&StoreVals::display));
    cout << endl;

    for_each(v1.begin(), v1.end(), bind2nd(mem_fun1_t<int, StoreVals, int>(&StoreVals::lessconst), 5));
    cout << "The squared values less 5 are: ";
    for_each(v1.begin(), v1.end(), mem_fun<bool, StoreVals>(&StoreVals::display));
    cout << endl;
}

void test_foreach_vector_int(vector<int> &v)
{
    for_each(v.begin(), v.end(), [](int val) {cout << val << "\t"; });
    cout << endl;
}

bool GradeThan5(int a)
{
    return a > 5;
}
void test_not1()
{
    vector<int> v = { 1,9,2,3,6,7,8, 4,5 };

    vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(GreaterThenFive()));
    int count = count_if(v.begin(), v.end(), not1(GreaterThenFive()));
    for (int num = 0; pos != v.end(), num < count; pos++, num++)
    {
        cout << *pos << endl;
    }

    //for_each(v.begin(), v.end(), not1([](int a) {return a > 5; }));
}
int main()
{
    test_not1();
    system("pause");
    return EXIT_SUCCESS;
}