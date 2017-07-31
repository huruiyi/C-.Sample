#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <ctime>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->mName = name;
		mScore = score;
	}

	string mName; //姓名
	int mScore; //平均分
};

void printDeque(const deque<int> d)
{
	for (deque<int>::const_iterator i = d.begin(); i < d.end(); i++)
	{
		cout << *i << "\t";
		//*i = 123;  值不可以修改
	}
	cout << endl;
}
void test01()
{
	deque<int> d{ 1,2,3,4,5 };
	d.push_back(6);
	d.push_back(7);
	printDeque(d);

	cout << d.front() << endl;
	cout << d.back() << endl;
	d.pop_front();
	d.pop_back();

	printDeque(d);

	//清空deque
	//d.clear();

	//新增
	d.insert(d.begin(), 11);
	printDeque(d);

	//删除
	d.erase(d.begin() + 2);

	printDeque(d);
}

void test04()
{
	Person p1("A", 50);
	Person p2("B", 90);
	Person p3("C", 75);
	Person p4("D", 88);
	Person p5("E", 60);
	Person p6("F", 68);
	Person p7("G", 102);
	Person p8("H", 91);
	Person p9("I", 78);
	Person p10("J", 63);

	vector<Person> vp = { p1,p2,p3,p4,p5 };
	vp.push_back(p6);
	vp.push_back(p7);
	vp.push_back(p8);
	vp.push_back(p9);
	vp.push_back(p10);

	deque<Person> de;
	for (vector<Person>::iterator i = vp.begin(); i < vp.end(); i++)
	{
		de.push_back(*i);
	}
	//deque<Person> de = { p1 ,p2,p3,p4,p5,p6 };
	cout << "排序前：....................." << endl;
	for_each(de.begin(), de.end(), [](Person p) {cout << p.mName << " " << p.mScore << endl; });
	cout << "排序后：....................." << endl;
	sort(de.begin(), de.end(), [](Person p1, Person p2) {return p1.mScore > p2.mScore; });
	de.pop_front();
	de.pop_back();
	for_each(de.begin(), de.end(), [](Person p) {cout << p.mName << " " << p.mScore << endl; });

	int sumSocore = 0;
	for (deque<Person>::iterator i = de.begin(); i < de.end(); i++)
	{
		sumSocore += (*i).mScore;
	}

	cout << "平均分：" << sumSocore / de.size() << endl;
}

/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/

void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//10评委打分 分数存到deque
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~ 100
			d.push_back(score);
		}
		//看下评委的打分
		//for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//排序
		sort(d.begin(), d.end());
		//取出最高 最低分
		d.pop_back(); // 最高分数
		d.pop_front(); //最低分数

					   //求总分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//求平均分
		int avg = sum / d.size();

		(*it).mScore = avg;
	}
}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it).mName << " 分数： " << (*it).mScore << endl;
	}
}

void test05()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//创建五名选手
	vector<Person>v;// 存放选手的容器

	createPerson(v);

	//打分
	setScore(v);

	//显示平均分
	showScore(v);

	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << "姓名：" << (*it).mName << " 分数： " << it->mScore << endl;
	//}
}
int main()
{
	test01();
	system("pause");
	return 0;
}