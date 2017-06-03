#include <iostream>
#include <string>
#include "Person.h"
#include"Circle.h"
#include"Point.h"
#include "Student.h"
using namespace std;

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
int main()
{
    int *p1 = new int;
    delete p1;
    int *p2 = new int;

    Demo2();
    system("pause");

    //int *pi = new int(5);
    //double *pd = new double();
    //char *pc = new char[10];
    //string *ps = new string(10);  //error
    return 0;
}