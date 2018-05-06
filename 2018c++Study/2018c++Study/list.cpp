#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

struct Item
{
	Item(int itemCd, int buyMoney)
	{
		ItemCd = itemCd;
		BuyMoney = buyMoney;
	}

	int ItemCd;		// ������ �ڵ�
	int BuyMoney;	// �Ǹűݾ�
};

// remove_if �׽�Ʈ : 20 �̻� 30 �̸��̸� true
template <typename T> class is_Over20_Under30 : public std::unary_function<T, bool>
{
public:
	bool operator() (T& val)
	{
		return (val >= 20 && val < 30);
	}
};

// sort �׽�Ʈ : �Լ� ��ü ����
template <typename T> struct COMPARE_ITEM
{
	bool operator()(const T l, const T r) const
	{
		// ���� �ÿ��� ���� ������ �ȴ�.
		return l.ItemCd < r.ItemCd;
	}
};

void main()
{
	list<Item> ItemList;
	
	// �տ� ������ �߰�
	Item item1(1, 2000);
	ItemList.push_front(item1);

	Item item2(2, 1000);
	ItemList.push_front(item2);

	// �ڿ� ������ �߰�
	Item item3(3, 3000);
	ItemList.push_back(item3);

	Item item4(4, 4000);
	ItemList.push_back(item4);

	// ������ �ڵ� ��ȣ�� 2, 1, 3, 4 ������ ��µȴ�.
	auto iterEnd = ItemList.end();
	for (auto iter = ItemList.begin(); iter != iterEnd; ++iter)
	{
		cout << "������ �ڵ� : " << iter->ItemCd << endl;
	}

	// �տ� �ִ� �����͸� �����Ѵ�.
	ItemList.pop_front();

	// �տ� �ִ� �������� ������ �����Ѵ�.
	Item front_item = ItemList.front();
	cout << "������ �ڵ� : " << front_item.ItemCd << endl;

	// �������� �ִ� �����͸� �����Ѵ�.
	ItemList.pop_back();

	// �������� �ִ� �������� ������ �����Ѵ�.
	Item back_item = ItemList.back();
	cout << "������ �ڵ� : " << back_item.ItemCd << endl;

	// ����� �����Ͱ� �ִ°�?
	if (false == ItemList.empty())
	{
		auto count = ItemList.size();
		cout << "���� �ִ� ������ ���� : " << count << endl;
	}

	// ��� �����͸� �����.
	ItemList.clear();
	auto count = ItemList.size();
	cout << "���� �ִ� ������ ���� : " << count << endl;

	
	// insert �׽�Ʈ
	
	list<int> list1;

	list1.push_back(20);
	list1.push_back(30);

	cout << "insert �׽�Ʈ 1" << endl;

	// ù ��° ��ġ�� �����Ѵ�.
	auto iterInsertPos = list1.begin();
	list1.insert(iterInsertPos, 100);

	auto iterEnd2 = list1.end();
	for (auto iter = list1.begin(); iter != iterEnd2; ++iter)
	{
		cout << "list 1 : " << *iter << endl;
	}

	cout << endl << "insert �׽�Ʈ 2" << endl;
	
	// �� ��° ��ġ�� 200�� 2�� �����Ѵ�.
	iterInsertPos = list1.begin();
	++iterInsertPos;
	list1.insert(iterInsertPos, 2, 200);

	iterEnd2 = list1.end();
	for (auto iter = list1.begin(); iter != iterEnd2; ++iter)
	{
		cout << "list 1 : " << *iter << endl;
	}

	cout << endl << "insert �׽�Ʈ 3" << endl;
	list<int> list2;
	list2.push_back(1000);
	list2.push_back(2000);
	list2.push_back(3000);

	// �� ��° ��ġ�� list2�� ��� �����͸� �����Ѵ�.
	iterInsertPos = list1.begin();
	list1.insert(++iterInsertPos, list2.begin(), list2.end());

	iterEnd2 = list1.end();
	for (auto iter = list1.begin(); iter != iterEnd2; ++iter)
	{
		cout << "list 1 : " << *iter << endl;
	}


	// erase �׽�Ʈ

	list<int> list3;

	list3.push_back(10);
	list3.push_back(20);
	list3.push_back(30);
	list3.push_back(40);
	list3.push_back(50);

	cout << "erase �׽�Ʈ 1" << endl;

	// ù ��° ������ ����
	list3.erase(list3.begin());
	for (auto iter = list3.begin(); iter != list3.end(); ++iter)
	{
		cout << "list 3 : " << *iter << endl;
	}
	
	cout << endl << "erase �׽�Ʈ 2" << endl;
	
	// �� ��° �����Ϳ��� ���������� �����Ѵ�.
	list3.erase(++list3.begin(), list3.end());

	for (auto iter = list3.begin(); iter != list3.end(); ++iter)
	{
		cout << "list 3 : " << *iter << endl;
	}


	// remove �׽�Ʈ

	// Item �����͸� ��ƾ� �Ѵ�.
	list<Item*> ItemList2;

	Item* pItem1 = new Item(10, 100);
	ItemList2.push_back(pItem1);

	Item* pItem2 = new Item(20, 200);
	ItemList2.push_back(pItem2);

	Item* pItem3 = new Item(30, 300);
	ItemList2.push_back(pItem3);

	// pItem2�� �����Ѵ�.
	ItemList2.remove(pItem2);

	cout << endl << "remove �׽�Ʈ - ����ü ���� " << endl;

	for (auto iter = ItemList2.begin(); iter != ItemList2.end(); ++iter)
	{
		cout << "ItemList2 : " << (*iter)->ItemCd << endl;
	}


	// remove_if �׽�Ʈ

	list<int> list4;
	list4.push_back(10);
	list4.push_back(20);
	list4.push_back(25);
	list4.push_back(30);
	list4.push_back(34);

	// 20 �̻� 30 �̸��� �����Ѵ�.
	list4.remove_if(is_Over20_Under30<int>());

	cout << endl << "remove_if �׽�Ʈ" << endl;
	for (auto iter = list4.begin(); iter != list4.end(); ++iter)
	{
		cout << "list 4 : " << *iter << endl;
	}
	

	// sort �׽�Ʈ

	list<int> list5;
	list5.push_back(20);
	list5.push_back(10);
	list5.push_back(35);
	list5.push_back(15);
	list5.push_back(12);

	cout << endl << "sort ��������" << endl;
	list5.sort();

	for (auto iter = list5.begin(); iter != list5.end(); ++iter)
	{
		cout << "list 5 : " << *iter << endl;
	}

	cout << endl << "sort ��������" << endl;
	list5.sort(greater<int>());
	for (auto iter = list5.begin(); iter != list5.end(); ++iter)
	{
		cout << "list 5 : " << *iter << endl;
	}

	cout << endl << "sort - ����� ������ ������� ����" << endl;
	list<Item> ItemList3;

	Item item7(20, 100);
	ItemList3.push_back(item7);

	Item item5(10, 200);
	ItemList3.push_back(item5);

	Item item6(7, 300);
	ItemList3.push_back(item6);

	// �����Ѵ�.
	ItemList3.sort(COMPARE_ITEM<Item>());
	
	for (auto iter = ItemList3.begin(); iter != ItemList3.end(); ++iter)
	{
		cout << "ItemList 3 : " << (iter)->ItemCd << endl;
	}
}