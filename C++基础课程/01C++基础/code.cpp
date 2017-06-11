#include <vector>
#include <stdarg.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using namespace std;

void SetwDemo()
{
    //char * chrs = NULL;
    //cin >> chrs;
    //int *p = (int *)chrs;

    int num1{ 1234 }, num2{ 5678 };
    cout << setw(10) << num1 << setw(6) << num2 << endl;

    char  a[10];
    cin >> a;

    cout << *a << endl;

    char * ps = "Good Morning";

    while (*ps)
    {
        putchar(*ps++);
        printf("\t");
    }
}

void CinDemo()
{
    int x;
    cin >> x;
    cout << "The int number is x= " << x << endl;

    float y;
    cin >> y;
    cout << "The float number is y= " << y << endl;
}

void VectorDemo()
{
    vector<int> first;
    vector<int> second;
    vector<int> third;

    first.assign(7, 100);             // 7 ints with a value of 100

    vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1); // the 5 central values of first

    int myints[] = { 1776, 7, 4 };
    third.assign(myints, myints + 3);   // assigning from array.

    cout << "Size of first: " << int(first.size()) << '\n';
    cout << "Size of second: " << int(second.size()) << '\n';
    cout << "Size of third: " << int(third.size()) << '\n';

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << &arr[0];
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] + "  " << &arr[i] << endl;
    }
    getchar();
}

double average(int num, ...)

{
    va_list valist;
    double sum = 0.0;
    int i;

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum / num;
}

void AverageDemo()
{
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));
    system("pause");
}

#if 1
void main()
{
    char *p = "123456789";
    while (*p != '\0')
    {
        printf("%c %c\n", *p, p[0]);
        p++;
    }
    printf("|");
    SetwDemo();
    system("pause");
}
#endif // 0