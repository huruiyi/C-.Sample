#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void Speak()
    {
        cout << "Animal::Speak()" << endl;
    }
};

class Dog : public Animal
{
public:
    virtual void Speak()
    {
        cout << "Dog::Speak()" << endl;
    }
};

void test()
{
    //父类指针或者引用指向子类对象
    Dog dog;
    //当把子类对象转换成父类对象，发生了对象切割
    //对象切割：会子类新增的成员全部剔除掉
    Animal animal = dog;
    animal.Speak();
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}