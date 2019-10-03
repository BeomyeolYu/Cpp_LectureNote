/*
11.4�� "������(Derived) Ŭ�������� ������ �ʱ�ȭ"
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

	// Mother�� Child�� ǥ���� �� �ʿ��� �ּ����� �����;�.
	cout << sizeof(Mother) << endl; // int = 4 bytes 
	cout << sizeof(Child) << endl;  // padding �������� ���� int(4) + double(8) = 12 bytes�� �ƴ� 16 bytes�� ��µȴ�.
	cout << sizeof(c1) << endl;  // ��, Child class�� Mother class�� ���� �� ���� ��ŭ�� �����Ͱ� �Ҵ���� ���.

/**************** Topic 2 ****************/
	C c(1024, 3.14, 'a');

	return 0;
}
