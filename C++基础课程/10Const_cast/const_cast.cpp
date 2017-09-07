#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
	Person();
	~Person();
	void SetAge(int age);
	int GetAge() const;

	void SetName(string name);
	string GetName() const;

	void ShowPersonInfo();

private:
	string Name;
	int Age;

protected:
	string ProtectedInfo;
};

Person::Person()
{
	cout << "Person" << this->Name << "被构造" << endl;
}
Person::~Person()
{
	cout << "Person" << this->Name << "被析构" << endl;
}
void Person::SetName(string name)
{
	Name = name;
}
string Person::GetName() const
{
	return  Name;
}

void Person::SetAge(int age)
{
	if (age < 0 || age>100)
	{
		return;
	}
	Age = age;
}
int Person::GetAge() const
{
	return  Age;
}

void Person::ShowPersonInfo()
{
	cout << Name << "  " << Age << endl;
}
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

int main()
{
	test01();
	test01();
	return 0;
}