#ifndef _MyString_H
#define   _MyString_H
#include <iostream>

class MyString
{
    friend std::ostream & operator<<(std::ostream &out, const MyString &str);
    friend std::iostream & operator>>(std::iostream &out, const MyString &str);
public:
    MyString();
    MyString(const char *s);
    MyString(int n, char  ch);
    MyString(const MyString &str);
    ~MyString();
    MyString &operator=(const MyString &str);

    char &operator[](int index);

    MyString operator+(const MyString &str);
    MyString operator+(const char  *c);

    MyString &operator+=(const MyString &str);
    MyString &operator+=(const char *c);

    bool operator==(const MyString &str);
    bool operator==(const char *s);

    int size();

    //MyString->const char *
    const char * c_str();
public:
    char *pString;//指向真正存储字符串的空间
    int mSize;
};

#endif // !_MyString_H
