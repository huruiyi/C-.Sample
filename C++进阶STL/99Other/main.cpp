#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric> //accumulate 头文件
#include <iterator>

void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int sum = accumulate(v.begin(), v.end(), 1000); //参数3 起始值

	cout << "0~100总和为： " << sum << endl;
}

/*
fill算法 向容器中添加元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value t填充元素
*/
void test02()
{
	vector<int>v;

	v.resize(10);

	fill(v.begin(), v.end(), 100);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void test03()
{
	vector<int>v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(30);

	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int v){cout << v << " "; });

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
}

class myReplace
{
public:
	bool operator()(int v)
	{
		return v > 4;
	}
};

void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	replace(v.begin(), v.end(), 4, 400);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	replace_if(v.begin(), v.end(), myReplace(), 4000);
	replace_if(v.begin(), v.end(), myReplace(), [](int a) {return a > 5; });
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2;
	v2.push_back(10);
	v2.push_back(30);
	v2.push_back(20);

	swap(v, v2);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void test06()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int sum = std::accumulate(v.begin(), v.end(), 0);

	int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

	std::string s = std::accumulate(std::next(v.begin()), v.end(),
		std::to_string(v[0]),
		[](std::string a, int b)
	{
		return a + '-' + std::to_string(b);
	});

	std::cout << "sum: " << sum << '\n'
		<< "product: " << product << '\n'
		<< "dash-separated string: " << s << '\n';
}
int main()
{
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}