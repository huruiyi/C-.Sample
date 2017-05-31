#include <iostream>
#include <string>
#include "person.h"
#include"Circle.h"
#include"Point.h"
using namespace std;

void Demo0()
{
    Person p;
    p.SetName("едЫФ");
    p.SetAge(20);

    cout << p.GetName() << "  " << p.GetAge() << endl;
    p.ShowPersonInfo();
}
void Demo1()
{
    Circle circle;
    circle.setHeart(10, 10);
    circle.setR(20);

    Point point;
    point.setX(10);
    point.setY(30);

    circle.judgeCirleAndPointRelation(point);

    Circle *c = new Circle();
    delete c;
}

#if 1
int main()
{
    int *p1 = new int;
    delete p1;
    int *p2 = new int;

    system("pause");
    return 0;
}
#endif