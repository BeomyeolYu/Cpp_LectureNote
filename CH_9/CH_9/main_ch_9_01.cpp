/*
9.1강 "산술 연산자 오버로딩 하기"

- int, double과 같은 기본 자료형들은 산술 연산자가 기본적으로 정의가 되어있어 편리하게 사용할 수 있다.
- class와 같은 사용자 정의 자료형끼리도 산술 연산자를 정의해줄 수 있다.

- 오버로딩이 안되는 연산자: ?: / :: / sizeof / . / .*
- 오버로딩 한 연산자 또한 기본 연산자와 우선순위가 동일하다.
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

	friend Cents2 operator + (const Cents2 &c1, const Cents2 &c2) // func.의 정의만 friend로 class 안에 두고 함수를 class 밖으로 꺼낼 수도 있다.
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

	Cents3 operator + (const Cents3 &c2) // 왼쪽에 있는 parameter를 this로 대체.
	{
		return Cents3(this->m_cents + c2.m_cents); // member func.이 되었으므로 getCents()를 통하지 않고 m_cents로 직접 접근할 수 있다.
	}
};

int main()
{
/**************** Topic 1 ****************/
	// 6센트와 8센트를 더하고 싶을 경우.
	// (1) 일반적인 함수로 오버로딩 하는 방법.
	Cents cents1(6);
	Cents cents2(8);

	cout << add(cents1, cents2).getCents() << endl;
	// --> 직관적이지 않은 연산이 수행될 경우에는 이처럼 함수를 사용하는 것이 안전하다.

/**************** Topic 2 ****************/
	// (2) 산술 연산자를 사용하는 방법.
	cout << (cents1 + cents2).getCents() << endl;

/**************** Topic 3 ****************/
	// (3) friend func.을 이용하는 방법.
	Cents2 cents3(6);
	Cents2 cents4(8);
	cout << (cents3 + cents4 + Cents2(2)).getCents() << endl;

/**************** Topic 4 ****************/
	// (4) member func.으로 구현. 
	Cents3 cents5(6);
	Cents3 cents6(8);
	cout << (cents5 + cents6 + Cents3(2) + Cents3(4)).getCents() << endl;
	// --> class의 member func.로만 써야하는 연산자: = , [] , () , -> 

	return 0;
}