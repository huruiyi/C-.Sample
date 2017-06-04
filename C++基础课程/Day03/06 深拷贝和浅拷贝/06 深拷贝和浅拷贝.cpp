#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
    Person(int a, int b)
    {
        mA = a;
        mB = b;
    }
public:
    int mA;
    int mB;
};

void test01()
{
    Person p1(100, 200);
    Person p2(p1);
    Person p3 = p1;

    cout << "A = " << p2.mA << " B:" << p2.mB << endl;
}

class Student
{
public:
    Student(const char *str, int age)
    {
        pName = (char *)malloc(sizeof(char)* strlen(str) + 1);
        strcpy(pName, str);
        mAge = age;
    }

    Student(const Student &stu)
    {
        this->pName = new char[strlen(stu.pName) + 1];

        strcpy(pName, stu.pName);
        mAge = stu.mAge;
    }

    Student &operator=(const Student &stu)
    {
        if (this->pName)
        {
            delete this->pName;
            this->pName = NULL;
        }
        this->pName = new char[strlen(stu.pName) + 1];
        strcpy(this->pName, stu.pName);

        this->mAge = stu.mAge;
        return *this;
    }
    ~Student()
    {
        if (pName != NULL)
        {
            delete this->pName;
            pName = NULL;
        }
    }

public:
    char *pName;
    int mAge;
};

void test02()
{
    //深拷贝
    Student s1("trump", 88);

    Student s2(s1);
}

void test03()
{
    Student s1("张三", 77);
    Student s2("李四", 88);
    cout << s1.pName << "   " << s1.mAge << endl;
    cout << s2.pName << "   " << s2.mAge << endl;

    //赋值
    s1 = s2;

    cout << s1.pName << "   " << s1.mAge << endl;
    cout << s2.pName << "   " << s2.mAge << endl;
}

//如果类的内部有指针指向堆内存，那么必须手动提供拷贝构造函数
//如果类的内部有指针指向堆内存，那么此时如果只是调用默认的拷贝构造函数，进行简单的指针值拷贝，叫做浅拷贝
//如果编写自定义拷贝过程，对内存进行拷贝，叫做深拷贝

int main()
{
    test02();
    test03();

    system("pause");
    return EXIT_SUCCESS;
}