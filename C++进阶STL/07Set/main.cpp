#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;
/*
 *set
1 ��Ԫ�ػ��Զ�ȥ��
2������ظ�Ԫ�ر��벻������������ӳɹ�
3��Ĭ�ϴ�С�������򣬣��÷º��� ָ��������򣩿����شӴ�С����
multiset
1:Ԫ�ز���ȥ��
 */
void test01()
{
	pair<string, int> p1("����1", 19);
	pair<string, int> p2("����2", 25);
	cout << p1.first << p1.second << endl;
	cout << p2.first << p2.second << endl;
	p1.swap(p2);
	cout << p1.first << p1.second << endl;
	cout << p2.first << p2.second << endl;
}

void test_insert(set<int> &s1)
{
	pair< set<int>::iterator, bool > ret = s1.insert(10);
	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}

	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}

	multiset<int>s2; //�ɹ� ���Բ����ظ���keyֵ
	s2.insert(10);
	s2.insert(10);
}
void test_count(set<int> & se, int delVal)
{
	//����  count ����set���� Ҫô0 Ҫô1
	int num = se.count(delVal);
	cout << delVal << "�ĸ���Ϊ��" << num << endl;
	cout << (num ? "���ҵ�" : "δ���ҵ�") << endl;
}

void test_empty_size(set<int> & se)
{
	if (se.empty())
	{
		cout << "seΪ��" << endl;
	}
	else
	{
		cout << "size = " << se.size() << endl;
	}
}

void test_foreach(const set<int> & se)
{
	for (set<int>::iterator i = se.begin(); i != se.end(); i++)
	{
		cout << *i << "\t";
	}
	cout << endl;
}

void test_foreach(set<int> & se)
{
	for (set<int>::iterator i = se.begin(); i != se.end(); i++)
	{
		cout << *i << "\t";
	}
	cout << endl;
}

void test_bound(set<int> & s1)
{
	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	set<int>::iterator it = s1.lower_bound(30);
	if (it != s1.end())
	{
		cout << "�ҵ���lower_bound��ֵ" << *it << endl;
	}

	//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	set<int>::iterator it2 = s1.upper_bound(30);
	if (it2 != s1.end())
	{
		cout << "�ҵ���upper_bound��ֵ" << *it2 << endl;
	}

	//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
	pair<set<int>::iterator, set<int>::iterator> it3 = s1.equal_range(30);
	if (it3.first != s1.end())
	{
		cout << "�ҵ�equal_range��lower_bound��ֵ��" << *(it3.first) << endl;
	}

	if (it3.second != s1.end())
	{
		cout << "�ҵ�equal_range��upper_bound��ֵ��" << *(it3.second) << endl;
	}
}

void test_find(set<int> & se, int val)
{
	set<int>::iterator pos = se.find(val);
	if (pos != se.end())
	{
		cout << "�ҵ���ֵ Ϊ��" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

void test_clear_erase(set<int> & se)
{
	//se.clear();//ɾ������Ԫ��
	se.erase(se.begin());//ɾ����һ��Ԫ��
	se.erase(5); //ɾ�����е��ڵ�Ԫ��
	se.erase(se.begin(), se.end());//ɾ������
}

void test02()
{
	set<int> se;
	se.insert(2);
	se.insert(5);
	se.insert(6);
	se.insert(1);
	se.insert(3);
	se.insert(15);
	se.insert(9);
	se.insert(5);
	se.insert(11);
	se.insert(8);
	se.insert(11);
	se.insert(19);
	se.insert(16);

	test_foreach(se);
}

class myCompare
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
void test03()
{
	set<int, myCompare> s;
	s.insert(2);
	s.insert(7);
	s.insert(1);
	s.insert(6);
	for (set<int, myCompare>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << *i << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->mName = name;
		this->mAge = age;
	}
public:
	string mName;
	int mAge;
};
class myPersonCompare
{
public:
	bool operator()(const Person &p1, const Person &p2) const
	{
		return p1.mAge > p2.mAge;
	}
};
void test04()
{
	set<Person, myPersonCompare> sp;
	Person p4("үү", 50);
	Person p2("����", 10);
	Person p3("����", 6);
	Person p1("����", 20);

	sp = { p1,p2,p3 };
	sp.insert(p4);

	for (set<Person, myPersonCompare>::iterator i = sp.begin(); i != sp.end(); i++)
	{
		cout << i->mName << "   " << (*i).mAge << endl;
	}
}

template <typename T> void print_elem(const T& t) {
	cout << "(" << t << ") ";
}

template <typename T> void print_collection(const T& t) {
	cout << t.size() << " elements: ";

	for (const auto& p : t)
	{
		print_elem(p);
	}
	cout << endl;
}

template <typename C, class T> void findit(const C& c, T val) {
	cout << "Trying find() on value " << val << endl;
	auto result = c.find(val);
	if (result != c.end()) {
		cout << "Element found: "; print_elem(*result); cout << endl;
	}
	else {
		cout << "Element not found." << endl;
	}
}

void test_multiset1()
{
	multiset<int> s1({ 40, 45 });
	cout << "The starting multiset s1 is: " << endl;
	print_collection(s1);

	vector<int> v;
	v.push_back(43);
	v.push_back(41);
	v.push_back(46);
	v.push_back(42);
	v.push_back(44);
	v.push_back(44); // attempt a duplicate

	cout << "Inserting the following vector data into s1: " << endl;
	print_collection(v);

	s1.insert(v.begin(), v.end());

	cout << "The modified multiset s1 is: " << endl;
	print_collection(s1);
	cout << endl;
	findit(s1, 45);
	findit(s1, 6);
}

template <typename S> void print(const S& s)
{
	cout << s.size() << " elements: ";

	for (const auto& p : s)
	{
		cout << "(" << p << ") ";
	}

	cout << endl;
}

void test_multiset2()
{
	// insert single values
	multiset<int> s1;
	// call insert(const value_type&) version
	s1.insert({ 1, 10 });
	// call insert(ValTy&&) version
	s1.insert(20);

	cout << "The original multiset values of s1 are:" << endl;
	print(s1);

	// intentionally attempt a duplicate, single element
	s1.insert(1);
	cout << "The modified multiset values of s1 are:" << endl;
	print(s1);
	cout << endl;

	// single element, with hint
	s1.insert(s1.end(), 30);
	cout << "The modified multiset values of s1 are:" << endl;
	print(s1);
	cout << endl;

	// The templatized version inserting a jumbled range
	multiset<int> s2;
	vector<int> v;
	v.push_back(43);
	v.push_back(294);
	v.push_back(41);
	v.push_back(330);
	v.push_back(42);
	v.push_back(45);

	cout << "Inserting the following vector data into s2:" << endl;
	print(v);

	s2.insert(v.begin(), v.end());

	cout << "The modified multiset values of s2 are:" << endl;
	print(s2);
	cout << endl;

	// The templatized versions move-constructing elements
	multiset<string>  s3;
	string str1("blue"), str2("green");

	// single element
	s3.insert(move(str1));
	cout << "After the first move insertion, s3 contains:" << endl;
	print(s3);

	// single element with hint
	s3.insert(s3.end(), move(str2));
	cout << "After the second move insertion, s3 contains:" << endl;
	print(s3);
	cout << endl;

	multiset<int> s4;
	// Insert the elements from an initializer_list
	s4.insert({ 4, 44, 2, 22, 3, 33, 1, 11, 5, 55 });
	cout << "After initializer_list insertion, s4 contains:" << endl;
	print(s4);
	cout << endl;
}

void test_multiset3()
{
	multiset<int> mset{ 1,2,3,7,8,7,3,5,5,4,7,4,4,5,6,6,6,7,7,8,5,8,9,10 };

	multiset<int>::iterator i = mset.find(7);
	cout << "Ĭ�ϲ��ҵ�һ����" << *i << endl;
	int fiveCount = mset.count(7);
	while (i != mset.end() && fiveCount)
	{
		cout << *i << endl;
		i++;
		fiveCount--;
	}

	cout << "equal_range���ҽ����" << endl;
	auto it = mset.equal_range(7);
	cout << typeid(it).name() << endl;//����ֵ��pair
	for (auto i = it.first; i != it.second; i++)//pair first��ʼ�㣬secontd�����յ�
	{
		cout << *i << endl;
	}
}

int main()
{
	test_multiset3();
	system("pause");
	return 0;
}