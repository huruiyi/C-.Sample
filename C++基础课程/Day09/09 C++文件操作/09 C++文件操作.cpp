#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

//1. �ı���ʽ��д�ļ�
void test01write()
{
	//1. �����ļ����������
	//ofstream ofs("./test.txt", ios::out );
	ofstream ofs;
	ofs.open("./test.txt", ios::out);

	//2. �ж��ļ��Ƿ��
	if (!ofs)
	{
		cout << "�ļ���ʧ��!" << endl;
	}

	//3. ���ļ���д������
	char* buf[] = {
		"12345789\n",
		"987654321\n",
		"abcdefghi\n",
		"ddddddddd\n"
	};

#if 1 �ļ����ַ�д��
	int len = sizeof(buf) / sizeof(char*);
	for (int i = 0; i < len; ++i)
	{
		int lineLen = strlen(buf[i]);
		for (int j = 0; j < lineLen; ++j)
		{
			ofs.put(buf[i][j]);
		}
	}
#endif

#if 0 �ļ�����д��
	int len = sizeof(buf) / sizeof(char*);
	for (int i = 0; i < len; ++i)
	{
		ofs << buf[i];
	}
#endif // 0

	//�ر��ļ�
	ofs.close(); //ˢ�»������� �ر��ļ�
}
int test011write()
{
	std::ofstream outfile;
	outfile.open("test.txt");

	outfile.write("This is an apple", 16);
	long pos = outfile.tellp();
	outfile.seekp(pos - 7);
	outfile.write(" sam", 4);

	outfile.close();

	return 0;
}

void test01read()
{
	//���ļ�
	ifstream ifs("./test.txt", ios::in);
	if (!ifs)
	{
		cout << "�ļ���ʧ��!" << endl;
	}

	char buf2[1024] = { 0 };
	/*
		0123456789
		9876543210
		abcdefghij
	*/

	ifs.seekg(0, std::ios_base::end);
	std::streampos sp = ifs.tellg();

	cout << sp << endl;
	ifs.seekg(-sp, ios::end);

	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}

	cout << "*******************************" << endl;

	sp = ifs.tellg();

	//�����������¶�ȡ
	// ifs.clear();
	ifs.clear(ios_base::eofbit);

	ifs.seekg(0);

	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}
	//�ر��ļ�
	ifs.close();
}

int test011read()
{
	std::ifstream is("test.txt", std::ifstream::binary);
	if (is)
	{
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		// allocate memory:
		char* buffer = new char[length];

		// read data as a block:
		is.read(buffer, length);

		is.close();

		// print content:
		std::cout.write(buffer, length);

		delete[] buffer;
	}

	return 0;
}

//2. �������ļ���д
class Person
{
public:
	Person(const char* name, int age)
	{
		//memset(mName, 0, 64);
		strcpy(mName, name);
		mAge = age;
	}
public:
	char mName[64];
	int mAge;
};
void test02write()
{
	//��������
	Person persons[3]{ Person("aaa", 10), Person("bbb", 20), Person("ccc", 30) };
	//������д���ļ�
	ofstream ofs("./persons.dat", ios::out | ios::binary);
	if (!ofs)
	{
		cout << "��ʧ��!" << endl;
	}
	//�������Զ����Ƶķ�ʽд���ļ�
	ofs.write((const char*)persons, sizeof(Person) * 3);
	//�ر��ļ�
	ofs.close();
}

void test02read()
{
	ifstream ifs("./persons.dat", ios::in | ios::binary);
	if (!ifs)
	{
		cout << "��ʧ��!" << endl;
	}

	//�����ڴ�
	char* person = (char*)malloc(sizeof(Person) * 3);
	memset(person, 0, sizeof(Person) * 3);

	ifs.read(person, sizeof(Person) * 3);

	Person* ps = (Person*)person;

	for (int i = 0; i < 3; ++i)
	{
		cout << "Name:" << ps[i].mName << " Age:" << ps[i].mAge << endl;
	}

	free(person);

	//�ر��ļ�
	ifs.close();
}

//�ļ���дע��
//eof
//fail
//bad �����޸�
//good
void  test03()
{
	//���ļ�
	ifstream ifs("./test.txt", ios::in);
#if 0
	ifs.fail();
	ifs.bad();
	ifs.eof();
	ifs.good();
#endif
	if (!ifs)
	{
		cout << "�ļ���ʧ��!" << endl;
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
	//�ļ�ָ������Ϊ��ʼλ��
	ifs.seekg(0, ios::beg);

	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}

	//�ر��ļ�
	ifs.close();
}

void  test04()
{
	char buf1[1] = { 0 };
	cin.getline(buf1, 1);

	cout << boolalpha << cin.fail() << endl;
	cout << boolalpha << cin.good() << endl;

	//char buf2[2] = { 0 };
	//cin.getline(buf2, 2);

	//cout << boolalpha << cin.fail() << endl;
	//cout << boolalpha << cin.good() << endl;

	char b[1024] = { 0 };
	cin.get(b, 1024);
	cout << b << endl;
}

void print_state(const std::ios & stream)
{
	std::cout << " good()=" << stream.good();
	std::cout << " eof()=" << stream.eof();
	std::cout << " fail()=" << stream.fail();
	std::cout << " bad()=" << stream.bad();
}

void tese05()
{
	std::stringstream stream;

	stream.clear(stream.goodbit);
	std::cout << "goodbit:"; print_state(stream); std::cout << '\n';

	stream.clear(stream.eofbit);
	std::cout << " eofbit:"; print_state(stream); std::cout << '\n';

	stream.clear(stream.failbit);
	std::cout << "failbit:"; print_state(stream); std::cout << '\n';

	stream.clear(stream.badbit);
	std::cout << " badbit:"; print_state(stream); std::cout << '\n';
}

void test06()
{
	//�����Ʒ�ʽ��
	FILE* fp1 = fopen("./���ѧϰ3D��Ϸ.avi", "rb");
	//�����Ʒ�ʽд��
	FILE* fp2 = fopen("./a.avi", "wb");
	if (!fp1 || !fp2)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//ջ�Ͽ���һ������,��СΪ512*512�ֽ�
	char buf[BUFSIZ * BUFSIZ] = { 0 };

	while (!feof(fp1))
	{
		//����bufÿ�ζ�ȡ1��,��СΪBUFSIZ*BUFSIZ,��ȡ�ɹ����ض�������Ч�ֽ�,��ȡʧ�ܷ���0
		int len = fread(buf, 1, BUFSIZ * BUFSIZ, fp1);
		//printf("len = %d\n", len);
		cout << "len= " << len << endl;
		//д���ļ�,�ļ�Դbuf,ÿ��д��1��,��СΪlen����Ч�ֽ�
		fwrite(buf, 1, len, fp2);
		memset(buf, 0, BUFSIZ * BUFSIZ);
	}
	fclose(fp1);
	fclose(fp2);
}

void test07()
{
	//�˰汾Ч�ʵ�
	ifstream is("./���ѧϰ3D��Ϸ.avi", ios::in | ios::binary);
	ofstream os("aa.avi", ios::out | ios::binary);
	/*is.open("./���ѧϰ3D��Ϸ.avi", ios::in | ios::binary);
	os.open("aa.avi", ios::out | ios::binary);*/

	if (is.fail() || os.fail())
	{
		is.close();
		os.close();
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//���ļ�����os����
	os << is.rdbuf();

	is.close();
	os.close();
}

void test08()
{
	ifstream is("./���ѧϰ3D��Ϸ.avi", ios::in | ios::binary);
	ofstream os("./aa.avi", ios::out | ios::binary);
	if (!is || !os)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	char buf[BUFSIZ * BUFSIZ] = { 0 };
	long long nRead = 0;
	while (!is.eof())
	{
		//gcount()��������ֵ��langlang����,����Ҫ��langlang��������
		istream& temp = is.read(buf, BUFSIZ * BUFSIZ);
		nRead = temp.gcount();

		//is.read(buf, BUFSIZ*BUFSIZ)���ص��Ƕ���,���Խ�����ʽ���
		//nRead = is.read(buf, BUFSIZ*BUFSIZ).gcount();
		cout << "nRead= " << nRead << endl;
		//д��,ÿ��д��nRead��С
		os.write(buf, nRead);
	}
	is.close();
	os.close();
}

void main()
{
	char ch[] = "Hello World";
	char des[256] = { 0 };
	strcpy_s(des, strlen(ch) + 1, ch);
	system("pause");
}