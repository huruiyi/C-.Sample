#pragma once
#include<iostream>

//template<class T> class MyArray1;

//template<class T> void showArray(MyArray1<T> &arr);
//template<class T> std::ostream& operator<<(std::ostream& out, MyArray1<T> &arr);

template<class T>
class MyArray1
{
    //普通函数声明 还是 函数模板声明？
    //这是一个普通函数声明
    //friend std::ostream& operator<<<>(std::ostream& out, MyArray1<T> &arr);

    //友元函数模板
    //template<class TT> friend void showArray(MyArray1<TT> &arr);

    //friend void showArray<>(MyArray1<T> &arr);

public:
    T *pAddress;
    int mSize;
    int mCapcity;

public:
    MyArray1(int size);
    ~MyArray1();
    void Push(const T &pAddress)
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
            throw string("访问越界");
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
    //不能越界，申请多少空间，才能释放多少内存
    delete this->pAddress;
}

template<class T> std::ostream& operator<<(std::ostream& out, MyArray1<T> &arr)
{
    showArray(arr);
    return out;
}

template<class T> void showArray(MyArray1<T> &arr)
{
    for (int i = 0; i < arr.mSize; i++)
    {
        cout << arr.pAddress[i] << "  ";
    }
    cout << endl;
}