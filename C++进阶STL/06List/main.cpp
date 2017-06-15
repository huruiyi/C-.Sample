#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
/*
 1:不支持随机访问
    //list<int>::const_iterator itx;
    //itx + 2;//不支持随机访问
 2:自定义元素不能直接remove,要重载后才可以
 3:元素可重复出现
 4:删除元素会删除所有满足条件的值
 */


class Person
{
public:
    Person(string name, int age, int heigth)
    {
        this->mName = name;
        this->mAge = age;
        this->mHeight = heigth;
    }
    bool operator==(const Person p) const
    {
        if (p.mName == this->mName&&p.mAge == this->mAge)
        {
            return true;
        }
        return false;
    }

public:
    string mName;
    int mAge;
    int mHeight;
};
//对于自定义数据类型，必须指定排序规则
bool myCompare2(Person & p1, Person & p2)
{
    if (p1.mAge == p2.mAge)
    {
        return p1.mHeight > p2.mHeight;
    }
    else
    {
        return p1.mAge < p2.mAge;
    }
}

class Cmpare
{
public:
    bool operator()(const Person p1, const Person  p2) const
    {
        return p1.mAge < p2.mAge;
    }
};

bool myCompare(const int v1, const int v2)
{
    //从大到小
    return v1 > v2;
}
void test_foreach(const list<int>& L)
{
    //list<int>::const_iterator itx;
    //itx + 2;//不支持随机访问
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test_foreach_reverse(const list<int>& L)
{
    //L.reverse();

    for (list<int>::const_reverse_iterator i = L.rbegin(); i < L.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
void test_empty_size_resize(list<int>& L)
{
    if (L.empty())
    {
        cout << "为空" << endl;
    }
    else
    {
        cout << "不为空  L4 大小： " << L.size() << endl;
    }

    L.resize(10);
    L.resize(10, 100);
}
void test_init_Insert(list<int>& L)
{
    /*
        list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
        list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
        list(n,elem);//构造函数将n个elem拷贝给本身。
        list(const list &lst);//拷贝构造函数。
    */
    list<int>L;
    list<int>L2(10, 10);
    list<int>L3(L2.begin(), L2.end());
    L3.push_back(100);

    list<int> L4;
    L4.push_back(10);
    L4.push_back(20);
    L4.push_back(30);
    L4.push_front(100);
    L4.push_front(200);
    L4.push_front(300);

    //remove 删除容器中所有与elem值匹配的元素
    L4.remove(10);
    /*
        insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
        insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
        insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
     */
    L4.insert(L.begin(), 1000);
    L4.insert(L.begin(), 5, 10);
}
void test_front_front(list<int>& L)
{
    cout << "第一个元素：" << L.front() << " 最后一个元素： " << L.back() << endl;
    L.pop_back();//尾删
    L.pop_front();//头删
    L.push_front(90);
    L.push_back(110);
}
void test_erase(list<int>& L)
{
    /*
        erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
        erase(pos);//删除pos位置的数据，返回下一个数据的位置。
*/
    L.erase(L.begin());
    L.erase(L.begin(), L.end());
}
void test01()
{
    list<int> li;
    li.push_back(18);
    li.push_back(12);
    li.push_back(11);
    li.push_back(16);
    li.push_back(13);
    li.push_back(12);

    //li.sort();//默认从小到大
    //li.sort([](int a, int b) {return a < b; });//从小到大
    //li.sort([](int a, int b) {return a > b; });//从大到下
    li.sort(myCompare);
    test_foreach(li);

    for_each(li.begin(), li.end(), [](int a) {cout << a << endl; });

    cout << "移除12前大小" << li.size() << endl;
    li.remove(12);
    cout << "移除12后大小" << li.size() << endl;

    //排序
    //sort(li.begin(), li.end()); //所有不支持随机访问的迭代器的容器，不可以使用系统提供的公共算法
    //不支持随机访问的容器，内部会提供响应算法
    li.sort();
}

void test02()
{
    list<Person> lip;
    Person p1("A", 20, 178);
    Person p2("B", 29, 160);
    Person p3("C", 25, 156);
    Person p4("D", 22, 138);
    Person p5("E", 27, 169);
    Person p6("F", 21, 159);
    Person p6("F", 25, 155);
    lip.push_back(p1);
    lip.push_back(p2);
    lip.push_back(p3);
    lip.push_back(p4);
    lip.push_back(p5);
    lip.push_back(p6);

    //自定义数据类型需要重载“==”运算符，才能remove
    lip.remove(p4);

    lip.sort(Cmpare()); //自定义类型不支持排序
    lip.sort(myCompare2);
    
    //lip.sort([](Person p1, Person p2) {return p1.mAge > p2.mAge; });
    for_each(lip.begin(), lip.end(), [](Person p)
    {
        cout << "name：" << p.mName << "，ag：" << p.mAge << endl;
    });
}

int main()
{
    system("pause");
    return 0;
}

/*
3.6.4.3 list大小操作
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

3.6.4.4 list赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。

*/

#if 0
void test01()
{
    list<int> myList;
    for (int i = 0; i < 10; i++)
    {
        myList.push_back(i);
    }

    list<int>::_Nodeptr node = myList._Myhead->_Next;
    //双向循环链表
    for (int i = 0; i < myList._Mysize * 2; i++)
    {
        cout << "Node:" << node->_Myval << endl;
        node = node->_Next;
        if (node == myList._Myhead) {
            node = node->_Next;
        }
    }
}
#endif