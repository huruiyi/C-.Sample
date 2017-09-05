#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

//��������������
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
    cout << "��������ʼֵ��" << endl;
    int start;
    cin >> start;

    for_each(v.begin(), v.end(), bind2nd(MyPrint(), start));

    //for_each(v.begin(), v.end(), bind1st(MyPrint(), start));
}

//1 ����bind2nd �������ݰ�
//2 ��Ҫ�̳�  ��Ԫ binary_function<�������ͣ��������ͣ�����ֵ����>  һԪ unary_function<�������ͣ�����ֵ����>
//3 ��const

class GreaterThenFive :public unary_function<int, bool>
{
public:
    bool operator()(int v)const
    {
        return v > 5;
    }
};
//ȡ��������
void test02()
{
    //һԪȡ��
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //��С��5�����֣��º�������

    vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(GreaterThenFive()));
    if (pos != v.end())
    {
        cout << "�ҵ���" << *pos << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }

    //��Ԫȡ��
    sort(v.begin(), v.end(), not2(less<int>())); //�Ӵ�С
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
}

//����ָ��������
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

    //������ָ�� ����ɺ�������
    //���� ptr_fun
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint3), 100));
}

//��Ա����������
class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }
    //��Ա����
    void printPerson()
    {
        cout << "��Ա������ӡ���� ������ " << mName << " ���䣺" << mAge << endl;
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
//	cout << "������ " << p.mName << " ���䣺" << p.mAge << endl;
//}
void test_mem_fun_ref()
{
    vector<Person>v;
    Person p1("����", 10);
    Person p2("����", 20);
    Person p3("����", 30);
    Person p4("��ʦ", 18);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //��Ա�������� mem_fun_ref
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

    cout << (result ? "���" : "�����") << endl;
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