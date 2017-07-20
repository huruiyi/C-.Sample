#ifndef _Student_he_
#define _Student_he_
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