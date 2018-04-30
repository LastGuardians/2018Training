#include <iostream>

using namespace std;

// 템플릿으로 만든 값을 비교하는 Max 함수
template <typename T1, typename T2> const T1& Max(const T1& a, const T2& b)
{
	cout << "Max(const T1& a, const T2& b) 템플릿 버전 사용" << endl;
	return a > b ? a : b;
}

// 전문화 시킨 Max 함수
template<> const double& Max(const double& a, const double& b)
{
	cout << "Max(const double& a, const double& b) 전문화 버전 사용" << endl;
	return a > b ? a : b;
}

// non-type 함수 템플릿 : 지정된 값만큼 더해준다.
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
	cout << "MP와 SP 중 가장 큰 값은 " << maxValue1 << endl;

	int mp2 = 300;
	double sp2 = 400.25;
	double maxValue2 = Max(mp2, sp2);
	cout << "MP와 SP 중 가장 큰 값은 " << maxValue2 << endl << endl;

	int charHP = 250;
	cout << charHP << "에서 이벤트에 의해 " << AddValue<int, EVENT_ADD_HP_VALUE>(charHP)
		<< "로 변경" << endl;

	float charEXP = 389.89f;
	cout << charEXP << "에서 이벤트에 의해 " << AddValue<float, EVENT_ADD_EXP_VALUE>(charEXP)
		<< "로 변경" << endl;

	__int64 charMONEY = 10000;
	cout << charMONEY << "에서 이벤트에 의해 " << AddValue<__int64, EVENT_ADD_MONEY_VALUE>(charMONEY)
		<< "로 변경" << endl;
}