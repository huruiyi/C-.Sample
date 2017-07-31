#pragma once

#include<stdlib.h>
#include<iostream>

class MyArray
{
public:
	MyArray();
	MyArray(int capacity);
	MyArray(int n, int ele);
	MyArray(const MyArray& arr);
	~MyArray();

	//���ָ��λ�õ�����
	int& getData(int index);
	void setData(int index, int val);
	//ͷ��
	void pushFront(int val);
	//β������
	void pushBack(int val);
	//ͷɾ
	void popFront();
	//βɾ��
	void popBack();
	//��ָ��λ�ò���
	void insert(int index, int val);
	//��ô�С
	int size();
	//�������
	int capacity();
	//����
	void foreach();

private:
	int *pArray; //ָ�������������ݵ��ڴ�
	int mCapacity; //����
	int mSize; //��С
};
