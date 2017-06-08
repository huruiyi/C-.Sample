#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
void selectSort(T arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        int min = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            T temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void test()
{
    int arr[] = { 6, 3, 2, 8, 9 };
    int arrLen = sizeof(arr) / sizeof(int);
    printArray(arr, arrLen);
    selectSort(arr, arrLen);
    printArray(arr, arrLen);

    cout << "--------------" << endl;

    char p[] = "edcba";
    int pLen = strlen(p);
    printArray(p, pLen);
    selectSort(p, pLen);
    printArray(p, pLen);

    //cout << &"aaa" << endl;
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}