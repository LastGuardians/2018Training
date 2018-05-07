#include <iostream>
#include <list>

using namespace std;

/* 
	과제 1
	list 활용 과제 - 도형 만들기
*/

class Point
{
public:
	Point() {};
	Point(int f, int s, char name)
	{
		_firstPoint = f;
		_secondPoint = s;
		strcpy(&_name, &name);
	}

	int getFirst() {
		return _firstPoint;
	}

	int getSecond() {
		return _secondPoint;
	}

	char getName()
	{
		return _name;
	}

	void setPoint(int f, int s)
	{
		_firstPoint = f;
		_secondPoint = s;
	}

private:
	int _firstPoint;
	int _secondPoint;
	char _name;
};

void main()
{
	list<Point> Figure;

	Point pointA(50, 200, 'A');
	Point pointB(20, 80, 'B');
	Point pointC(75, 10, 'C');
	Point pointD(130, 80, 'D');
	Point pointE(100, 200, 'E');

	Figure.push_back(pointA);
	Figure.push_back(pointB);
	Figure.push_back(pointC);
	Figure.push_back(pointD);
	Figure.push_back(pointE);

	for (auto iter = Figure.begin(); iter != Figure.end(); ++iter)
	{
		cout << "도형 Figure의 각 점 출력 : " << iter->getName() << " - ( " <<
			iter->getFirst() << ", " << iter->getSecond() << " ) " << endl;
	}

	// 점 F 추가
	Point PointF(180, 150, 'F');

	auto figureIterEnd = Figure.end();
	Figure.insert(--figureIterEnd, PointF);

	cout << endl;
	for (auto iter = Figure.begin(); iter != Figure.end(); ++iter)
	{
		cout << "점 F 추가 후 각 점 출력 : " << iter->getName() << " - ( " <<
			iter->getFirst() << ", " << iter->getSecond() << " ) " << endl;
	}

	// 점 D 값 변경
	for (auto iter = Figure.begin(); iter != Figure.end(); ++iter)
	{
		if ('D' == iter->getName())
		{
			iter->setPoint(200, 100);
			break;
		}
	}

	cout << endl;
	for (auto iter = Figure.begin(); iter != Figure.end(); ++iter)
	{
		cout << "점 D 값 변경 : " << iter->getName() << " - ( "<<
			iter->getFirst() << ", " << iter->getSecond() << " ) " << endl;
	}
	
	// 점 C 삭제
	for (auto iter = Figure.begin(); iter != Figure.end(); ++iter)
	{
		if ('C' == iter->getName())
		{
			Figure.erase(iter);
			break;
		}
	}

	cout << endl;
	for (auto iter = Figure.begin(); iter != Figure.end(); ++iter)
	{
		cout << "점 C 삭제 : " << iter->getName() << " - ( " <<
			iter->getFirst() << ", " << iter->getSecond() << " ) " << endl;
	}
}