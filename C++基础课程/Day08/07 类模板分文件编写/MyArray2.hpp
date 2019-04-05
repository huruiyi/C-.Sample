#pragma once
#include<iostream>
using namespace std;

template<class T> class MyArray2;
template<class T> std::ostream& operator<<(std::ostream& out, MyArray2<T>* arr);

template<class T>
class MyArray2
{
public:
	friend std::ostream& operator<<<>(std::ostream& out, MyArray2<T>* arr);
	MyArray2()
	{
		cout << "���캯��!" << endl;
	}
public:
	T* pAddress;
	int mSize;
};
template<class T>
std::ostream& operator<<(std::ostream& out, MyArray2<T>* arr)
{
	out << arr->mSize << "  " << arr->pAddress << "  " << *arr->pAddress << endl;
	return out;
}