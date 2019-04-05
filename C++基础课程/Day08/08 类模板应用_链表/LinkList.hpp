#pragma once

//��������һϵ�нڵ���ɵģ��ڵ����������������ָ����(����ڵ��ϵ)�����ڴ��з�������

//����ڵ�
template<class T>
class LinkNode
{
public:
	T mData;
	LinkNode* pNext;
};

template<class T>
class LinkList
{
public:
	//ͷ���
	LinkNode<T> mHeader;
	//�ڵ����
	int mSize;
	//β�ڵ�ָ��
	LinkNode<T>* pRear;
public:
	//���캯��
	LinkList()
	{
		mHeader.pNext = NULL;
		mSize = 0;
		pRear = &mHeader;
	}

	//��������
	LinkList(const LinkList& list)
	{
		mHeader.pNext = NULL;
		pRear = &mHeader;
		mSize = 0;

		LinkNode<T>* pCurrent = list.mHeader.pNext;
		while (pCurrent != NULL)
		{
			pushBack(pCurrent->mData);
			pCurrent = pCurrent->pNext;
		}

		mSize = list.mSize;
	}

	//��ֵ���������
	LinkList<T>& operator=(const LinkList& list)
	{
		//���ͷŵ�ǰ�ڵ���ڴ�
		if (mSize > 0)
		{
			//��������
			LinkNode<T>* pCurrent = mHeader.pNext;
			while (pCurrent != NULL)
			{
				//������һ���ڵ�ĵ�ַ
				LinkNode<T>* pNext = pCurrent->pNext;
				//�ͷŵ�ǰ�ڵ��ڴ�
				delete pCurrent;
				//pCurrentָ����һ���ڵ�
				pCurrent = pNext;
			}
		}

		//�����ڵ�����
		mHeader.pNext = NULL;
		pRear = &mHeader;
		mSize = 0;

		LinkNode<T>* pCurrent = list.mHeader.pNext;
		while (pCurrent != NULL)
		{
			pushBack(pCurrent->mData);
			pCurrent = pCurrent->pNext;
		}

		mSize = list.mSize;

		return *this;
	}

	//β������
	void pushBack(const T& val)
	{
		//�����µĽڵ�
		LinkNode<T>* newnode = new LinkNode<T>;
		newnode->mData = val;
		newnode->pNext = NULL;

		//�½ڵ�������
		pRear->pNext = newnode;
		pRear = newnode;

		//����size��С
		++mSize;
	}

	//ָ��λ�ò���
	void insert(int pos, const T& val)
	{
		//λ��У��͵���
		if (pos < 0 || pos > mSize)
		{
			pos = mSize;
		}

		//Ѱ��Posλ��ǰһ��λ�õĽڵ�
		LinkNode<T>* pCurrent = &mHeader;
		for (int i = 0; i < pos; ++i)
		{
			pCurrent = pCurrent->pNext;
		}

		//�����µĽڵ�
		LinkNode<T>* newnode = new LinkNode<T>;
		newnode->mData = val;
		newnode->pNext = NULL;

		//�½ڵ��������
		newnode->pNext = pCurrent->pNext;
		pCurrent->pNext = newnode;

		//����rearָ��
		if (pos == mSize)
		{
			pRear = newnode;
		}

		//���´�С
		++mSize;
	}

	//��ֵ��ɾ��
	void remove(const T& val)
	{
		LinkNode<T>* pPrev = &mHeader;
		LinkNode<T>* pCurrent = pPrev->pNext;

		while (pCurrent != NULL)
		{
			if (pCurrent->mData == val)
			{
				//����pRearָ��ָ��
				if (pRear == pCurrent)
				{
					pRear = pPrev;
				}

				//�ҵ���
				//�����´�ɾ���ڵ����һ���ڵ�
				LinkNode<T>* pNext = pCurrent->pNext;
				//�ͷŵ�ǰ�ڵ���ڴ�
				//deleteָ��֮��ָ���ֵ���ܻᷢ���仯
				delete pCurrent;
				//���½�����ɾ���ڵ��ǰ���ͺ�̽ڵ��ϵ
				pPrev->pNext = pNext;
				//���´�С
				--mSize;

				break;
			}

			pPrev = pCurrent;
			pCurrent = pCurrent->pNext;
		}
	}

	//����
	template<class _CallBack> //_CallBack =  myPrint
	void foreach(_CallBack func)
	{
		cout << typeid(_CallBack).name() << endl;

		LinkNode<T>* pCurrent = mHeader.pNext;
		while (pCurrent != NULL)
		{
			func(pCurrent->mData); // 	func.operator()(pCurrent->mData);

			pCurrent = pCurrent->pNext;
		}
	}

	//��������
	~LinkList()
	{
		if (mSize > 0)
		{
			//��������
			LinkNode<T>* pCurrent = mHeader.pNext;
			while (pCurrent != NULL)
			{
				//������һ���ڵ�ĵ�ַ
				LinkNode<T>* pNext = pCurrent->pNext;
				//�ͷŵ�ǰ�ڵ��ڴ�
				delete pCurrent;
				//pCurrentָ����һ���ڵ�
				pCurrent = pNext;
			}
		}
	}
};