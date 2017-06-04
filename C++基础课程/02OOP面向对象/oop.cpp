#include <iostream>
#include <string>
#include "Person.h"
#include"Circle.h"
#include"Point.h"
#include "Student.h"
using namespace std;

#define Connect(X, Y) X##Y
#define Connect2(X, Y) Connect(X, Y)
#define ToString(X) #X
#define ToString2(X) ToString(X)

namespace NDemo
{
    void Demo0()
    {
        Person p;
        p.SetName("赵四");
        p.SetAge(20);

        cout << p.GetName() << "  " << p.GetAge() << endl;
        p.ShowPersonInfo();

        Person *per = new Person();
        per->SetName("张三");
        delete per;
    }
    void Demo1()
    {
        Circle circle;
        circle.setHeart(10, 10);
        circle.setR(20);

        Point point;
        point.setX(10);
        point.setY(30);

        circle.judgeCirleAndPointRelation(point);

        Circle *c = new Circle();
        delete c;
    }
    void Demo2()
    {
        Student stu("拉布拉多", 3);
        stu.ShowInfo();
    }
    void Demo3()
    {
        int *p1 = new int;
        delete p1;
        int *p2 = new int[10];
        p2[0] = 123;
        p2[1] = 456;

        //int *pi = new int(5);
        //double *pd = new double();
        //char *pc = new char[10];
        //string *ps = new string(10);  //error
    }
    void Demo4()
    {
        cout << Connect(123, 456) << endl;
        cout << Connect2(123, 456) << endl;
        cout << ToString(123) << endl;
        cout << ToString2(123) << endl;
    }
}

namespace 静态成员
{
    class Person
    {
    public:
        const static string Country;//不可以修改
        string Name;
        Person()
        {
            this->pTotal++;
        }

        Person(string name)
        {
            this->pTotal++;
            this->Name = name;
            cout << "------------------构造（" << this->Name << "---" << this << "）------------------" << endl;
        }

        int  GetTotal()
        {
            return this->pTotal;
        }

        void ShowTotal()
        {
            cout << "总人数：" << this->pTotal << endl;
        }
        static void Show()
        {
            //this->Country;
        }

        ~Person()
        {
            this->pTotal--;
            cout << "------------------析构（" << this->Name << "---" << this << "）------------------" << endl << endl;
        }
    private:
        static int pTotal;
    };
    const string Person::Country = "中国";
    int   Person::pTotal = 0;

    void test()
    {
        Person p("A");
        cout << p.GetTotal() << endl;
        p.ShowTotal();

        p = Person("B");
        cout << p.GetTotal() << endl;
        p.ShowTotal();

        p = Person("C");
        cout << p.GetTotal() << endl;
        p.ShowTotal();

        p = Person("D");
        cout << p.GetTotal() << endl;
        p.ShowTotal();
    }
}

namespace 对象模型
{
    class Person
    {
    public:
        //非静态成员函数有this指针，静态成员没有
        void showPerson()
        {
            cout << this->mAge << endl;
        }

        //static  void showPerson()
        //{
        //    cout << this->mAge << endl;
        //}
    public:
        int mAge;
    };
    void test()
    {
        Person p1, p2;
        p1.showPerson();
        p2.showPerson();
        cout << sizeof Person << endl;
    }
}

namespace this指针加强
{
    class Person
    {
    public:
        Person()
        {
            cout << "Init" << endl;
        }
        ~Person()
        {
            cout << "Over" << endl;
        }
        void printPerson1()
        {
        }
        void printPerson2() const
        {
        }
        void showPerson() const
        {
            //this->mA = 123;   const 修饰的函数，不能在本函数中修改成员变量的值（除了mutable修饰的成员变量）
            //const Person * const this 相当于this
            if (this)
            {
                this->mB = 123;
                cout << "Hello World" << endl;
            }
            else
            {
                cout << "Hello World NULL" << endl;
                return;
            }
        }
    public:
        int mA;
        mutable int mB;
        static int mC;
    };

    void test()
    {
        Person *person = NULL;
        person->showPerson(); //正常
                              //person->mA = 123;      //异常

        const Person *person1 = new Person;
        //person1->printperson1();//常对象只能调用个常函数
        person1->printPerson2();
        //55 person1->mA = 123; //常对象不能修改类的普通成员变量，除了mutabel修饰的
        person1->mB = 123; //常对象只能访问mutable修饰的成员变量
        //person1->mC = 456;
        delete person1;
    }
}

namespace friend友元全局函数
{
    class Building
    {
        //友元只是声明，不是类的成员
        friend class GoodFriend;
        friend void GoodGay(Building &building);
    public:
        Building()
        {
            mSittingRoom = "客厅";
            mBedRoom = "卧室";
        }
    public:
        string mSittingRoom;
    private:
        string mBedRoom;
    };
    class GoodFriend
    {
    public:
        void Visit(Building &xbuilding)
        {
            xbuilding.mBedRoom;
            xbuilding.mSittingRoom;
        }

        void Vist()
        {
            building.mSittingRoom = "";
            pBuilding->mSittingRoom = "";
        }
        void Clean()
        {
            building.mBedRoom = "";
            pBuilding->mBedRoom = "";
        }
    private:
        Building building;
        Building *pBuilding;
    };
    void GoodGay(Building &building)
    {
        building.mBedRoom = "";
        building.mSittingRoom = "";
    }
    void test()
    {
        Building building;
        GoodGay(building);
        //building.mBedRoom = "";//此处访问受限
        building.mSittingRoom = "客厅";
    };
}

namespace 友元成员函数
{
    class Person;
    class GirlFriend
    {
    public:
        void Talk(Person &person);
        void Beat(Person &person);
    };

    class Person
    {
        friend void GirlFriend::Beat(Person &person);

    private:
        string mName;
    };

    void GirlFriend::Talk(Person &person)
    {
    }
    void GirlFriend::Beat(Person &person)
    {
        person.mName;
    }
}

namespace 运算符重载加号
{
    class Person
    {
    public:
        int mA;
        int mB;
        Person(int a, int b)
        {
            this->mA = a;
            this->mB = b;
        }
        Person operator+(const Person &person)
        {
            Person p(this->mA + person.mA, this->mB + person.mB);
            return p;
        }
        Person operator+(int val)
        {
            Person p(this->mA + val, this->mB + val);
            return p;
        }
    };
    Person  operator+(int val, const Person &person)
    {
        Person p(person.mA + val, person.mB + val);
        return p;
    }

    void test()
    {
        Person p1(100, 200);
        Person p2(200, 100);
        p1 + p2;
        p1 + 12;
        12 + p1;
    }
}

namespace 运算符重载减号
{
    class Student
    {
    public:
        Student() {}
        Student(int a, int b)
        {
            this->mA = a;
            this->mB = b;
        }
        Student operator[](std::initializer_list<Student> list) {}
        int mA;
        int mB;
    };

    class Person
    {
        friend class Student;
    public:
        Person(int a, int b) :mA(a), mB(b)
        {
        }

        Person operator -(const Student &stu)
        {
            Person p(this->mA - stu.mA, this->mB - stu.mB);
            return p;
        }
    private:
        int mA;
        int mB;
    };

    void test0(Student stu)
    {
    }
    void test1(Student & stu)
    {
    }

    void test2(Student * stu)
    {
    }
    void test()
    {
        Student s1(123, 456);
        Student s2(147, 258);
        Student stus[] = { s1,s2 };
        Student sx1 = stus[0];

        Student &s3 = s1;
        test0(s1);
        test1(s3);
        test2(&s1);
    }
}

namespace 运算符重载MyInteger
{
    class  MyInteger
    {
    public:
        MyInteger()
        {
            mNum = 0;
        }
        MyInteger& operator++()
        {
            ++mNum;
            return *this;
        }

        MyInteger operator++(int)
        {
            MyInteger temp(*this);
            ++mNum;
            return temp;
        }
    private:
        int mNum;
    };
    void test()
    {
        MyInteger my;
        MyInteger mi = ++my;
        int a = 10;
        cout << a++ << endl;
        cout << a << endl;
    }
}

namespace 运算符重载左移
{
    class Person
    {
        friend   ostream& operator<<(ostream &out, Person &person);
    public:
        Person(int a, int b)
        {
            this->mA = a;
            this->mB = b;
        }

        int mA;
        int mB;
    };

    ostream& operator<<(ostream &out, Person &person)
    {
        out << person.mA << " " << person.mB;
        return out;
    }
    void test()
    {
        Person p(123, 456);
        cout << p << endl;
    }
}

namespace 运算符重载赋值
{
    class Person
    {
    public:
        int mA;
        int mB;
        Person(int a, int b)
        {
            this->mA = a;
            this->mB = b;
        }
    };
    class Student
    {
    public:
        char *pName;
        int mAge;
        Student(const char *name, int age)
        {
            this->pName = new char[strlen(name) + 1];
            strcpy(this->pName, name);
            this->mAge = age;
        }
        Student(const Student &stu)
        {
            cout << "拷贝" << endl;
            this->pName = new char[strlen(stu.pName) + 1];
            strcpy(this->pName, stu.pName);
            this->mAge = stu.mAge;
        }

        Student &operator=(const Student &stu)
        {
            cout << "赋值重载" << endl;
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
            if (this->pName)
            {
                delete this->pName;
                this->pName = NULL;
            }
        }
    };
    void test1()
    {
        //调用默认的赋值运算符（适用于没有指向堆空间的成员变量）
        Person p1(123, 456);
        Person p2(147, 258);
        cout << p1.mA << "  " << p1.mB << endl;
        cout << p2.mA << "  " << p2.mB << endl;
        p2 = p1;
        cout << p1.mA << "  " << p1.mB << endl;
        cout << p2.mA << "  " << p2.mB << endl;
    }
    void test2()
    {
        //调用自定义的赋值运算符（适用于有指向堆空间的成员变量）
        Student s1("u1", 30);
        Student s2("u2", 50);
        cout << s1.pName << "  " << s1.mAge << endl;
        cout << s2.pName << "  " << s2.mAge << endl;
        s1 = s2;
        cout << s1.pName << "  " << s1.mAge << endl;
        cout << s2.pName << "  " << s2.mAge << endl;
    }
}

namespace 自定义类型转化
{
    class Student
    {
    public:
        Student(int a, int b)
        {
            this->mA = a;
            this->mB = b;
        }

    public:
        int mA;
        int mB;
    };
    class Person
    {
    public:
        Person(int age)
        {
            this->m_Age = age;
        }
        operator int()
        {
            return this->m_Age;
        }

        operator bool()
        {
            return this->m_Age > 0;
        }

        operator Student()
        {
            return Student(m_Age, m_Age);
        }
    public:
        int m_Age;
    };
    void test()
    {
        Person p(100);
        int age = p;
        cout << age << endl;

        bool b = p;
        cout << b << endl;

        Student s = p;
    }
}
int main()
{
    自定义类型转化::test();

    system("pause");
    return 0;
}