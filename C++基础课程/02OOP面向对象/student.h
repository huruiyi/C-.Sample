#ifndef _Student_h_
#define _Student_h_
#include "Person.h"

class Student
{
public:
    Student();
    ~Student();
    Student(const char *name, int age);

    void ShowInfo();
private:
    char *sName;
    int Age;
};

#endif