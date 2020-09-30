#include <iostream>
#include <iomanip>
#include <array>
#include <tuple>
#include <string>
#include <algorithm>
#include "file_reader.h"
#include "arr_op.h"

using namespace concurrency;
using namespace std;

const size_t maxRecords{ 100 };
using Record = std::tuple<int, std::string, std::string, int>;
using Records = std::array<Record, maxRecords>;
using namespace std;

int stonetolb(int);

int stonetolb(int sts)
{
	return 14 * sts;
}

struct info
{
	int a;
	char b[30];
};

typedef char* PChar0;
#define PChar1 char*
FILE* stream, * stream2;

void main01()
{
	const int  hj = 10;
	int a[hj];//a是数组名,下标必须是常量或者常量表达式  ，
	//为了有效使用内存，并且内存是碎片化的

	//int类型规定了占据4个内存字节，有10个元素，规定了占据40个字节

	printf("%p", a);//a是数组名，等价于内存地址
	printf("\n数组内存字节%d", sizeof(a));//求出数组占据多少内存
	printf("\n数组占据%d个元素", sizeof(a) / sizeof(int));//求出数组有多少个元素
	a[0] = 100;//直接访问数组的元素
	for (int i = 0; i < 10; i++)
	{
		//a[i]=i;//对数组循环初始化

		a[i] = rand() % 100;//rand就是随机数生成，除以100的余数限定了它的范围
	}
	for (int j = 0; j < 12; j++)
	{
		//printf("\n%d,%p,%p", a[j], &a[j], a + j);
		//循环打印数组的每一个元素

		//int类型，每个元素地址相隔4个字节
		//a+j是计算机访问内存的方法，a+0相当于第一个元素的地址，
		//a+1相当于第二个元素的地址，a+2相当于第三个元素的地址
		//&a[j]等价于a+j
	}
	//数组不可以越界，越界以后读取到其他的内存，所以读取的数据的很垃圾,等价于变量没有初始化
	//数组越界，后果是自己承担，我们要遵守规则，不要越界
}
/*********************************************************************************************************************/
void main02()
{
	int hj3[10] = { 1, 2, 3, 4, 5 };//除了循环初始化，也可以大括号集合初始化
	//一唯数组初始化的一般格式{1,2,3,4,5,6,7,8,9,0}
	//如果数组的元素超过了大括号中集合的元素，没有得到赋值的元素，就会被初始化为0

	//int hj4[10];//数组没有初始化，出现的垃圾数据

	int hj1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//元素大小确定的场合，数组的大小可以省略;
	//int hj2[];//数组必须有明确的大小

	//int jk[]={};数组必须要有明确的大小，必须是正整数

	int hj5[10] = { 0 };//所有的元素初始化为0
	/*
	int  b[  ]={1,2,3,4};有四个元素
	int  b[10]={1,2,3,4};有十个元素，所以不等价
	*/

	for (int i = 0; i < 10; i++)
	{
		printf("\n%d", hj5[i]);
	}
}
/*********************************************************************************************************************/
void main03()
{
	int a[3] = { 1, 2, 3 };
	int b[3];
	// b=a;数组之间不可以直接赋值,可以对挨个元素赋值
	printf("%p,%p", a, b);
	//a,b就是内存地址，是一个整数，
	//b+=a;数组不允许直接运算，直接赋值
	if (a > b)
	{
		//可以比较，实际上比较的是内存地址，对实际的数组没有任何影响
	}

	//printf("%d",a[1]);//只能输出某个元素，不能整体性输出;

	char  c[3] = { 'a', 'v', '\0' };//用字符数组代表字符串必须包含一个/0
	printf("%s", c);//按照字符串输出，字符串以/0为结束。
}
/*********************************************************************************************************************/
void main04()
{
	int a[10]; //0,1,2,3,4,5,6,7,8,9
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	for (int j = 0; j < 10; j++)
	{
		printf("\n%d", a[9 - j]);//??Dòê?3?
	}
}
/*********************************************************************************************************************/
void main05()
{
	int a[40] = { 1, 1 };
	//a[0]=1,a[1]=1;
	//a[2]=a[1]+a[0];
	//a[3]=a[2]+a[1];
	for (int i = 2; i <= 39; i++)
	{
		a[i] = a[i - 1] + a[i - 2];//实现斐波那契数列的计算
	}
	//循环打印出数组每一个元素
	for (int j = 0; j < 40; j++)
	{
		if (j % 5 == 0)//检测是否被5整除
		{
			printf("\n");//打印换行
		}
		printf("%d    ", a[j]);
	}
}
/*********************************************************************************************************************/
//实现找出最小的元素
void main06()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;//取0到100的随机数
	}
	for (int j = 0; j < 10; j++)
	{
		printf("\n%d", a[j]);
	}
	int min;//最小的元素
	min = a[0];

	printf("\n\n\n");
	for (int k = 1; k < 10; k++)
	{
		if (min > a[k])//吧ak,min的最小值存入min
		{
			//交换两个变量
			int temp;
			temp = min;
			min = a[k];
			a[k] = temp;
		}
		printf("\nk=%d,min=%d,a[%d]=%d ", k, min, k, a[k]);
		a[0] = min;//赋值给第一个元素，让第一个元素最小
		for (int u = 0; u < 10; u++)//打印出数组的状态
		{
			printf("\n%d", a[u]);
		}
	}
	printf("\n%d", min);
}
/*********************************************************************************************************************/
void main07()
{
	const int N = 10;
	int  a[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;//取0-1000之间的随机数
	}
	for (int j = 0; j < N; j++)
	{
		printf("\n%d", a[j]);//打印出数组的数据
	}
	printf("\n\n\n");
	int minb = 0;//保存临时的最小值的下标
	int min = 0;//临时的最小值
	for (int u = 0; u < N - 1; u++)//10个，一直到两个之间，选择极小值。
	{
		minb = u;//假定当前元素为最小元素
		for (int v = u + 1; v < N; v++)//u=0,a[1]到a[N-1],u=1,a[2]到a[N-1]
		{
			if (a[v] < a[minb])//吧a[v] a[minb]中间最小数的下标保存到minb
			{
				minb = v;    //循环判断，吧最小的下标存入minb,
				//
			}
		}
		printf("\n 调整以前的数据\n");
		for (int iii = 0; iii < N; iii++)
		{
			printf("%d    ", a[iii]);//打印出数组的数据
		}

		if (minb != u)//如果minb发生变化，就交换两个变量的值
		{
			//完成两个变量的交换
			int temp = a[minb];
			a[minb] = a[u];
			a[u] = temp;
		}
		printf("\n 调整以后的数据\n");
		for (int ii = 0; ii < N; ii++)
		{
			printf("%d    ", a[ii]);//打印出数组的数据
		}
	}

	printf("\n\n\n");

	for (int jj = 0; jj < N; jj++)
	{
		printf("\n%d", a[jj]);//打印出数组的数据
	}
}
/*********************************************************************************************************************/
//创建一个数组，实现从小到大，从大到小
void main08()
{
	const  int  N = 10;
	int a[N];
	int  i = 10;//外部变量，作于域也就是大括号包含起来的块语句
	for (int i = 0; i < 10; i++)//如果变量重名，以内部变量为优先。
	{
		a[i] = rand() % 125;//取0到125的随机数
		printf("%d   ", a[i]);
	}

	int min;//代表最大最小数组元素的下标

	for (int u = 0; u < N - 1; u++)
	{
		min = u;//假定从u开始时最小的变量
		printf("轮询时刻，min,v的值");
		for (int v = u + 1; v < N; v++)//从u+1到最后一个变量做一个轮训
		{
			if (a[v] < a[min])
			{
				min = v;//循环交替，使得最后一个值是最值
				printf("%d,%d    ", min, v);
			}
		}

		printf("\n数组操作之前的状态\n");
		for (int i = 0; i < N; i++)
		{
			printf("%d  ", a[i]);
		}
		if (min != u)
		{
			//实现两个变量的交换
			int temp;
			temp = a[min];
			a[min] = a[u];
			a[u] = temp;
		}
		printf("\n数组操作之后的状态\n");
		for (int i = 0; i < N; i++)
		{
			printf("%d  ", a[i]);
		}
	}
	//
	printf("\n数组排序以后的状态\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d  ", a[i]);
	}
}
/*********************************************************************************************************************/
//循环打印出二维数组
void main09()
{
	int a[4] = { 1, 2, 3, 4 };
	int b[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	//  b[2][3],
	printf("%d", sizeof(b) / sizeof(int));
	for (int i = 0; i < 3; i++)//外层循环
	{
		for (int j = 0; j < 4; j++)//内层循环
		{
			printf("\n%d,%d,%d,%p", i, j, b[i][j], &b[i][j]);
			//内存里面是一行一行来进行存储
		}
	}
}
/*********************************************************************************************************************/
void main10()
{
	int  hj[5] = { 1, 2, 3, 4, 5 };
	for (int o = 0; o < 5; o++)
	{
		printf("\n%d,%p,%p", hj[o], &hj[o], hj + o);
	}
	int a[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	//3指定有几行，2就代表每行有两列
	int  a1[][5] = { 1, 3, 4, 5, 6 };//在元素确定的情况下，可以不指定有几行
	//int  a2[2][5]={{1,2,3},{4,5,6}};//每一行有几列必须指定。
	int  a2[2][5] = { 0 };//所有的元素都为0
	printf("a2地址%p\n", a2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("\n%d,%p,%p", a2[i][j], &a2[i][j], a2[i] + j);
		}
	}
}
/*********************************************************************************************************************/
void main11()
{
	const int N = 3;//const定义常量
	int a[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = i * N + j + 1;//数学公式
			printf("%d   ", a[i][j]);//打印出每个元素的数据
		}
		printf("\n");//隔行换行
	}
	int jieguo = 0;
	for (int k = 0; k < N; k++)
	{
		jieguo += a[k][k];//对角线，横纵坐标相等
	}
	printf("\n%d", jieguo);
}
/*********************************************************************************************************************/
void main12()
{
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d     ", a[i][j]);
		}
		printf("\n");//每行打印完成以后换行
	}

	int b[4][3];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[j][i];
			printf("%d   ", b[i][j]);
		}
		printf("\n");//换行
	}
}
/*********************************************************************************************************************/
void main13()
{
	const int N = 8;
	int a[N][N];

	int data = 1;
	//对于数组进行填充,N*N个元素
	//i,j起到控制横坐标与纵坐标
	for (int i = 0, j = 0, k = 0; k < (N + 1) / 2; k++)//k起到分层的作用,层<k+1/2,根据层数才循环
	{
		while (j < N - k)
		{
			//a[i][j++]=data++;
			a[i][j] = data;  //横向向左a[0][0]    a[0][1]  a[0][2] ，i不变，j变化
			j = j + 1;
			data = data + 1;
			//	printf("")
		}
		j--;//消除最后的影响，不越界
		i++;//改变行，

		while (i < N - k)
		{
			a[i][j] = data;
			i = i + 1;
			data = data + 1;
		}
		i--;//消除最后的影响，不越界
		j--;

		while (j > k - 1)
		{
			a[i][j] = data;
			j = j - 1;
			data = data + 1;
		}
		j++;//消除最后的影响，不越界
		i--;

		while (i > k)
		{
			a[i][j] = data;
			i = i - 1;
			data = data + 1;
		}
		i++;//消除最后的影响，不越界
		j++;
	}
	//对于数组进行打印
	for (int u = 0; u < N; u++)
	{
		for (int v = 0; v < N; v++)
		{
			printf("%10d", a[u][v]);
		}
		printf("\n");
	}
}
/*********************************************************************************************************************/
void main14()
{
	char s1[10] = { 'A', 'B', 'C', 'D', 'M', '1', '2', 'T', 'U', '\0' };
	printf("\n%s", s1);
	for (int i = 0; i < 10; i++)
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			s1[i] += 32;
		}
	}
	printf("\n%s", s1);

	char s2[4] = { '1', '2', '3', '\0' };
	printf("\n%s", s2);
	for (int i = 0; i < 10; i++)
	{
		int  flag = 1;
		for (int j = 0; j < 3; j++)
		{
			if (s1[i + j] != s2[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("\nOK");
		}
	}
}
/*********************************************************************************************************************/
void main15_erfen()
{
	int a[4096];
	for (int i = 0; i < 4096; i++)
	{
		a[i] = i + 1;
	}
	int hj;
	scanf_s("%d", &hj);
	int tou = 0;
	int wei = 4095;
	int zhong = (tou + wei) / 2;
	int cishu = 0;
	int flag = 0;//假定找不到
	while (tou <= wei)//找到为止
	{
		cishu += 1;
		printf("\n%d,%d,%d", tou, zhong, wei);
		if (hj == a[zhong])
		{
			flag = 1;
			printf("\n数据类型找到位置%d", zhong);
			break;
		}
		else if (hj > a[zhong])//大于
		{
			tou = zhong + 1;
			zhong = (tou + wei) / 2;
		}
		else if (hj < a[zhong])//小于
		{
			wei = zhong - 1;
			zhong = (tou + wei) / 2;
		}
	}

	if (flag == 0)
	{
		printf("没有找到");
	}

	printf("一共执行%d次 ", cishu);
}
/*********************************************************************************************************************/
void main16_GoTo循环()
{
	int i = 1;
	int  j = 2;

C:  printf("%d,%d", i, j);
	goto C;
}
/*********************************************************************************************************************/
void main17_GoTo求和()
{
	int i = 1;
	int result = 0;
begin: if (i <= 100)
{
	result += i;//result=result+i
	i += 1;
	printf("\ni=%d,result=%d", i, result);
	goto begin;
}
}
/*********************************************************************************************************************/
void showmatrix(int* matrix, int length)
{
	int i, j;

	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			printf("%d\t", matrix[i * length + j]);
		}
		printf("\n");
	}
}

void BuildHelixmatrix(int length)
{
	int i, j, k;
	int a = 1;
	j = length - 1;
	i = k = 0;

	int* matrix = (int*)malloc(sizeof(int) * length * length);
	if (!matrix) {
		return;
	}
	for (; k < (length + 1) / 2; k++)  //k为层数
	{
		while (i < length - k)   //向下
		{
			//int  a1;

			matrix[i++ * length + j] = a++;  //a 为填充的自然数

			//printf("%d",matrix[a1]);
		}
		i--;  //复位一步
		j--;

		while (j > k)   //向左
		{
			matrix[i * length + j--] = a++;
		}
		j++;  //复位一步
		i++;
	}
	while (i > k - 1)   //向上
	{
		matrix[i-- * length + j] = a++;
	}
	i--;
	j--;
	while (j < length - k)   //向右
	{
		matrix[i * length + j++] = a++;
	}
	j--;
	i++;

	showmatrix(matrix, length);

	printf("\n");
}

/*********************************************************************************************************************/
int add(int x, int y)//加法的函数
{
	return x + y; //返回加法的结果
}

int mult(int x, int y)
{
	return x * y;
}

//函数int add(int x,int y);
void Point01()
{
	int a = 1;
	int b = 2;

	printf("%d", add(a, b));

	int(*p)(int, int);//函数指针类型，第一个int返回值类型，后面两个int是参数

	p = add;//add就是函数内存地址，p指针变量，函数指针

	printf("%p", p);
	printf("\n%d", p(a, b));//打印出1+2，打印p，也是函数的内存地址
	p = mult;
	printf("\n%p", p);
	printf("\n%d", p(a, b));
}

//指针修改变量
void Point02()
{
	int a = 1;
	int b = 2;
	int c = 0;
	printf("\na地址=%p,b地址=%p,c地址=%p", &a, &b, &c);

	c = a + b;

	printf("\n%d", c);//数学计算

	int* p;
	p = &a;//p相当于内存地址，等价于int *, int起到指示占据四个字节，从这个内存地址开始
	*p = 5;//*p相当于int类型数据，指针P所指向的数据
	printf("\n%d", a);
	printf("\n%p,%d", p, *p);

	printf("\n%d", add(a, b));//调用函数实现加减
}
/*********************************************************************************************************************/
double func1(double num)
{
	num += 0.04;
	return (((int)(num * 10)) / 10.0);
}

double func2(double num)
{
	num += 0.005;
	return (((int)(num * 100)) / 100.0);
}

int func()
{
	double a = 1.25;
	double b = 1.26;
	double c = 1.224;
	double d = 1.225;
	printf("a = %lf   , b = %lf   \n", func1(a), func1(b));
	printf("c = %lf   , d = %lf   \n", func2(c), func2(d));

	return 0;
}
/*********************************************************************************************************************/

void main18_指针()
{
	char* p1;
	char* p2;
	char c = 'a';
	p1 = &c;
	p2 = &c;

	char* p3, * p4;
	char c34 = 'a';
	p3 = &c34;
	p4 = &c34;
}

void listRecords(const Records& people)
{
	const size_t ID{}, firstname{ 1 }, secondname{ 2 }, age{ 3 };
	cout << setiosflags(std::ios::left);
	Record empty;
	for (const auto& record : people)
	{
		if (record == empty)
			break;
		cout << "ID: " << setw(6) << get<ID>(record)
			<< "Name: " << setw(25) << (get<firstname>(record) + " " + get<secondname>(record))
			<< "Age: " << setw(5) << get<age>(record) << endl;
	}
}

void main18()
{
	int a{ 15 };
	cout << a << endl;
	Records personnel
	{ Record(1001, "Arthur", "Dent", 35),
		Record{ 1002, "Mary", "Poppins", 55 },
		Record{ 1003, "David", "Copperfield", 34 },
		Record{ 1004, "James", "Bond", 44 } };
	personnel[4] = make_tuple(1005, "Harry", "Potter", 15);
	personnel.at(5) = Record{ 1006, "Bertie", "Wooster", 28 };

	listRecords(personnel);
}

void main19()
{
	int width{ 1280 };
	int height{ 1024 };
	//   double aspect = width / height;
	double aspect{ static_cast<double>(width) / height };

	cout << "The aspect ratio is " << aspect << endl;
}

void main20()
{
	using namespace std;

	int carrots;            // declare an integer variable

	carrots = 25;            // assign a value to the variable
	cout << "I have ";
	cout << carrots;        // display the value of the variable
	cout << " carrots.";
	cout << endl;
	carrots = carrots - 1;  // modify the variable
	cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl;
	// cin.get();
}

void main21()
{
	using namespace std;
	int stone;
	cout << "Enter the weight in stone: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " stone = ";
	cout << pounds << " pounds." << endl;
	// cin.get();
	// cin.get();
}

void main22()
{
	using namespace std;

	int carrots;

	cout << "How many carrots do you have?" << endl;
	cin >> carrots;                // C++ input
	cout << "Here are two more. ";
	carrots = carrots + 2;
	// the next line concatenates output
	cout << "Now you have " << carrots << " carrots." << endl;
	// cin.get();
	// cin.get();
}

void main23()
{
	// i is an int; p is a pointer to int; r is a reference to int
	int i = 1024, * p = &i, & r = i;

	// three ways to print the value of i
	cout << i << " " << *p << " " << r << endl;

	int j = 42, * p2 = &j;
	int*& pref = p2;  // pref is a reference to the pointer p2

					  // prints the value of j, which is the int to which p2 points
	cout << *pref << endl;

	// pref refers to a pointer; assigning &i to pref makes p point to i
	pref = &i;
	cout << *pref << endl; // prints the value of i

						   // dereferencing pref yields i, the int to which p2 points;
	*pref = 0;  // changes i to 0

	cout << i << " " << *pref << endl;
}

void main24()
{
	int x = -1;
	cout << "x=" << x << endl;
	if (x)
	{
		cout << "x true" << endl;
	}
	else
	{
		cout << "x false" << endl;
	}

	int y = 0;
	cout << "y=" << y << endl;
	if (y)
	{
		cout << "y true" << endl;
	}
	else
	{
		cout << "y false" << endl;
	}

	int z = 1;
	cout << "z=" << z << endl;
	if (z)
	{
		cout << "z true" << endl;
	}
	else
	{
		cout << "z false" << endl;
	}

	cout << "+++++++++++++++++++++++" << endl;
	bool b = 42;
	cout << b << endl;

	int j = b;
	cout << j << endl;

	double pi = 3.14;
	cout << pi << endl;

	j = pi;
	cout << j << endl;

	unsigned char c = -10;
	int i = c;

	cout << i << endl;
}

void main25()
{
	int ival = 1024;
	int* pi = &ival;   // pi points to an int
	int** ppi = &pi;   // ppi points to a pointer to an int
	cout << "The value of ival\n"
		<< "direct value: " << ival << "\n"
		<< "indirect value: " << *pi << "\n"
		<< "doubly indirect value: " << **ppi
		<< endl;

	int i = 2;
	int* p1 = &i;     // p1 points to i
	*p1 = *p1 * *p1;  // equivalent to i = i * i
	cout << "i  = " << i << endl;

	*p1 *= *p1;       // equivalent to i *= i
	cout << "i  = " << i << endl;
}

void main26()
{
	int a = 0;
	decltype(a) c = a;   // c is an int
	decltype((a)) d = a; // d is a reference to a
	++c;                 // increments c, a (and d) unchanged
	cout << "a: " << a << " c: " << c << " d: " << d << endl;
	++d;                 // increments a through the reference d
	cout << "a: " << a << " c: " << c << " d: " << d << endl;

	int A = 0, B = 0;
	decltype((A)) C = A;   // C is a reference to A
	decltype(A = B) D = A; // D is also a reference to A
	++C;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;
	++D;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;
}

void main27() {
	std::cout << '\n';       // prints a newline
	std::cout << "\tHi!\n";  // prints a tab followd by "Hi!" and a newline
	std::cout << "Hi \x4dO\115   !    \n"; // prints Hi MOM! followed by a newline
	std::cout << '\115' << '\n';    // prints M followed by a newline
}

void main28()
{
	char buffer[81];
	int i, ch;

	for (i = 0; (i < 80) && ((ch = getchar()) != EOF) && (ch != '\n'); i++) {
		buffer[i] = (char)ch;
	}

	buffer[i] = '\0';
	printf("Input was: %s\n", buffer);
}

void main29(void)
{
	int c;
	int a;
	a = getchar();

	if (EOF != a)
		printf("%c", a);

	while ((c = getchar()) != '\n')//c接收的值是输入第一个字符后按下的回车换行符'\n',c是不会显示的
	{
		if (EOF == a)
			break;
		printf("%c", c);
	}
}

void main30()
{
	int v1(1024);    // direct-initialization, functional form
	int v3 = 1024;   // copy-initialization

					 // alternative ways to initialize string from a character string literal
	std::string titleA = "C++ Primer, 5th Ed.";
	std::string titleB("C++ Primer, 5th Ed.");
	std::string all_nines(10, '9');  // all_nines = "9999999999"
}

//==%p是打印地址的，%x是以十六进制形式打印，完全不同！另外在64位下结果会不一样，所以打印指针老老实实用%p。=

class dog
{
public:
	dog()
	{
		_legs = 4;
		_bark = true;
	}

	void setDogSize(string dogSize)
	{
		_dogSize = dogSize;
	}
	virtual void setEars(string type)
	{
		_earType = type;
	}

private:
	string _dogSize, _earType;
	int _legs;
	bool _bark;
};

class breed : public dog
{
public:
	breed(string color, string size)
	{
		_color = color;
		setDogSize(size);
	}

	string getColor()
	{
		return _color;
	}

	void setEars(string length, string type)
	{
		_earLength = length;
		_earType = type;
	}

protected:
	string _color, _earLength, _earType;
};

void main31()
{
	dog mongrel;
	breed labrador("yellow", "large");
	mongrel.setEars("pointy");
	labrador.setEars("long", "floppy");
	cout << "Cody is a " << labrador.getColor() << " labrador" << endl;
}

void  main32_basicAgent()
{
	// An event object that signals the end of processing.
	event e;

	// The components of the Adler-32 sum.
	unsigned int a = 1;
	unsigned int b = 0;

	// A call object that updates the checksum when it receives data.
	call<string> calculate_checksum([&](string s) {
		// If the input string is empty, set the event to signal
		// the end of processing.
		if (s.size() == 0)
			e.set();
		// Perform the Adler-32 checksum algorithm.
		for_each(begin(s), end(s), [&](char c) {
			a = (a + c) % 65521;
			b = (b + a) % 65521;
			});
		});

	// Create the agent.
	file_reader reader("demo.cpp", calculate_checksum);

	// Start the agent and wait for it to complete.
	reader.start();
	agent::wait(&reader);

	// Wait for the call object to receive all data and complete.
	e.wait();

	// Check the file reader for errors.
	// If no error occurred, calculate the final Adler-32 sum and print it
	// to the console.
	std::exception error;
	if (reader.get_error(error))
	{
		wcout << error.what() << endl;
	}
	else
	{
		unsigned int adler32_sum = (b << 16) | a;
		wcout << L"Adler-32 sum is " << hex << adler32_sum << endl;
	}
}

void main33_concurrencydemo()
{
	concurrency::reader_writer_lock().lock();
	concurrency::reader_writer_lock().lock_read();
	concurrency::reader_writer_lock().unlock();
	concurrency::reader_writer_lock().try_lock();
	concurrency::reader_writer_lock().try_lock_read();
	concurrency::reader_writer_lock().~reader_writer_lock();
}

void demo01()
{
	FILE* pf;
	fopen_s(&pf, "bin1.txt", "rb");//r==read,fopen打开一个文件
	if (pf == NULL)
	{
		printf("文件打开失败");
	}
	else
	{
		printf("文件打开成功\n");

		struct info  a1, a2, a3;
		a1.a = 123;
		const char* str1 = "abc";
		strcpy_s(a1.b, str1);

		a2.a = 123;
		const	char* str2 = "opq";
		strcpy_s(a2.b, str2);

		a3.a = 123;
		const	char* str3 = "xyz";
		strcpy_s(a3.b, str3);

		fwrite(&a1, sizeof(a1), 1, pf);
		fwrite(&a2, sizeof(a2), 1, pf);
		fwrite(&a3, sizeof(a3), 1, pf);

		fclose(pf);
	}
	system("pause");
}

void demo02()
{
	FILE* fp;
	fopen_s(&fp, "bin1.txt", "rb");

	if (fp == NULL)
	{
		printf("文件打开失败");
	}
	else
	{
		while (!feof(fp))//从光标的开头
		{
			char str[80];
			fgets(str, 80, fp);//每次读取9个字符

			printf("\n%s", str);
			printf("\n%p", fp->_Placeholder);//光标的地址
		}
		rewind(fp);//将光标移动到文件开头
		int  weiyi = 10;
		fseek(fp, 10, SEEK_CUR);//从当前位置读到尾部
		printf("\n\n\n\n\n\n\n\n\n");
		while (!feof(fp))//从光标的开头,检测到结束为标志
		{
			char str[80];
			fgets(str, 80, fp);//每次读取9个字符

			printf("\n%s", str);
			//printf("\n%x", fp->_ptr);//光标的地址
		}

		rewind(fp);//将光标移动到文件开头
		fseek(fp, -80, SEEK_END);//根据这个位置，前后移动，
		printf("\n\n\n\n\n\n\n\n\n");

		char str[80] = { 0 };//往前读，必须数组初始化
		//fgets(str,80,fp);//每次读取9个字符,
		fread(str, 1, 79, fp);

		printf("\n%s", str);
		//printf("\n%x", fp->_ptr);//光标的地址

		fclose(fp);
	}
	system("pause");
}

void demo03()
{
	std::array<int, 3> arr = { 9, 8, 7 };
	cout << "Array size = " << arr.size() << endl;
	for (auto i : arr)
	{
		cout << i << endl;
	}

	system("pause");
}

void demo04()
{
	int numclosed;
	errno_t err;

	//?Open?for?read?(will?fail?if?file?"crt_fopen_s.c"?does?not?exist)
	if ((err = fopen_s(&stream, "crt_fopen_s.c", "r")) != 0)
	{
		printf("The?file?'data.txt'?was?not?opened\n");
	}
	else
	{
		printf("The?file?'crt_fopen_s.c'?was?opened\n");
	}
	if ((err = fopen_s(&stream2, "data2", "w+")) != 0)
	{
		printf("The?file?'data2'?was?not?opened\n");
	}
	else
	{
		printf("The?file?'data2'?was?opened\n");
	}
	if (stream)
	{
		if (fclose(stream))
		{
			printf("The?file?'crt_fopen_s.c'?was?not?closed\n");
		}
	}
	numclosed = _fcloseall();
	printf("Number?of?files?closed?by?_fcloseall:?%u\n", numclosed);
	system("pause");
}

void demo05()
{
	FILE* fp;
	int re = fopen_s(&fp, "data.txt", "w");
	if (fp) {
		fputs("你好吗", fp);
		fclose(fp);
	}
}

void demo06()
{
	char str[1024] = {};
	gets_s(str);
	puts(str);
	system(str);
}

void demo07()
{
	struct  Student
	{
		int Id;
		char UserName[10];
		char MobilePhoe[20];
		char UserPassword[20];
	} stu1, stu2;

	stu1.Id = 123456;
	strcpy_s(stu1.UserName, "胡睿毅");
	strcpy_s(stu1.MobilePhoe, "13612340000");
	strcpy_s(stu1.UserPassword, "Passord");

	printf("Id=%d\nUserName=%s\nMobilePhoe=%s\nUserPassword=%s\n", stu1.Id, stu1.UserName, stu1.MobilePhoe, stu1.UserPassword);

	stu2 = stu1;
	if (stu2.Id == NULL)
	{
		printf("为.0");
	}
	printf("Id=%d\nUserName=%s\nMobilePhoe=%s\nUserPassword=%s\n", stu2.Id, stu2.UserName, stu2.MobilePhoe, stu2.UserPassword);
}

void demo08()
{
	PChar0 p1, p2;
	char c = 'a';
	p1 = &c;
	p2 = &c;
}

void demo09()
{
	PChar1 p3;
	PChar1 p4;

	char c = 2;
	p3 = &c;
	p4 = &c;
}

int demo10_Random_Array()
{
	int iArray[ArraySize] = { 0 };//初始化数组

	for (int i = 0; i < ArraySize; i++)
	{
		iArray[i] = rand() % 100 + 100;
	}

	PrintArray(iArray, ArraySize);
	bubble_sort_ascend(iArray, ArraySize);
	PrintArray(iArray, ArraySize);
	bubble_sort_descend(iArray, ArraySize);
	PrintArray(iArray, ArraySize);
	printf("In this array, the max value is:%d\n", GetMaxNum(iArray, ArraySize));
	printf("In this array, the min value is:%d\n", GetMinNum(iArray, ArraySize));
	bubble_sort_ascend(iArray, ArraySize);
	printf("The element %d in this array No.%d\n", 112, BinarySearch(iArray, ArraySize, 112) + 1);

	system("pause");

	return 0;
}

void demo11() {
	char c1 = '\u03a0';   // C4566
	char c2 = '\u0642';   // C4566

	wchar_t c3 = L'\u03a0';   // OK
	wchar_t c4 = L'\u0642';   // OK
}
int wmain()
{
	demo10_Random_Array();
	return 0;
}