#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#if 1 /*��������*/
void test_map_value_comp();
void test_multimap6();
void test_multimap7();
void test_multimap8();
void test_multimap9();
#endif
using namespace std;
/*
 *ע�����
 *multimap��������m[4] = 40; ��ֵ
 *map������m[4] = 40; ��ֵ
 *
	�����ظ�Ԫ�ز��ᱨ�������ݲ�����ӵ�map������
	[]�÷�  �������֤ key���ڣ�������[]���з������ݣ����������һ�����ݵ�
	lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
 **/

void test_insert(map<int, int>& mp)
{
	// call insert(ValTy&&) version
	mp.insert(make_pair(2, 20));
	mp[5] = 50;
	// call insert(const value_type&) version
	mp.insert({ 1, 10 });
	mp.insert(map<int, int>::value_type(4, 40));
	mp.insert(pair<int, int>(3, 30));
	cout << "mp size:" << mp.size() << endl;
}
void test_empty(map<int, int>& mp)
{
	if (mp.empty())
	{
		cout << "mapΪ��" << endl;
	}
	else
	{
		cout << "map�ǿ�" << endl;
	}
}
void test_foreach(map<int, int>& mp)
{
	for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
	{
		cout << i->first << " : " << (*i).second << "--------------" << mp[i->first] << endl;
	}
	cout << endl;
}
void test_clear_erase(map<int, int>& mp)
{
	//mp.clear();//ɾ������Ԫ��
	//mp.erase(3); //ɾ��keyΪ3��Ԫ��
	//mp.erase(mp.begin());//ɾ����һ��Ԫ��
	mp.erase(mp.begin(), mp.end());//��ͷɾ��β
}
void test_find(map<int, int>& mp, int val)
{
	map<int, int>::iterator pos = mp.find(val);
	if (pos != mp.end())
	{
		cout << "�ҵ���  key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}
void test_cout(map<int, int>& mp)
{
	int num = mp.count(8);
	cout << num << endl;
	if (num)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "������" << endl;
	}
}
void test_bound(map<int, int>& m)
{
	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	map<int, int>::iterator it = m.lower_bound(3);
	if (it != m.end())
	{
		cout << "�ҵ� lower_bound key = " << (*it).first << " value = " << (*it).second << endl;
	}

	//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	map<int, int>::iterator it2 = m.upper_bound(3);
	if (it2 != m.end())
	{
		cout << "�ҵ� upper_bound key = " << (*it2).first << " value = " << (*it2).second << endl;
	}

	//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
	pair<map<int, int>::iterator, map<int, int>::iterator> it3 = m.equal_range(3);
	if (it3.first != m.end())
	{
		cout << "�ҵ� equal_range�е�lower_bound key =  " << it3.first->first << " value = " << it3.first->second << endl;
	}

	if (it3.second != m.end())
	{
		cout << "�ҵ� equal_range�е�upper_bound key =  " << it3.second->first << " value = " << it3.second->second << endl;
	}
}

namespace Multimap_Sample
{
	enum
	{
		CAIWU, RENLI, YANFA
	};

	class Worker
	{
	public:
		string mName; //����
		int mMoney; //����
	};

	void createWorker(vector<Worker>& v)
	{
		string nameSeed = "ABCDE";
		for (int i = 0; i < 5; i++)
		{
			string name = "Ա��";
			name += nameSeed[i];

			Worker w;
			w.mName = name;
			w.mMoney = rand() % 10000 + 10000; // 10000 ~ 19999

											   //��Ա�����뵽������
			v.push_back(w);
		}
	}

	void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
	{
		for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
		{
			//����������ű��
			int departmentId = rand() % 3; // 0 1 2
			//��Ա�����뵽 m������
			m.insert(make_pair(departmentId, *it));
		}
	}

	void showGroup1(multimap<int, Worker>& m)
	{
		// 0  A  0  B   1 C   2 D  2 E ������

		multimap<int, Worker>::iterator cPos = m.find(CAIWU);
		multimap<int, Worker>::iterator rPos = m.find(RENLI);
		multimap<int, Worker>::iterator yPos = m.find(YANFA);

		int cNum = m.count(CAIWU);
		int rNum = m.count(RENLI);
		int yNum = m.count(YANFA);

		cout << "������Ա�����£�" << endl;
		for (int num = 0; cPos != m.end(), num < cNum; cPos++, num++)
		{
			cout << "������ " << cPos->second.mName << " ���ʣ� " << cPos->second.mMoney << endl;
		}
		cout << "-----------------------" << endl;

		cout << "��������Ա�����£�" << endl;
		for (int num = 0; rPos != m.end(), num < rNum; rPos++, num++)
		{
			cout << "������ " << rPos->second.mName << " ���ʣ� " << rPos->second.mMoney << endl;
		}
		cout << "-----------------------" << endl;

		cout << "�з�����Ա�����£�" << endl;
		for (int num = 0; yPos != m.end(), num < yNum; yPos++, num++)
		{
			cout << "������ " << yPos->second.mName << " ���ʣ� " << yPos->second.mMoney << endl;
		}
		cout << "-----------------------" << endl;
	}

	void showGroup2(multimap<int, Worker>& m)
	{
		multimap<int, Worker>::iterator cPos = m.find(CAIWU);
		multimap<int, Worker>::iterator rPos = m.find(RENLI);
		multimap<int, Worker>::iterator yPos = m.find(YANFA);
		int cNum = m.count(CAIWU);
		int rNum = m.count(RENLI);
		int yNum = m.count(YANFA);

		cout << "������Ա�����£�" << endl;
		while (cPos != m.end() && cNum)
		{
			cout << "������ " << cPos->second.mName << " ���ʣ� " << cPos->second.mMoney << endl;
			cPos++;
			cNum--;
		}
		cout << "-----------------------" << endl;

		cout << "��������Ա�����£�" << endl;
		while (rPos != m.end() && rNum)
		{
			cout << "������ " << rPos->second.mName << " ���ʣ� " << rPos->second.mMoney << endl;
			rPos++;
			rNum--;
		}
		cout << "-----------------------" << endl;

		cout << "�з�����Ա�����£�" << endl;
		while (yPos != m.end() && yNum)
		{
			cout << "������ " << yPos->second.mName << " ���ʣ� " << yPos->second.mMoney << endl;
			yPos++;
			yNum--;
		}
		cout << "-----------------------" << endl;
	}

	int main()
	{
		//����Ա��
		vector<Worker>v;
		createWorker(v);

		//��Ա�����뵽����������
		//����multimap ��Ų��� �Լ���Ӧ����Ա
		multimap<int, Worker> m;
		setGroup(v, m);

		//�ֲ�����ʾԱ��
		showGroup1(m);
		showGroup2(m);

		//��������
		/*for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
		{
		cout << "������ " << it->mName << " ���ʣ� " << it->mMoney << endl;
		}*/

		system("pause");
		return EXIT_SUCCESS;
	}
}

template <typename T> void print_collection(const T& t)
{
	cout << t.size() << " elements: ";

	for (const auto& p : t)
	{
		print_elem(p);
	}
	cout << endl;
}

template <typename C, class T> void findit(const C& c, T val)
{
	cout << "Trying find() on value " << val << endl;
	auto result = c.find(val);
	if (result != c.end())
	{
		cout << "Element found: "; print_elem(*result); cout << endl;
	}
	else
	{
		cout << "Element not found." << endl;
	}
}

void test_multimap1()
{
	multimap<int, string> m1({ { 40, "Zr" },{ 45, "Rh" } });
	cout << "The starting multimap m1 is (key, value):" << endl;
	print_collection(m1);

	vector<pair<int, string>> v;
	v.push_back(make_pair(43, "Tc"));
	v.push_back(make_pair(41, "Nb"));
	v.push_back(make_pair(46, "Pd"));
	v.push_back(make_pair(42, "Mo"));
	v.push_back(make_pair(44, "Ru"));
	v.push_back(make_pair(44, "Ru")); // attempt a duplicate

	cout << "Inserting the following vector data into m1:" << endl;
	print_collection(v);

	m1.insert(v.begin(), v.end());

	cout << "The modified multimap m1 is (key, value):" << endl;
	print_collection(m1);
	cout << endl;
	findit(m1, 45);
	findit(m1, 6);
}

template <typename M> void print(const M& m)
{
	cout << m.size() << " elements: ";

	for (const auto& p : m)
	{
		cout << "(" << p.first << ", " << p.second << ") ";
	}

	cout << endl;
}

void test_multimap2()
{
	// insert single values
	multimap<int, int> m1;
	// call insert(const value_type&) version
	m1.insert({ 1, 10 });
	// call insert(ValTy&&) version
	m1.insert(make_pair(2, 20));

	cout << "The original key and mapped values of m1 are:" << endl;
	print(m1);

	// intentionally attempt a duplicate, single element
	m1.insert(make_pair(1, 111));

	cout << "The modified key and mapped values of m1 are:" << endl;
	print(m1);

	// single element, with hint
	m1.insert(m1.end(), make_pair(3, 30));
	cout << "The modified key and mapped values of m1 are:" << endl;
	print(m1);
	cout << endl;

	// The templatized version inserting a jumbled range
	multimap<int, int> m2;
	vector<pair<int, int>> v;
	v.push_back(make_pair(43, 294));
	v.push_back(make_pair(41, 262));
	v.push_back(make_pair(45, 330));
	v.push_back(make_pair(42, 277));
	v.push_back(make_pair(44, 311));

	cout << "Inserting the following vector data into m2:" << endl;
	print(v);

	m2.insert(v.begin(), v.end());

	cout << "The modified key and mapped values of m2 are:" << endl;
	print(m2);
	cout << endl;

	// The templatized versions move-constructing elements
	multimap<int, string>  m3;
	pair<int, string> ip1(475, "blue"), ip2(510, "green");

	// single element
	m3.insert(move(ip1));
	cout << "After the first move insertion, m3 contains:" << endl;
	print(m3);

	// single element with hint
	m3.insert(m3.end(), move(ip2));
	cout << "After the second move insertion, m3 contains:" << endl;
	print(m3);
	cout << endl;

	multimap<int, int> m4;
	// Insert the elements from an initializer_list
	m4.insert({ { 4, 44 },{ 2, 22 },{ 3, 33 },{ 1, 11 },{ 5, 55 } });
	cout << "After initializer_list insertion, m4 contains:" << endl;
	print(m4);
	cout << endl;
}

template <typename A, typename B> void print_elem(const pair<A, B>& p)
{
	cout << "(" << p.first << ", " << p.second << ") ";
}

typedef pair<int, int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs)
{
	if (lhs.first == rhs.first)
	{
		return lhs.second < rhs.second;
	}
	else
	{
		return lhs.first > rhs.first;
	}
}

struct CmpByValue
{
	bool operator()(const PAIR& lhs, const PAIR& rhs)
	{
		if (lhs.first == rhs.first)
		{
			return lhs.second < rhs.second;
		}
		else
		{
			return lhs.first > rhs.first;
		}
	}
};

//ֻͨ��ֵ������
bool cmp_only_by_value(const PAIR& lhs, const PAIR& rhs)
{
	return lhs.second < rhs.second;
}

//map ����value����
void test_multimap3()
{
	multimap<int, int, less<int> >mulp;
	mulp.insert(make_pair(7, 6));
	mulp.insert(make_pair(3, 4));
	mulp.insert(make_pair(1, 2));
	mulp.insert(make_pair(3, 5));
	mulp.insert(make_pair(3, 1));
	mulp.insert(make_pair(4, 7));
	mulp.insert(make_pair(9, 10));
	mulp.insert(make_pair(11, 2));
	mulp.insert(make_pair(14, 6));
	mulp.insert(make_pair(4, 3));
	vector<PAIR> nsv(mulp.begin(), mulp.end());
	//sort(nsv.begin(), nsv.end(), CmpByValue());
	//sort(nsv.begin(), nsv.end(), cmp_by_value);
	sort(nsv.begin(), nsv.end(), cmp_only_by_value);
	for (int i = 0; i != nsv.size(); ++i)
	{
		cout << nsv[i].first << "    " << nsv[i].second << endl;
	}
}

struct cmp
{
	bool operator() (const string& str1, const string& str2)
	{
		return str1.length() < str2.length();
	}
};

void test_multimap4()
{
	multimap<string, int, cmp>mp;
	mp.insert(make_pair("�й�������", 2));
	mp.insert(make_pair("�й�", 1));
	mp.insert(make_pair("�л����񹲺͹�", 4));
	mp.insert(make_pair("�л�����", 3));
	mp.insert(make_pair("�й���", 5));
	cout << "����key�ĳ�������" << endl;
	for (map<string, int, cmp>::iterator iter = mp.begin(); iter != mp.end(); iter++)
	{
		cout << iter->first << "  " << iter->second << endl;
	}
}

class myCompareMap
{
public:
	bool operator()(const int& v1, const int& v2)const
	{
		return v1 > v2;
	}
};

void test_multimap5()
{
	multimap<int, int, myCompareMap> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	//m[4] = 40; //multimap�������ô˷�ʽ��ֵ
	//����key���Ӵ�С
	for (map<int, int, myCompareMap>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

struct cstrcmp_less
{
	bool operator () (const char* a, const char* b)
	{
		return strcmp(a, b) == -1 ? 1 : 0;
	}
};

void test_multimap6()
{
	multimap<const char*, const char*, cstrcmp_less> xx;
	xx.insert(make_pair("12", "22"));
	xx.insert(make_pair("23", "22"));
	xx.insert(make_pair("14", "22"));
	xx.insert(make_pair("11", "22"));

	for (multimap<const char*, const char*>::iterator it = xx.begin(); it != xx.end(); ++it)
		cout << it->first << endl;
}
/*
	C++ STL�б�׼��������set, multiset, map, multimap�ڲ����õľ���һ�ַǳ���Ч��ƽ��������������������Ҳ��ΪRB��(Red-Black Tree)��
	map��set��������֮ʱ�ͻ��Զ��ź���֮ǰʹ��map�����ð�value������鷳��Ҫ��һ��multimap��ԭmap���ô洢��
	���ֻ��һ��mapʵ��value�������أ���key �� value��һ���ṹ�壬�ٽ��ṹ����Ϊkey��һ��map��
	������ȻҪд�ȽϺ������������ν���أ�֮ǰûȥ��map����map<T1, T2>ʱ��
	��ʵ���и�Ĭ�ϵıȽϺ��� map<T1, T2, less<T1>> ,����key���������У�
	���ǿ�����д�ȽϺ�����ʵ��������Ҫ������(value)������string��key, int��value;
	*/

struct Data
{
	string s;
	int n;
};
class KeyCompA
{
public:
	bool operator()(const Data& a1, const Data& a2) const
	{
		return (a1.n < a2.n || (a1.n == a2.n && a1.s < a2.s));
	}
};
void test_multimap7()
{
	map<Data, int, KeyCompA> m;
	Data d1 = { "123",1 };
	Data d2 = { "234",2 };
	Data d3 = { "789",7 };
	Data d4 = { "890",8 };
	Data d5 = { "345",3 };
	Data d6 = { "234",2 };
	Data d7 = { "678",6 };
	Data d8 = { "567",5 };
	m.insert(make_pair(d1, 1));
	m.insert(make_pair(d2, 2));
	m.insert(make_pair(d3, 7));
	m.insert(make_pair(d4, 8));
	m.insert(make_pair(d5, 3));
	m.insert(make_pair(d6, 2));
	m.insert(make_pair(d7, 6));
	m.insert(make_pair(d8, 5));
	//Data rec;
	//while (cin >> rec.s >> rec.n)
	//{
	//    m[rec]++;
	//}
	for (map<Data, int, KeyCompA>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first.s << " " << it->first.n << " " << it->second;
		cout << endl;
	}
}

struct B
{
	string s;
	int n;
};
class KeyCompB
{
public:
	bool operator()(const B& a1, const B& a2) const
	{
		return (a1.n < a2.n || (a1.n == a2.n && a1.s < a2.s));
	}
};
void test_multimap8()
{
	map<B, int, KeyCompB> m;

	B d1 = { "123",1 };
	B d2 = { "234",2 };
	B d3 = { "789",7 };
	B d4 = { "890",8 };
	B d5 = { "345",3 };
	B d6 = { "234",2 };
	B d7 = { "678",6 };
	B d8 = { "567",5 };

	m.insert(make_pair(d1, 1));
	m.insert(make_pair(d2, 2));
	m.insert(make_pair(d3, 7));
	m.insert(make_pair(d4, 8));
	m.insert(make_pair(d5, 3));
	m.insert(make_pair(d6, 2));
	m.insert(make_pair(d7, 6));
	m.insert(make_pair(d8, 5));
	/*  B rec;
	  while (cin >> rec.s >> rec.n)
	  {
		  m[rec]++;
	  }*/
	for (map<B, int, KeyCompB>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first.s << " " << it->first.n << " " << it->second;
		cout << endl;
	}
}

void test_multimap9()
{
	multimap <int, int, less<int> > m1;
	multimap <int, int, less<int> >::key_compare kc1 = m1.key_comp();
	bool result1 = kc1(2, 3);
	if (result1 == true)
	{
		cout << "kc1( 2,3 ) returns value of true, " << "where kc1 is the function object of m1." << endl;
	}
	else
	{
		cout << "kc1( 2,3 ) returns value of false " << "where kc1 is the function object of m1." << endl;
	}
	multimap <int, int, greater<int>> m2;
	multimap <int, int, greater<int>>::key_compare kc2 = m2.key_comp();
	bool result2 = kc2(2, 3);
	if (result2 == true)
	{
		cout << "kc2( 2,3 ) returns value of true, " << "where kc2 is the function object of m2." << endl;
	}
	else
	{
		cout << "kc2( 2,3 ) returns value of false, " << "where kc2 is the function object of m2." << endl;
	}
}
/*
��ӳ�������ȫ��Ԫ��֮�� value_types �� value_compare �ṩ�ıȽ��������ڵ���Ԫ�صļ�֮���һ�ֱȽϻᵼ�¸������๹�졣
��Ա������ value_compare ������ṩ�ĺ�������ʹ�ö���洢�� key_compare ���� ��� �Ƚ���Ԫ�� SORT �������

�������úͶ༯���Ǽ������ļ�ֵ��ֵԪ����ͬ�� value_compare ��Ч�� key_compare;
����ӳ��� multimaps û�У���Ϊ pair ����Ԫ�ص�ֵ��Ԫ�صļ���ֵ����ͬ��

ʾ��

template<class value_type>
class value_compare : public binary_function<value_type, value_type, bool>
{
public:
bool operator()(const value_type& _Left, const value_type& _Right) const;
value_compare(key_compare _Pred) : comp(_Pred);
protected:
key_compare comp;
};

value_compare value_comp( ) const;
value_compare value_comp( ) const;

����ֵ
--------------------------------------------------------------------------------

����ӳ��ʹ�ö���Ԫ�ؽ��бȽϺ�������

��ע
--------------------------------------------------------------------------------

����ӳ�� m���������Ԫ�� e1( k1, d1) �� e2( k2, d2) ���͵Ķ��� value_type, where k1 and k2 �����Լ��ļ� key_type and d1 and d2 ���͵����ݣ� mapped_type, then m. value_comp( e1, e2) ��Ч�� m. key_comp (k1, k2)�� һ���洢�Ķ����Ա��������

bool operator value_type&  value_type& (_Left��_Right);

���߷��� true������ؼ� _Left ֵǰ�沢���ֵ�����������˳��� _Right��

*/

void test_map_value_comp()
{
	map <int, int, less<int> > m1;

	map <int, int, less<int> >::value_compare vc1 = m1.value_comp();
	pair< map<int, int>::iterator, bool > pr1, pr2;

	pr1 = m1.insert(make_pair(1, 10));
	pr2 = m1.insert(make_pair(2, 5));

	//pr1 = m1.insert(map <int, int> ::value_type(1, 10));
	//pr2 = m1.insert(map <int, int> ::value_type(2, 5));

	auto a = *pr1.first;

	if (vc1(*pr1.first, *pr2.first) == true)
	{
		cout << "The element ( 1,10 ) precedes the element ( 2,5 )." << endl;
	}
	else
	{
		cout << "The element ( 1,10 ) does not precede the element ( 2,5 )." << endl;
	}

	if (vc1(*pr2.first, *pr1.first) == true)
	{
		cout << "The element ( 2,5 ) precedes the element ( 1,10 )." << endl;
	}
	else
	{
		cout << "The element ( 2,5 ) does not precede the element ( 1,10 )." << endl;
	}
}
int main()
{
	test_map_value_comp();
	system("pause");
	return 0;
}