/*
9.1�� "��� ������ �����ε� �ϱ�"

- int, double�� ���� �⺻ �ڷ������� ��� �����ڰ� �⺻������ ���ǰ� �Ǿ��־� ���ϰ� ����� �� �ִ�.
- class�� ���� ����� ���� �ڷ��������� ��� �����ڸ� �������� �� �ִ�.

- �����ε��� �ȵǴ� ������: ?: / :: / sizeof / . / .*
- �����ε� �� ������ ���� �⺻ �����ڿ� �켱������ �����ϴ�.
*/

#include <iostream>
using namespace std;
/**************** Topic 1 ****************/
class Cents
{
private:
	int m_cents;
	
public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }
};
Cents add(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

/**************** Topic 2 ****************/
Cents operator + (const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

/**************** Topic 3 ****************/
class Cents2
{
private:
	int m_cents;

public:
	Cents2(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend Cents2 operator + (const Cents2 &c1, const Cents2 &c2) // func.�� ���Ǹ� friend�� class �ȿ� �ΰ� �Լ��� class ������ ���� ���� �ִ�.
	{
		return Cents2(c1.getCents() + c2.getCents());
	}
};

/**************** Topic 4 ****************/
class Cents3
{
private:
	int m_cents;

public:
	Cents3(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	Cents3 operator + (const Cents3 &c2) // ���ʿ� �ִ� parameter�� this�� ��ü.
	{
		return Cents3(this->m_cents + c2.m_cents); // member func.�� �Ǿ����Ƿ� getCents()�� ������ �ʰ� m_cents�� ���� ������ �� �ִ�.
	}
};

int main()
{
/**************** Topic 1 ****************/
	// 6��Ʈ�� 8��Ʈ�� ���ϰ� ���� ���.
	// (1) �Ϲ����� �Լ��� �����ε� �ϴ� ���.
	Cents cents1(6);
	Cents cents2(8);

	cout << add(cents1, cents2).getCents() << endl;
	// --> ���������� ���� ������ ����� ��쿡�� ��ó�� �Լ��� ����ϴ� ���� �����ϴ�.

/**************** Topic 2 ****************/
	// (2) ��� �����ڸ� ����ϴ� ���.
	cout << (cents1 + cents2).getCents() << endl;

/**************** Topic 3 ****************/
	// (3) friend func.�� �̿��ϴ� ���.
	Cents2 cents3(6);
	Cents2 cents4(8);
	cout << (cents3 + cents4 + Cents2(2)).getCents() << endl;

/**************** Topic 4 ****************/
	// (4) member func.���� ����. 
	Cents3 cents5(6);
	Cents3 cents6(8);
	cout << (cents5 + cents6 + Cents3(2) + Cents3(4)).getCents() << endl;
	// --> class�� member func.�θ� ����ϴ� ������: = , [] , () , -> 

	return 0;
}