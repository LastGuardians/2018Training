#include <iostream>
#include <vector>

using namespace std;

/*
	과제 2-1
	vector를 사용하여 stack class 구현
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

	// 스택에 저장된 개수
	int Count()
	{
		return _datas.size();
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
	
	cout << "vector로 구현한 list - pop()" << endl;
	for (int i = 0; i < count; ++i)
	{
		stack.pop(&value);
		cout << value << endl;
	}
}