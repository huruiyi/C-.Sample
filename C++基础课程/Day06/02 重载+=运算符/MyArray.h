#pragma once

#include<stdlib.h>
#include<iostream>
#include<initializer_list>

class MyArray
{
public:

    //是一个类initializer_list
    MyArray(std::initializer_list<int> list);
    MyArray();
    MyArray(int capacity);
    MyArray(int n, int ele);
    MyArray(const MyArray& arr);
    ~MyArray();

    //重载+=运算符
    MyArray& operator+=(int val);
    MyArray& operator,(int val);

    //重载下标运算符
    int& operator[](int index);

    //获得指定位置的数据
    int& getData(int index);
    void setData(int index, int val);
    //头插
    void pushFront(int val);
    //尾部插入
    void pushBack(int val);
    //头删
    void popFront();
    //尾删除
    void popBack();
    //在指定位置插入
    void insert(int index, int val);
    //获得大小
    int size();
    //获得容量
    int capacity();
    //遍历
    void foreach();

private:
    int *pArray; //指向真正保存数据的内存
    int mCapacity; //容量
    int mSize; //大小
};
