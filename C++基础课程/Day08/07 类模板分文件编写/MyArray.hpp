#pragma once
#include<iostream>

template<class T> class MyArray;

//template<class T> void showArray(MyArray<T> &arr);
template<class T> std::ostream& operator<<(std::ostream& out, MyArray<T> &arr);

template<class T>
class MyArray
{
    //普通函数声明 还是 函数模板声明？
    //这是一个普通函数声明
    friend std::ostream& operator<<<>(std::ostream& out, MyArray<T> &arr);
    //friend void showArray<>(MyArray<T> &arr);

    //友元函数模板
    template<class TT> friend void showArray(MyArray<TT> &arr);
public:
    MyArray();
    ~MyArray();
    void Push(const T &pAddress)
    {
        if (this->mSize >= 10)
        {
            return;
        }
        else
        {
            this->pAddress[mSize] = pAddress;
            mSize++;
        }
    }
public:
    T *pAddress;
    int mSize;
};

template<class T> MyArray<T>::MyArray()
{
    this->pAddress = new T[10];
}

template<class T> MyArray<T>::~MyArray()
{
    //for (int i = 0; i < this->mSize; i++)
    //{
    //    delete this->pAddress[i];
    //    this->pAddress[i] = NULL;
    //}
    //不能越界，申请多少空间，才能释放多少内存
    delete this->pAddress;
}

template<class T> std::ostream& operator<<(std::ostream& out, MyArray<T> &arr)
{
    return out;
}

template<class T> void showArray(MyArray<T> &arr)
{
    for (int i = 0; i < arr.mSize; i++)
    {
        cout << arr.pAddress[i] << "  ";
    }
    cout << "普通友元函数！" << endl;
}