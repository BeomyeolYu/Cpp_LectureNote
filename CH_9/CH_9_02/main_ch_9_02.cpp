/*
9.2강 "입출력 연산자(<<, >>) 오버로딩 하기"

- 편하고 자주 쓰이며 사용 규칙을 준수해야 한다.
- console 출력과 file 출력을 한 번에 해준다. 특히 C언어와 다르게 별도의 file 출력 코드 없이.
  --> tap에서 .cpp 우 클릭 후 Open Containing Folder.
  --> out.txt이 생성되고 결과가 출력된다.
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

	// friend인 이유: 첫 번째 parameter가 ostream이므로 member func.으로 만들기는 어렵다.
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		//out << "(" << point.m_x << " " << point.m_y << " " << point.m_z << ")";
		out << point.m_x << " " << point.m_y << " " << point.m_z;

		return out; // chaining 하기 위하여 out을 return. <-- return type으로 ostream이 있기 때문에.
	}

	// 입력은 const로 선언하지 않는 것이 핵심.
	friend std::istream& operator >> (std::istream &in, Point &point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;

		return in; 
	}
};

int main()
{
/**************** Topic 1 ****************/
	// console에 출력(cout).
	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
	cout << p1 << " " << p2 << endl;


/**************** Topic 2 ****************/
	// file로 출력(of).
	ofstream of("out.txt");
	of << p1 << " " << p2 << endl;
	of.close();


/**************** Topic 3 ****************/
	// 입력: ostream --> istream
	Point p3, p4;
	cin >> p3 >> p4;
	cout << p3 << " " << p4 << endl;

	ifstream inf("out.txt");
	inf >> p3 >> p4;
	cout << p3 << " " << p4 << endl;
	inf.close();

	return 0;
}