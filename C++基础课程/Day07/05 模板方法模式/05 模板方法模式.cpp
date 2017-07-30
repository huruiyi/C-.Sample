#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//选择题 填空题 简答题
class AbstractPaper
{
public:
    //选择题
    virtual void selectSubject() = 0;
    //填空题
    virtual void fillBlank() = 0;
    //简答题
    virtual void answerSubject() = 0;

    void startTest()
    {
        selectSubject();
        fillBlank();
        answerSubject();
    }
};

//语文试卷
class ChinesePaper : public AbstractPaper
{
public:

    //填空题
    virtual void fillBlank()
    {
        cout << "语文试卷填空题!" << endl;
    }

    //选择题
    virtual void selectSubject()
    {
        cout << "语文试卷选择题!" << endl;
    }

    //简答题
    virtual void answerSubject()
    {
        cout << "语文试卷的简单题!" << endl;
    }
};

class EnglishPaper : public AbstractPaper
{
public:
    //填空题
    virtual void fillBlank()
    {
        cout << "英语试卷填空题!" << endl;
    }

    //选择题
    virtual void selectSubject()
    {
        cout << "英语试卷选择题!" << endl;
    }

    //简答题
    virtual void answerSubject()
    {
        cout << "英语试卷的简单题!" << endl;
    }
};

void test()
{
    //AbstractPaper per = new AbstractPaper;//包含纯虚函数的类不能实例化
    AbstractPaper *paper = NULL;
    paper = new ChinesePaper;
    paper->startTest();
    delete paper;

    cout << "----------" << endl;

    paper = new EnglishPaper;
    paper->startTest();
    delete paper;
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}