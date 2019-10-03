/*
11.4강 "유도된(Derived) 클래스들의 생성과 초기화"
*/

#include <iostream>
using namespace std;

/**************** Topic 1 ****************/
class Mother
{
private:
	int m_i;

public:
	Mother(const int & i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
private:
	double m_d;

public:
	Child()
		: m_d(1.0f), Mother(1024)
	{
		cout << "Child construction" << endl;
	}
};

/**************** Topic 2 ****************/
class A
{
public:
	A(int a)
	{
		cout << "A: " << a << endl;
	}

	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		: A(a)
	{
		cout << "B: " << b << endl;
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a, b)
	{
		cout << "C: " << c << endl;
	}

	~C()
	{
		cout << "Destructor C" << endl;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Child c1;

	// Mother와 Child를 표현할 때 필요한 최소한의 데이터양.
	cout << sizeof(Mother) << endl; // int = 4 bytes 
	cout << sizeof(Child) << endl;  // padding 현상으로 인해 int(4) + double(8) = 12 bytes이 아닌 16 bytes가 출력된다.
	cout << sizeof(c1) << endl;  // 즉, Child class는 Mother class를 담을 수 있을 만큼의 데이터가 할당됨을 기억.

/**************** Topic 2 ****************/
	C c(1024, 3.14, 'a');

	return 0;
}
