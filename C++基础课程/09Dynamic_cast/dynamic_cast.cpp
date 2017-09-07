#include<iostream>
#include<string>

using namespace std;

/*
��̬ת��(dynamic_cast)
dynamic_cast��Ҫ�������μ������ת��������ת����
�����μ��������ת��ʱ��dynamic_cast��static_cast��Ч����һ���ģ�
�ڽ�������ת��ʱ��dynamic_cast�������ͼ��Ĺ��ܣ���static_cast����ȫ��
����virtual�����Ļ��������֮���ת����
*/
class Animal
{
public:
	virtual void ShowName() = 0;
};
class Dog : public Animal
{
	virtual void ShowName() {
		cout << "I am a dog!" << endl;
	}
};
class Other
{
public:
	void PrintSomething()
	{
		cout << "����������!" << endl;
	}
};

//��ͨ����ת��
void test01()
{
	//��֧�ֻ�����������
	int a = 10;
	//double a = dynamic_cast<double>(a);
}

//�̳й�ϵָ��
void test02()
{
	Animal* animal01 = NULL;
	Dog* dog01 = new Dog;

	//����ָ��ת���ɸ���ָ�� ����
	Animal* animal02 = dynamic_cast<Animal*>(dog01);
	animal02->ShowName();
	//����ָ��ת��������ָ�� ������
	//Dog* dog02 = dynamic_cast<Dog*>(animal01);
}

//�̳й�ϵ����
void test03()
{
	Dog dog_ref;
	Dog& dog01 = dog_ref;

	//��������ת���ɸ������� ����
	Animal& animal02 = dynamic_cast<Animal&>(dog01);
	animal02.ShowName();
}

//�޼̳й�ϵָ��ת��
void test04()
{
	Animal* animal01 = NULL;
	Other* other = NULL;

	//������
	//Animal* animal02 = dynamic_cast<Animal*>(other);
}

int main()
{
	test01();
	test01();
	return 0;
}