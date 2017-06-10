#include <iostream>

//分文件编写步骤
/************************************************************************/
/* 1:类模版声明
 * 2：类模版定义
 * 3：类模版函数声明的定义（必须指定类型）
/************************************************************************/

 

template<class T>
class LinkNode
{
public:
    T *pData;
    LinkNode  *pNext;

public:
    LinkNode(T *data);
};

template<class T>
LinkNode<T>::LinkNode(T *data)
{
    this->pData = new T(sizeof(T));
    this->pData = data;
}

 

template<class T>
class LinkList
{
public:
    LinkList();

    void Push(T t);

public:
    LinkNode<T>   pHeader;
    LinkNode<T>   pFooted;
    int mSize;
};

template<class T>
LinkList<T>::LinkList()
{
    cout << "  " << endl;
}

template<class T>
void LinkList<T>::Push(T t)
{
    cout << "" << endl;
}