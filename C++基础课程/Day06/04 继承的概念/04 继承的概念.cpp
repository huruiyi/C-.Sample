#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class CommonInfo
{
public:
    void Header()
    {
        cout << "新版的公共头部信息!" << endl;
    }

    void Footer()
    {
        cout << "公共底部信息!" << endl;
    }

    void Left()
    {
        cout << "公共左部信息!" << endl;
    }
};

class IndexPage : public CommonInfo
{
public:
    void MainBody()
    {
        cout << "首页主体部分!" << endl;
    }
};

class NewsPage : public CommonInfo
{
public:
    void MainBody()
    {
        cout << "新闻页部分!" << endl;
    }
};

void test()
{
    IndexPage ip;
    ip.Header();
    ip.Left();
    ip.MainBody();
    ip.Footer();

    cout << "---------" << endl;

    NewsPage np;
    np.Header();
    np.Left();
    np.MainBody();
    np.Footer();
}

//1. 继承就是用来复用代码
//2. 对已有的类进行功能扩展
//3. 继承的最终目的是为了实现多态

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}