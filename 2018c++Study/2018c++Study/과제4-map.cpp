#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

struct Item
{
	char name[32];	// �̸�
	char kind;		// ����
	int buyMoney;	// ���� ����
	int skillCd;	// ��ų �ڵ�
};

int main()
{
	// ������ �̸��� key ������
	map<char*, Item> Items;

	Item item1;
	strncpy(item1.name, "Į", 32);
	item1.kind = 1;
	item1.buyMoney = 200;
	item1.skillCd = 0;

	Item item2;
	strncpy(item2.name, "����", 32);
	item2.kind = 2;
	item2.buyMoney = 1000;
	item2.skillCd = 4;

	Item item3;
	strncpy(item3.name, "�ظ�", 32);
	item3.kind = 1;
	item3.buyMoney = 500;
	item3.skillCd = 0;

	// Items�� ������ �߰�
	Items.insert(make_pair(item2.name, item2));
	Items.insert(make_pair(item1.name, item1));
	Items.insert(make_pair(item3.name, item3));

	// Items�� ������� �ʴٸ�
	if (false == Items.empty())
	{
		cout << "����� ������ ���� : " << Items.size() << endl;
	}

	for (auto iter = Items.begin(); iter != Items.end(); ++iter)
	{
		cout << "�̸� : " << iter->first << ", ���� : " << iter->second.buyMoney << endl;
	}

	auto find = Items.find("Į");
	if (find == Items.end())
	{
		cout << "������ 'Į'�� �����ϴ�." << endl;
	}

	cout << endl << "������������ ���ĵǾ� �ִ� map(key �ڷ������� string ���)" << endl;

	map<string, Item, less<string>> Items2;
	Items2.insert(make_pair(item2.name, item2));
	Items2.insert(make_pair(item1.name, item1));
	Items2.insert(make_pair(item3.name, item3));

	Items2[item3.name] = item3;

	for (auto iter = Items2.begin(); iter != Items2.end(); ++iter)
	{
		cout << "�̸� : " << iter->first << ", ���� : " << iter->second.buyMoney << endl;
	}
	cout << endl;

	cout << "�ظ��� ������ ��? ";
	auto find2 = Items2.find("�ظ�");
	if (find2 != Items2.end())
	{
		cout << find2->second.buyMoney << endl;
	}
	else
	{
		cout << "�ظӰ� �����ϴ�." << endl;
	}

	// ������ Į�� �����Ѵ�.
	auto find3 = Items2.find("Į");
	if (find3 != Items2.end())
	{
		Items2.erase(find3);
	}

	
	// ������ ������ key������
	map<int, Item, greater<int>> Items3;

	Item item4;
	strncpy(item4.name, "Ȱ", 32);
	item4.kind = 1;
	item4.buyMoney = 400;
	item4.skillCd = 0;

	Item item5;
	strncpy(item5.name, "����", 32);
	item5.kind = 2;
	item5.buyMoney = 600;
	item5.skillCd = 0;

	Items3.insert(make_pair(item4.buyMoney, item4));
	Items3.insert(make_pair(item5.buyMoney, item5));

	cout << endl << "������ ������ key ������ ��������" << endl;
	for (auto iter = Items3.begin(); iter != Items3.end(); ++iter)
	{
		cout << "�̸� : " << iter->second.name << ", ���� : " << iter->first << endl;
	}
}