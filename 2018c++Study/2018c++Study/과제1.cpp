#include <iostream>
#include <list>

using namespace std;

/* 
	���� 1
	list Ȱ�� ���� - ���� �����
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
		cout << "���� Figure�� �� �� ��� : " << iter->getName() << " - ( " <<
			iter->getFirst() << ", " << iter->getSecond() << " ) " << endl;
	}

	// �� F �߰�
	Point PointF(180, 150, 'F');

	auto figureIterEnd = Figure.end();
	Figure.insert(--figureIterEnd, PointF);

	cout << endl;
	for (auto iter = Figure.begin(); iter != Figure.end(); ++iter)
	{
		cout << "�� F �߰� �� �� �� ��� : " << iter->getName() << " - ( " <<
			iter->getFirst() << ", " << iter->getSecond() << " ) " << endl;
	}

	// �� D �� ����
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
		cout << "�� D �� ���� : " << iter->getName() << " - ( "<<
			iter->getFirst() << ", " << iter->getSecond() << " ) " << endl;
	}
	
	// �� C ����
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
		cout << "�� C ���� : " << iter->getName() << " - ( " <<
			iter->getFirst() << ", " << iter->getSecond() << " ) " << endl;
	}
}