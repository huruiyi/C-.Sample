#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

//1. 文本方式读写文件
void test01()
{
	//1. 创建文件输出流对象
	//ofstream ofs("./test.txt", ios::out );
	ofstream ofs;
	ofs.open("./test.txt", ios::out);

	//2. 判断文件是否打开
	if (!ofs)
	{
		cout << "文件打开失败!" << endl;
	}

	//3. 向文件中写入数据
	char *buf[] = {
		"aaaaaaaaaaaaa\n",
		"bbbbbbbbbbbbbbbbbbbbb\n",
		"cccccccccccccccccccccc\n",
		"ddddddddd\n"
	};
	int len = sizeof(buf) / sizeof(char *);

#if 0
	for (int i = 0; i < len; ++i)
	{
		int lineLen = strlen(buf[i]);
		for (int j = 0; j < lineLen; ++j)
		{
			ofs.put(buf[i][j]);
		}
	}
#endif

	for (int i = 0; i < len; ++i)
	{
		ofs << buf[i];
	}
	//关闭文件
	ofs.close(); //刷新缓冲区， 关闭文件

	/*************************/

	//打开文件
	ifstream ifs("./test.txt",ios::in);
	if (!ifs)
	{
		cout << "文件打开失败!" << endl;
	}

	char buf2[1024] = { 0 };
	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}

	//关闭文件
	ifs.close();
}

//2. 二进制文件读写
class Person
{
public:
	Person(const char *name,int age)
	{
		//memset(mName, 0, 64);
		strcpy(mName, name);
		mAge = age;
	}
public:
	char mName[64];
	int mAge;
};
void test02()
{
	//对象数组
	Person persons[3]{Person("aaa", 10), Person("bbb", 20), Person("ccc", 30)};
	//将数据写入文件
	ofstream ofs("./persons.txt", ios::out | ios::binary);
	if (!ofs)
	{
		cout << "打开失败!" << endl;
	}
	//将对象以二进制的方式写入文件
	ofs.write((const char *)persons, sizeof(Person)* 3);
	//关闭文件
	ofs.close();

	/*******************/
	ifstream ifs("./persons.txt", ios::in | ios::binary);
	if (!ifs)
	{
		cout << "打开失败!" << endl;
	}

	//开辟内存
	char *person = (char *)malloc(sizeof(Person)* 3);
	memset(person, 0, sizeof(Person)* 3);

	ifs.read(person, sizeof(Person) *3);

	Person *ps = (Person *)person;

	for (int i = 0; i < 3; ++i)
	{
		cout << "Name:" << ps[i].mName << " Age:" << ps[i].mAge << endl;
	}

	free(person);

	//关闭文件
	ifs.close();

}

//文件读写注意
//eof
//fail
//bad 不可修复
//good
void  test03()
{

	//打开文件
	ifstream ifs("./test.txt", ios::in);
#if 0
	ifs.fail();
	ifs.bad();
	ifs.eof();
	ifs.good();
#endif
	if (!ifs)
	{
		cout << "文件打开失败!" << endl;
	}

	char buf2[1024] = { 0 };
	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}


	cout << "--------------" << endl;
	cout << boolalpha << ifs.good();

	ifs.clear();
	//文件指针设置为开始位置
	ifs.seekg(0,ios::beg);

	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}

	//关闭文件
	ifs.close();
}

void  test04()
{
	char buf[1] = { 0 };
	cin.getline(buf,1);

	cout << boolalpha << cin.fail() << endl;
	cout << boolalpha << cin.good() << endl;

	char b[1024] = { 0 };
	cin.get(b,1024);
	cout << b << endl;
}

int main(){

	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}