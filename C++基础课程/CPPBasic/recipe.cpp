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
	int a[hj];//a��������,�±�����ǳ������߳������ʽ  ��
	//Ϊ����Чʹ���ڴ棬�����ڴ�����Ƭ����

	//int���͹涨��ռ��4���ڴ��ֽڣ���10��Ԫ�أ��涨��ռ��40���ֽ�

	printf("%p", a);//a�����������ȼ����ڴ��ַ
	printf("\n�����ڴ��ֽ�%d", sizeof(a));//�������ռ�ݶ����ڴ�
	printf("\n����ռ��%d��Ԫ��", sizeof(a) / sizeof(int));//��������ж��ٸ�Ԫ��
	a[0] = 100;//ֱ�ӷ��������Ԫ��
	for (int i = 0; i < 10; i++)
	{
		//a[i]=i;//������ѭ����ʼ��

		a[i] = rand() % 100;//rand������������ɣ�����100�������޶������ķ�Χ
	}
	for (int j = 0; j < 12; j++)
	{
		//printf("\n%d,%p,%p", a[j], &a[j], a + j);
		//ѭ����ӡ�����ÿһ��Ԫ��

		//int���ͣ�ÿ��Ԫ�ص�ַ���4���ֽ�
		//a+j�Ǽ���������ڴ�ķ�����a+0�൱�ڵ�һ��Ԫ�صĵ�ַ��
		//a+1�൱�ڵڶ���Ԫ�صĵ�ַ��a+2�൱�ڵ�����Ԫ�صĵ�ַ
		//&a[j]�ȼ���a+j
	}
	//���鲻����Խ�磬Խ���Ժ��ȡ���������ڴ棬���Զ�ȡ�����ݵĺ�����,�ȼ��ڱ���û�г�ʼ��
	//����Խ�磬������Լ��е�������Ҫ���ع��򣬲�ҪԽ��
}
/*********************************************************************************************************************/
void main02()
{
	int hj3[10] = { 1, 2, 3, 4, 5 };//����ѭ����ʼ����Ҳ���Դ����ż��ϳ�ʼ��
	//һΨ�����ʼ����һ���ʽ{1,2,3,4,5,6,7,8,9,0}
	//��������Ԫ�س����˴������м��ϵ�Ԫ�أ�û�еõ���ֵ��Ԫ�أ��ͻᱻ��ʼ��Ϊ0

	//int hj4[10];//����û�г�ʼ�������ֵ���������

	int hj1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//Ԫ�ش�Сȷ���ĳ��ϣ�����Ĵ�С����ʡ��;
	//int hj2[];//�����������ȷ�Ĵ�С

	//int jk[]={};�������Ҫ����ȷ�Ĵ�С��������������

	int hj5[10] = { 0 };//���е�Ԫ�س�ʼ��Ϊ0
	/*
	int  b[  ]={1,2,3,4};���ĸ�Ԫ��
	int  b[10]={1,2,3,4};��ʮ��Ԫ�أ����Բ��ȼ�
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
	// b=a;����֮�䲻����ֱ�Ӹ�ֵ,���Զ԰���Ԫ�ظ�ֵ
	printf("%p,%p", a, b);
	//a,b�����ڴ��ַ����һ��������
	//b+=a;���鲻����ֱ�����㣬ֱ�Ӹ�ֵ
	if (a > b)
	{
		//���ԱȽϣ�ʵ���ϱȽϵ����ڴ��ַ����ʵ�ʵ�����û���κ�Ӱ��
	}

	//printf("%d",a[1]);//ֻ�����ĳ��Ԫ�أ��������������;

	char  c[3] = { 'a', 'v', '\0' };//���ַ���������ַ����������һ��/0
	printf("%s", c);//�����ַ���������ַ�����/0Ϊ������
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
		printf("\n%d", a[9 - j]);//??D����?3?
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
		a[i] = a[i - 1] + a[i - 2];//ʵ��쳲��������еļ���
	}
	//ѭ����ӡ������ÿһ��Ԫ��
	for (int j = 0; j < 40; j++)
	{
		if (j % 5 == 0)//����Ƿ�5����
		{
			printf("\n");//��ӡ����
		}
		printf("%d    ", a[j]);
	}
}
/*********************************************************************************************************************/
//ʵ���ҳ���С��Ԫ��
void main06()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;//ȡ0��100�������
	}
	for (int j = 0; j < 10; j++)
	{
		printf("\n%d", a[j]);
	}
	int min;//��С��Ԫ��
	min = a[0];

	printf("\n\n\n");
	for (int k = 1; k < 10; k++)
	{
		if (min > a[k])//��ak,min����Сֵ����min
		{
			//������������
			int temp;
			temp = min;
			min = a[k];
			a[k] = temp;
		}
		printf("\nk=%d,min=%d,a[%d]=%d ", k, min, k, a[k]);
		a[0] = min;//��ֵ����һ��Ԫ�أ��õ�һ��Ԫ����С
		for (int u = 0; u < 10; u++)//��ӡ�������״̬
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
		a[i] = rand() % 100;//ȡ0-1000֮��������
	}
	for (int j = 0; j < N; j++)
	{
		printf("\n%d", a[j]);//��ӡ�����������
	}
	printf("\n\n\n");
	int minb = 0;//������ʱ����Сֵ���±�
	int min = 0;//��ʱ����Сֵ
	for (int u = 0; u < N - 1; u++)//10����һֱ������֮�䣬ѡ��Сֵ��
	{
		minb = u;//�ٶ���ǰԪ��Ϊ��СԪ��
		for (int v = u + 1; v < N; v++)//u=0,a[1]��a[N-1],u=1,a[2]��a[N-1]
		{
			if (a[v] < a[minb])//��a[v] a[minb]�м���С�����±걣�浽minb
			{
				minb = v;    //ѭ���жϣ�����С���±����minb,
				//
			}
		}
		printf("\n ������ǰ������\n");
		for (int iii = 0; iii < N; iii++)
		{
			printf("%d    ", a[iii]);//��ӡ�����������
		}

		if (minb != u)//���minb�����仯���ͽ�������������ֵ
		{
			//������������Ľ���
			int temp = a[minb];
			a[minb] = a[u];
			a[u] = temp;
		}
		printf("\n �����Ժ������\n");
		for (int ii = 0; ii < N; ii++)
		{
			printf("%d    ", a[ii]);//��ӡ�����������
		}
	}

	printf("\n\n\n");

	for (int jj = 0; jj < N; jj++)
	{
		printf("\n%d", a[jj]);//��ӡ�����������
	}
}
/*********************************************************************************************************************/
//����һ�����飬ʵ�ִ�С���󣬴Ӵ�С
void main08()
{
	const  int  N = 10;
	int a[N];
	int  i = 10;//�ⲿ������������Ҳ���Ǵ����Ű��������Ŀ����
	for (int i = 0; i < 10; i++)//����������������ڲ�����Ϊ���ȡ�
	{
		a[i] = rand() % 125;//ȡ0��125�������
		printf("%d   ", a[i]);
	}

	int min;//���������С����Ԫ�ص��±�

	for (int u = 0; u < N - 1; u++)
	{
		min = u;//�ٶ���u��ʼʱ��С�ı���
		printf("��ѯʱ�̣�min,v��ֵ");
		for (int v = u + 1; v < N; v++)//��u+1�����һ��������һ����ѵ
		{
			if (a[v] < a[min])
			{
				min = v;//ѭ�����棬ʹ�����һ��ֵ����ֵ
				printf("%d,%d    ", min, v);
			}
		}

		printf("\n�������֮ǰ��״̬\n");
		for (int i = 0; i < N; i++)
		{
			printf("%d  ", a[i]);
		}
		if (min != u)
		{
			//ʵ�����������Ľ���
			int temp;
			temp = a[min];
			a[min] = a[u];
			a[u] = temp;
		}
		printf("\n�������֮���״̬\n");
		for (int i = 0; i < N; i++)
		{
			printf("%d  ", a[i]);
		}
	}
	//
	printf("\n���������Ժ��״̬\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d  ", a[i]);
	}
}
/*********************************************************************************************************************/
//ѭ����ӡ����ά����
void main09()
{
	int a[4] = { 1, 2, 3, 4 };
	int b[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	//  b[2][3],
	printf("%d", sizeof(b) / sizeof(int));
	for (int i = 0; i < 3; i++)//���ѭ��
	{
		for (int j = 0; j < 4; j++)//�ڲ�ѭ��
		{
			printf("\n%d,%d,%d,%p", i, j, b[i][j], &b[i][j]);
			//�ڴ�������һ��һ�������д洢
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
	//3ָ���м��У�2�ʹ���ÿ��������
	int  a1[][5] = { 1, 3, 4, 5, 6 };//��Ԫ��ȷ��������£����Բ�ָ���м���
	//int  a2[2][5]={{1,2,3},{4,5,6}};//ÿһ���м��б���ָ����
	int  a2[2][5] = { 0 };//���е�Ԫ�ض�Ϊ0
	printf("a2��ַ%p\n", a2);

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
	const int N = 3;//const���峣��
	int a[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = i * N + j + 1;//��ѧ��ʽ
			printf("%d   ", a[i][j]);//��ӡ��ÿ��Ԫ�ص�����
		}
		printf("\n");//���л���
	}
	int jieguo = 0;
	for (int k = 0; k < N; k++)
	{
		jieguo += a[k][k];//�Խ��ߣ������������
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
		printf("\n");//ÿ�д�ӡ����Ժ���
	}

	int b[4][3];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[j][i];
			printf("%d   ", b[i][j]);
		}
		printf("\n");//����
	}
}
/*********************************************************************************************************************/
void main13()
{
	const int N = 8;
	int a[N][N];

	int data = 1;
	//��������������,N*N��Ԫ��
	//i,j�𵽿��ƺ�������������
	for (int i = 0, j = 0, k = 0; k < (N + 1) / 2; k++)//k�𵽷ֲ������,��<k+1/2,���ݲ�����ѭ��
	{
		while (j < N - k)
		{
			//a[i][j++]=data++;
			a[i][j] = data;  //��������a[0][0]    a[0][1]  a[0][2] ��i���䣬j�仯
			j = j + 1;
			data = data + 1;
			//	printf("")
		}
		j--;//��������Ӱ�죬��Խ��
		i++;//�ı��У�

		while (i < N - k)
		{
			a[i][j] = data;
			i = i + 1;
			data = data + 1;
		}
		i--;//��������Ӱ�죬��Խ��
		j--;

		while (j > k - 1)
		{
			a[i][j] = data;
			j = j - 1;
			data = data + 1;
		}
		j++;//��������Ӱ�죬��Խ��
		i--;

		while (i > k)
		{
			a[i][j] = data;
			i = i - 1;
			data = data + 1;
		}
		i++;//��������Ӱ�죬��Խ��
		j++;
	}
	//����������д�ӡ
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
	int flag = 0;//�ٶ��Ҳ���
	while (tou <= wei)//�ҵ�Ϊֹ
	{
		cishu += 1;
		printf("\n%d,%d,%d", tou, zhong, wei);
		if (hj == a[zhong])
		{
			flag = 1;
			printf("\n���������ҵ�λ��%d", zhong);
			break;
		}
		else if (hj > a[zhong])//����
		{
			tou = zhong + 1;
			zhong = (tou + wei) / 2;
		}
		else if (hj < a[zhong])//С��
		{
			wei = zhong - 1;
			zhong = (tou + wei) / 2;
		}
	}

	if (flag == 0)
	{
		printf("û���ҵ�");
	}

	printf("һ��ִ��%d�� ", cishu);
}
/*********************************************************************************************************************/
void main16_GoToѭ��()
{
	int i = 1;
	int  j = 2;

C:  printf("%d,%d", i, j);
	goto C;
}
/*********************************************************************************************************************/
void main17_GoTo���()
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
	for (; k < (length + 1) / 2; k++)  //kΪ����
	{
		while (i < length - k)   //����
		{
			//int  a1;

			matrix[i++ * length + j] = a++;  //a Ϊ������Ȼ��

			//printf("%d",matrix[a1]);
		}
		i--;  //��λһ��
		j--;

		while (j > k)   //����
		{
			matrix[i * length + j--] = a++;
		}
		j++;  //��λһ��
		i++;
	}
	while (i > k - 1)   //����
	{
		matrix[i-- * length + j] = a++;
	}
	i--;
	j--;
	while (j < length - k)   //����
	{
		matrix[i * length + j++] = a++;
	}
	j--;
	i++;

	showmatrix(matrix, length);

	printf("\n");
}

/*********************************************************************************************************************/
int add(int x, int y)//�ӷ��ĺ���
{
	return x + y; //���ؼӷ��Ľ��
}

int mult(int x, int y)
{
	return x * y;
}

//����int add(int x,int y);
void Point01()
{
	int a = 1;
	int b = 2;

	printf("%d", add(a, b));

	int(*p)(int, int);//����ָ�����ͣ���һ��int����ֵ���ͣ���������int�ǲ���

	p = add;//add���Ǻ����ڴ��ַ��pָ�����������ָ��

	printf("%p", p);
	printf("\n%d", p(a, b));//��ӡ��1+2����ӡp��Ҳ�Ǻ������ڴ��ַ
	p = mult;
	printf("\n%p", p);
	printf("\n%d", p(a, b));
}

//ָ���޸ı���
void Point02()
{
	int a = 1;
	int b = 2;
	int c = 0;
	printf("\na��ַ=%p,b��ַ=%p,c��ַ=%p", &a, &b, &c);

	c = a + b;

	printf("\n%d", c);//��ѧ����

	int* p;
	p = &a;//p�൱���ڴ��ַ���ȼ���int *, int��ָʾռ���ĸ��ֽڣ�������ڴ��ַ��ʼ
	*p = 5;//*p�൱��int�������ݣ�ָ��P��ָ�������
	printf("\n%d", a);
	printf("\n%p,%d", p, *p);

	printf("\n%d", add(a, b));//���ú���ʵ�ּӼ�
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

void main18_ָ��()
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

	while ((c = getchar()) != '\n')//c���յ�ֵ�������һ���ַ����µĻس����з�'\n',c�ǲ�����ʾ��
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

//==%p�Ǵ�ӡ��ַ�ģ�%x����ʮ��������ʽ��ӡ����ȫ��ͬ��������64λ�½���᲻һ�������Դ�ӡָ������ʵʵ��%p��=

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
	fopen_s(&pf, "bin1.txt", "rb");//r==read,fopen��һ���ļ�
	if (pf == NULL)
	{
		printf("�ļ���ʧ��");
	}
	else
	{
		printf("�ļ��򿪳ɹ�\n");

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
		printf("�ļ���ʧ��");
	}
	else
	{
		while (!feof(fp))//�ӹ��Ŀ�ͷ
		{
			char str[80];
			fgets(str, 80, fp);//ÿ�ζ�ȡ9���ַ�

			printf("\n%s", str);
			printf("\n%p", fp->_Placeholder);//���ĵ�ַ
		}
		rewind(fp);//������ƶ����ļ���ͷ
		int  weiyi = 10;
		fseek(fp, 10, SEEK_CUR);//�ӵ�ǰλ�ö���β��
		printf("\n\n\n\n\n\n\n\n\n");
		while (!feof(fp))//�ӹ��Ŀ�ͷ,��⵽����Ϊ��־
		{
			char str[80];
			fgets(str, 80, fp);//ÿ�ζ�ȡ9���ַ�

			printf("\n%s", str);
			//printf("\n%x", fp->_ptr);//���ĵ�ַ
		}

		rewind(fp);//������ƶ����ļ���ͷ
		fseek(fp, -80, SEEK_END);//�������λ�ã�ǰ���ƶ���
		printf("\n\n\n\n\n\n\n\n\n");

		char str[80] = { 0 };//��ǰ�������������ʼ��
		//fgets(str,80,fp);//ÿ�ζ�ȡ9���ַ�,
		fread(str, 1, 79, fp);

		printf("\n%s", str);
		//printf("\n%x", fp->_ptr);//���ĵ�ַ

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
		fputs("�����", fp);
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
	strcpy_s(stu1.UserName, "�����");
	strcpy_s(stu1.MobilePhoe, "13612340000");
	strcpy_s(stu1.UserPassword, "Passord");

	printf("Id=%d\nUserName=%s\nMobilePhoe=%s\nUserPassword=%s\n", stu1.Id, stu1.UserName, stu1.MobilePhoe, stu1.UserPassword);

	stu2 = stu1;
	if (stu2.Id == NULL)
	{
		printf("Ϊ.0");
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
	int iArray[ArraySize] = { 0 };//��ʼ������

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