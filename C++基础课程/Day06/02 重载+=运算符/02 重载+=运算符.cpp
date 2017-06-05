#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"MyArray.h"
using namespace std;

int main() {
    MyArray arr;
    arr += 10, 20, 30, 40, 50, 60, 70;

    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return EXIT_SUCCESS;
}