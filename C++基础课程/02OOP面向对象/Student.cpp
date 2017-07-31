#include "Student.h"
#include <string>

Student::Student()
{
}

Student::Student(const char *name, int age)
{
	int length = strlen(name) + 1;
	sName = (char *)malloc(sizeof(char)*length);
	strcpy_s(sName, strlen(sName) + 1, name);
	Age = age;
}
Student::~Student()
{
	if (sName)
	{
		free(sName);
	}
}

void Student::ShowInfo()
{
	cout << this->sName << this->Age << endl;
}