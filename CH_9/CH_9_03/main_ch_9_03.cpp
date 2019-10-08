/*
9.3강 "단항 연산자(+, -, !) 오버로딩 하기"
*/

#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	bool operator ! () const
	{
		// 무엇을 return 할 것인지는 문맥에 따라 결정된다. --> 돈이 없는 경우를 true로 본다고 가정.
		return (m_cents == 0) ? true : false;
	}

	friend std::ostream& operator << (std::ostream &out, const Cents &cents)
	{
		out << cents.m_cents;
		return out; 
	}
};

int main()
{
/**************** Topic 1 ****************/
	int a = 6;
	cout << -a << endl;

	Cents cents1(6);
	cout << -cents1 << endl;
	cout << -Cents(-10) << endl;

/**************** Topic 2 ****************/
	// not operator는 return type이 bool이다.
	cout << !a << endl;

	Cents cents2(0);
	cout << !cents1 << " " << !cents2 << endl;


	return 0;
}