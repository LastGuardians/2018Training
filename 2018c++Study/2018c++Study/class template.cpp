#include <iostream>
#include <string>

using namespace std;

// ����ġ�� ������ �� �ִ� �ִ� ����
const int MAX_EXP_COUNT = 100;

// Stack ���ø� Ŭ���� ���� �κ�
// ���ø� �Ķ���� �� int size�� non-type �Ķ���ʹ�.
template<typename T>
class Stack
{
public:
	explicit Stack(int size);
	~Stack();

	void Clear();

	// ���ÿ� ����� ����
	int Count();

	int GetStackSize();

	// ����� �����Ͱ� ���°�?
	bool IsEmpty();

	// ����ġ ����
	bool push(T data);

	// ���ÿ��� ����ġ ����
	T pop();

private:
	T*		m_aData;
	int		m_Count;

	int		m_Size;
};

template <typename T> Stack<T>::Stack(int size)
{
	m_Size = size;
	m_aData = new T[m_Size];

	Clear();
}

// Stack ���ø� Ŭ���� ���� �κ�
template <typename T> Stack<T>::~Stack()
{
	delete[] m_aData;
}

template <typename T> void Stack<T>::Clear()
{
	m_Count = 0;
}

template <typename T> int Stack<T>::Count()
{
	return m_Count;
}

template <typename T> int Stack<T>::GetStackSize()
{
	return m_Size;
}

template <typename T> bool Stack<T>::IsEmpty()
{
	return 0 == m_Count ? true : false;
}

template <typename T> bool Stack<T>::push(T data)
{
	if (m_Count >= m_Size)
	{
		return false;
	}

	m_aData[m_Count++] = data;
	return true;
}

template <typename T> T Stack<T>::pop()
{
	if (m_Count < 1)
	{
		return 0.0f;
	}

	return m_aData[--m_Count];
}

//////////////////////////////////////////////////// Stack ���ø� Ŭ����


const int MAX_ID_LENGTH = 21;

// Stack : ���ڿ��� �����ϱ� ���� char* �� ����ȭ�� Stack Ŭ�����̴�.
template<> class Stack<char*>
{
public:
	explicit Stack(int size)
	{
		m_Size = size;

		m_ppData = new char *[m_Size];
		for (int i = 0; i < m_Size; ++i)
		{
			m_ppData[i] = new char[MAX_ID_LENGTH];
		}

		Clear();
	}

	~Stack()
	{
		for (int i = 0; i < m_Size; ++i)
		{
			delete[] m_ppData[i];
		}
		delete[] m_ppData;
	}

	void Clear()
	{
		m_Count = 0;
	}

	// ���ÿ� ����� ����
	int Count()
	{
		return m_Count;
	}

	int GetStackSize()
	{
		return m_Size;
	}

	// ����� �����Ͱ� ���°�?
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// �����͸� �����Ѵ�.
	bool push(char* pID)
	{
		// ������ �� �ִ� ������ �Ѵ��� �����Ѵ�.
		if (m_Count >= m_Size)
		{
			return false;
		}

		// ���� �� ������ �ϳ� �ø���.
		strncpy_s(m_ppData[m_Count], MAX_ID_LENGTH, pID, MAX_ID_LENGTH - 1);
		m_ppData[m_Count][MAX_ID_LENGTH - 1] = '\0';

		++m_Count;
		return true;
	}

	// ���ÿ��� ������.
	char* pop()
	{
		// ����� ���� ���ٸ� 0 ��ȯ
		if (m_Count < 1)
		{
			return 0;
		}

		// ������ �ϳ� ���� �� ��ȯ
		return m_ppData[--m_Count];
	}

private:
	char**	m_ppData;
	int		m_Count;

	int		m_Size;
};

//////////////////////////////////////////////////// Stack ����ȭ Ŭ����


/*
	�κ� ����ȭ Ŭ���� ���ø�
*/

// Test : �Ϲ� Ŭ���� ���ø�
template <typename T1, typename T2>
class Test
{
public:
	T1 Add(T1 a, T2 b)
	{
		cout << "�Ϲ� Ŭ���� ���ø��� ����߽��ϴ�." << endl;
		return a;
	}
};

// Test : T2�� float�� ��üȭ�� Test�� �κ� ����ȭ ���ø�
template <typename T1>
class Test<T1, float>
{
public:
	T1 Add(T1 a, float b)
	{
		cout << "float �κ� ����ȭ Ŭ���� ���ø��� ����߽��ϴ�." << endl;
		return a;
	}
};



/*
	�̱��� ���ø� Ŭ����
*/

// �Ķ���� T�� �̱����� �ǵ��� �����Ѵ�.
template <typename T>
class MySingleton
{
public:
	MySingleton(){}
	virtual ~MySingleton(){}

	// �� ����� ���ؼ��� ������ �����ϴ�.
	static T* GetSingleton()
	{
		// ���� ������ �� �Ǿ������� �����Ѵ�.
		if (NULL == _Singleton)
			_Singleton = new T;

		return(_Singleton);
	}

	static void Release()
	{
		delete _Singleton;
		_Singleton = NULL;
	}

private:
	static T* _Singleton;
};

template <typename T> T* MySingleton<T> ::_Singleton = NULL;

// �̱��� Ŭ���� ���ø��� ��� �����鼭 �Ķ���Ϳ� �� Ŭ������ �ѱ��.
class MyObject : public MySingleton<MyObject>
{
public:
	MyObject() : _nValue(10){}
	
	void setValue(int value) { _nValue = value; }
	int GetValue() { return _nValue; }

private:
	int _nValue;
};

int main()
{
	Stack<double> kExpStack(64);

	cout << "ù��° ���� ���� - ���� ����ġ 145.5f" << endl;
	kExpStack.push(145.5f);

	cout << "�ι�° ���� ���� - ���� ����ġ 183.25f" << endl;
	kExpStack.push(183.25f);

	cout << "����° ���� ���� - ���� ����ġ 162.3f" << endl;
	kExpStack.push(162.3f);

	int count = kExpStack.Count();
	for (int i = 0; i < count; ++i)
	{
		cout << "���� ����ġ : " << kExpStack.pop() << endl;
	}
	cout << "������ ũ���? " << kExpStack.GetStackSize() << endl;

	Stack<__int64> kStackMoney(100);
	cout << endl << endl;
	cout << "ù��° ���� ���� - ���� �� 1000023" << endl;
	kStackMoney.push(1000023);

	cout << "ù��° ���� ���� - ���� �� 1000234" << endl;
	kStackMoney.push(1000234);

	cout << "ù��° ���� ���� - ���� �� 1000145" << endl;
	kStackMoney.push(1000145);
	

	count = kStackMoney.Count();
	for (int i = 0; i < count; ++i)
	{
		cout << "���� �� : " << kStackMoney.pop() << endl;
	}
	cout << "������ ũ���? " << kStackMoney.GetStackSize() << endl;
	cout << endl << endl;

	char GameID1[MAX_ID_LENGTH] = "NiceKim";
	char GameID2[MAX_ID_LENGTH] = "SuperWoman";
	char GameID3[MAX_ID_LENGTH] = "Seventeen";

	// Stack Ŭ���� ���ø��� char* ����ȭ ������ �����Ѵ�.
	Stack<char*> kStackChar(64);
	kStackChar.push(GameID1);
	kStackChar.push(GameID2);
	kStackChar.push(GameID3);

	int count2 = kStackChar.Count();
	for (int i = 0; i < count2; ++i)
	{
		cout << "���� ������ �� ������ ID -> " << kStackChar.pop() << endl;
	}
	cout << endl << endl;

	Test<int, int> test1;
	test1.Add(2, 3);

	Test<int, float> test2;
	test2.Add(2, 5.8f);
	cout << endl << endl;


	// �̱��� ���ø� Ŭ����
	MyObject* myObj1 = MyObject::GetSingleton();

	cout << myObj1->GetValue() << endl;

	// myObj2�� myObj1�� ������ ��ü�̴�.
	MyObject* myObj2 = MyObject::GetSingleton();
	myObj2->setValue(20);

	cout << "myObj1 : " << myObj1->GetValue() << endl;
	cout << "myObj2 : " << myObj2->GetValue() << endl;
}