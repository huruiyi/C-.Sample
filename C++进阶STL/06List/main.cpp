#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
/*
 1:��֧���������
	//list<int>::const_iterator itx;
	//itx + 2;//��֧���������
 2:�Զ���Ԫ�ز���ֱ��remove,Ҫ���غ�ſ���
 3:Ԫ�ؿ��ظ�����
 4:ɾ��Ԫ�ػ�ɾ����������������ֵ
 */

void test_foreach(const list<int>& L)
{
	//list<int>::const_iterator itx;
	//itx + 2;//��֧���������
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test_foreach_reverse(const list<int>& L)
{
	//const���β��ܸı�list
   //L.reverse();

	//for (list<int>::const_reverse_iterator i = L.rbegin(); i < L.rend(); i++)//����
	for (list<int>::const_reverse_iterator i = L.rbegin(); i != L.rend(); i++)
	{
		cout << *i << " ";
	}
	//cout << endl;
}
void test_empty_size_resize(list<int>& L)
{
	if (L.empty())
	{
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "��Ϊ��  L4 ��С�� " << L.size() << endl;
	}

	L.resize(10);
	L.resize(10, 100);
}
void test_init_Insert(list<int>& L)
{
	/*
		list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
		list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
		list(n,elem);//���캯����n��elem����������
		list(const list &lst);//�������캯����
	*/
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

	//remove ɾ��������������elemֵƥ���Ԫ��
	L4.remove(10);
	/*
		insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
		insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
		insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
	 */
	L4.insert(L.begin(), 1000);
	L4.insert(L.begin(), 5, 10);
}
void test_front_front(list<int>& L)
{
	cout << "��һ��Ԫ�أ�" << L.front() << " ���һ��Ԫ�أ� " << L.back() << endl;
	L.pop_back();//βɾ
	L.pop_front();//ͷɾ
	L.push_front(90);
	L.push_back(110);
}
void test_erase(list<int>& L)
{
	/*
		erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
		erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
*/
	L.erase(L.begin());
	L.erase(L.begin(), L.end());
}

bool CompareIntList(const int v1, const int v2)
{
	//�Ӵ�С
	return v1 > v2;
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

	//li.sort();//Ĭ�ϴ�С����
	//li.sort([](int a, int b) {return a < b; });//��С����
	//li.sort([](int a, int b) {return a > b; });//�Ӵ���
	li.sort(CompareIntList);
	test_foreach(li);

	for_each(li.begin(), li.end(), [](int a) {cout << a << endl; });

	cout << "�Ƴ�12ǰ��С" << li.size() << endl;
	li.remove(12);
	cout << "�Ƴ�12���С" << li.size() << endl;

	//����
	//sort(li.begin(), li.end()); //���в�֧��������ʵĵ�������������������ʹ��ϵͳ�ṩ�Ĺ����㷨
	//��֧��������ʵ��������ڲ����ṩ��Ӧ�㷨
	li.sort();
}

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
		if (p.mName == this->mName && p.mAge == this->mAge)
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
class Cmpare
{
public:
	bool operator()(const Person p1, const Person  p2) const
	{
		return p1.mAge < p2.mAge;
	}
};
//�����Զ����������ͣ�����ָ���������
bool ComparePerson(Person& p1, Person& p2)
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
void test02()
{
	list<Person> lip;
	Person p1("A", 20, 178);
	Person p2("B", 29, 160);
	Person p3("C", 25, 156);
	Person p4("D", 22, 138);
	Person p5("E", 27, 169);
	Person p6("F", 21, 159);
	Person p7("F", 25, 155);
	lip.push_back(p1);
	lip.push_back(p2);
	lip.push_back(p3);
	lip.push_back(p4);
	lip.push_back(p5);
	lip.push_back(p6);
	lip.push_back(p7);

	//�Զ�������������Ҫ���ء�==�������������remove
	lip.remove(p4);

	lip.sort(Cmpare()); //�Զ������Ͳ�֧������
	lip.sort(ComparePerson);

	//lip.sort([](Person p1, Person p2) {return p1.mAge > p2.mAge; });
	for_each(lip.begin(), lip.end(), [](Person p)
	{
		cout << "name��" << p.mName << "��ag��" << p.mAge << endl;
	});
}

int main()
{
	test02();
	system("pause");
	return 0;
}

/*
3.6.4.3 list��С����
resize(num);//����ָ�������ĳ���Ϊnum��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);//����ָ�������ĳ���Ϊnum��
�������䳤������elemֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

3.6.4.4 list��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
list& operator=(const list &lst);//���صȺŲ�����
swap(lst);//��lst�뱾���Ԫ�ػ�����

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
	//˫��ѭ������
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