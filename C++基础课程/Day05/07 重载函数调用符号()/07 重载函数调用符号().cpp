#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyFunctor
{
public:
	int operator()(int a, int b, int c)
	{
		return a + b + c;
	}
};

void test01()
{
	//�������� �º���
	MyFunctor functor;
	cout << "ret:" << functor(10, 20, 30) << endl; //functor.operator();

	cout << MyFunctor()(100, 200, 300) << endl;

	//����û�����ͣ���������������
	//����������Իص�������Ч��Ҫ�Ⱥ���ָ���
	//����������������״̬

	//MyFunctor *f = new MyFunctor;
	//(*f)(10,20,30);
}

int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}