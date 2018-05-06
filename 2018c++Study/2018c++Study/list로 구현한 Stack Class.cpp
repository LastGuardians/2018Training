#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Stack
{
public:
	Stack() { Clear(); }

	// 저장 방식을 설정한다.
	void SetInOutType(bool bLIFO) { _LIFO = bLIFO; }

	void Clear()
	{
		if (false == _datas.empty())
			_datas.clear();
	}

	// 스택에 저장된 개수
	int Count()
	{
		return static_cast(_datas.size());
	}

	// 저장된 데이터가 없는가?
	bool IsEmpty()
	{
		return _datas.empty();
	}

	// 데이터를 저장한다.
	void push(T data)
	{
		_datas.push_back(data);
	}

	bool pop(T* data)
	{
		if (true == IsEmpty())
		{
			return false;
		}

		if (true == _LIFO)
		{
			memcpy(data, &_datas.back(), sizeof(T));
			_datas.pop_back();
		}
		else
		{
			memcpy(data, &_datas.front(), sizeof(T));
			_datas.pop_front();
		}
		return true;
	}

private:
	list<T> _datas;
	bool _LIFO; // true이면 후입선출, false이면 선입선출
};

void main()
{
	Stack<int> Int_Stack;

	//LIFO로 설정
	Int_Stack.SetInOutType(true);

	Int_Stack.push(10);
	Int_Stack.push(20);
	Int_Stack.push(30);

	int value = 0;
	Int_Stack.pop(&value);
	cout << "LIFO pop : " << value << endl << endl;

	Int_Stack.Clear();

	//FIFO로 설정
	Int_Stack.SetInOutType(false);

	Int_Stack.push(10);
	Int_Stack.push(20);
	Int_Stack.push(30);

	Int_Stack.pop(&value);
	cout << "FIFO pop : " << value << endl << endl;

}