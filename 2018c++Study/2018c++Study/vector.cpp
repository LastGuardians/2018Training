#include <iostream>
#include <vector>

using namespace std;

void main()
{
	// assign �׽�Ʈ
	vector<int> vector1;

	// 4�� 7�� ä���.
	vector1.assign(7, 4);

	int count = vector1.size();
	for (int i = 0; i < count; ++i)
	{
		cout << "vector1 : " << vector1[i] << endl;
	}
	cout << endl;
	
	vector<int> vector2;
	vector2.push_back(10);
	vector2.push_back(20);
	vector2.push_back(30);

	// vector2�� ��ҷ� ä���.
	vector1.assign(vector2.begin(), vector2.end());
	for (int i = 0; i < vector1.size(); ++i)
	{
		cout << "vector1 : " << vector1[i] << endl;
	}
	cout << endl;


	// swap �׽�Ʈ
	vector<int> vector3;
	vector3.push_back(1);
	vector3.push_back(2);
	vector3.push_back(3);

	vector<int> vector4;
	vector4.push_back(10);
	vector4.push_back(20);
	vector4.push_back(30);
	vector4.push_back(40);

	cout << "swap �� " << endl;
	for (int i = 0; i < vector3.size(); ++i)
	{
		cout << "vector3 : " << vector3[i] << endl;
	}

	for (int i = 0; i < vector4.size(); ++i)
	{
		cout << "vector4 : " << vector4[i] << endl;
	}
	cout << endl;

	vector3.swap(vector4);
	cout << "swap �� " << endl;
	for (int i = 0; i < vector3.size(); ++i)
	{
		cout << "vector3 : " << vector3[i] << endl;
	}

	for (int i = 0; i < vector4.size(); ++i)
	{
		cout << "vector4 : " << vector4[i] << endl;
	}
}