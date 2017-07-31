#include"MyArray.h"

MyArray::MyArray()
{
	this->mCapacity = 20;
	this->mSize = 0;
	this->pArray = new int[this->mCapacity];
}
MyArray::MyArray(int capacity)
{
	this->mCapacity = capacity;
	this->mSize = 0;
	this->pArray = new int[this->mCapacity];
}
MyArray::MyArray(int n, int ele)
{
	this->mCapacity = n;
	this->mSize = n;
	this->pArray = new int[this->mCapacity];
	for (int i = 0; i < this->mSize; ++i)
	{
		this->pArray[i] = ele;
	}
}

MyArray::MyArray(const MyArray& arr)
{
	this->mCapacity = arr.mSize;
	this->mSize = arr.mSize;
	this->pArray = new int[this->mCapacity];
	for (int i = 0; i < this->mSize; ++i)
	{
		this->pArray[i] = arr.pArray[i];
	}
}

MyArray::~MyArray()
{
	if (this->pArray != NULL)
	{
		delete[] this->pArray;
		this->pArray = NULL;
	}
}

//获得指定位置的数据
int& MyArray::getData(int index)
{
	//判断用户下标越界，最好使用异常
	if (index < 0 || index > this->mSize - 1)
	{
		throw "数组下标越界";
	}
	return this->pArray[index];
}
void MyArray::setData(int index, int val)
{
	//判断用户下标越界，最好使用异常
	if (index < 0 || index > this->mSize - 1)
	{
		throw "数组下标越界";
	}
	this->pArray[index] = val;
}
//头插
void MyArray::pushFront(int val)
{
	insert(0, val);
}
//尾部插入
void MyArray::pushBack(int val)
{
	insert(this->mSize, val);
}
//头删
void MyArray::popFront()
{
	if (this->mSize == 0)
	{
		return;
	}
	for (int i = 0; i < this->mSize; ++i)
	{
		this->pArray[i] = this->pArray[i + 1];
	}
	--mSize;
}
//尾删除
void MyArray::popBack()
{
	if (this->mSize == 0)
	{
		return;
	}
	--mSize;
}
//在指定位置插入
void MyArray::insert(int index, int val)
{
	if (this->mSize == this->mCapacity)
	{
		return;
	}

	for (int i = this->mSize - 1; i >= index; --i)
	{
		this->pArray[i + 1] = this->pArray[i];
	}
	this->pArray[index] = val;
	++mSize;
}
//获得大小
int MyArray::size()
{
	return mSize;
}
//获得容量
int MyArray::capacity()
{
	return mCapacity;
}
//遍历
void MyArray::foreach()
{
	using std::cout;
	using std::endl;

	for (int i = 0; i < this->mSize; ++i)
	{
		cout << this->pArray[i] << " ";
	}
	cout << endl;
}