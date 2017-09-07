#include<iostream>
#include<string>

using namespace std;

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

int main()
{
	test01();
	test01();
	return 0;
}