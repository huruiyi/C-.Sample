#include "Person.h"

Person::Person()
{
	cout << "Person" << this->Name << "������" << endl;
}
Person::~Person()
{
	cout << "Person" << this->Name << "������" << endl;
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