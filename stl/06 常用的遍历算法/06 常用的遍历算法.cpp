#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <functional>

void myPrint(int v)
{
    cout << v << " ";
}

class myPrint01
{
public:
    void operator()(int v)
    {
        cout << v << " ";
        count++;
    }
    int count = 0;
};

//for_each
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //for_each(v.begin(), v.end(), myPrint);
    for_each(v.begin(), v.end(), myPrint01());
}

//�з���ֵ
void test02()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    myPrint01 myP = for_each(v.begin(), v.end(), myPrint01());
    cout << endl;
    //cout << "ʹ�ô���" << myP.count << endl;;
}

class myPrint03 :public binary_function<int, int, void>
{
public:
    void operator()(int v, int start) const
    {
        cout << v + start << " ";
    }
};
//�󶨲������
void test03()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), bind2nd(myPrint03(), 1000));
}

/*
transform�㷨 ��ָ����������Ԫ�ذ��˵���һ������
ע�� : transform �����Ŀ�����������ڴ棬������Ҫ������ǰ������ڴ�
@param beg1 Դ������ʼ������
@param end1 Դ��������������
@param beg2 Ŀ��������ʼ������
@param _cakkback �ص��������ߺ�������
@return ����Ŀ������������
*/

class myTransform
{
public:
    int operator()(int v)
    {
        return v + 1000;
    }
};

void test04()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //Ŀ������
    vector<int>vTarget;
    vTarget.resize(v.size());

    transform(v.begin(), v.end(), vTarget.begin(), myTransform());

    for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}

int main() {
    //	test01();

    //	test02();

    //	test03();

    test04();
    system("pause");
    return EXIT_SUCCESS;
}