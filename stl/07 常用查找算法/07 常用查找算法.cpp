#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
/*
find�㷨 ����Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return ���ز���Ԫ�ص�λ��
*/
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //����5
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos != v.end())
    {
        cout << "�ҵ���5" << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}

//�����Զ�����������
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
        cout << "�ҵ���p3 ����Ϊ��" << (*pos).mName << " ���� " << pos->mAge << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
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
        cout << "�ҵ��� ������" << (*pos)->mName << " ���䣺  " << (*pos)->mAge << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}

/*
adjacent_find�㷨 ���������ظ�Ԫ��
@param beg ������ʼ������
@param end ��������������
@param  _callback �ص���������ν��(����bool���͵ĺ�������)
@return ��������Ԫ�صĵ�һ��λ�õĵ�����
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
        cout << "�鵽�������ظ�Ԫ�� " << *pos << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}

/*
binary_search�㷨 ���ֲ��ҷ�
ע��: �����������в�����
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return bool ���ҷ���true ����false
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
        cout << "�ҵ���" << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}

/*
count�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  value�ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���
*/
/*
count_if�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  callback �ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���
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

    //���Ҵ���4�ĸ���
    int num2 = count_if(v.begin(), v.end(), GreaterThenFour());
    cout << "����4�ĸ���Ϊ�� " << num2 << endl;
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