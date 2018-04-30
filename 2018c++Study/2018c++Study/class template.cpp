#include <iostream>
#include <string>

using namespace std;

// 경험치를 저장할 수 있는 최대 개수
const int MAX_EXP_COUNT = 100;

// Stack 템플릿 클래스 선언 부분
// 템플릿 파라미터 중 int size가 non-type 파라미터다.
template<typename T>
class Stack
{
public:
	explicit Stack(int size);
	~Stack();

	void Clear();

	// 스택에 저장된 개수
	int Count();

	int GetStackSize();

	// 저장된 데이터가 없는가?
	bool IsEmpty();

	// 경험치 저장
	bool push(T data);

	// 스택에서 경험치 빼기
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

// Stack 템플릿 클래스 정의 부분
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

//////////////////////////////////////////////////// Stack 템플릿 클래스


const int MAX_ID_LENGTH = 21;

// Stack : 문자열을 저장하기 위해 char* 로 전문화한 Stack 클래스이다.
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

	// 스택에 저장된 개수
	int Count()
	{
		return m_Count;
	}

	int GetStackSize()
	{
		return m_Size;
	}

	// 저장된 데이터가 없는가?
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 데이터를 저장한다.
	bool push(char* pID)
	{
		// 저장할 수 있는 개수를 넘는지 조사한다.
		if (m_Count >= m_Size)
		{
			return false;
		}

		// 저장 후 개수를 하나 늘린다.
		strncpy_s(m_ppData[m_Count], MAX_ID_LENGTH, pID, MAX_ID_LENGTH - 1);
		m_ppData[m_Count][MAX_ID_LENGTH - 1] = '\0';

		++m_Count;
		return true;
	}

	// 스택에서 빼낸다.
	char* pop()
	{
		// 저장된 것이 없다면 0 반환
		if (m_Count < 1)
		{
			return 0;
		}

		// 개수를 하나 감소 후 반환
		return m_ppData[--m_Count];
	}

private:
	char**	m_ppData;
	int		m_Count;

	int		m_Size;
};

//////////////////////////////////////////////////// Stack 전문화 클래스


/*
	부분 전문화 클래스 템플릿
*/

// Test : 일반 클래스 템플릿
template <typename T1, typename T2>
class Test
{
public:
	T1 Add(T1 a, T2 b)
	{
		cout << "일반 클래스 템플릿을 사용했습니다." << endl;
		return a;
	}
};

// Test : T2를 float로 구체화한 Test의 부분 전문화 템플릿
template <typename T1>
class Test<T1, float>
{
public:
	T1 Add(T1 a, float b)
	{
		cout << "float 부분 전문화 클래스 템플릿을 사용했습니다." << endl;
		return a;
	}
};



/*
	싱글톤 템플릿 클래스
*/

// 파라미터 T를 싱글톤이 되도록 정의한다.
template <typename T>
class MySingleton
{
public:
	MySingleton(){}
	virtual ~MySingleton(){}

	// 이 멤버를 통해서만 생성이 가능하다.
	static T* GetSingleton()
	{
		// 아직 생성이 안 되어있으면 생성한다.
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

// 싱글톤 클래스 템플릿을 상속 받으면서 파라미터에 본 클래스를 넘긴다.
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

	cout << "첫번째 게임 종료 - 현재 경험치 145.5f" << endl;
	kExpStack.push(145.5f);

	cout << "두번째 게임 종료 - 현재 경험치 183.25f" << endl;
	kExpStack.push(183.25f);

	cout << "세번째 게임 종료 - 현재 경험치 162.3f" << endl;
	kExpStack.push(162.3f);

	int count = kExpStack.Count();
	for (int i = 0; i < count; ++i)
	{
		cout << "현재 경험치 : " << kExpStack.pop() << endl;
	}
	cout << "스택의 크기는? " << kExpStack.GetStackSize() << endl;

	Stack<__int64> kStackMoney(100);
	cout << endl << endl;
	cout << "첫번째 게임 종료 - 현재 돈 1000023" << endl;
	kStackMoney.push(1000023);

	cout << "첫번째 게임 종료 - 현재 돈 1000234" << endl;
	kStackMoney.push(1000234);

	cout << "첫번째 게임 종료 - 현재 돈 1000145" << endl;
	kStackMoney.push(1000145);
	

	count = kStackMoney.Count();
	for (int i = 0; i < count; ++i)
	{
		cout << "현재 돈 : " << kStackMoney.pop() << endl;
	}
	cout << "스택의 크기는? " << kStackMoney.GetStackSize() << endl;
	cout << endl << endl;

	char GameID1[MAX_ID_LENGTH] = "NiceKim";
	char GameID2[MAX_ID_LENGTH] = "SuperWoman";
	char GameID3[MAX_ID_LENGTH] = "Seventeen";

	// Stack 클래스 템플릿의 char* 전문화 버전을 생성한다.
	Stack<char*> kStackChar(64);
	kStackChar.push(GameID1);
	kStackChar.push(GameID2);
	kStackChar.push(GameID3);

	int count2 = kStackChar.Count();
	for (int i = 0; i < count2; ++i)
	{
		cout << "같이 게임을 한 유저의 ID -> " << kStackChar.pop() << endl;
	}
	cout << endl << endl;

	Test<int, int> test1;
	test1.Add(2, 3);

	Test<int, float> test2;
	test2.Add(2, 5.8f);
	cout << endl << endl;


	// 싱글톤 템플릿 클래스
	MyObject* myObj1 = MyObject::GetSingleton();

	cout << myObj1->GetValue() << endl;

	// myObj2는 myObj1과 동일한 객체이다.
	MyObject* myObj2 = MyObject::GetSingleton();
	myObj2->setValue(20);

	cout << "myObj1 : " << myObj1->GetValue() << endl;
	cout << "myObj2 : " << myObj2->GetValue() << endl;
}