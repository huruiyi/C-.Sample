#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal 构造函数!" << endl;
        pName = new char[64];
    }

    virtual void func()
    {
        cout << "Animal::func()" << endl;
    }

#if 0
    virtual ~Animal()
    {
        cout << "Animal 析构函数!" << endl;
    }
#endif

    //包含纯虚析构函数的类仍然叫做抽象类，不能被实例化
    //纯虚析构函数必须在类外实现
    virtual ~Animal() = 0;
public:
    char *pName;
};

Animal::~Animal()
{
}

class Dog : public Animal
{
public:
    Dog()
    {
        cout << "Dog 构造函数!" << endl;
        pName = new char[64];
    }

    virtual void func()
    {
        cout << "Dog::func()" << endl;
    }

    ~Dog()
    {
        cout << "Dog 析构函数!" << endl;
        if (pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }
    }
public:
    char *pName;
};

void test()
{
    Animal *animal = new Dog;
    animal->func();

    delete animal;

    //当发生多态的时候，我们通过父类指针去释放子类对象的时候，子类对象不会调用析构函数
    //虚析构函数用来解决在多态的情况下，通过父类指针来释放子类对象
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}