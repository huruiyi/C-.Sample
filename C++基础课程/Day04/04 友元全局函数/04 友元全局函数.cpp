#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Building
{
	//告诉编译器GoodGay是当前类的好基友
	friend void GoodGay();
	friend class GoodFriend;
public:
	Building()
	{
		mSittingRoom = "客厅";
		mBedRoom = "卧室";
	}
public:
	string mSittingRoom; //客厅
private:
	string mBedRoom; //卧室
};

#if 0
class GoodFriend
{
public:
	void visit(Building &building)
	{
		building.mBedRoom;
	}

	void clean(Building &building)
	{
		building.mBedRoom;
	}
};
#endif

#if 0
class GoodFriend
{
public:
	void visit()
	{
		mBuilding.mBedRoom;
	}

	void clean()
	{
		mBuilding.mBedRoom;
	}
public:
	Building mBuilding;
};
#endif

class GoodFriend
{
public:
	void visit()
	{
		pBuilding->mBedRoom;
	}

	void clean()
	{
		pBuilding->mBedRoom;
	}
public:
	Building *pBuilding;
};

//好基友
//只要在函数范围内访问Building对象，都可以访问其私有成员
void GoodGay()
{
	Building building;
	cout << "好基友来到" << building.mSittingRoom << "溜达一圈!" << endl;
	cout << "好基友不甘寂寞来到了" << building.mBedRoom << "....." << endl;
}

void test()
{
	Building building;
	GoodGay();
}

//友元类和友元全局函数用的比较多
//友元函数不是成员函数，也没有this指针，普通全局函数

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}