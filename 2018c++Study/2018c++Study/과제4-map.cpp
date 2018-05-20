#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

struct Item
{
	char name[32];	// 이름
	char kind;		// 종류
	int buyMoney;	// 구입 가격
	int skillCd;	// 스킬 코드
};

int main()
{
	// 아이템 이름을 key 값으로
	map<char*, Item> Items;

	Item item1;
	strncpy(item1.name, "칼", 32);
	item1.kind = 1;
	item1.buyMoney = 200;
	item1.skillCd = 0;

	Item item2;
	strncpy(item2.name, "방패", 32);
	item2.kind = 2;
	item2.buyMoney = 1000;
	item2.skillCd = 4;

	Item item3;
	strncpy(item3.name, "해머", 32);
	item3.kind = 1;
	item3.buyMoney = 500;
	item3.skillCd = 0;

	// Items에 아이템 추가
	Items.insert(make_pair(item2.name, item2));
	Items.insert(make_pair(item1.name, item1));
	Items.insert(make_pair(item3.name, item3));

	// Items가 비어있지 않다면
	if (false == Items.empty())
	{
		cout << "저장된 아이템 개수 : " << Items.size() << endl;
	}

	for (auto iter = Items.begin(); iter != Items.end(); ++iter)
	{
		cout << "이름 : " << iter->first << ", 가격 : " << iter->second.buyMoney << endl;
	}

	auto find = Items.find("칼");
	if (find == Items.end())
	{
		cout << "아이템 '칼'이 없습니다." << endl;
	}

	cout << endl << "오름차순으로 정렬되어 있는 map(key 자료형으로 string 사용)" << endl;

	map<string, Item, less<string>> Items2;
	Items2.insert(make_pair(item2.name, item2));
	Items2.insert(make_pair(item1.name, item1));
	Items2.insert(make_pair(item3.name, item3));

	Items2[item3.name] = item3;

	for (auto iter = Items2.begin(); iter != Items2.end(); ++iter)
	{
		cout << "이름 : " << iter->first << ", 가격 : " << iter->second.buyMoney << endl;
	}
	cout << endl;

	cout << "해머의 가격은 얼마? ";
	auto find2 = Items2.find("해머");
	if (find2 != Items2.end())
	{
		cout << find2->second.buyMoney << endl;
	}
	else
	{
		cout << "해머가 없습니다." << endl;
	}

	// 아이템 칼을 삭제한다.
	auto find3 = Items2.find("칼");
	if (find3 != Items2.end())
	{
		Items2.erase(find3);
	}

	
	// 아이템 가격을 key값으로
	map<int, Item, greater<int>> Items3;

	Item item4;
	strncpy(item4.name, "활", 32);
	item4.kind = 1;
	item4.buyMoney = 400;
	item4.skillCd = 0;

	Item item5;
	strncpy(item5.name, "갑옷", 32);
	item5.kind = 2;
	item5.buyMoney = 600;
	item5.skillCd = 0;

	Items3.insert(make_pair(item4.buyMoney, item4));
	Items3.insert(make_pair(item5.buyMoney, item5));

	cout << endl << "아이템 가격을 key 값으로 내림차순" << endl;
	for (auto iter = Items3.begin(); iter != Items3.end(); ++iter)
	{
		cout << "이름 : " << iter->second.name << ", 가격 : " << iter->first << endl;
	}
}