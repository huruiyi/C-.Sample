#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iterator>

/*
copy算法 将容器内指定范围的元素拷贝到另一容器中
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param dest 目标起始迭代器
*/
void test01()
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

/*
replace算法 将容器内指定范围的旧元素修改为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param oldvalue 旧元素
@param oldvalue 新元素
*/
/*
replace_if算法 将容器内指定范围满足条件的元素替换为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param callback函数回调或者谓词(返回Bool类型的函数对象)
@param oldvalue 新元素
*/

class myReplace
{
public:
    bool operator()(int v)
    {
        return v > 4;
    }
};

void test02()
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
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

/*
swap算法 互换两个容器的元素
@param c1容器1
@param c2容器2
*/

void test03()
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

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return EXIT_SUCCESS;
}