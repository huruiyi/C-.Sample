#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//在C++中2个不一样的类型不能够直接赋值
class Base {};
class Derived : public Base {};

void test01()
{
	//子类对象的大小>=父类大小的
	//对象的大小影响对象指针的寻址范围
	Base *b = new Derived;

	//Derived d;
	//Base b = d;

	//Base bb;
	//Derived dd = bb;
}

class Animal
{
public:
	virtual void Speak() = 0;
};

class Dog : public Animal
{
public:
	virtual void Speak()
	{
		cout << "Dog::Speak()" << endl;
	}
};

class Cat : public Animal
{
public:
	virtual void Speak()
	{
		cout << "Cat::Speak()" << endl;
	}
};

void doLogic(Animal &animal)
{
	//编译器根据指针或者引用的类型在编译阶段确定Speak函数的调用
	//由于调用的是Speak是Animal类型对象，所以编译器就将此函数调用在编译阶段绑定为Animal的Speak函数
	animal.Speak();

	cout << typeid(animal).name() << endl;
}

void test02()
{
	//Animal animal;
	//doLogic(animal);

	//不论传入是那个对象，仍然调用父类的Speak函数
	//我们需要传入什么对象，就调用那个对象的Speak函数
	//原因是因为此函数调用用的是静态绑定
	//解决办法不要让编译器在编译阶段给我们确定函数的调用，在运行阶段根据指针或者引用真正
	//指向的对象来确定函数调用
	Dog dog;
	doLogic(dog);

	cout << "---------" << endl;
	((void(*)())*((int *)*(int *)&dog + 0))();

	//dog.Animal::Speak();

	cout << "---------" << endl;

	Cat cat;
	doLogic(cat);

	//多态实现条件
	//父类指针或者引用指向子类对象
	//父类有虚函数
	//子类重写父类的虚函数
}

//纯虚函数和虚函数一样都是为了实现多态
//纯虚函数没有实现，仅仅为了让基类指针或者引用指向子类对象，从而实现调用子类函数
//只要类中包含纯虚函数，这个类叫做抽象类，这个类不能够被实例化
//子类继承了抽象类，子类必须要实现父类里面定义所有的纯虚函数
int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}