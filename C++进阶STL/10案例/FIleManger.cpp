#include "FIleManger.h"

void FIleManger::LoadFile(string fileName, map<int, map<string, string>> &mp)
{
	ifstream ifs(fileName);
	string firstLine;

	ifs >> firstLine;
	vector<string> vfTitle;
	ParseLineToVector(firstLine, vfTitle);
	//int:武器的Id,  map<string,string> Id对应武器的属性名，和属性值
	string line;
	while (ifs >> line)
	{
		vector<string> vf;

		ParseLineToVector(line, vf);
		map<string, string> mss;
		for (rsize_t i = 0; i < vf.size(); i++)
		{
			mss.insert(make_pair(vfTitle[i], vf[i]));
		}

		vector<string>::iterator iter = vf.begin();
		int id = atoi((*iter).c_str());
		mp.insert(make_pair(id, mss));
	}
}

void FIleManger::ParseLineToVector(string line, vector<string> &vf)
{
	int pos = 0;
	int start = 0;
	string info;

	while (true)
	{
		if (pos == -1)
		{
			break;
		}
		pos = line.find(",", start);
		info = line.substr(start, pos - start);
		vf.push_back(info);
		start = pos + 1;
	}
}