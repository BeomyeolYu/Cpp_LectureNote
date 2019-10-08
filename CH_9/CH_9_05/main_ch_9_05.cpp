/*
9.5강 "증감 연산자 오버로딩 하기"

- 증감 연산자는 전위(prefix)와 후위(postfix)에 차이가 있다.
- prefix: '증감 연산' 후 변수에 '할당'.
- postfix: 변수에 '할당' 후 '증감 연산'.
- 전위나 후위 모두 사용해도 될 경우에는 전위 증감 연산자를 사용하면 성능상 이득을 볼 수 있다.
*/

#include <iostream>
using namespace std;

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) : m_digit(digit) {}
	int getCents() const { return m_digit; }

	// prefix
	Digit & operator ++ () // ref. 
	{
		++m_digit;
		return *this; // 자기 자신을 return 한다.
	}
	
	// postfix
	Digit operator ++ (int) // parameter로 dummy를 넣어주는 것이 postfix의 규칙이다.
	{
		Digit temp(m_digit); // 우선 현재 값을 저장한다.
		++m_digit; // = ++(*this); 위에서 만든 prefix를 사용.
		return temp; 
	}

	friend ostream& operator << (ostream &out, const Digit &d)
	{
		out << d.m_digit;
		return out;
	}
};

int main()
{
/**************** Topic 1 ****************/
	// prefix와 postfix의 차이.
	int a = 10;

	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;

/**************** Topic 2 ****************/
	Digit d(10);
	cout << ++d << endl;
	cout << d << endl;
	cout << d++ << endl;
	cout << d << endl;

	return 0;
}