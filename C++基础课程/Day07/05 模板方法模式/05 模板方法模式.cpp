#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ѡ���� ����� �����
class AbstractPaper
{
public:
    //ѡ����
    virtual void selectSubject() = 0;
    //�����
    virtual void fillBlank() = 0;
    //�����
    virtual void answerSubject() = 0;

    void startTest()
    {
        selectSubject();
        fillBlank();
        answerSubject();
    }
};

//�����Ծ�
class ChinesePaper : public AbstractPaper
{
public:

    //�����
    virtual void fillBlank()
    {
        cout << "�����Ծ������!" << endl;
    }

    //ѡ����
    virtual void selectSubject()
    {
        cout << "�����Ծ�ѡ����!" << endl;
    }

    //�����
    virtual void answerSubject()
    {
        cout << "�����Ծ�ļ���!" << endl;
    }
};

class EnglishPaper : public AbstractPaper
{
public:
    //�����
    virtual void fillBlank()
    {
        cout << "Ӣ���Ծ������!" << endl;
    }

    //ѡ����
    virtual void selectSubject()
    {
        cout << "Ӣ���Ծ�ѡ����!" << endl;
    }

    //�����
    virtual void answerSubject()
    {
        cout << "Ӣ���Ծ�ļ���!" << endl;
    }
};

void test()
{
    //AbstractPaper per = new AbstractPaper;//�������麯�����಻��ʵ����
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