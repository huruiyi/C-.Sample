#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

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
void myPrint(int a);

void test01()
{
	//vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int> v;
	v.push_back(1);
	v.push_back(7);
	v.push_back(6);
	v.push_back(9);
	v.push_back(10);
	v.push_back(8);

	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();

	//while (itBegin != itEnd)
	//{
	//    cout << *itBegin << endl;
	//    itBegin++;
	//}
	/*
	*itBegin 指的是尖括号中的内容
	*/
	//for (vector<int>::iterator itBegin = v.begin(); itBegin < v.end(); itBegin++)
	//{
	//    cout << *itBegin << endl;
	//}

	//for_each(v.begin(), v.end(), [] (int a){cout << a << endl; });

	for_each(v.begin(), v.end(), myPrint);
}

void myPrint(int a)
{
	cout << a << endl;
}

void test02()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	Person p6("fff", 60);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	for (vector<Person>::iterator itBegin = v.begin(); itBegin < v.end(); itBegin++)
	{
		cout << (*itBegin).mName << endl;
	}

	for_each(v.begin(), v.end(), [](Person a) {cout << a.mName << "  " << a.mAge << endl; });
}

void test03()
{
	vector<Person *> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	Person p6("fff", 60);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);

	for (vector<Person *>::iterator itBegin = v.begin(); itBegin < v.end(); itBegin++)
	{
		cout << (*itBegin)->mName << (*itBegin)->mAge << endl;
	}

	for_each(v.begin(), v.end(), [](Person * a) {cout << (*a).mName << "  " << (*a).mAge << endl; });
}

void test04()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 10);
		v2.push_back(i + 20);
		v3.push_back(i + 30);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator pi = v.begin(); pi < v.end(); pi++)
	{
		vector<int> vItem = *pi;
		for (vector<int>::iterator pj = vItem.begin(); pj < vItem.end(); pj++)
		{
			cout << *pj << "\t";
		}
		cout << endl;
	}

	for_each(v.begin(), v.end(), [](vector<int> vItem)
	{
		for (vector<int>::iterator pj = vItem.begin(); pj < vItem.end(); pj++)
		{
			cout << *pj << "\t";
		}
		cout << endl;
	});
}

void test05()
{
	using namespace std;
	vector <int> v1;
	vector <int>::iterator Iter;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	for_each(v1.begin(), v1.end(), [](int a) {cout << " " << a; });
	cout << endl;

	//v1.insert(v1.begin() + 1, 40);//第一个位置添加40
	//for_each(v1.begin(), v1.end(), [](int a) {cout << " " << a; });
	//cout << endl;

	//v1.insert(v1.begin() + 2, 4, 50);//第二个位置起添加啊4个50
	//for_each(v1.begin(), v1.end(), [](int a) {cout << " " << a; });
	//cout << endl;

	v1.insert(v1.begin() + 1, v1.begin() + 2, v1.begin() + 4);
	for_each(v1.begin(), v1.end(), [](int a) {cout << " " << a; });
	cout << endl;

	//// initialize a vector of vectors by moving v1
	//vector < vector <int> > vv1;

	//vv1.insert(vv1.begin(), move(v1));
	//if (vv1.size() != 0 && vv1[0].size() != 0)
	//{
	//    vector < vector <int> >::iterator Iter;
	//    cout << "vv1[0] =";
	//    for (Iter = vv1[0].begin(); Iter != vv1[0].end(); Iter++)
	//        cout << " " << *Iter;
	//    cout << endl;
	//}
}

void test06()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	if (v.empty())
	{
		cout << "为空" << endl;
	}

	//v.resize(10);
	v.resize(10, 50);// 扩充容器空间以50进行填充
	for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
	cout << endl;
}

void test07()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);

	//v.erase(v.begin()); //删除第一个元素
	//for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
	//cout << endl;

	//v.erase(v.begin(), v.end());//全部删除
	//for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
	//cout << endl;

	v.erase(v.begin() + 1, v.begin() + 3); //从第1个元素删除两个元素
	for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });//10,40,50,60,70
	cout << endl;

	//v.erase(v.begin() + 3, v.end()); //从第三个元素开始删除到尾
	//for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; }); // 10,20,30
	//cout << endl;
	//

	v.clear(); //清除数据
	for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
	cout << endl;
}

void test08()
{
	vector<int> v1 = { 1,2,3,4,5,6 };
	vector<int> v2 = { 5,6,7,8,9 };
	for_each(v1.begin(), v1.end(), [](int a) {cout << a << "\t"; });
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << "\t"; });
	cout << endl;
	v1.swap(v2);//vector交换
	for_each(v1.begin(), v1.end(), [](int a) {cout << a << "\t"; });
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int a) {cout << a << "\t"; });
	cout << endl;
}

void test09()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	v.resize(10);

	cout << v.capacity() << endl;
	cout << v.size() << endl;

	//内存空间收缩

	vector<int> v2 = vector<int>(v);
	cout << "v2.capacity：" << v2.capacity() << endl;
	cout << "v2.size：" << v2.size() << endl;

	vector<int>(v).swap(v);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}

void test10()
{
	vector<int> v;

	//预留空间
	v.reserve(100000);

	int *p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << num << endl;
}

void test11()
{
	vector<int> v = { 1,2,3,4,5,6 };
	cout << v[0] << endl;

	for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
	cout << endl;

	for (vector<int>::iterator itBegin = v.begin(); itBegin < v.end(); itBegin++)
	{
		cout << *itBegin << "\t";
	}
	cout << endl;

	for (vector<int>::reverse_iterator itBegin = v.rbegin(); itBegin < v.rend(); itBegin++)
	{
		cout << *itBegin << "\t";
	}
	cout << endl;
}

struct Sum {
	Sum() { sum = 0; }
	void operator()(int n) { sum += n; }

	int sum;
};
void test_foreach()
{
	vector<int> nums{ 3, 4, 2, 9, 15, 267 };

	cout << "before: ";
	for (auto n : nums) {
		cout << n << " ";
	}
	cout << '\n';

	for_each(nums.begin(), nums.end(), [](int &n) { n++; });
	Sum s = for_each(nums.begin(), nums.end(), Sum());

	cout << "after:  ";
	for (auto n : nums) {
		cout << n << " ";
	}
	cout << '\n';
	cout << "sum: " << s.sum << '\n';
}
int main()
{
	test_foreach();

	system("pause");
	return 0;
}