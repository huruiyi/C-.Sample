#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
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
class Person
{
public:
	string mName;
	int mAge;
public:
	Person() {}
	Person(string name, int age)
	{
		this->mName = name;
		this->mAge = age;
	}
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

	Animal** animals = new Animal*[9];
	animals[0] = new Tiger;
	animals[1] = new Duck;
	animals[2] = new Duck;
	animals[3] = new Dog;
	animals[4] = new Cat;
	animals[5] = new Chicken;
	animals[6] = new Duck;
	animals[7] = new Dog;
	animals[8] = new Duck;
	animals[9] = new Snake;

	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << typeid(animals[0]).name() << endl;
	cout << typeid(Animal*).name() << endl;
	cout << typeid(animals).name() << endl;
	cout << typeid(Animal**).name() << endl;

	Person p("张三丰", 100);
	Person *p0 = &p;
	cout << p0->mName << "  " << p0->mAge << endl;
	//delete p0;//p0指向的是栈上的空间，不允许用户删除
	//p0 = NULL;

	Person * p1 = new Person;
	p1->mAge = 12;
	p1->mName = "张三丰P1";
	cout << p1->mName << "  " << p1->mAge << endl;
	delete p1;
	p1 = NULL;

	Person **p2 = new Person *[1];
	p2[0] = new Person;
	p2[0]->mName = "张君宝P2";
	p2[0]->mAge = 110;
	cout << p2[0]->mName << "  " << p2[0]->mAge << endl;
	delete p2[0];
	p2[0] = NULL;
	delete p2;
	p2 = NULL;

	Person **p3 = new Person *;
	p3[0] = new Person;
	p3[0]->mName = "张君宝P3";
	p3[0]->mAge = 110;
	cout << p3[0]->mName << "  " << p3[0]->mAge << endl;
	delete p3[0];
	p3[0] = NULL;
	delete p3;
	p3 = NULL;

	Person **p4 = new Person *[2];
	p4[0] = new Person("P41", 10);
	p4[1] = new Person("P42", 10);
	for (int i = 0; i < 2; i++)
	{
		delete p4[i];
		p4[i] = NULL;
	}
	delete p4;
	p4 = NULL;

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