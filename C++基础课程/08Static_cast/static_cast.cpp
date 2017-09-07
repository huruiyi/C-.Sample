#include<iostream>
#include<string>

using namespace std;

/*
��̬ת��(static_cast)
1���������νṹ�л��ࣨ���ࣩ�������ࣨ���ࣩ֮��ָ������õ�ת����
2����������ת�������������ָ�������ת���ɻ����ʾ���ǰ�ȫ�ģ�
3����������ת�����ѻ���ָ�������ת�����������ʾ��ʱ������û�ж�̬���ͼ�飬�����ǲ���ȫ�ġ�
4�����ڻ�����������֮���ת�������intת����char����charת����int������ת���İ�ȫ��ҲҪ������Ա����֤��
*/
class Animal {};
class Dog : public Animal {};
class Other {};

//������������ת��
void test01()
{
	char a = 'a';
	double b = static_cast<double>(a);
}

//�̳й�ϵָ�뻥��ת��
void test02()
{
	//�̳й�ϵָ��ת��
	Animal* animal01 = NULL;
	Dog* dog01 = NULL;
	//����ָ��ת�ɸ���ָ��,��ȫ(С��ת����)
	Animal* animal02 = static_cast<Animal*>(dog01);
	//����ָ��ת������ָ�룬����ȫ
	Dog* dog02 = static_cast<Dog*>(animal01);
}

//�̳й�ϵ�����໥ת��
void test03()
{
	Animal ani_ref;
	Dog dog_ref;
	//�̳й�ϵָ��ת��
	Animal& animal01 = ani_ref;
	Dog& dog01 = dog_ref;
	//����ָ��ת�ɸ���ָ��,��ȫ
	Animal& animal02 = static_cast<Animal&>(dog01);
	//����ָ��ת������ָ�룬����ȫ
	Dog& dog02 = static_cast<Dog&>(animal01);
}

//�޼̳й�ϵָ��ת��
void test04()
{
	Animal* animal01 = NULL;
	Other* other01 = NULL;

	//ת��ʧ��
	//Animal* animal02 = static_cast<Animal*>(other01);
}

int main()
{
	test01();
	test01();
	return 0;
}