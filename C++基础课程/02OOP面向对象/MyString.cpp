#include "MyString.h"

std::ostream & operator<<(std::ostream &out, const MyString &str)
{
}

std::iostream & operator>>(std::iostream &out, const MyString &str)
{
}
MyString::MyString()
{
    this->pString = NULL;
    this->mSize = 0;
}

MyString::MyString(const char *s)
{
    this->pString = new char[strlen(s) + 1];
    strcpy(this->pString, s);
    this->mSize = strlen(s);
}

MyString::MyString(int n, char  ch)
{
}

MyString::MyString(const MyString &str)
{
}

MyString::~MyString()
{
}

MyString &MyString::operator=(const MyString &str)
{
}

char &MyString::operator[](int index)
{
}

MyString MyString::operator+(const MyString &str)
{
}

MyString MyString::operator+(const char  *c)
{
}

MyString &MyString::operator+=(const MyString &str)
{
}

MyString &MyString::operator+=(const char *c)
{
    return *this;
}

bool MyString::operator==(const MyString &str)
{
    if (this->mSize!=str.mSize)
    {
        return false;
    }
    if (strcmp(this->pString,str.pString))
    {
        return false;
    }
    return true;
}

bool MyString::operator==(const char *s)
{
}

int MyString::size()
{
}

//MyString->const char *
const char * MyString::c_str()
{
}