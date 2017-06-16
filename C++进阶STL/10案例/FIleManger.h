#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <list>
#include<map>
using namespace std;
class FIleManger
{
public:
    void LoadFile(string fileName, map<int, map<string, string>> &mp);
    void ParseLineToVector(string line, vector<string> &vf);
};