#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct Person
{
	double &p;
};

//引用在内部实现的时候是以常量指针来实现的
void test01()
{
	int a = 10;
	int &ref = a; //int *const ref = &a;
	ref = 100; //*ref = 100;

	cout << sizeof(int&) << endl;
	cout << sizeof(double&) << endl;
	cout << sizeof(Person) << endl;
}

void allocateSpace(char* &temp)
{
	temp = (char *)malloc(sizeof(char) * 64);
	memset(temp, 0, 64);
	strcpy(temp, "hello world");
}
void test02()
{
#if 0
	int a = 10;
	int &b = a;

	char *p = NULL;
	char* &ref = p;

	char **pp = NULL;
	char** &ppref = pp;
#endif

	char *p = NULL;
	allocateSpace(p);
	cout << p << endl;
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}