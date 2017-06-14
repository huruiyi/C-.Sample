#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>

void test01()
{
    list<int> myList;
    for (int i = 0; i < 10; i++) {
        myList.push_back(i);
    }

    list<int>::_Nodeptr node = myList._Myhead->_Next;

    for (int i = 0; i < myList._Mysize * 2; i++) {
        cout << "Node:" << node->_Myval << endl;
        node = node->_Next;
        if (node == myList._Myhead) {
            node = node->_Next;
        }
    }
}

/*
3.6.4.1 list构造函数
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。
3.6.4.2 list数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
*/

void printList(const list<int>& L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test02()
{
    list<int>L;
    list<int>L2(10, 10);
    list<int>L3(L2.begin(), L2.end());
    L3.push_back(100);

    //正向遍历
    for (list<int>::iterator it = L3.begin(); it != L3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //逆序遍历
    for (list<int>::reverse_iterator it = L3.rbegin(); it != L3.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    list<int> L4;
    L4.push_back(10);
    L4.push_back(20);
    L4.push_back(30);
    L4.push_front(100);
    L4.push_front(200);
    L4.push_front(300);

    printList(L4); // 300 200 100 10 20 30

    //头删
    L4.pop_front();
    //尾删
    L4.pop_back();
    printList(L4); //  200 100 10 20

    //insert 插入  迭代器

    L4.insert(L4.begin(), 1000);
    printList(L4); //  1000 200 100 10 20

    //删除 erase
    L4.erase(L4.begin());
    printList(L4); //   200 100 10 20
    L4.push_back(10);//   200 100 10 20 10

    //remove 删除容器中所有与elem值匹配的元素
    L4.remove(10);
    printList(L4);//   200 100  20
}

/*
3.6.4.3 list大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
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
3.6.4.5 list数据的存取
front();//返回第一个元素。
back();//返回最后一个元素。

*/

void test03()
{
    list<int> L4;
    L4.push_back(10);
    L4.push_back(20);
    L4.push_back(30);
    L4.push_front(100);
    L4.push_front(200);
    L4.push_front(300);

    printList(L4); // 300 200 100 10 20 30

    if (L4.empty())
    {
        cout << "为空" << endl;
    }
    else
    {
        cout << "不为空  L4 大小： " << L4.size() << endl;
    }

    L4.resize(10);
    printList(L4);

    cout << "第一个元素：" << L4.front() << " 最后一个元素： " << L4.back() << endl;
}

/*
list反转排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/
//指定排序规则
bool myCompare(int v1, int v2)
{
    //从大到小
    return v1 > v2;
}

void test04()
{
    list<int> L4;
    L4.push_back(10);
    L4.push_back(20);
    L4.push_back(30);
    L4.push_front(100);
    L4.push_front(200);
    L4.push_front(300);

    //反转
    L4.reverse();
    printList(L4);

    //排序
    //sort(L4.begin(), L4.end()); //所有不支持随机访问的迭代器的容器，不可以使用系统提供的公共算法
    //不支持随机访问的容器，内部会提供响应算法
    L4.sort();
    printList(L4);

    //从大到小排序
    L4.sort(myCompare);
    printList(L4);
}

//对于自定义数据类型 如何排序
class Person
{
public:
    Person(string name, int age, int height)
    {
        this->mName = name;
        this->mAge = age;
        this->mHeight = height;
    }
    //重载 == 运算符
    bool operator== (const Person& p)
    {
        if (this->mAge == p.mAge && this->mName == p.mName && this->mHeight == p.mHeight)
        {
            return true;
        }
        return false;
    }

    string mName;
    int mAge;
    int mHeight; // 身高
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
void test05()
{
    list<Person> L;

    Person p1("亚瑟", 18, 180);
    Person p2("妲己", 20, 160);
    Person p3("干将", 80, 175);
    Person p4("东皇太一", 70, 170);
    Person p5("赵云", 130, 20);
    Person p6("孙悟空", 130, 10);
    Person p7("阿斗", 130, 30);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);
    L.push_back(p7);

    //按照年龄 从小到大排序 ,如果年龄相同 身高按照 从大到小排序
    L.sort(myCompare2);

    //遍历
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名： " << it->mName << " 年龄：" << it->mAge << " 身高： " << it->mHeight << endl;
    }

    //删除东皇太一
    L.remove(p4);
    cout << endl;

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名： " << it->mName << " 年龄：" << it->mAge << " 身高： " << it->mHeight << endl;
    }
}

int main() {
    //test01();

    //test02();

    //test03();

    //test04();

    test05();

    system("pause");
    return EXIT_SUCCESS;
}