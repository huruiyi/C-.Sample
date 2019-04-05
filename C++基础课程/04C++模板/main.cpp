#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <assert.h>

using namespace std;

namespace 函数模版
{
	class Person
	{
	public:
		Person(const char* name)
		{
			this->pName = new char[strlen(name) + 1];
			strcpy(this->pName, name);
		}
		char* pName;
	};

	void SwapInt(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	void test1()
	{
		int a = 123;
		int b = 456;

		cout << "a=" << a << "\tb=" << b << endl;
		SwapInt(a, b);
		cout << "a=" << a << "\tb=" << b << endl;
	}

	//函数模版可以有默认值，值是类型
	//template<class T = int>或
	template<typename T = int>
	void Swap(T & a, T & b)
	{
		T   temp = a;
		a = b;
		b = temp;
	}
	void test2()
	{
		int a = 123;
		int b = 456;

		cout << "a=" << a << "\tb=" << b << endl;
		Swap(a, b);
		cout << "a=" << a << "\tb=" << b << endl;

		Person pa("AAA");
		Person pb("BBB");
		cout << "pa=" << pa.pName << "\tpb=" << pb.pName << endl;
		Swap(pa, pb);
		cout << "pa=" << pa.pName << "\tpb=" << pb.pName << endl;
	}

	template<class T>
	void PrintArr(T* arr, int len)
	{
		for (int i = 0; i < len; ++i)
		{
			cout << arr[i];
		}
		cout << endl;
	}
	template<class T>
	void SelectSort(T* arr, int len)
	{
		for (int i = 0; i < len; ++i)
		{
			int min = i;
			for (int j = i + 1; j < len; ++j)
			{
				if (arr[min] < arr[j])
				{
					min = j;
				}
			}
			if (min != i)
			{
				T temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
	}
	void test3()
	{
		int arr[] = { 5,1,9,3,7,2,4,6,8 };
		int len = sizeof(arr) / sizeof(arr[0]);
		PrintArr(arr, len);
		SelectSort(arr, len);
		PrintArr(arr, len);
	}

	//void fun(int a, int b)
	//{
	//    cout << "void fun(int a,int b)" << endl;
	//}

	template<class T>
	void fun(T a, T b)
	{
		cout << "void fun(T a, T b)" << endl;
	}
	template<class T>
	void fun(T a, T b, T c)
	{
		cout << "void fun(T a, T b,T c)" << endl;
	}
	void fun(int a, double b)
	{
		cout << "void fun(int a,double b)" << endl;
	}

	void test4()
	{
		//函数模版和普通函数匹配优先级
		// 优先匹配普通函数，其次是函数参数类型，不续转化的优先调用
		// 函数模版亦可以重载
		int a = 10;
		int b = 20;
		double c = 3.123;
		fun(a, b);
		fun(a, c);
	}

	void test5()
	{
		//extern void fun1(int a, int b);
		//fun1(10, 20);

		//template<class T> void fun2(T a, T b);
		//   fun2(10, 20);//不可以调用
	}
}

namespace 类模版
{
	class Person
	{
	public:
		Person(const char* name)
		{
			this->pName = new char[strlen(name) + 1];
			strcpy(this->pName, name);
		}
	public:
		char* pName;
		int mA;
		int mB;
	};

	class Teacher
	{
	public:
		char* pName;
		int mA;
		int mB;
	};
	template<class T>
	class MyArray
	{
	public:
		MyArray()
		{
			pArr = new T * [10];
		}
		~MyArray()
		{
			for (int i = 0; i < 10; i++)
			{
				if (this->pArr[i] != NULL)
				{
					delete pArr[i];
					pArr[i] = NULL;
				}
			}
			if (this->pArr != NULL)
			{
				delete this->pArr;
				this->pArr = NULL;
			}
		}
	public:
		T** pArr;
	};

	void test1()
	{
		MyArray<类模版::Person> mpArray;
		mpArray.pArr[0] = new 类模版::Person("A");
		mpArray.pArr[1] = new 类模版::Person("B");
		mpArray.pArr[2] = new 类模版::Person("C");
		mpArray.pArr[3] = new 类模版::Person("D");
		mpArray.pArr[4] = new 类模版::Person("E");
		mpArray.pArr[5] = new 类模版::Person("F");
		mpArray.pArr[6] = new 类模版::Person("G");
		mpArray.pArr[7] = new 类模版::Person("H");
		mpArray.pArr[8] = new 类模版::Person("I");
		mpArray.pArr[9] = new 类模版::Person("J");
		for (int i = 0; i < 10; i++)
		{
			cout << mpArray.pArr[i]->pName << endl;
		}
	}
}

int main()
{
	return 0;
}