#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Stack
{
public:
	Stack() { Clear(); }

	// ���� ����� �����Ѵ�.
	void SetInOutType(bool bLIFO) { _LIFO = bLIFO; }

	void Clear()
	{
		if (false == _datas.empty())
			_datas.clear();
	}

	// ���ÿ� ����� ����
	int Count()
	{
		return static_cast(_datas.size());
	}

	// ����� �����Ͱ� ���°�?
	bool IsEmpty()
	{
		return _datas.empty();
	}

	// �����͸� �����Ѵ�.
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
	bool _LIFO; // true�̸� ���Լ���, false�̸� ���Լ���
};

void main()
{
	Stack<int> Int_Stack;

	//LIFO�� ����
	Int_Stack.SetInOutType(true);

	Int_Stack.push(10);
	Int_Stack.push(20);
	Int_Stack.push(30);

	int value = 0;
	Int_Stack.pop(&value);
	cout << "LIFO pop : " << value << endl << endl;

	Int_Stack.Clear();

	//FIFO�� ����
	Int_Stack.SetInOutType(false);

	Int_Stack.push(10);
	Int_Stack.push(20);
	Int_Stack.push(30);

	Int_Stack.pop(&value);
	cout << "FIFO pop : " << value << endl << endl;

}