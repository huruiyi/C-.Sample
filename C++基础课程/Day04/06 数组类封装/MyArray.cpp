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

//���ָ��λ�õ�����
int& MyArray::getData(int index)
{
	//�ж��û��±�Խ�磬���ʹ���쳣
	if (index < 0 || index > this->mSize - 1)
	{
		throw "�����±�Խ��";
	}
	return this->pArray[index];
}
void MyArray::setData(int index, int val)
{
	//�ж��û��±�Խ�磬���ʹ���쳣
	if (index < 0 || index > this->mSize - 1)
	{
		throw "�����±�Խ��";
	}
	this->pArray[index] = val;
}
//ͷ��
void MyArray::pushFront(int val)
{
	insert(0, val);
}
//β������
void MyArray::pushBack(int val)
{
	insert(this->mSize, val);
}
//ͷɾ
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
//βɾ��
void MyArray::popBack()
{
	if (this->mSize == 0)
	{
		return;
	}
	--mSize;
}
//��ָ��λ�ò���
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
//��ô�С
int MyArray::size()
{
	return mSize;
}
//�������
int MyArray::capacity()
{
	return mCapacity;
}
//����
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