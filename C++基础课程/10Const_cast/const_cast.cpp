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
/*
������������޸����͵�const���ԡ���
����ָ�뱻ת���ɷǳ���ָ�룬������Ȼָ��ԭ���Ķ���
�������ñ�ת���ɷǳ������ã�������Ȼָ��ԭ���Ķ���
ע��:����ֱ�ӶԷ�ָ��ͷ����õı���ʹ��const_cast������ȥֱ���Ƴ�����const
*/
//����ָ��ת���ɷǳ���ָ��
void test01()
{
	//��ָ������const
	int* p = new int;
	Person* person = new Person;
	const int* const_p = const_cast<const int*>(p);
	const Person* const_person = const_cast<const Person*>(person);

	delete person;
	delete p;

	//ȥ��const
	const Person* p2 = new Person;
	Person* p3 = const_cast<Person*>(p2);
}

//��������ת���ɷǳ�������
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