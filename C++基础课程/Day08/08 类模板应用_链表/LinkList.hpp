#pragma once

//链表是由一系列节点组成的，节点包含两个域，数据域，指针域(保存节点关系)，在内存中非连续的

//链表节点
template<class T>
class LinkNode
{
public:
    T mData;
    LinkNode *pNext;
};

template<class T>
class LinkList
{
public:
    //头结点
    LinkNode<T> mHeader;
    //节点个数
    int mSize;
    //尾节点指针
    LinkNode<T> *pRear;
public:
    //构造函数
    LinkList()
    {
        mHeader.pNext = NULL;
        mSize = 0;
        pRear = &mHeader;
    }

    //拷贝构造
    LinkList(const LinkList &list)
    {
        mHeader.pNext = NULL;
        pRear = &mHeader;
        mSize = 0;

        LinkNode<T> *pCurrent = list.mHeader.pNext;
        while (pCurrent != NULL)
        {
            pushBack(pCurrent->mData);
            pCurrent = pCurrent->pNext;
        }

        mSize = list.mSize;
    }

    //赋值运算符函数
    LinkList<T>& operator=(const LinkList &list)
    {
        //先释放当前节点的内存
        if (mSize > 0)
        {
            //遍历链表
            LinkNode<T> *pCurrent = mHeader.pNext;
            while (pCurrent != NULL)
            {
                //保存下一个节点的地址
                LinkNode<T> *pNext = pCurrent->pNext;
                //释放当前节点内存
                delete pCurrent;
                //pCurrent指向下一个节点
                pCurrent = pNext;
            }
        }

        //拷贝节点数据
        mHeader.pNext = NULL;
        pRear = &mHeader;
        mSize = 0;

        LinkNode<T> *pCurrent = list.mHeader.pNext;
        while (pCurrent != NULL)
        {
            pushBack(pCurrent->mData);
            pCurrent = pCurrent->pNext;
        }

        mSize = list.mSize;

        return *this;
    }

    //尾部插入
    void pushBack(const T &val)
    {
        //创建新的节点
        LinkNode<T> *newnode = new LinkNode<T>;
        newnode->mData = val;
        newnode->pNext = NULL;

        //新节点入链表
        pRear->pNext = newnode;
        pRear = newnode;

        //更新size大小
        ++mSize;
    }

    //指定位置插入
    void insert(int pos, const T &val)
    {
        //位置校验和调整
        if (pos < 0 || pos > mSize)
        {
            pos = mSize;
        }

        //寻找Pos位置前一个位置的节点
        LinkNode<T> *pCurrent = &mHeader;
        for (int i = 0; i < pos; ++i)
        {
            pCurrent = pCurrent->pNext;
        }

        //创建新的节点
        LinkNode<T> *newnode = new LinkNode<T>;
        newnode->mData = val;
        newnode->pNext = NULL;

        //新节点加入链表
        newnode->pNext = pCurrent->pNext;
        pCurrent->pNext = newnode;

        //更新rear指针
        if (pos == mSize)
        {
            pRear = newnode;
        }

        //更新大小
        ++mSize;
    }

    //按值来删除
    void remove(const T &val)
    {
        LinkNode<T> *pPrev = &mHeader;
        LinkNode<T> *pCurrent = pPrev->pNext;

        while (pCurrent != NULL)
        {
            if (pCurrent->mData == val)
            {
                //更新pRear指针指向
                if (pRear == pCurrent)
                {
                    pRear = pPrev;
                }

                //找到了
                //缓存下待删除节点的下一个节点
                LinkNode<T> *pNext = pCurrent->pNext;
                //释放当前节点的内存
                //delete指针之后，指针的值可能会发生变化
                delete pCurrent;
                //重新建立待删除节点的前驱和后继节点关系
                pPrev->pNext = pNext;
                //更新大小
                --mSize;

                break;
            }

            pPrev = pCurrent;
            pCurrent = pCurrent->pNext;
        }
    }

    //遍历
    template<class _CallBack> //_CallBack =  myPrint
    void foreach(_CallBack func)
    {
        cout << typeid(_CallBack).name() << endl;

        LinkNode<T> *pCurrent = mHeader.pNext;
        while (pCurrent != NULL)
        {
            func(pCurrent->mData); // 	func.operator()(pCurrent->mData);

            pCurrent = pCurrent->pNext;
        }
    }

    //析构函数
    ~LinkList()
    {
        if (mSize > 0)
        {
            //遍历链表
            LinkNode<T> *pCurrent = mHeader.pNext;
            while (pCurrent != NULL)
            {
                //保存下一个节点的地址
                LinkNode<T> *pNext = pCurrent->pNext;
                //释放当前节点内存
                delete pCurrent;
                //pCurrent指向下一个节点
                pCurrent = pNext;
            }
        }
    }
};