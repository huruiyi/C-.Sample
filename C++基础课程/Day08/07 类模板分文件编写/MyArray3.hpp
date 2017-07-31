#pragma once
#include <string>
using namespace std;

template<class T> class MyArray3;
template<class T>    void ShowArray3(MyArray3<T> &arr);

template<class T>   std::ostream& operator<<  (std::ostream& out, MyArray3<T> &arr);
template<class T>
class MyArray3
{
	template<class T> friend void ShowArray2(MyArray3<T> &arr);

	//����Ԫ�������������η������࣬��ʵ��
	friend void ShowArray3<>(MyArray3<T> &arr);

	//<> ǿ��Ҫ��ƥ�亯��ģ��, ����ǰ������
	friend std::ostream& operator<<<> (std::ostream& out, MyArray3<T> &arr);
public:
	string mName;
	int mAge;
	MyArray3();

	MyArray3(string name, int age);
};
template<class T> MyArray3<T>::MyArray3() {}

template<class T> MyArray3<T>::MyArray3(string name, int age)
{
	this->mName = name;
	this->mAge = age;
}

template<class T> void ShowArray1(MyArray3<T> &arr)
{
	cout << arr.mName << "|" << arr.mAge << endl;
}

template<class T>   void ShowArray2(MyArray3<T> &arr)
{
	cout << arr.mName << "|" << arr.mAge << endl;
}

template<class T>   void ShowArray3(MyArray3<T> &arr)
{
	cout << arr.mName << "|" << arr.mAge << endl;
}

template<class T> std::ostream& operator<<(std::ostream& out, MyArray3<T> &arr)
{
	ShowArray1(arr);
	return out;
}