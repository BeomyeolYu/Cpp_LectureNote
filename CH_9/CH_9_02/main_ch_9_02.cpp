/*
9.2�� "����� ������(<<, >>) �����ε� �ϱ�"

- ���ϰ� ���� ���̸� ��� ��Ģ�� �ؼ��ؾ� �Ѵ�.
- console ��°� file ����� �� ���� ���ش�. Ư�� C���� �ٸ��� ������ file ��� �ڵ� ����.
  --> tap���� .cpp �� Ŭ�� �� Open Containing Folder.
  --> out.txt�� �����ǰ� ����� ��µȴ�.
*/

#include <iostream>
#include <fstream>
using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	// friend�� ����: ù ��° parameter�� ostream�̹Ƿ� member func.���� ������ ��ƴ�.
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		//out << "(" << point.m_x << " " << point.m_y << " " << point.m_z << ")";
		out << point.m_x << " " << point.m_y << " " << point.m_z;

		return out; // chaining �ϱ� ���Ͽ� out�� return. <-- return type���� ostream�� �ֱ� ������.
	}

	// �Է��� const�� �������� �ʴ� ���� �ٽ�.
	friend std::istream& operator >> (std::istream &in, Point &point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;

		return in; 
	}
};

int main()
{
/**************** Topic 1 ****************/
	// console�� ���(cout).
	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
	cout << p1 << " " << p2 << endl;


/**************** Topic 2 ****************/
	// file�� ���(of).
	ofstream of("out.txt");
	of << p1 << " " << p2 << endl;
	of.close();


/**************** Topic 3 ****************/
	// �Է�: ostream --> istream
	Point p3, p4;
	cin >> p3 >> p4;
	cout << p3 << " " << p4 << endl;

	ifstream inf("out.txt");
	inf >> p3 >> p4;
	cout << p3 << " " << p4 << endl;
	inf.close();

	return 0;
}