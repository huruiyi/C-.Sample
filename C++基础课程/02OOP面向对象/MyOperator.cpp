#include <iostream>
class MyOperator
{
	//ÔËËã·ûÖØÔØMyInteger
public:
	MyOperator()
	{
		mNum = 0;
	}
	MyOperator& operator++()
	{
		++mNum;
		return *this;
	}

	MyOperator operator++(int)
	{
		const MyOperator temp(*this);
		++mNum;
		return temp;
	}
	int mNum;

	void test()
	{
		MyOperator my;
		std::cout << my.mNum << std::endl;

		++my;
		std::cout << my.mNum << std::endl;

		++my;
		std::cout << my.mNum << std::endl;
	}
};