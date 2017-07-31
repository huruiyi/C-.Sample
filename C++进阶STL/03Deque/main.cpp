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

	string mName; //����
	int mScore; //ƽ����
};

void printDeque(const deque<int> d)
{
	for (deque<int>::const_iterator i = d.begin(); i < d.end(); i++)
	{
		cout << *i << "\t";
		//*i = 123;  ֵ�������޸�
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

	//���deque
	//d.clear();

	//����
	d.insert(d.begin(), 11);
	printDeque(d);

	//ɾ��
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
	cout << "����ǰ��....................." << endl;
	for_each(de.begin(), de.end(), [](Person p) {cout << p.mName << " " << p.mScore << endl; });
	cout << "�����....................." << endl;
	sort(de.begin(), de.end(), [](Person p1, Person p2) {return p1.mScore > p2.mScore; });
	de.pop_front();
	de.pop_back();
	for_each(de.begin(), de.end(), [](Person p) {cout << p.mName << " " << p.mScore << endl; });

	int sumSocore = 0;
	for (deque<Person>::iterator i = de.begin(); i < de.end(); i++)
	{
		sumSocore += (*i).mScore;
	}

	cout << "ƽ���֣�" << sumSocore / de.size() << endl;
}

/*
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
//1. ��������ѡ�֣��ŵ�vector��
//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//3. sort�㷨��deque�����з�������pop_back pop_frontȥ����ߺ���ͷ�
//4. deque��������һ�飬�ۼӷ������ۼӷ���/d.size()
//5. person.score = ƽ����
*/

void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
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
		//10��ί��� �����浽deque
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~ 100
			d.push_back(score);
		}
		//������ί�Ĵ��
		//for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//����
		sort(d.begin(), d.end());
		//ȡ����� ��ͷ�
		d.pop_back(); // ��߷���
		d.pop_front(); //��ͷ���

					   //���ܷ�
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//��ƽ����
		int avg = sum / d.size();

		(*it).mScore = avg;
	}
}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << (*it).mName << " ������ " << (*it).mScore << endl;
	}
}

void test05()
{
	//���������
	srand((unsigned int)time(NULL));

	//��������ѡ��
	vector<Person>v;// ���ѡ�ֵ�����

	createPerson(v);

	//���
	setScore(v);

	//��ʾƽ����
	showScore(v);

	//����
	//for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << "������" << (*it).mName << " ������ " << it->mScore << endl;
	//}
}
int main()
{
	test01();
	system("pause");
	return 0;
}