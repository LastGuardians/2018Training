#include <iostream>
#include <deque>

using namespace std;

/*
	���� 3
	- deque�� ����Ͽ� Stack ����
	- deque�� ����Ͽ� Undo, Redo ����
*/

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

	void Undo()
	{
		cout << "Undo()" << endl;
		if (0 == _datas.size())
		{
			cout << "Undo �� �����Ͱ� �����ϴ�." << endl;
			return;
		}

		auto data = _datas.back();
		_datas.pop_back();

		_redoData.push_back(data);
	}

	void Redo()
	{
		cout << "Redo()" << endl;
		if (0 == _redoData.size())
		{
			cout << "Redo �� �����Ͱ� �����ϴ�." << endl;
			return;
		}

		auto data = _redoData.front();
		_redoData.pop_front();

		_datas.push_back(data);
	}

	void PrintDatas()
	{
		for (auto iter = _datas.begin(); iter != _datas.end(); ++iter)
		{
			cout << *iter << endl;
		}
		cout << endl;
	}

private:
	deque<T> _datas;
	bool _LIFO; // true�̸� ���Լ���, false�̸� ���Լ���
	deque<T> _redoData;
};

void main()
{
	Stack<int> deque1;
	deque1.SetInOutType(false);
	deque1.push(10);
	deque1.push(20);
	deque1.push(30);
	deque1.push(40);
	deque1.push(50);
	deque1.push(60);

	cout << endl << "deque1�� ����" << endl;
	deque1.PrintDatas();

	deque1.Undo();

	cout << endl << "deque1�� ����" << endl;
	deque1.PrintDatas();

	deque1.Redo();

	cout << endl << "deque1�� ����" << endl;
	deque1.PrintDatas();

	deque1.Undo();
	deque1.Undo();

	cout << endl << "deque1�� ����" << endl;
	deque1.PrintDatas();

	deque1.Redo();
	deque1.Redo();

	cout << endl << "deque1�� ����" << endl;
	deque1.PrintDatas();

	deque1.Undo();
	deque1.Undo();
	deque1.Undo();

	cout << endl << "deque1�� ����" << endl;
	deque1.PrintDatas();

	deque1.Redo();
	deque1.Redo();
	deque1.Redo();
	deque1.Redo();

	cout << endl << "deque1�� ����" << endl;
	deque1.PrintDatas();
}