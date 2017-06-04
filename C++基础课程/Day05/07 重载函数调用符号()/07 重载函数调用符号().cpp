#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyFunctor
{
public:
    int operator()(int a, int b, int c)
    {
        return a + b + c;
    }
};

void test01()
{
    //函数对象 仿函数
    MyFunctor functor;
    cout << "ret:" << functor(10, 20, 30) << endl; //functor.operator();

    cout << MyFunctor()(100, 200, 300) << endl;

    //函数没有类型，函数对象有类型
    //函数对象可以回调函数，效率要比函数指针高
    //函数对象可以自身的状态

    //MyFunctor *f = new MyFunctor;
    //(*f)(10,20,30);
}

int main() {
    test01();

    system("pause");
    return EXIT_SUCCESS;
}