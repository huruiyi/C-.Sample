#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void Speak() = 0;
    virtual ~Animal() {}
};

class Chicken : public Animal
{
public:
    virtual void Speak()
    {
        cout << "小鸡咯咯咯..." << endl;
    }
};

class Tiger : public Animal
{
public:
    virtual void Speak()
    {
        cout << "老虎嗷嗷嗷..." << endl;
    }
};

class Dog : public Animal
{
public:
    virtual void Speak()
    {
        cout << "小狗汪汪汪..." << endl;
    }
};

class Cat : public Animal
{
public:
    virtual void Speak()
    {
        cout << "小猫喵喵喵..." << endl;
    }
};

class Duck : public Animal
{
public:
    virtual void Speak()
    {
        cout << "鸭子嘎嘎嘎..." << endl;
    }
};

class Snake : public Animal
{
public:
    Snake()
    {
        mSpeed = 100;
    }
    virtual void Speak()
    {
        dance();
        cout << "并且以" << mSpeed << "时速向前狂奔!" << endl;
    }
    void dance()
    {
        cout << "小蛇扭着屁股往前走..." << endl;
    }
public:
    int mSpeed;
};

class Zoo
{
public:
    Zoo()
    {
        pAnimals = new Animal*[20];
        mSize = 0;
    }

    //向动物园中添加新的动物
    void addNewAnimal(Animal *animal)
    {
        if (mSize == 20)
        {
            return;
        }
        this->pAnimals[mSize++] = animal;
    }

    //动物表演，开始嚎
    void startKTV()
    {
        for (int i = 0; i < mSize; ++i)
        {
            this->pAnimals[i]->Speak();
        }
    }

    //析构函数
    ~Zoo()
    {
        for (int i = 0; i < mSize; ++i)
        {
            if (this->pAnimals[i] != NULL)
            {
                delete this->pAnimals[i];
                this->pAnimals[i] = NULL;
            }
        }

        //清理动物园
        delete[] this->pAnimals;
        this->pAnimals = NULL;
        mSize = 0;
    }
public:
    Animal **pAnimals;
    int mSize;
};

void test()
{
    //创建动物园
    Zoo zoo;
    zoo.addNewAnimal(new Tiger);
    zoo.addNewAnimal(new Duck);
    zoo.addNewAnimal(new Dog);
    zoo.addNewAnimal(new Cat);
    zoo.addNewAnimal(new Chicken);
    zoo.addNewAnimal(new Duck);
    zoo.addNewAnimal(new Snake);

    zoo.startKTV();

#if 0
    Animal *animal = NULL;
    animal = new Duck;
    animal->Speak();
    delete animal;

    animal = new Tiger;
    animal->Speak();
    delete animal;
#endif
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}