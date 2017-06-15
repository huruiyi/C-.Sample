#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <deque>
#include <list>
#include <numeric>
/*
set_intersection算法 求两个set集合的交集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/

void test01()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int>vTarget;
    vTarget.resize(min(v1.size(), v2.size()));

    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
}

/*
set_union算法 求两个set集合的并集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址

*/

void test02()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int>vTarget;
    vTarget.resize(v1.size() + v2.size());

    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
}

/*
set_difference算法 求两个set集合的差集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/
void test03()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int>vTarget;
    vTarget.resize(max(v1.size(), v2.size()));

    //vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    vector<int>::iterator itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
}
void test04()
{
    const int MAX_ELEMENTS = 8;

    // Define a template class vector of int
    typedef vector<int> IntVector;

    //Define an iterator for template class vector of ints
    typedef IntVector::iterator IntVectorIt;

    IntVector NumbersVector(MAX_ELEMENTS);

    IntVectorIt startv, endv, itv;

    // Define a template class list of int
    typedef list<int> IntList;

    //Define an iterator for template class list of ints
    typedef IntList::iterator IntListIt;

    IntList NumbersList;

    IntListIt first, last, itl;

    // Define a template class deque of int
    typedef deque<int> IntDeque;

    //Define an iterator for template class deque of ints
    typedef IntDeque::iterator IntDequeIt;

    IntDeque NumbersDeque(2 * MAX_ELEMENTS);

    IntDequeIt itd;

    // Initialize vector NumbersVector
    NumbersVector[0] = 4;
    NumbersVector[1] = 10;
    NumbersVector[2] = 70;
    NumbersVector[3] = 10;
    NumbersVector[4] = 30;
    NumbersVector[5] = 69;
    NumbersVector[6] = 96;
    NumbersVector[7] = 100;

    startv = NumbersVector.begin();   // location of first
    // element of NumbersVector

    endv = NumbersVector.end();  // one past the location
    // last element of NumbersVector

    // sort NumbersVector, merge requires the sequences
    // to be sorted
    sort(startv, endv);

    // print content of NumbersVector
    cout << "NumbersVector { ";
    for (itv = startv; itv != endv; itv++)
        cout << *itv << " ";
    cout << " }\n" << endl;

    // Initialize vector NumbersList
    for (int i = 0; i < MAX_ELEMENTS; i++)
        NumbersList.push_back(i);

    first = NumbersList.begin();   // location of first
    // element of NumbersList

    last = NumbersList.end();  // one past the location
    // last element of NumbersList

    // print content of NumbersList
    cout << "NumbersList { ";
    for (itl = first; itl != last; itl++)
        cout << *itl << " ";
    cout << " }\n" << endl;

    // merge the elements of NumbersVector
    // and NumbersList and place the
    // results in NumbersDeque
    merge(startv, endv, first, last, NumbersDeque.begin());

    cout << "After calling merge\n" << endl;

    // print content of NumbersDeque
    cout << "NumbersDeque { ";
    for (itd = NumbersDeque.begin();
        itd != NumbersDeque.end(); itd++)
        cout << *itd << " ";
    cout << " }\n" << endl;
}

void test05()
{
    vector < string >rgs;
    rgs.push_back("This ");
    rgs.push_back("is ");
    rgs.push_back("one ");
    rgs.push_back("sentence. ");
    cout << "The concatenated vector of strings: "
        << accumulate(rgs.begin(), rgs.end(), string(""))
        << endl;
}

void test06()
{
    const int VECTOR_SIZE = 8;

    // Define a template class vector of strings
    typedef vector<string > StringVector;

    //Define an iterator for template class vector of strings
    typedef StringVector::iterator StringVectorIt;

    StringVector NamesVect(VECTOR_SIZE);
    //vector containing names

    string value("Sea");
    // stores the value used
    // to count matching elements

    StringVectorIt start, end, it;

    ptrdiff_t result = 0;
    // stores count of elements
    // that match value.

    // Initialize vector NamesVect
    NamesVect[0] = "She";
    NamesVect[1] = "Sells";
    NamesVect[2] = "Sea";
    NamesVect[3] = "Shells";
    NamesVect[4] = "by";
    NamesVect[5] = "the";
    NamesVect[6] = "Sea";
    NamesVect[7] = "Shore";

    start = NamesVect.begin();
    // location of first
    // element of NamesVect

    end = NamesVect.end();
    // one past the location
    // last element of NamesVect

    // print content of NamesVect
    cout << "NamesVect { ";
    for (it = start; it != end; it++)
        cout << *it << " ";
    cout << " }\n" << endl;

    // Count the number of elements in the range [first, last +1)
    // that match value.
    result = count(start, end, value);

    // print the count of elements that match value
    cout << "Number of elements that match \"Sea\" = " << result << endl;
}

int MatchFirstChar(const string& str)
{
    string s("S");
    return s == str.substr(0, 1);
}
void test07()
{
    const int VECTOR_SIZE = 8;

    // Define a template class vector of strings
    typedef vector<string > StringVector;

    //Define an iterator for template class vector of strings
    typedef StringVector::iterator StringVectorIt;

    StringVector NamesVect(VECTOR_SIZE);   //vector containing names

    StringVectorIt start, end, it;

    ptrdiff_t result = 0;   // stores count of elements
                            // that match value.

                            // Initialize vector NamesVect
    NamesVect[0] = "She";
    NamesVect[1] = "Sells";
    NamesVect[2] = "Sea";
    NamesVect[3] = "Shells";
    NamesVect[4] = "by";
    NamesVect[5] = "the";
    NamesVect[6] = "Sea";
    NamesVect[7] = "Shore";

    start = NamesVect.begin();   // location of first
                                 // element of NamesVect

    end = NamesVect.end();       // one past the location
                                 // last element of NamesVect

                                 // print content of NamesVect
    cout << "NamesVect { ";
    for (it = start; it != end; it++)
        cout << *it << " ";
    cout << " }\n" << endl;

    // Count the number of elements in the range [first, last +1)
    // that start with letter 'S'
    result = count_if(start, end, MatchFirstChar);

    // print the count of elements that start with letter 'S'
    cout << "Number of elements that start with letter \"S\" = "
        << result << endl;
}
int main() {
    test05();
    system("pause");
    return EXIT_SUCCESS;
}