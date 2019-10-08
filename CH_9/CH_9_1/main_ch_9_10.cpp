/*
9.10�� "��ȯ ������(Converting constructor), explicit, delete"

- Converting constructor: ���α׷����� ���Ǹ� ���ؼ� �����ڸ� ��ȯ���ش�.
- explicit: converting constructor�� ������� ���ϵ��� ���´�.
- delete: Ư���� �����ڸ� ������� ���ϵ��� �����.
  --> ���� �Ҵ翡�� �޸𸮸� ����� delete�ʹ� �ٸ� keyword�̴�.
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
	Fraction(int num = 0, int den = 1) // �⺻���� �����Ǿ� �ִ�.
		: m_numetator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction &frac) // copy constructor
		: m_numetator(frac.m_numetator), m_denominator(frac.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Fraction & f)
	{
		out << f.m_numetator << "/" << f.m_denominator;
		return out;
	}
};
void doSomething(Fraction frac) { cout << frac << endl; }

class Fraction1
{
private:
	int m_numetator;
	int m_denominator;

public:
	Fraction1(char) = delete;

	explicit Fraction1(int num = 0, int den = 1) // explicit: ��Ȯ�� �϶�� ��.
		: m_numetator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	Fraction1(const Fraction1 &frac) // copy constructor
		: m_numetator(frac.m_numetator), m_denominator(frac.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Fraction1 & f)
	{
		out << f.m_numetator << "/" << f.m_denominator;
		return out;
	}
};
void doSomething1(Fraction1 frac) {	cout << frac << endl; }

int main()
{
/**************** Topic 1 ****************/
	Fraction frac(7);

	doSomething(frac);
	doSomething(Fraction(7));
	doSomething(7);	// 7�� �־ �⺻�� 1�� �Բ� ��µȴ�. = Converting constructor

/**************** Topic 2 ****************/
	// explicit�� ����ϸ� ��Ȯ�ϰ� �Է����� ��쿡�� �۵��Ѵ�.
	Fraction1 frac1(7);

	doSomething1(frac1);
	doSomething1(Fraction1(7));
	doSomething1(7); // �Է��� �ϳ��� ��쿡 ����� �� ����.

/**************** Topic 3 ****************/
	// delete: ���� ��� ���α׷����� �� ���ȴ�.
	// --> Ex) �������� �� �� ����ڵ��� ���� �������� ����ϴ� ����� ����� ���� ����� �� ������ ���ƹ��� �� ����� �� �ִ�.
	Fraction frac2('c');
	Fraction1 frac3('c');

	return 0;
}