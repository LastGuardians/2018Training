#include <iostream>
#include <vector>

using namespace std;

/*
	과제 2-2
	온라인 게임에서 방에 있는 유저 관리를 vector를 이용해서 만들기
*/

// 유저 정보
struct UserInfo
{
	char _UserName[21]; // 이름
	int	 _Level;		// 레벨
	int  _Exp;			// 경험치
};

// 게임 방의 유저를 관리하는 클래스
// 방에는 최대 6명까지 들어갈 수 있다.
// 방에 들어오는 순서 중 가장 먼저 들어 온 사람이 방장이 된다.
class GameRoomUser
{
public:
	GameRoomUser() {};
	~GameRoomUser() {};

	// 방에 유저 추가
	bool AddUser(UserInfo& tUserInfo);

	// 방에서 유저 삭제
	// 만약 방장이 나가면 _MasterUserName에 새로운 방장 이름을 설정해야 한다.
	bool DelUser(char* pcUserName);

	// 방에 유저가 없는 지 조사. 없으면 true 리턴
	bool IsEmpty();

	// 방에 유저가 꽉 찼는지 조사. 꽉 찼다면 true 리턴
	bool IsFull();

	// 특정 유저의 정보
	UserInfo* GetUserOfName(char* pcName);

	// 방장의 유저 정보
	UserInfo* GetMasterName();

	// 가장 마지막에 방에 들어온 유저의 정보
	UserInfo& GetUserOfLastOrder();

	// 특정 순서에 들어 온 유저를 쫓아낸다.
	bool BanUser(int orderNum);

	void PrintAllUser();

private:
	vector<UserInfo> _Users;
	char _MasterUserName[21];	// 방장의 이름
};

bool GameRoomUser::AddUser(UserInfo & tUserInfo)
{
	if (true == IsFull())
	{
		cout << "유저가 꽉 찼습니다." << endl;
		return false;
	}
	if (true == IsEmpty())
	{
		// 방장 지정
		strcpy(_MasterUserName, tUserInfo._UserName);
	}

	cout << tUserInfo._UserName << " 님 입장" << endl;
	_Users.push_back(tUserInfo);
	return true;
}

bool GameRoomUser::DelUser(char * pcUserName)
{
	if (true == IsEmpty())
	{
		cout << "유저가 없습니다." << endl;
		return false;
	}

	// 유저를 삭제.
	for (auto iter = _Users.begin(); iter != _Users.end(); ++iter)
	{
		if (0 == strcmp(pcUserName, iter->_UserName))
		{
			cout << pcUserName << " 유저가 방에서 나갑니다." << endl << endl;
			_Users.erase(iter);
			break;
		}
	}

	// 방장이 방에서 나가는 거라면.
	if (0 == strcmp(_MasterUserName, pcUserName))
	{
		for (auto iter = _Users.begin(); iter != _Users.end(); ++iter)
		{
			if (0 != strcmp(_MasterUserName, iter->_UserName))
			{
				strcpy(_MasterUserName, iter->_UserName);			
				break;
			}
		}		
	}
	return true;
}

bool GameRoomUser::IsEmpty()
{
	if (true == _Users.empty())
		return true;
	return false;
}

bool GameRoomUser::IsFull()
{
	if (_Users.size() > 5)
		return true;
	return false;
}

UserInfo* GameRoomUser::GetUserOfName(char * pcName)
{
	cout << pcName << " 유저를 찾습니다." << endl;
	for (int i = 0; i < _Users.size(); ++i)
	{
		if (0 == strcmp(pcName, _Users[i]._UserName))
		{
			return &_Users[i];
		}
	}
	cout << "찾는 유저가 없습니다." << endl;
	return nullptr;
}

UserInfo* GameRoomUser::GetMasterName()
{
	for (int i = 0; i < _Users.size(); ++i)
	{
		if (0 == strcmp(_MasterUserName, _Users[i]._UserName))
		{
			return &_Users[i];
		}
	}
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{	
	auto lastIter = _Users.end() -1;
	return *lastIter;
}

bool GameRoomUser::BanUser(int orderNum)
{
	// 방장이 방에서 나가는 거라면.
	if (0 == strcmp(_MasterUserName, _Users[orderNum]._UserName))
	{
		for (auto iter = _Users.begin(); iter != _Users.end(); ++iter)
		{
			if (0 != strcmp(_MasterUserName, iter->_UserName))
			{
				strcpy(_MasterUserName, iter->_UserName);
				break;
			}
		}
	}

	_Users.erase(_Users.begin() + orderNum);
	return true;
}

void GameRoomUser::PrintAllUser()
{
	for (auto iter = _Users.begin(); iter != _Users.end(); ++iter)
	{
		cout << iter->_UserName << endl;
	}
	cout << endl;
}

void main()
{
	UserInfo user1 = { "song", 20, 32040 };
	UserInfo user2 = { "hohohoho", 10, 220 };
	UserInfo user3 = { "chokokok", 32, 94930 };
	UserInfo user4 = { "bananan", 39, 849201 };
	UserInfo user5 = { "hiri", 44, 29280094 };
	UserInfo user6 = { "ghibri", 58, 7432400 };

	GameRoomUser room1;
	room1.AddUser(user1);
	room1.AddUser(user2);
	room1.AddUser(user3);
	room1.AddUser(user4);

	cout << endl << "[ room1 유저 ]" << endl;
	room1.PrintAllUser();

	room1.DelUser(user2._UserName);

	UserInfo* userInfo1 = room1.GetUserOfName(user1._UserName);
	if (nullptr != userInfo1)
	{
		cout << "[ " << user1._UserName << " 유저 정보 ]" << endl;
		cout << "레벨 : " << userInfo1->_Level << endl;
		cout << "경험치 : " << userInfo1->_Exp << endl;
		cout << endl;
	}

	cout << endl << "[ room1 유저 ]" << endl;
	room1.PrintAllUser();
	
	cout << "[ 가장 마지막에 들어온 유저 정보 ]" << endl;
	UserInfo& userInfo2 = room1.GetUserOfLastOrder();
	cout << "이름 : " << userInfo2._UserName << endl;
	cout << "레벨 : " << userInfo2._Level << endl;
	cout << "경험치 : " << userInfo2._Exp << endl;
	cout << endl;

	cout << "[ 2 번째 유저를 강퇴합니다. ] " << endl;
	room1.BanUser(1);

	cout << endl << "[ room1 유저 ]" << endl;
	room1.PrintAllUser();

	cout << "[ 현재 방장의 정보 ]" << endl;
	UserInfo* userInfo3 = room1.GetMasterName();
	cout << "이름 : " << userInfo3->_UserName << endl;
	cout << "레벨 : " << userInfo3->_Level << endl;
	cout << "경험치 : " << userInfo3->_Exp << endl;
	cout << endl;

	room1.AddUser(user5);
	room1.AddUser(user6);

	cout << endl << "[ room1 유저 ]" << endl;
	room1.PrintAllUser();

	cout << "[ 1 번째 유저를 강퇴합니다. ] " << endl;
	room1.BanUser(0);

	cout << endl << "[ room1 유저 ]" << endl;
	room1.PrintAllUser();

	cout << "[ 현재 방장의 정보 ]" << endl;
	userInfo3 = room1.GetMasterName();
	cout << "이름 : " << userInfo3->_UserName << endl;
	cout << "레벨 : " << userInfo3->_Level << endl;
	cout << "경험치 : " << userInfo3->_Exp << endl;
	cout << endl;
}