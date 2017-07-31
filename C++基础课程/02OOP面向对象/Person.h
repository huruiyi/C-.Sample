#ifndef _Person_h_
#define _Person_h_

#include <iostream>
#include <string>
using namespace  std;

class Person
{
public:
	Person();
	~Person();
	void SetAge(int age);
	int GetAge() const;

	void SetName(string name);
	string GetName() const;

	void ShowPersonInfo();

private:
	string Name;
	int Age;

protected:
	string ProtectedInfo;
};

#endif
