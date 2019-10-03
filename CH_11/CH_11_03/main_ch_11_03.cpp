/*
11.3�� "������(Derived) Ŭ�������� ���� ����"

- �Ҹ��ڴ� �����ڿ� �ݴ� ������ ����ȴ�.
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
		//: m_i(1) // m_i�� public���� ����Ǿ� �־ �����ڿ��� �ʱ�ȭ�� �Ұ����ϴ�.
		//: Mother1(), m_d(1.0) // ���������� Mother1()�� �����ִ�.
		// --> �������� ȣ�� ����: �θ� class�� ���� �ʱ�ȭ�� �� �ڽ� class�� �ʱ�ȭ�ȴ�.
		// --> breakpoint�� ���� Ȯ���غ� ��.
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
		: Mother2(1024), m_d(1.0) // �ڽ� class�� �����ڿ��� m_i�� �ʱ�ȭ�ϴ� ���.
	    //: Mother2(), m_d(1.0)   // ������ ������� �����Ϸ��� �θ� class�� �����ڸ� �켱 �����ϴ�.
	{
			cout << "Child2 construction" << endl;
	}
};

/**************** Topic 3 ****************/
// �ٴ� ������ ����� �Ǵ� ��� A->B->C ������ �����ڰ� ����.
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
