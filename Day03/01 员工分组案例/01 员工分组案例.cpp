#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <ctime>

//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过Multimap进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息

enum
{
    CAIWU, RENLI, YANFA
};

class Worker
{
public:
    string mName; //姓名
    int mMoney; //工资
};

void createWorker(vector<Worker>&v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "员工";
        name += nameSeed[i];

        Worker w;
        w.mName = name;
        w.mMoney = rand() % 10000 + 10000; // 10000 ~ 19999

        //将员工放入到容器中
        v.push_back(w);
    }
}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //随机产生部门编号
        int departmentId = rand() % 3; // 0 1 2
        //将员工放入到 m容器中
        m.insert(make_pair(departmentId, *it));
    }
}

void showGroup1(multimap<int, Worker>&m)
{
    // 0  A  0  B   1 C   2 D  2 E 假数据

    multimap<int, Worker>::iterator cPos = m.find(CAIWU);
    multimap<int, Worker>::iterator rPos = m.find(RENLI);
    multimap<int, Worker>::iterator yPos = m.find(YANFA);

    int cNum = m.count(CAIWU);
    int rNum = m.count(RENLI);
    int yNum = m.count(YANFA);

    cout << "财务部门员工如下：" << endl;
    for (int num = 0; cPos != m.end(), num < cNum; cPos++, num++)
    {
        cout << "姓名： " << cPos->second.mName << " 工资： " << cPos->second.mMoney << endl;
    }
    cout << "-----------------------" << endl;

    cout << "人力部门员工如下：" << endl;
    for (int num = 0; rPos != m.end(), num < rNum; rPos++, num++)
    {
        cout << "姓名： " << rPos->second.mName << " 工资： " << rPos->second.mMoney << endl;
    }
    cout << "-----------------------" << endl;

    cout << "研发部门员工如下：" << endl;
    for (int num = 0; yPos != m.end(), num < yNum; yPos++, num++)
    {
        cout << "姓名： " << yPos->second.mName << " 工资： " << yPos->second.mMoney << endl;
    }
    cout << "-----------------------" << endl;
}
void showGroup2(multimap<int, Worker>&m)
{
    multimap<int, Worker>::iterator cPos = m.find(CAIWU);
    multimap<int, Worker>::iterator rPos = m.find(RENLI);
    multimap<int, Worker>::iterator yPos = m.find(YANFA);
    int cNum = m.count(CAIWU);
    int rNum = m.count(RENLI);
    int yNum = m.count(YANFA);

    cout << "财务部门员工如下：" << endl;
    while (cPos != m.end() && cNum)
    {
        cout << "姓名： " << cPos->second.mName << " 工资： " << cPos->second.mMoney << endl;
        cPos++;
        cNum--;
    }
    cout << "-----------------------" << endl;

    cout << "人力部门员工如下：" << endl;
    while (rPos != m.end() && rNum)
    {
        cout << "姓名： " << rPos->second.mName << " 工资： " << rPos->second.mMoney << endl;
        rPos++;
        rNum--;
    }
    cout << "-----------------------" << endl;

    cout << "研发部门员工如下：" << endl;
    while (yPos != m.end() && yNum)
    {
        cout << "姓名： " << yPos->second.mName << " 工资： " << yPos->second.mMoney << endl;
        yPos++;
        yNum--;
    }
    cout << "-----------------------" << endl;
}

int main() {
    srand((unsigned int)time(NULL));

    //创建员工
    vector<Worker>v;
    createWorker(v);

    //将员工放入到各个部门中
    //容器multimap 存放部门 以及相应的人员
    multimap<int, Worker> m;
    setGroup(v, m);

    //分部门显示员工
    showGroup1(m);
    showGroup2(m);

    //测试容器
    /*for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
    {
    cout << "姓名： " << it->mName << " 工资： " << it->mMoney << endl;
    }*/

    system("pause");
    return EXIT_SUCCESS;
}