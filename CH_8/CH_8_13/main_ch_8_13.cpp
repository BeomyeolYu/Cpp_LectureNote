/*
8.13�� "�͸�(anonymous) ��ü"

- ��ü�� ����� �� �̸��� ���� ������ �������� �ʰ� �ٷ� ����ϴ� ��.
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
	// �̸��� ���� ������ �����Ͽ� ���� �� print�� ���
	A a;
	a.print();
	a.print(); // Constructor�� Destructor�� �� ������ ����ȴ�.

/**************** Topic 2 ****************/
	// �� ���� print �Լ� ����� ���Ͽ� a�� �����ϴ� ���� ���ŷο� �� �ִ�. 
	A().print(); // A()�� L-Value�� �ƴ� R-Value�� ������ �Ѵ�.
	// �׷���, �ݺ� ��� �� �� Constructor�� Destructor�� �Ź� ����ȴ�. (= ���� �� �ٷ� destructor �ȴ�)
	A().print(); 

/**************** Topic 3 ****************/
	B b(1); // <-- �Է��� ��ġ�� �ٸ���.
	b.printDouble();

	B(2).printDouble(); // <-- �Է��� ��ġ�� �ٸ���.

/**************** Topic 4 ****************/
	// ����
	cout << add(Cents(6), Cents(8)).getCents() << endl;
	// ����: ������ ���� �ε����� ������
	cout << int(6) + int(8) << endl;

	return 0;
}