#include <iostream>
#include <vector>

using namespace std;

/*
	���� 2-2
	�¶��� ���ӿ��� �濡 �ִ� ���� ������ vector�� �̿��ؼ� �����
*/

// ���� ����
struct UserInfo
{
	char _UserName[21]; // �̸�
	int	 _Level;		// ����
	int  _Exp;			// ����ġ
};

// ���� ���� ������ �����ϴ� Ŭ����
// �濡�� �ִ� 6����� �� �� �ִ�.
// �濡 ������ ���� �� ���� ���� ��� �� ����� ������ �ȴ�.
class GameRoomUser
{
public:
	GameRoomUser() {};
	~GameRoomUser() {};

	// �濡 ���� �߰�
	bool AddUser(UserInfo& tUserInfo);

	// �濡�� ���� ����
	// ���� ������ ������ _MasterUserName�� ���ο� ���� �̸��� �����ؾ� �Ѵ�.
	bool DelUser(char* pcUserName);

	// �濡 ������ ���� �� ����. ������ true ����
	bool IsEmpty();

	// �濡 ������ �� á���� ����. �� á�ٸ� true ����
	bool IsFull();

	// Ư�� ������ ����
	UserInfo* GetUserOfName(char* pcName);

	// ������ ���� ����
	UserInfo* GetMasterName();

	// ���� �������� �濡 ���� ������ ����
	UserInfo& GetUserOfLastOrder();

	// Ư�� ������ ��� �� ������ �ѾƳ���.
	bool BanUser(int orderNum);

	void PrintAllUser();

private:
	vector<UserInfo> _Users;
	char _MasterUserName[21];	// ������ �̸�
};

bool GameRoomUser::AddUser(UserInfo & tUserInfo)
{
	if (true == IsFull())
	{
		cout << "������ �� á���ϴ�." << endl;
		return false;
	}
	if (true == IsEmpty())
	{
		// ���� ����
		strcpy(_MasterUserName, tUserInfo._UserName);
	}

	cout << tUserInfo._UserName << " �� ����" << endl;
	_Users.push_back(tUserInfo);
	return true;
}

bool GameRoomUser::DelUser(char * pcUserName)
{
	if (true == IsEmpty())
	{
		cout << "������ �����ϴ�." << endl;
		return false;
	}

	// ������ ����.
	for (auto iter = _Users.begin(); iter != _Users.end(); ++iter)
	{
		if (0 == strcmp(pcUserName, iter->_UserName))
		{
			cout << pcUserName << " ������ �濡�� �����ϴ�." << endl << endl;
			_Users.erase(iter);
			break;
		}
	}

	// ������ �濡�� ������ �Ŷ��.
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
	cout << pcName << " ������ ã���ϴ�." << endl;
	for (int i = 0; i < _Users.size(); ++i)
	{
		if (0 == strcmp(pcName, _Users[i]._UserName))
		{
			return &_Users[i];
		}
	}
	cout << "ã�� ������ �����ϴ�." << endl;
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
	// ������ �濡�� ������ �Ŷ��.
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

	cout << endl << "[ room1 ���� ]" << endl;
	room1.PrintAllUser();

	room1.DelUser(user2._UserName);

	UserInfo* userInfo1 = room1.GetUserOfName(user1._UserName);
	if (nullptr != userInfo1)
	{
		cout << "[ " << user1._UserName << " ���� ���� ]" << endl;
		cout << "���� : " << userInfo1->_Level << endl;
		cout << "����ġ : " << userInfo1->_Exp << endl;
		cout << endl;
	}

	cout << endl << "[ room1 ���� ]" << endl;
	room1.PrintAllUser();
	
	cout << "[ ���� �������� ���� ���� ���� ]" << endl;
	UserInfo& userInfo2 = room1.GetUserOfLastOrder();
	cout << "�̸� : " << userInfo2._UserName << endl;
	cout << "���� : " << userInfo2._Level << endl;
	cout << "����ġ : " << userInfo2._Exp << endl;
	cout << endl;

	cout << "[ 2 ��° ������ �����մϴ�. ] " << endl;
	room1.BanUser(1);

	cout << endl << "[ room1 ���� ]" << endl;
	room1.PrintAllUser();

	cout << "[ ���� ������ ���� ]" << endl;
	UserInfo* userInfo3 = room1.GetMasterName();
	cout << "�̸� : " << userInfo3->_UserName << endl;
	cout << "���� : " << userInfo3->_Level << endl;
	cout << "����ġ : " << userInfo3->_Exp << endl;
	cout << endl;

	room1.AddUser(user5);
	room1.AddUser(user6);

	cout << endl << "[ room1 ���� ]" << endl;
	room1.PrintAllUser();

	cout << "[ 1 ��° ������ �����մϴ�. ] " << endl;
	room1.BanUser(0);

	cout << endl << "[ room1 ���� ]" << endl;
	room1.PrintAllUser();

	cout << "[ ���� ������ ���� ]" << endl;
	userInfo3 = room1.GetMasterName();
	cout << "�̸� : " << userInfo3->_UserName << endl;
	cout << "���� : " << userInfo3->_Level << endl;
	cout << "����ġ : " << userInfo3->_Exp << endl;
	cout << endl;
}