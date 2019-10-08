/*
9.9강 "복사 생성자(Copy constructor), 복사 초기화, 반환값 최적화(RVO, Return Value Optimization)"
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

	Fraction(const Fraction &frac) // 자기 자신, 자신과 똑같은 type이 들어오면 복사한다.
		: m_numetator(frac.m_numetator), m_denominator(frac.m_denominator)
	{
		cout << "Copy constructor called" << endl; // copy constructor는 얼마나 자주 호출이 되는지가 중요.
	}
	// --> 보안 등의 이유로 copy constructor를 막고 싶을 때는 private:으로 이동한다.

	friend std::ostream & operator << (std::ostream & out, const Fraction & f)
	{
		out << f.m_numetator << "/" << f.m_denominator;
		return out;
	}
};

Fraction doSomething() // 특정한 함수 형태로 Fraction을 return 하는 경우.
{
	Fraction temp(1, 2); // default constructor로 생성이 된 값이 copy 된다.
	cout << "temp: " << &temp << endl;
	return temp;
}


int main()
{
/**************** Topic 1 ****************/
	// copy constructor가 호출이 될 필요가 없는 상태.
	Fraction frac(3, 5);
	
/**************** Topic 2 ****************/
	// copy constructor 호출.
	Fraction frac_copy(frac); // 3과 5가 copy 되기를 기대한다.
	cout << frac << " " << frac_copy << endl;

/**************** Topic 3 ****************/
	// copy initialize할 때도 copy constructor가 호출된다.
	Fraction frac_copy1 = frac;
	cout << frac << " " << frac_copy1 << endl;

/**************** Topic 4 ****************/
	// Fraction을 새로 만들어 대입할 땐 copy constructor가 호출되지 않는다.
	Fraction frac_copy2(Fraction(3, 10));
	// = Fraction frac_copy2(3, 10); <-- 컴파일러가 임의로 판단.
	cout << frac << " " << frac_copy2 << endl;

/**************** Topic 5 ****************/
	// 함수를 이용한 경우 debug mode 일 때는 copy constructor가 호출되지만 release mode에서는 최적화의 이유로 호출되지 않는다.
	Fraction result = doSomething();
	cout << "result: " << &result << endl;
	cout << result << endl;
	// debug mode 일 때는 주소가 다르다 = 복사했다.
	// release mode에서는 주소가 같다 = 복사할 필요가 없다.

	return 0;
}