#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Building
{
	//���߱�����GoodGay�ǵ�ǰ��ĺû���
	friend void GoodGay();
	friend class GoodFriend;
public:
	Building()
	{
		mSittingRoom = "����";
		mBedRoom = "����";
	}
public:
	string mSittingRoom; //����
private:
	string mBedRoom; //����
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

//�û���
//ֻҪ�ں�����Χ�ڷ���Building���󣬶����Է�����˽�г�Ա
void GoodGay()
{
	Building building;
	cout << "�û�������" << building.mSittingRoom << "���һȦ!" << endl;
	cout << "�û��Ѳ��ʼ�į������" << building.mBedRoom << "....." << endl;
}

void test()
{
	Building building;
	GoodGay();
}

//��Ԫ�����Ԫȫ�ֺ����õıȽ϶�
//��Ԫ�������ǳ�Ա������Ҳû��thisָ�룬��ͨȫ�ֺ���

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}