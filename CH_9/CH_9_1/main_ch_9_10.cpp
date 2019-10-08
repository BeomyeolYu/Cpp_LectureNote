/*
9.10강 "변환 생성자(Converting constructor), explicit, delete"

- Converting constructor: 프로그래머의 편의를 위해서 생성자를 변환해준다.
- explicit: converting constructor를 사용하지 못하도록 막는다.
- delete: 특별한 생성자를 사용하지 못하도록 지운다.
  --> 동적 할당에서 메모리를 지우는 delete와는 다른 keyword이다.
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
	Fraction(int num = 0, int den = 1) // 기본값이 지정되어 있다.
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

	explicit Fraction1(int num = 0, int den = 1) // explicit: 명확히 하라는 뜻.
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
	doSomething(7);	// 7만 넣어도 기본값 1과 함께 출력된다. = Converting constructor

/**************** Topic 2 ****************/
	// explicit을 사용하면 명확하게 입력해준 경우에만 작동한다.
	Fraction1 frac1(7);

	doSomething1(frac1);
	doSomething1(Fraction1(7));
	doSomething1(7); // 입력이 하나인 경우에 사용할 수 없다.

/**************** Topic 3 ****************/
	// delete: 주의 깊게 프로그래밍할 때 사용된다.
	// --> Ex) 버전업을 할 때 사용자들이 이전 버전에서 사용하던 방식을 사용할 것이 우려될 때 강력히 막아버릴 때 사용할 수 있다.
	Fraction frac2('c');
	Fraction1 frac3('c');

	return 0;
}