#include <iostream>

using namespace std;

// ���ø����� ���� ���� ���ϴ� Max �Լ�
template <typename T1, typename T2> const T1& Max(const T1& a, const T2& b)
{
	cout << "Max(const T1& a, const T2& b) ���ø� ���� ���" << endl;
	return a > b ? a : b;
}

// ����ȭ ��Ų Max �Լ�
template<> const double& Max(const double& a, const double& b)
{
	cout << "Max(const double& a, const double& b) ����ȭ ���� ���" << endl;
	return a > b ? a : b;
}

// non-type �Լ� ���ø� : ������ ����ŭ �����ش�.
template <typename T, int Val> T AddValue(T const& curValue)
{
	return curValue + Val;
}

const int EVENT_ADD_HP_VALUE = 50;
const int EVENT_ADD_EXP_VALUE = 30;
const int EVENT_ADD_MONEY_VALUE = 10000;


int main()
{
	double mp1 = 300;
	double sp1 = 400.25;
	double maxValue1 = Max(mp1, sp1);
	cout << "MP�� SP �� ���� ū ���� " << maxValue1 << endl;

	int mp2 = 300;
	double sp2 = 400.25;
	double maxValue2 = Max(mp2, sp2);
	cout << "MP�� SP �� ���� ū ���� " << maxValue2 << endl << endl;

	int charHP = 250;
	cout << charHP << "���� �̺�Ʈ�� ���� " << AddValue<int, EVENT_ADD_HP_VALUE>(charHP)
		<< "�� ����" << endl;

	float charEXP = 389.89f;
	cout << charEXP << "���� �̺�Ʈ�� ���� " << AddValue<float, EVENT_ADD_EXP_VALUE>(charEXP)
		<< "�� ����" << endl;

	__int64 charMONEY = 10000;
	cout << charMONEY << "���� �̺�Ʈ�� ���� " << AddValue<__int64, EVENT_ADD_MONEY_VALUE>(charMONEY)
		<< "�� ����" << endl;
}