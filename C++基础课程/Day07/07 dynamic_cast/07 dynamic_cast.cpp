#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void func()
    {
    }
};
class Dog : public Animal
{
public:
    virtual void func()
    {
    }
};

//只能用于具有继承关系的指针或者引用，只能向上类型转换(如果是多态的话，可以向下)
void test()
{
    //1. 没有发生多态的时候
    Animal *animal = new Animal;
    //Dog *d =  dynamic_cast<Dog *>(animal);

    Dog *dog = new Dog;
    Animal *a = dynamic_cast<Animal *>(dog);

    //2. 发生多态
    Animal *aa = new Dog;
    Dog *dd = dynamic_cast<Dog *>(aa);
    dynamic_cast<Animal *>(dd);
}

int main() {
    system("pause");
    return EXIT_SUCCESS;
}