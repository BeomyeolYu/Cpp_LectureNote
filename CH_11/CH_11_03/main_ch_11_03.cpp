/*
11.3강 "유도된(Derived) 클래스들의 생성 순서"

- 소멸자는 생성자와 반대 순서로 실행된다.
*/

#include <iostream>
using namespace std;

/**************** Topic 1 ****************/
class Mother1
{
public:
	int m_i;

public:
	Mother1()
		: m_i(1)
	{
		cout << "Mother1 construction" << endl;
	}
};

class Child1 : public Mother1
{
public:
	double m_d;

public:
	Child1()
		//: m_i(1) // m_i가 public으로 선언되어 있어도 생성자에서 초기화는 불가능하다.
		//: Mother1(), m_d(1.0) // 내부적으로 Mother1()이 숨어있다.
		// --> 생성자의 호출 순서: 부모 class가 먼저 초기화된 뒤 자식 class가 초기화된다.
		// --> breakpoint를 찍어가며 확인해볼 것.
		: m_d(1.0)
	{
		cout << "Child1 construction" << endl;
		m_i = 10;
		this->m_i = 10;
		Mother1::m_i = 1024;
		this->Mother1::m_i = 1024;
	}
};

/**************** Topic 2 ****************/
class Mother2
{
private:
	int m_i;

public:
	Mother2(const int & in_m)
		: m_i(in_m)
	{
		cout << "Mother2 construction" << endl;
	}
};

class Child2 : public Mother2
{
public:
	double m_d;

public:
	Child2()
		: Mother2(1024), m_d(1.0) // 자식 class의 생성자에서 m_i를 초기화하는 방법.
	    //: Mother2(), m_d(1.0)   // 순서와 상관없이 컴파일러는 부모 class의 생성자를 우선 실행하다.
	{
			cout << "Child2 construction" << endl;
	}
};

/**************** Topic 3 ****************/
// 다단 구조의 상속이 되는 경우 A->B->C 순으로 생성자가 실행.
class A
{
public:
	A()
	{
		cout << "A construction" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B construction" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "C construction" << endl;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Child1 c1;


/**************** Topic 2 ****************/
	Child2 c2;


/**************** Topic 3 ****************/
	C c; // A->B->C
	B b; // A->B

	return 0;
}
