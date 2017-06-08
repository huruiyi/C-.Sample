#pragma once
#include<iostream>

template<class T> class MyArr;
template<class T> std::ostream& operator<<(std::ostream& out, MyArr<T> *arr);

template<class T>
class MyArr
{
public:
    friend std::ostream& operator<<<>(std::ostream& out, MyArr<T> *arr);
    MyArr()
    {
        cout << "¹¹Ôìº¯Êý!" << endl;
    }
public:
    T *pAddress;
    int mSize;
};
template<class T>
std::ostream& operator<<(std::ostream& out, MyArr<T> *arr)
{
    out << arr->mSize << "  " << arr->pAddress << "  " << *arr->pAddress << endl;
    return out;
}