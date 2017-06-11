#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

//1. 文本方式读写文件
void test01write()
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
        "12345789\n",
        "987654321\n",
        "abcdefghi\n",
        "ddddddddd\n"
    };

#if 1 文件按字符写入
    int len = sizeof(buf) / sizeof(char *);
    for (int i = 0; i < len; ++i)
    {
        int lineLen = strlen(buf[i]);
        for (int j = 0; j < lineLen; ++j)
        {
            ofs.put(buf[i][j]);
        }
    }
#endif

#if 0 文件按行写入
    int len = sizeof(buf) / sizeof(char *);
    for (int i = 0; i < len; ++i)
    {
        ofs << buf[i];
    }
#endif // 0

    //关闭文件
    ofs.close(); //刷新缓冲区， 关闭文件
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
    //打开文件
    ifstream ifs("./test.txt", ios::in);
    if (!ifs)
    {
        cout << "文件打开失败!" << endl;
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

    //清理后才能重新读取
    // ifs.clear();
    ifs.clear(ios_base::eofbit);

    ifs.seekg(0);

    while (ifs >> buf2)
    {
        cout << buf2 << endl;
        memset(buf2, 0, 1024);
    }
    //关闭文件
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
        char * buffer = new char[length];

        // read data as a block:
        is.read(buffer, length);

        is.close();

        // print content:
        std::cout.write(buffer, length);

        delete[] buffer;
    }

    return 0;
}

//2. 二进制文件读写
class Person
{
public:
    Person(const char *name, int age)
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
    //对象数组
    Person persons[3]{ Person("aaa", 10), Person("bbb", 20), Person("ccc", 30) };
    //将数据写入文件
    ofstream ofs("./persons.dat", ios::out | ios::binary);
    if (!ofs)
    {
        cout << "打开失败!" << endl;
    }
    //将对象以二进制的方式写入文件
    ofs.write((const char *)persons, sizeof(Person) * 3);
    //关闭文件
    ofs.close();
}

void test02read()
{
    ifstream ifs("./persons.dat", ios::in | ios::binary);
    if (!ifs)
    {
        cout << "打开失败!" << endl;
    }

    //开辟内存
    char *person = (char *)malloc(sizeof(Person) * 3);
    memset(person, 0, sizeof(Person) * 3);

    ifs.read(person, sizeof(Person) * 3);

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
    ifs.seekg(0, ios::beg);

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

void print_state(const std::ios& stream)
{
    std::cout << " good()=" << stream.good();
    std::cout << " eof()=" << stream.eof();
    std::cout << " fail()=" << stream.fail();
    std::cout << " bad()=" << stream.bad();
}

#include <sstream>

int tese05()
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

    return 0;
}

int main()
{
    test04();
    system("pause");
    return EXIT_SUCCESS;
}