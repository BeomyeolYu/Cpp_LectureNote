/*
8.13강 "익명(anonymous) 객체"

- 객체를 사용할 때 이름이 붙은 변수를 선언하지 않고 바로 사용하는 법.
*/

#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "Constructor" << endl;
	};
	~A() 
	{
		cout << "Destructor" << endl;
	};
	void print()
	{
		cout << "Hello" << endl;
	}
};

class B
{
public:
	int m_value;

	B(const int& input)
		: m_value(input)
	{
		cout << "Constructor" << endl;
	};
	~B()
	{
		cout << "Destructor" << endl;
	};
	
	void printDouble()
	{
		cout << m_value * 2 << endl;
	}
};

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
};
Cents add(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
/**************** Topic 1 ****************/
	// 이름이 붙은 변수를 선언하여 여러 번 print를 사용
	A a;
	a.print();
	a.print(); // Constructor와 Destructor가 한 번씩만 실행된다.

/**************** Topic 2 ****************/
	// 한 번의 print 함수 사용을 위하여 a를 선언하는 것이 번거로울 수 있다. 
	A().print(); // A()는 L-Value가 아닌 R-Value의 역할을 한다.
	// 그러나, 반복 사용 할 때 Constructor와 Destructor가 매번 실행된다. (= 선언 후 바로 destructor 된다)
	A().print(); 

/**************** Topic 3 ****************/
	B b(1); // <-- 입력의 위치가 다르다.
	b.printDouble();

	B(2).printDouble(); // <-- 입력의 위치가 다르다.

/**************** Topic 4 ****************/
	// 예제
	cout << add(Cents(6), Cents(8)).getCents() << endl;
	// 참고: 연산자 오버 로딩과의 연관성
	cout << int(6) + int(8) << endl;

	return 0;
}