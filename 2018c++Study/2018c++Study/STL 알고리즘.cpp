#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct User
{
	int _money;
	int _level;
};

struct FindMoneyUser
{
	bool operator()(User& user) const
	{
		return user._money == _compareMoney;
	}

	int _compareMoney;
};


struct GameUser
{
	int _id;
	int _playTime;
};

struct UpdatePlayTime
{
	void operator()(GameUser& user)
	{
		user._playTime += PlayTime;
	}
	int PlayTime;
};

int main()
{
	// find_if : 특정 돈 가지고 있는 유저 찾기
	User user1;
	user1._level = 10;
	user1._money = 2000;

	User user2;
	user2._level = 5;
	user2._money = -10;

	User user3;
	user3._level = 20;
	user3._money = 35000;

	vector<User> Users;
	Users.push_back(user1);
	Users.push_back(user2);
	Users.push_back(user3);

	FindMoneyUser tFindMoney;
	tFindMoney._compareMoney = 2000;

	auto findUser = find_if(Users.begin(), Users.end(), tFindMoney);
	if (findUser != Users.end())
	{
		cout << "유저가 소지한 돈 : " << findUser->_money << endl;
	}
	else
	{
		cout << "해당 돈을 소지한 유저가 없습니다." << endl;
	}
	//////  find_if


	// for_each : 유저들의 플레이 시간 갱신
	GameUser gUser1;
	gUser1._id = 1;
	gUser1._playTime = 40000;

	GameUser gUser2;
	gUser2._id = 2;
	gUser2._playTime = 0;

	GameUser gUser3;
	gUser3._id = 3;
	gUser3._playTime = 25000;

	vector<GameUser> gUsers;
	gUsers.push_back(gUser1);
	gUsers.push_back(gUser2);
	gUsers.push_back(gUser3);

	cout << endl << "현재 플레이 시간" << endl;
	for (auto iter = gUsers.begin(); iter != gUsers.end(); ++iter)
	{
		cout << iter->_id << "의 총 플레이 시간 : " << iter->_playTime << endl;
	}

	UpdatePlayTime updateTime;
	updateTime.PlayTime = 2000;

	// 두 번째 유저부터 갱신
	for_each(gUsers.begin() + 1, gUsers.end(), updateTime);

	cout << endl << "갱신 후 플레이 시간" << endl;
	for (auto iter = gUsers.begin(); iter != gUsers.end(); ++iter)
	{
		cout << iter->_id << "의 총 플레이 시간 : " << iter->_playTime << endl;
	}
	////// for_each
}