#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int demo0()
{
	cout << "Hello World" << endl;
	char str[20] = "Hello World";

	cout << str[0] << endl;
	cout << sizeof(str) << endl;
	cout << strlen(str) << endl;
	cout << strnlen(str, 100) << endl;
	cout << &str << endl;

	for (size_t i = 0; i < sizeof(str); i++)
	{
		cout << "[" << &str[i] << "]---" << i << endl;
	}
	return EXIT_SUCCESS;
}

void demo1()
{
	char c[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	const  string s = "Hello World!";

	std::cout << c << std::endl;
	std::cout << s + " How are You?" << std::endl;
	std::cin.ignore();
}

void demo2() {
	char str[20] = "Hello World";
	int size = sizeof(str);

	for (int i = 0; i < size; i++)
	{
		printf("%c - %p \n", str[i], &str[i]);
	}
	printf("%d", size);
	printf("Hello");
}

void demo3()
{
	float firstNumber;
	float secondNumber;
	float answer;
	int userResponse;
	bool continueCalcuator = true;

	while (continueCalcuator)
	{
		system("CLS");
		std::cout << "CALCULATOR PROGRAM" << std::endl;
		std::cout << "1) Addition" << std::endl;
		std::cout << "2) Subtraction" << std::endl;
		std::cout << "3) Multiplication" << std::endl;
		std::cout << "4) Division" << std::endl;
		std::cout << "5) EXIT" << std::endl;
		std::cout << "Please make a selection (1-5): ";
		std::cin >> userResponse;

		if (userResponse > 5 || userResponse < 1) {
			std::cout << "Incorrect choice please choose again." << std::endl;
			system("pause");
		}
		else if (userResponse == 5)
		{
			continueCalcuator = false;
		}
		else
		{
			std::cout << "Please enter the first number" << std::endl;
			std::cin >> firstNumber;

			std::cout << "Please enter the second number" << std::endl;
			std::cin >> secondNumber;

			if (userResponse == 1)
			{
				answer = firstNumber + secondNumber;
				std::cout << firstNumber << " + " << secondNumber << " = " << answer << std::endl;
			}
			else if (userResponse == 2)
			{
				answer = firstNumber - secondNumber;
				std::cout << firstNumber << " - " << secondNumber << " = " << answer << std::endl;
			}
			else if (userResponse == 3)
			{
				answer = firstNumber * secondNumber;
				std::cout << firstNumber << " * " << secondNumber << " = " << answer << std::endl;
			}
			else
			{
				answer = firstNumber / secondNumber;
				std::cout << firstNumber << " / " << secondNumber << " = " << answer << std::endl;
			}
			system("pause");
		}
	}
}

void demo4_1()
{
	std::string line;
	std::ifstream file;

	file.open("c:\\temp\\testInput.txt");

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	}
	system("pause");
}

void demo4_2()
{
	std::ofstream outFile;

	outFile.open("c:\\temp\\outFile.txt");
	outFile << "I am writing into this file.\n";
	outFile << "Goodbye!\n";
	outFile.close();
}

void increment_r(int& var)
{
	var++;
	std::cout << "Parameter in function: " << var << std::endl << std::endl;
}

void demo5_pass_by_reference()
{
	int var = 0;

	std::cout << "Parameter in Main before funcation call: " << var << std::endl << std::endl;
	increment_r(var);
	std::cout << "Parameter in Main after funcation call: " << var << std::endl << std::endl;
	system("pause");
}

void increment_v(int var)
{
	var++;
	std::cout << "Parameter in function: " << var << std::endl << std::endl;
}
void demo5_pass_by_value()
{
	int var = 0;

	std::cout << "Parameter in Main before funcation call: " << var << std::endl << std::endl;
	increment_v(var);
	std::cout << "Parameter in Main after funcation call: " << var << std::endl << std::endl;
	system("pause");
}

struct Movie {
	std::string name;
	std::string rating;
	int releaseYear;
	int totalSales;
};

void printMovie(Movie& movie)
{
	std::cout << "Movie Name: " << movie.name << std::endl;
	std::cout << "Movie Rating: " << movie.rating << std::endl;
	std::cout << "Movie Release Year: " << movie.releaseYear << std::endl;
	std::cout << "Movie Total Sales: " << movie.totalSales << std::endl << std::endl;
}

void demo6_struct()
{
	Movie movieA;
	Movie movieB;

	movieA.name = "Spaceballs";
	movieA.rating = "PG";
	movieA.releaseYear = 1987;
	movieA.totalSales = 38119483;

	movieB.name = "Robin Hood: Men in Tights";
	movieB.rating = "PG-13";
	movieB.releaseYear = 1993;
	movieB.totalSales = 35739755;

	printMovie(movieA);
	printMovie(movieB);

	system("pause");
}

void demo7_array()
{
	int iArray[5] = { 12, 32, 64, 21, 9 };
	std::cout << "0: " << iArray[0] << std::endl;
	std::cout << "1: " << iArray[1] << std::endl;
	std::cout << "2: " << iArray[2] << std::endl;
	std::cout << "3: " << iArray[3] << std::endl;
	std::cout << "4: " << iArray[4] << std::endl;
	std::cout << "5: " << iArray[5] << std::endl;
	system("pause");
}

void printVector(std::vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << i << ": " << vec[i] << std::endl;
	}
}

void demo8_vector()
{
	std::vector<int> vectorList;

	vectorList.push_back(11);
	vectorList.push_back(22);
	vectorList.push_back(33);
	vectorList.push_back(44);
	vectorList.push_back(55);

	std::cout << "Vector Size: " << vectorList.size() << std::endl;
	printVector(vectorList);
	std::cout << std::endl;

	vectorList.pop_back();
	std::cout << "Vector Size: " << vectorList.size() << std::endl;
	printVector(vectorList);
	system("pause");
}

void demo9_map()
{
	std::map<int, std::string> mapList;

	mapList.insert(std::pair<int, std::string>(5, "Hello"));
	mapList.insert(std::pair<int, std::string>(7, "World"));

	std::cout << "Map Size: " << mapList.size() << std::endl;
	std::cout << mapList[5] << std::endl;
	std::cout << mapList[7] << std::endl;
	system("pause");
}

void demoA()
{
	char str[20] = "Hello World";
	int size = sizeof(str);

	for (int i = 0; i < size; i++)
	{
		printf("%c - %p \n", str[i], &str[i]);
	}
	printf("%d", size);
 }

int demoB()
{
	double a;
	scanf_s("%lf", &a);
	printf("%.2f", a);
	double  b = ((int)(a * 10 + 0.5)) / 10.0;
	printf("\n%f", b);

	system("pause");

	const int N = 8; //	输入的正偶数

	for (int i = 1; i <= N / 2; i++)
	{
		if (i % 2 == 0)
			printf("%d = %d + %d\n", N, i, N - i);
	}

	system("pause");
	return 0;
}

int numberOfInt(int num)
{
	int i;
	for (i = 1; i <= 24; i++)
	{
		if ((num /= 10) == 0)
		{
			break;
		}
	}

	return i;
}

int demoC()
{
	int num = 123456789;
	printf("%d的整数个数有%d个\n", num, numberOfInt(num));

	system("pause");
	return 0;
}

int demoD()
{
	for (int i = 200; i <= 2000; i++)
	{
		if ((i % 2 != 0) && (i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0))
		{
			printf(" i = %d\t", i);
		}
	}

	system("pause");
	return 0;
}

int demoE()
{
	const int N = 948;
	for (int i = 0; i <= N / 11; i++)
	{
		for (int j = 0; j <= N / 13; j++)
		{
			if (i * 13 + j * 11 == N)
			{
				printf("%d*13 + %d*11 = %d\n", i, j, N);
			}
		}
	}

	system("pause");
	return 0;
}