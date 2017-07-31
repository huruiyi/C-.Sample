#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <numeric>
#include <algorithm>
#include <deque>
#include <ctime>
#include "FIleManger.h"
/*
1) ����ѡ�� �� ABCDEFGHIJKLMNOPQRSTUVWX �� �������÷֣�ѡ�ֱ��
2) ��1��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
3) ��2��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
4) ��3��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
*/

//����ѡ����
class Speaker
{
public:
	string mName; //����
	int score[3]; //�÷�
};

void createSpraker(vector<int>&v, map<int, Speaker>&m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";
	for (int i = 0; i < 24; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.mName = name;

		for (int j = 0; j < 3; j++)
		{
			sp.score[j] = 0;
		}

		v.push_back(i + 100); //100 ~ 123
		m.insert(make_pair(i + 100, sp));
	}
}

void draw(vector<int>&v)
{
	random_shuffle(v.begin(), v.end());
}

void speechContest(int index, vector<int>&v, map<int, Speaker>&m, vector<int>&v2)
{
	multimap<int, int, greater<int>> groupMap; // ��������� ���������
	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~100
			d.push_back(score);
		}
		//����
		sort(d.begin(), d.end());
		//ȥ����� ��ͷ�
		d.pop_back(); //��
		d.pop_front(); //��

					   //��ȡ�ܷ�
		int sum = accumulate(d.begin(), d.end(), 0);
		//��ƽ����
		int avg = sum / d.size();

		m[*it].score[index - 1] = avg;
		groupMap.insert(make_pair(avg, *it));
		//ÿ6�� ȡǰ����
		if (num % 6 == 0)
		{
			/*cout << "С������ɼ����£�" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); mit++)
			{
			cout << "��ţ� " << mit->second << " ������ " << m[mit->second].mName << " ������ " << m[mit->second].score[index - 1] << endl;;
			}*/

			//ȡǰ�������뵽 v2������
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(), count < 3; mit++, count++)
			{
				v2.push_back((*mit).second);
			}
			groupMap.clear();
		}
	}
}

void showScore(int index, vector<int>&v, map<int, Speaker>&m)
{
	cout << "��" << index << "�ֽ�����Ա���£�" << endl;
	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "ѡ�ֱ�ţ� " << it->first << " ������ " << it->second.mName << " �÷֣� " << it->second.score[index - 1] << endl;
	}

	cout << "���н���ѡ������" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
}

void test()
{
	//���������
	srand((unsigned int)time(NULL));

	//����ѡ��
	vector<int>v; //ѡ�ֱ������
	map<int, Speaker> m; //��ѡ�ֵı�ź�ѡ�ֶ�Ӧ
	createSpraker(v, m);

	//��ǩ
	draw(v);

	vector<int>v2; //��һ�ֽ�������Ա���
				   //����
	speechContest(1, v, m, v2);

	//չʾ���
	showScore(1, v2, m);

	//�ڶ��ֱ���
	draw(v2);
	vector<int>v3; //�ڶ��ֽ�����Ա���
				   //����
	speechContest(2, v2, m, v3);
	//չʾ���
	showScore(2, v3, m);

	//�����ֱ���
	draw(v3);
	vector<int>v4; //�����ֽ�����Ա���
				   //����
	speechContest(3, v3, m, v4);
	//չʾ���
	showScore(3, v4, m);

	//����
	/*for (map<int, Speaker>::iterator it = m.begin(); it != m.end();it++)
	{
	cout << "��ţ� " << it->first << "����" << it->second.mName << endl;
	}*/
}
void test02()
{
	//key�Ӵ�С
	multimap<int, int, greater<int>> mmp;
	mmp.insert(make_pair(1, 5));
	mmp.insert(make_pair(9, 7));
	mmp.insert(make_pair(8, 3));
	mmp.insert(make_pair(6, 2));
	mmp.insert(make_pair(6, 8));
	for (multimap<int, int, greater<int>>::iterator mit = mmp.begin(); mit != mmp.end(); mit++)
	{
		cout << mit->first << "  " << mit->second << endl;
	}
}
//multimap �Զ�������
void test03()
{
}

void test_fileManger()
{
	FIleManger fm;
	map<int, map<string, string>> li;
	fm.LoadFile("Hero.csv", li);
	cout << "test_fileManger............................" << endl;
}

void print(std::string::size_type n, std::string const &s)
{
	if (n == std::string::npos)
	{
		std::cout << "not found\n";
	}
	else
	{
		std::cout << "found: " << s.substr(n) << '\n';
	}
}
void test_string_find()
{
	std::string::size_type n;
	std::string const s = "This is a string";

	// search from beginning of string
	n = s.find("is");
	print(n, s);

	// search from position 5
	n = s.find("is", 5);
	print(n, s);

	// find a single character
	n = s.find('a');
	print(n, s);

	// find a single character
	n = s.find('q');
	print(n, s);

	//find an not exit string
	n = s.find("hello");
	print(n, s);

	int pos = s.find("hello");
	print(n, s);
}
int main()
{
	test_fileManger();
	system("pause");
	return EXIT_SUCCESS;
}