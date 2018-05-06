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

	int ItemCd;		// 아이템 코드
	int BuyMoney;	// 판매금액
};

// remove_if 테스트 : 20 이상 30 미만이면 true
template <typename T> class is_Over20_Under30 : public std::unary_function<T, bool>
{
public:
	bool operator() (T& val)
	{
		return (val >= 20 && val < 30);
	}
};

// sort 테스트 : 함수 객체 정의
template <typename T> struct COMPARE_ITEM
{
	bool operator()(const T l, const T r) const
	{
		// 정렬 시에는 오름 차순이 된다.
		return l.ItemCd < r.ItemCd;
	}
};

void main()
{
	list<Item> ItemList;
	
	// 앞에 데이터 추가
	Item item1(1, 2000);
	ItemList.push_front(item1);

	Item item2(2, 1000);
	ItemList.push_front(item2);

	// 뒤에 데이터 추가
	Item item3(3, 3000);
	ItemList.push_back(item3);

	Item item4(4, 4000);
	ItemList.push_back(item4);

	// 아이템 코드 번호가 2, 1, 3, 4 순서로 출력된다.
	auto iterEnd = ItemList.end();
	for (auto iter = ItemList.begin(); iter != iterEnd; ++iter)
	{
		cout << "아이템 코드 : " << iter->ItemCd << endl;
	}

	// 앞에 있는 데이터를 삭제한다.
	ItemList.pop_front();

	// 앞에 있는 데이터의 참조를 리턴한다.
	Item front_item = ItemList.front();
	cout << "아이템 코드 : " << front_item.ItemCd << endl;

	// 마지막에 있는 데이터를 삭제한다.
	ItemList.pop_back();

	// 마지막에 있는 데이터의 참조를 리턴한다.
	Item back_item = ItemList.back();
	cout << "아이템 코드 : " << back_item.ItemCd << endl;

	// 저장된 데이터가 있는가?
	if (false == ItemList.empty())
	{
		auto count = ItemList.size();
		cout << "남아 있는 아이템 개수 : " << count << endl;
	}

	// 모든 데이터를 지운다.
	ItemList.clear();
	auto count = ItemList.size();
	cout << "남아 있는 아이템 개수 : " << count << endl;

	
	// insert 테스트
	
	list<int> list1;

	list1.push_back(20);
	list1.push_back(30);

	cout << "insert 테스트 1" << endl;

	// 첫 번째 위치에 삽입한다.
	auto iterInsertPos = list1.begin();
	list1.insert(iterInsertPos, 100);

	auto iterEnd2 = list1.end();
	for (auto iter = list1.begin(); iter != iterEnd2; ++iter)
	{
		cout << "list 1 : " << *iter << endl;
	}

	cout << endl << "insert 테스트 2" << endl;
	
	// 두 번째 위치에 200을 2개 삽입한다.
	iterInsertPos = list1.begin();
	++iterInsertPos;
	list1.insert(iterInsertPos, 2, 200);

	iterEnd2 = list1.end();
	for (auto iter = list1.begin(); iter != iterEnd2; ++iter)
	{
		cout << "list 1 : " << *iter << endl;
	}

	cout << endl << "insert 테스트 3" << endl;
	list<int> list2;
	list2.push_back(1000);
	list2.push_back(2000);
	list2.push_back(3000);

	// 두 번째 위치에 list2의 모든 데이터를 삽입한다.
	iterInsertPos = list1.begin();
	list1.insert(++iterInsertPos, list2.begin(), list2.end());

	iterEnd2 = list1.end();
	for (auto iter = list1.begin(); iter != iterEnd2; ++iter)
	{
		cout << "list 1 : " << *iter << endl;
	}


	// erase 테스트

	list<int> list3;

	list3.push_back(10);
	list3.push_back(20);
	list3.push_back(30);
	list3.push_back(40);
	list3.push_back(50);

	cout << "erase 테스트 1" << endl;

	// 첫 번째 데이터 삭제
	list3.erase(list3.begin());
	for (auto iter = list3.begin(); iter != list3.end(); ++iter)
	{
		cout << "list 3 : " << *iter << endl;
	}
	
	cout << endl << "erase 테스트 2" << endl;
	
	// 두 번째 데이터에서 마지막까지 삭제한다.
	list3.erase(++list3.begin(), list3.end());

	for (auto iter = list3.begin(); iter != list3.end(); ++iter)
	{
		cout << "list 3 : " << *iter << endl;
	}


	// remove 테스트

	// Item 포인터를 담아야 한다.
	list<Item*> ItemList2;

	Item* pItem1 = new Item(10, 100);
	ItemList2.push_back(pItem1);

	Item* pItem2 = new Item(20, 200);
	ItemList2.push_back(pItem2);

	Item* pItem3 = new Item(30, 300);
	ItemList2.push_back(pItem3);

	// pItem2를 삭제한다.
	ItemList2.remove(pItem2);

	cout << endl << "remove 테스트 - 구조체 삭제 " << endl;

	for (auto iter = ItemList2.begin(); iter != ItemList2.end(); ++iter)
	{
		cout << "ItemList2 : " << (*iter)->ItemCd << endl;
	}


	// remove_if 테스트

	list<int> list4;
	list4.push_back(10);
	list4.push_back(20);
	list4.push_back(25);
	list4.push_back(30);
	list4.push_back(34);

	// 20 이상 30 미만은 삭제한다.
	list4.remove_if(is_Over20_Under30<int>());

	cout << endl << "remove_if 테스트" << endl;
	for (auto iter = list4.begin(); iter != list4.end(); ++iter)
	{
		cout << "list 4 : " << *iter << endl;
	}
	

	// sort 테스트

	list<int> list5;
	list5.push_back(20);
	list5.push_back(10);
	list5.push_back(35);
	list5.push_back(15);
	list5.push_back(12);

	cout << endl << "sort 오름차순" << endl;
	list5.sort();

	for (auto iter = list5.begin(); iter != list5.end(); ++iter)
	{
		cout << "list 5 : " << *iter << endl;
	}

	cout << endl << "sort 내림차순" << endl;
	list5.sort(greater<int>());
	for (auto iter = list5.begin(); iter != list5.end(); ++iter)
	{
		cout << "list 5 : " << *iter << endl;
	}

	cout << endl << "sort - 사용자 정의한 방식으로 정렬" << endl;
	list<Item> ItemList3;

	Item item7(20, 100);
	ItemList3.push_back(item7);

	Item item5(10, 200);
	ItemList3.push_back(item5);

	Item item6(7, 300);
	ItemList3.push_back(item6);

	// 정렬한다.
	ItemList3.sort(COMPARE_ITEM<Item>());
	
	for (auto iter = ItemList3.begin(); iter != ItemList3.end(); ++iter)
	{
		cout << "ItemList 3 : " << (iter)->ItemCd << endl;
	}
}