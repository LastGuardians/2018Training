#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <functional>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class Player
{
public:
	Player(){}
	~Player(){}

	int _level;
};

// ������ ���� ������ ����
template <typename T>
struct LEVEL_COMPARE : public binary_function<T, T, bool>
{
	bool operator()(const T& player1, const T& player2) const
	{
		return player1->_level > player2->_level;
	}
};

int main()
{
	set<Player*, LEVEL_COMPARE<Player*> > playerList;

	Player* pPlayer1 = new Player;
	pPlayer1->_level = 10;

	Player* pPlayer2 = new Player;
	pPlayer2->_level = 50;

	Player* pPlayer3 = new Player;
	pPlayer3->_level = 5;

	playerList.insert(pPlayer1);
	playerList.insert(pPlayer2);
	playerList.insert(pPlayer3);

	cout << "���� ���� ������ ���" << endl;
	for (auto iter = playerList.begin(); iter != playerList.end(); ++iter)
	{
		cout << (*iter)->_level << endl;
	}

	cout << endl << "���� ���� ������ ���" << endl;
	for (auto iter = playerList.rbegin(); iter != playerList.rend(); ++iter)
	{
		cout << (*iter)->_level << endl;
	}

	if (playerList.find(pPlayer3) != playerList.end())
	{
		cout << "pPlayer3�� ã�ҽ��ϴ�." << endl;
	}
	else
	{
		cout << "pPlayer3�� �� ã�ҽ��ϴ�." << endl;
	}

	unordered_set<int> uSet1;
	uSet1.begin();

	uSet1.find(1);
	find(uSet1.begin(), uSet1.end(), 1);

	vector<int> v1;
	list<int> list1;

	

	delete pPlayer1;
	delete pPlayer2;
	delete pPlayer3;
}