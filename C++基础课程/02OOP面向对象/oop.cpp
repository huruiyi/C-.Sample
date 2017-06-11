#include <iostream>
#include <string>
#include "Person.h"
#include"Circle.h"
#include"Point.h"
#include "Student.h"
#include "MyArray.h"
#include "MyString.h"
using namespace std;

#define Connect(X, Y) X##Y
#define Connect2(X, Y) Connect(X, Y)
#define ToString(X) #X
#define ToString2(X) ToString(X)
#include <fstream>

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
        stu.mA = 1;
    }
    void test1(Student & stu)
    {
        stu.mA = 2;
    }

    void test2(Student * stu)
    {
        stu->mA = 3;
    }
    void test()
    {
        Student s1(123, 456);
        Student s2(147, 258);
        Student stus[] = { s1,s2 };
        Student sx1 = stus[0];

        Student &s3 = s1;

        Student s4(123, 789);
        test0(s4);//不会修改s4的值
        test1(s4);
        test2(&s4);
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

namespace 指针运算符的重载
{
    class Person
    {
    public:
        Person(string name, int age)
        {
            this->Name = name;
            this->Age = age;
        }
        void ShowPersonInfo()
        {
            cout << this->Name << "  " << this->Age << endl;
        }
    public:
        string Name;
        int Age;
    };

    class SmartPointer
    {
    public:
        SmartPointer(Person * p)
        {
            pPerson = p;
        }
        Person *operator->()
        {
            return pPerson;
        }
        Person &operator*()
        {
            return *pPerson;
        }
        ~SmartPointer()
        {
            if (pPerson != NULL)
            {
                delete pPerson;
                pPerson = NULL;
            }
        }
    private:
        Person *pPerson;
    };

    void test()
    {
        SmartPointer sp = new Person("张三", 20);
        sp->ShowPersonInfo();
        (*sp).ShowPersonInfo();
    }
}

namespace 自定义数组
{
    void 大括号运算符重载()
    {
        MyArray arr = { 1,2,3,4,5,6,7,8,9 };
        arr.foreach();
    }
    void  加等于运算符重载()
    {
        MyArray arr;
        arr += 1, 2, 3, 4, 5, 6, 7, 8, 9;
        arr.foreach();
    }
}

void MyStringTest()
{
    /*
     1：初始化
     MyString(const char *s);
     MyString(int n, char  ch);
     MyString(const MyString &str);
  */
    MyString s1 = "ABCDEFG";
    s1.ShowInfo();

    MyString s2(5, 'B');
    s2.ShowInfo();

    MyString s3(s1);
    s3.ShowInfo();

    /************************************************************************/
    /*  赋值重载    MyString &operator=(const MyString &str);            */
    /************************************************************************/
    MyString s4 = s2;
    s4.ShowInfo();

    /************************************************************************/
    /*    取值重载  char &operator[](int index);                                      */
    /************************************************************************/
    MyString s5("123456789");
    cout << s5[2] << endl;

    /************************************************************************/
    /*         相加操作，返回的是新值
     *         MyString operator+(const MyString &str);
     *         MyString operator+(const char  *c);                                    */
     /************************************************************************/

    MyString s6("123456");
    MyString s7("abcdef");

    MyString s8 = s6 + s7;
    MyString s9 = s6 + "54321";
    s6.ShowInfo();
    s7.ShowInfo();
    s8.ShowInfo();
    s9.ShowInfo();

    /************************************************************************/
    /*  追加操作，返回的是自身，先前的只地址，值要处理
                MyString &operator+=(const MyString &str);
                MyString &operator+=(const char *c);                               */
                /************************************************************************/

    cout << "/************************************************************************/" << endl;
    MyString s10("123456");
    MyString s11("789");
    s10.ShowInfo();
    s11.ShowInfo();
    s10 += s11;
    s10.ShowInfo();
    s11.ShowInfo();

    cout << "/************************************************************************/" << endl;
    MyString s12("123");
    s12.ShowInfo();
    s12 += "456";
    s12.ShowInfo();

    /************************************************************************/
    /*  判断
                bool operator==(const MyString &str);
                bool operator==(const char *s);                                         */
                /************************************************************************/

    MyString s13 = "abc";
    MyString s14 = "abc";
    MyString s15 = "def";
    cout << (s13 == s14 ? "相等" : "不相等") << endl;
    cout << (s13 == s15 ? "相等" : "不相等") << endl;
    const char *ch1 = "abc";
    const char *ch2 = "def";
    cout << (s13 == ch1 ? "相等" : "不相等") << endl;
    cout << (s13 == ch2 ? "相等" : "不相等") << endl;

    /************************************************************************/
    /*  //获取字符大小
                    int size();
    //  MyString->const char *
                  const char * c_str();                                                          */
                  /************************************************************************/
    MyString s16 = "abcdef";
    cout << s16.c_str() << endl;

    /************************************************************************/
    /* >>输入                                                                     */
    /************************************************************************/
    MyString s18 = "123";
    cin >> s18;
}

namespace Animal多态
{
    class Animal
    {
    public:
        virtual void Speak()
        {
            cout << "Animal::Speak()" << endl;
        }
    };

    class Dog :public Animal
    {
    public:
        void Speak() override
        {
            cout << "Dog::Speak()" << endl;
        }
    };

    class Cat :public Animal
    {
    public:
        void Speak() override
        {
            cout << "Cat::Speak()" << endl;
        }
    };

    void DoLogic(Animal &animal)
    {
        animal.Speak();
    }
    void test()
    {
        Animal animal;
        DoLogic(animal);

        Dog dog;
        DoLogic(dog);

        Cat cat;
        DoLogic(cat);
    }

    void test2()
    {
        Animal *animal = new Dog;
        animal->Speak();
    }
}

namespace 动物园多态案例
{
    class Animal
    {
    public:
        virtual void Speak() = 0;
        virtual ~Animal() = 0;
    };
    Animal::~Animal()
    {
    }
    class Dog :public Animal
    {
    public:
        Dog()
        {
            cout << "构造Dog" << endl;
        }
        void Speak() override
        {
            cout << "Dog::Speak()" << endl;
        }
        ~Dog()
        {
            cout << "析构Dog" << endl;
        }
    };
    class Cat :public Animal
    {
    public:
        Cat()
        {
            cout << "构造Cat" << endl;
        }
        void Speak() override
        {
            cout << "Cat::Speal()" << endl;
        }
        ~Cat()
        {
            cout << "析构Cat" << endl;
        }
    };

    class Duck :public Animal
    {
    public:
        Duck()
        {
            cout << "构造Duck" << endl;
        }
        void Speak() override
        {
            cout << "Duck::Speal()" << endl;
        }
        ~Duck()
        {
            cout << "析构Duck" << endl;
        }
    };

    class Zoo
    {
    public:
        Zoo()
        {
            cout << "构造Zoo" << endl;

            this->pAnimals = new Animal*[20];
            this->mSize = 0;
        }
        void Add(Animal *animal)
        {
            if (this->mSize == 20)
            {
                return;
            }
            this->pAnimals[this->mSize] = animal;
            this->mSize++;
        }
        void Show()
        {
            for (int index = 0; index < this->mSize; ++index)
            {
                this->pAnimals[index]->Speak();
            }
        }

        ~Zoo()
        {
            cout << "析构Zoo" << endl;
            if (this->pAnimals != NULL)
            {
                for (int i = 0; i < this->mSize; ++i)
                {
                    delete this->pAnimals[i];
                    this->pAnimals[i] = NULL;
                }
            }
            delete this->pAnimals;
            this->pAnimals = NULL;
        }
    public:
        Animal **pAnimals;
        int mSize;
    };
    void test()
    {
        /*       Cat cat;
               Animal &animal = cat;
               cat.Speak();
       */
        Zoo zoo;
        zoo.Add(new Cat);
        zoo.Add(new Duck);
        zoo.Add(new Dog);
        zoo.Show();
    }
}

namespace Static_cast_Demo
{
    /*
    静态转换(static_cast)
         1：用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。
         2：进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
         3：进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
         4：用于基本数据类型之间的转换，如把int转换成char，把char转换成int。这种转换的安全性也要开发人员来保证。
    */
    class Animal {};
    class Dog : public Animal {};
    class Other {};

    //基础数据类型转换
    void test01()
    {
        char a = 'a';
        double b = static_cast<double>(a);
    }

    //继承关系指针互相转换
    void test02()
    {
        //继承关系指针转换
        Animal* animal01 = NULL;
        Dog* dog01 = NULL;
        //子类指针转成父类指针,安全(小类转大类)
        Animal* animal02 = static_cast<Animal*>(dog01);
        //父类指针转成子类指针，不安全
        Dog* dog02 = static_cast<Dog*>(animal01);
    }

    //继承关系引用相互转换
    void test03()
    {
        Animal ani_ref;
        Dog dog_ref;
        //继承关系指针转换
        Animal& animal01 = ani_ref;
        Dog& dog01 = dog_ref;
        //子类指针转成父类指针,安全
        Animal& animal02 = static_cast<Animal&>(dog01);
        //父类指针转成子类指针，不安全
        Dog& dog02 = static_cast<Dog&>(animal01);
    }

    //无继承关系指针转换
    void test04()
    {
        Animal* animal01 = NULL;
        Other* other01 = NULL;

        //转换失败
        //Animal* animal02 = static_cast<Animal*>(other01);
    }
}

namespace Dynamic_cast_Demo
{
    /*
    动态转换(dynamic_cast)
         dynamic_cast主要用于类层次间的上行转换和下行转换；
         在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；
         在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全；
         含有virtual函数的基类和子类之间的转换。
     */
    class Animal
    {
    public:
        virtual void ShowName() = 0;
    };
    class Dog : public Animal
    {
        virtual void ShowName() {
            cout << "I am a dog!" << endl;
        }
    };
    class Other
    {
    public:
        void PrintSomething()
        {
            cout << "我是其他类!" << endl;
        }
    };

    //普通类型转换
    void test01()
    {
        //不支持基础数据类型
        int a = 10;
        //double a = dynamic_cast<double>(a);
    }

    //继承关系指针
    void test02()
    {
        Animal* animal01 = NULL;
        Dog* dog01 = new Dog;

        //子类指针转换成父类指针 可以
        Animal* animal02 = dynamic_cast<Animal*>(dog01);
        animal02->ShowName();
        //父类指针转换成子类指针 不可以
        //Dog* dog02 = dynamic_cast<Dog*>(animal01);
    }

    //继承关系引用
    void test03()
    {
        Dog dog_ref;
        Dog& dog01 = dog_ref;

        //子类引用转换成父类引用 可以
        Animal& animal02 = dynamic_cast<Animal&>(dog01);
        animal02.ShowName();
    }

    //无继承关系指针转换
    void test04()
    {
        Animal* animal01 = NULL;
        Other* other = NULL;

        //不可以
        //Animal* animal02 = dynamic_cast<Animal*>(other);
    }
}

namespace Const_Cast_Demo
{
    /*
     该运算符用来修改类型的const属性。。
         常量指针被转化成非常量指针，并且仍然指向原来的对象；
         常量引用被转换成非常量引用，并且仍然指向原来的对象；
         注意:不能直接对非指针和非引用的变量使用const_cast操作符去直接移除它的const
     */
     //常量指针转换成非常量指针
    void test01()
    {
        //给指针增加const
        int* p = new int;
        Person* person = new Person;
        const int* const_p = const_cast<const int*>(p);
        const Person* const_person = const_cast<const Person*>(person);

        delete person;
        delete p;

        //去掉const
        const Person* p2 = new Person;
        Person* p3 = const_cast<Person*>(p2);
    }

    //常量引用转换成非常量引用
    void test02()
    {
        int a = 10;
        int& p_ref = a;
        Person person;
        Person& person_ref = person;

        const int& const_b = const_cast<const int&>(p_ref);
        const Person& const_person = const_cast<const Person&>(person_ref);
    }
}

namespace Test
{
    //非纯虚析构函数
    class A
    {
    public:
        virtual ~A();
    };

    A::~A() {}

    //纯析构函数
    class B
    {
    public:
        virtual ~B() = 0;
    };

    B::~B() {}

    //B是抽象类
    //则：
     //B fun(int); //Error
    //B *p; //Ok
    //int fun(B);//Error
    //B Obj;//Error
    void test() {
        A a; //A类不是抽象类，可以实例化对象
         //B b; //B   类是抽象类，不可以实例化对象
    }
}

namespace Exception
{
    void FunError()
    {
        //throw "Char * Exception";
        //throw string("String Exception");
        //throw 23.456;
        throw 123;
    }
    void test0()
    {
        try
        {
            FunError();
        }
        catch (const char* e)
        {
            cout << "const char *类型异常！" << endl;
        }
        catch (string e)
        {
            cout << "string类型异常！" << endl;
        }
        catch (double e)
        {
            cout << "double类型异常！" << endl;
        }
        catch (...)
        {
            cout << "其他类型异常!" << endl;
        }
    }

    int IntException(int a, int b)
    {
        if (b == 0)
        {
            throw - 111;
        }
        return a / b;
    }
    void test1()
    {
        int result = -1;
        try
        {
            result = IntException(12, 0);
        }
        catch (int e)
        {
            cout << "错误码" << e << endl;
        }
    }

    void CharPException()
    {
        throw "Char * Exception";
    }
    void test2()
    {
        try
        {
            CharPException();
        }
        catch (const char * error)
        {
            cout << error << endl;
        }
    }

    void StringException()
    {
        throw string("String Exception");
    }
    void test3()
    {
        try
        {
            StringException();
        }
        catch (const string error)
        {
            cout << error << endl;
        }
        //try
        //{
        //}
        //catch (CMemoryException* e)
        //{
        //
        //}
        //catch (CFileException* e)
        //{
        //}
        //catch (CException* e)
        //{
        //}
    }

    void IntStringException() throw(int, string)
    {
    }

    void NotException() throw()
    {
    }

    class BaseException
    {
    public:
        virtual void PrintError() = 0;
    };

    class NullException :public BaseException
    {
    public:
        virtual void PrintError()
        {
            cout << "NullException" << endl;
        }
    };

    class ZeroException :public BaseException
    {
    public:
        virtual void PrintError()
        {
            cout << "ZeroException" << endl;
        }
    };

    void test4()
    {
        try
        {
            //throw NullException();
            throw ZeroException();
        }
        catch (BaseException& ex)
        {
            ex.PrintError();
        }
    }
}

int main()
{
    system("pause");
    return 0;
}