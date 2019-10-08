/*
9.9�� "���� ������(Copy constructor), ���� �ʱ�ȭ, ��ȯ�� ����ȭ(RVO, Return Value Optimization)"
*/

#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numetator;
	int m_denominator;

public:
	Fraction(int num, int den)
		: m_numetator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction &frac) // �ڱ� �ڽ�, �ڽŰ� �Ȱ��� type�� ������ �����Ѵ�.
		: m_numetator(frac.m_numetator), m_denominator(frac.m_denominator)
	{
		cout << "Copy constructor called" << endl; // copy constructor�� �󸶳� ���� ȣ���� �Ǵ����� �߿�.
	}
	// --> ���� ���� ������ copy constructor�� ���� ���� ���� private:���� �̵��Ѵ�.

	friend std::ostream & operator << (std::ostream & out, const Fraction & f)
	{
		out << f.m_numetator << "/" << f.m_denominator;
		return out;
	}
};

Fraction doSomething() // Ư���� �Լ� ���·� Fraction�� return �ϴ� ���.
{
	Fraction temp(1, 2); // default constructor�� ������ �� ���� copy �ȴ�.
	cout << "temp: " << &temp << endl;
	return temp;
}


int main()
{
/**************** Topic 1 ****************/
	// copy constructor�� ȣ���� �� �ʿ䰡 ���� ����.
	Fraction frac(3, 5);
	
/**************** Topic 2 ****************/
	// copy constructor ȣ��.
	Fraction frac_copy(frac); // 3�� 5�� copy �Ǳ⸦ ����Ѵ�.
	cout << frac << " " << frac_copy << endl;

/**************** Topic 3 ****************/
	// copy initialize�� ���� copy constructor�� ȣ��ȴ�.
	Fraction frac_copy1 = frac;
	cout << frac << " " << frac_copy1 << endl;

/**************** Topic 4 ****************/
	// Fraction�� ���� ����� ������ �� copy constructor�� ȣ����� �ʴ´�.
	Fraction frac_copy2(Fraction(3, 10));
	// = Fraction frac_copy2(3, 10); <-- �����Ϸ��� ���Ƿ� �Ǵ�.
	cout << frac << " " << frac_copy2 << endl;

/**************** Topic 5 ****************/
	// �Լ��� �̿��� ��� debug mode �� ���� copy constructor�� ȣ������� release mode������ ����ȭ�� ������ ȣ����� �ʴ´�.
	Fraction result = doSomething();
	cout << "result: " << &result << endl;
	cout << result << endl;
	// debug mode �� ���� �ּҰ� �ٸ��� = �����ߴ�.
	// release mode������ �ּҰ� ���� = ������ �ʿ䰡 ����.

	return 0;
}