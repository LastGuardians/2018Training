#include <iostream>
#include <vector>

using namespace std;

/*
	���� 2-1
	vector�� ����Ͽ� stack class ����
*/

template <typename T>
class Stack
{
public:
	Stack() { Clear(); }

	void Clear()
	{
		if (false == _datas.empty())
			_datas.clear();
	}

	// ���ÿ� ����� ����
	int Count()
	{
		return _datas.size();
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

		memcpy(data, &_datas.back(), sizeof(T));
		_datas.pop_back();
		return true;
	}

private:
	vector<T> _datas;
};

void main()
{
	Stack<int> stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);

	int value = 0;
	int count = stack.Count();
	
	cout << "vector�� ������ list - pop()" << endl;
	for (int i = 0; i < count; ++i)
	{
		stack.pop(&value);
		cout << value << endl;
	}
}