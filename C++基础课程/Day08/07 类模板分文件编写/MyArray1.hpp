#pragma once
#include<iostream>
using namespace std;

//template<class T> class MyArray1;

//template<class T> void showArray(MyArray1<T> &arr);
//template<class T> std::ostream& operator<<(std::ostream& out, MyArray1<T> &arr);

template<class T>
class MyArray1
{
	//��ͨ�������� ���� ����ģ��������
	//����һ����ͨ��������
	//friend std::ostream& operator<<<>(std::ostream& out, MyArray1<T> &arr);

	//��Ԫ����ģ��
	//template<class TT> friend void showArray(MyArray1<TT> &arr);

	//friend void showArray<>(MyArray1<T> &arr);

public:
	T* pAddress;
	int mSize;
	int mCapcity;

public:
	MyArray1(int size);
	~MyArray1();
	void Push(const T& pAddress)
	{
		if (this->mSize >= mCapcity)
		{
			return;
		}
		else
		{
			this->pAddress[mSize] = pAddress;
			mSize++;
		}
	}

	T operator[] (int index)
	{
		if (this->mCapcity <= index)
		{
			throw string("����Խ��");
		}
		return   this->pAddress[index];
	}
};

template<class T> MyArray1<T>::MyArray1(int size)
{
	this->pAddress = new T[size];
	this->mCapcity = size;
}

template<class T> MyArray1<T>::~MyArray1()
{
	//����Խ�磬������ٿռ䣬�����ͷŶ����ڴ�
	delete this->pAddress;
}

template<class T> std::ostream& operator<<(std::ostream& out, MyArray1<T>& arr)
{
	showArray(arr);
	return out;
}

template<class T> void showArray(MyArray1<T>& arr)
{
	for (int i = 0; i < arr.mSize; i++)
	{
		cout << arr.pAddress[i] << "  ";
	}
	cout << endl;
}