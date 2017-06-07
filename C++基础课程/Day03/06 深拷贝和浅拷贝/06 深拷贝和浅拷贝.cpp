#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace 原始拷贝赋值
{
    class Person
    {
    public:
        Person() {    }
        Person(int a, int b, const char *pname)
        {
            this->mA = a;
            this->mB = b;
            this->pName = new char[strlen(pname) + 1];
            strcpy(pName, pname);
        }
        Person(const Person &person)
        {
            this->pName = person.pName;

            this->mA = person.mA;
            this->mB = person.mB;
            cout << "拷贝构造函数!" << endl;
        }

        Person& operator=(const Person &person)
        {
            this->pName = person.pName;

            this->mA = person.mA;
            this->mB = person.mB;
            cout << "赋值函数!" << endl;
            return *this;
        }
        ~Person()
        {
            if (this->pName != NULL)
            {
                delete this->pName;
                this->pName = NULL;
            }
        }
    public:
        char *pName;
        int mA;
        int mB;
    };

    void test01()
    {
        Person p1(100, 200, "Name");

        Person p2 = p1;

        Person p3;
        p3 = p1;
        /*
        0x00ef8ab0存储如下
        0x009DFD94  b0
        0x009DFD95  8a
        0x009DFD96  ef
        0x009DFD97  00

        0x00ef8ab0 "Name"存储如下
        0x00EF8AB0  4e  N
        0x00EF8AB1  61  a
        0x00EF8AB2  6d  m
        0x00EF8AB3  65  e
        */
        cout << "A = " << p2.mA << " B:" << p2.mB << endl;
        cout << "&p1：" << &p1 << "   " << "p1.pName（对应堆空间）：" << &p1.pName << endl;
        cout << "&p2：" << &p2 << "   " << "p2.pName（对应堆空间）：" << &p2.pName << endl;
        cout << "&p3：" << &p3 << "   " << "p3.pName（对应堆空间）：" << &p3.pName << endl;

        cout << p1.pName << endl;
        cout << p2.pName << endl;
        cout << p3.pName << endl;
        int a = 123;
        int *p = &a;
        int &r = a;

        printf("&p1.pName=%p，%s\n", p1.pName, p1.pName);
        printf("&p2.pName=%p，%s\n", p2.pName, p2.pName);
        printf("&p3.pName=%p，%s\n", p3.pName, p3.pName);
    }
}

namespace 自定义拷贝赋值
{
    class Person
    {
    public:
        Person() {    }
        Person(int a, int b, const char *pname)
        {
            this->mA = a;
            this->mB = b;
            this->pName = new char[strlen(pname) + 1];
            strcpy(pName, pname);
        }
        Person(const Person &person)
        {
            //在进行拷贝前本身并没有有效的值（没有构造完毕），固不需进行释放
            this->pName = new char[strlen(person.pName) + 1];
            strcpy(this->pName, person.pName);

            this->mA = person.mA;
            this->mB = person.mB;
            cout << "拷贝构造函数!" << endl;
        }

        Person& operator=(const Person &person)
        {
            //在赋值之前，自身的的内控空间和值都要处理
            if (this->pName != NULL)
            {
                delete this->pName;//清除值
                this->pName = NULL; //清地址
            }

            this->pName = new char[strlen(person.pName) + 1];
            strcpy(this->pName, person.pName);

            this->mA = person.mA;
            this->mB = person.mB;

            return *this;
        }
        ~Person()
        {
            if (this->pName != NULL)
            {
                delete this->pName;
                this->pName = NULL;
            }
        }
    public:
        char *pName;
        int mA;
        int mB;
    };

    void test01()
    {
        Person p1(100, 200, "Name1");

        Person p2 = p1;

        Person p3(300, 400, "Name2");
        cout << p3.pName << "  " << p3.mA << "   " << p3.mB << endl;

        p3 = p1;
        /*
            &p1.pName
            &p2.pName
            &p3.pName
        */
        printf("&p1=%p    &p1.pName=%p    %s\n", &p1, p1.pName, p1.pName);

        printf("&p2=%p    &p2.pName=%p    %s\n", &p2, p2.pName, p2.pName);

        printf("&p3=%p    &p3.pName=%p    %s\n", &p3, p3.pName, p3.pName);
    }
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
//★★★★★★★有指针的时候才有深拷贝和浅拷贝问题
//
//提供默认的拷贝构造器，一经定义不再提供,默认是等位拷贝，也就是通常意义上的浅拷贝(默认值拷贝)
//如果类的内部有指针指向堆内存，那么必须手动提供拷贝构造函数
//如果类的内部有指针指向堆内存，那么此时如果只是调用默认的拷贝构造函数，进行简单的指针值拷贝，叫做浅拷贝
//如果编写自定义拷贝过程，对内存进行拷贝，叫做深拷贝

int main()
{
    自定义拷贝赋值::test01();
    system("pause");
    return EXIT_SUCCESS;
}