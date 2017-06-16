#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <numeric>
#include <algorithm>
#include <deque>
#include <ctime>
#include "FIleManger.h"
/*
1) 产生选手 （ ABCDEFGHIJKLMNOPQRSTUVWX ） 姓名、得分；选手编号
2) 第1轮	选手抽签 选手比赛 查看比赛结果
3) 第2轮	选手抽签 选手比赛 查看比赛结果
4) 第3轮	选手抽签 选手比赛 查看比赛结果
*/

//创建选手类
class Speaker
{
public:
    string mName; //姓名
    int score[3]; //得分
};

void createSpraker(vector<int>&v, map<int, Speaker>&m)
{
    string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";
    for (int i = 0; i < 24; i++)
    {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.mName = name;

        for (int j = 0; j < 3; j++)
        {
            sp.score[j] = 0;
        }

        v.push_back(i + 100); //100 ~ 123
        m.insert(make_pair(i + 100, sp));
    }
}

void draw(vector<int>&v)
{
    random_shuffle(v.begin(), v.end());
}

void speechContest(int index, vector<int>&v, map<int, Speaker>&m, vector<int>&v2)
{
    multimap<int, int, greater<int>> groupMap; // 分数，编号 ，排序规则
    int num = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        num++;
        deque<int>d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60; // 60 ~100
            d.push_back(score);
        }
        //排序
        sort(d.begin(), d.end());
        //去除最高 最低分
        d.pop_back(); //高
        d.pop_front(); //低

                       //获取总分
        int sum = accumulate(d.begin(), d.end(), 0);
        //求平均分
        int avg = sum / d.size();

        m[*it].score[index - 1] = avg;
        groupMap.insert(make_pair(avg, *it));
        //每6人 取前三名
        if (num % 6 == 0)
        {
            /*cout << "小组比赛成绩如下：" << endl;
            for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); mit++)
            {
            cout << "编号： " << mit->second << " 姓名： " << m[mit->second].mName << " 分数： " << m[mit->second].score[index - 1] << endl;;
            }*/

            //取前三名放入到 v2容器中
            int count = 0;
            for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(), count < 3; mit++, count++)
            {
                v2.push_back((*mit).second);
            }
            groupMap.clear();
        }
    }
}

void showScore(int index, vector<int>&v, map<int, Speaker>&m)
{
    cout << "第" << index << "轮晋级人员如下：" << endl;
    for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "选手编号： " << it->first << " 姓名： " << it->second.mName << " 得分： " << it->second.score[index - 1] << endl;
    }

    cout << "所有晋级选手名单" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
}

void test()
{
    //随机数种子
    srand((unsigned int)time(NULL));

    //产生选手
    vector<int>v; //选手编号容器
    map<int, Speaker> m; //将选手的编号和选手对应
    createSpraker(v, m);

    //抽签
    draw(v);

    vector<int>v2; //第一轮晋级的人员编号
                   //比赛
    speechContest(1, v, m, v2);

    //展示结果
    showScore(1, v2, m);

    //第二轮比赛
    draw(v2);
    vector<int>v3; //第二轮晋级人员编号
                   //比赛
    speechContest(2, v2, m, v3);
    //展示结果
    showScore(2, v3, m);

    //第三轮比赛
    draw(v3);
    vector<int>v4; //第三轮晋级人员编号
                   //比赛
    speechContest(3, v3, m, v4);
    //展示结果
    showScore(3, v4, m);

    //测试
    /*for (map<int, Speaker>::iterator it = m.begin(); it != m.end();it++)
    {
    cout << "编号： " << it->first << "姓名" << it->second.mName << endl;
    }*/
}
void test02()
{
    //key从大到小
    multimap<int, int, greater<int>> mmp;
    mmp.insert(make_pair(1, 5));
    mmp.insert(make_pair(9, 7));
    mmp.insert(make_pair(8, 3));
    mmp.insert(make_pair(6, 2));
    mmp.insert(make_pair(6, 8));
    for (multimap<int, int, greater<int>>::iterator mit = mmp.begin(); mit != mmp.end(); mit++)
    {
        cout << mit->first << "  " << mit->second << endl;
    }
}
//multimap 自定义排序
void test03()
{
}

void test_fileManger()
{
    FIleManger fm;
    list<vector<string>> li;
    fm.LoadFile("Hero.csv", li);
    cout << "test_fileManger............................" << endl;
    for (list<vector<string>>::iterator iter = li.begin(); iter != li.end(); iter++)
    {
        vector<string> v = *iter;
        for (vector<string>::iterator  i = v.begin(); i !=v.end(); i++)
        {
            cout << *i << "\t";
        }
        cout << endl;
    }
}

void print(std::string::size_type n, std::string const &s)
{
    if (n == std::string::npos)
    {
        std::cout << "not found\n";
    }
    else
    {
        std::cout << "found: " << s.substr(n) << '\n';
    }
}
void test_string_find()
{
    std::string::size_type n;
    std::string const s = "This is a string";

    // search from beginning of string
    n = s.find("is");
    print(n, s);

    // search from position 5
    n = s.find("is", 5);
    print(n, s);

    // find a single character
    n = s.find('a');
    print(n, s);

    // find a single character
    n = s.find('q');
    print(n, s);

    //find an not exit string
    n = s.find("hello");
    print(n, s);

    int pos = s.find("hello");
    print(n, s);
}
int main()
{
    test_fileManger();
    system("pause");
    return EXIT_SUCCESS;
}