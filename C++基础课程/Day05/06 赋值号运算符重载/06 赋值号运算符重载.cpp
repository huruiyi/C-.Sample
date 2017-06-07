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
    //C++编译器默认给类增加了赋值运算符函数，默认的赋值运算符函数进行简单值拷贝

    Person p1(10, 100);
    Person p2(20, 200);

    cout << "A:" << p1.mA << " B:" << p1.mB << endl;
    cout << "A:" << p2.mA << " B:" << p2.mB << endl;
    p1 = p2; //p1.operator=(p2);

    cout << "--------------" << endl;
    cout << "A:" << p1.mA << " B:" << p1.mB << endl;
    cout << "A:" << p2.mA << " B:" << p2.mB << endl;
}

class Student
{
public:
    Student(const char *name, int age)
    {
        pName = new char[strlen(name) + 1];
        strcpy(pName, name);
        mAge = age;
    }

    //重新编写赋值函数规则
#if 1
    Student& operator=(const Student &person)
    {
        //先把自身的内存释放调用
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }

        //给pName重新开辟新空间
        this->pName = new char[strlen(person.pName) + 1];
        strcpy(this->pName, person.pName);

        this->mAge = person.mAge;

        return *this;
    }
#endif

    Student(const Student &person)
    {
        this->pName = new char[strlen(person.pName) + 1];
        strcpy(this->pName, person.pName);
        this->mAge = person.mAge;
    }

    ~Student()
    {
        if (pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }
    }

public:
    int mAge;
    char *pName;
};

void test02()
{
    Student s1("Edward", 22);
    Student s2("Trump", 33);

    cout << "Name:" << s1.pName << " Age:" << s1.mAge << endl;
    cout << "Name:" << s2.pName << " Age:" << s2.mAge << endl;

    //赋值操作
    s1 = s2;

    cout << "---------------" << endl;
    cout << "&s1：" << &s1 << "   &s2：" << &s2 << endl;
    cout << "Name:" << s1.pName << " Age:" << s1.mAge << endl;
    cout << "Name:" << s2.pName << " Age:" << s2.mAge << endl;

    getchar();
}

//以后写类，只要类的内部有指针指向堆内存，析构函数 拷贝构造函数 赋值运算符函数 都写上

int main() {
    //test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}