#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

func()
{
    return 10;
}

//1. 可读性 2.效率

int main01() {
    //printf("ret = %d\n", func(10,20,30));

    //存放10的内存  内存里面10
    int a = 10;
    int b = 20;

    printf("ret = %d\n", a > b ? a : b);

    //(a > b ? a : b) = 100;

    //10叫做字面量，存放在代码区
    //10 = 100;

    system("pause");
    return EXIT_SUCCESS;
}