/*
8.3강 "생성자(Constructors)"

- Constructor가 없으면 instant를 생성하지 못한다. 
  그러나, constructor가 instant를 자체적으로 생성하는 것은 아니다. 
- Constructor는 construction 될 때 호출되는 함수이다. 
*/

#include <iostream>
using namespace std;

class Fraction1
{
 private: // member variable들은 encapsulation 하여 꽁꽁 숨겨놓았다.
// public: // Topic 2의 초기화 (1), (2)시에 public으로 바꿔야 함.
	int m_numerator;
	int m_denominator;

public: 
	Fraction1() // constructor: return 타입이 없고 class와 이름이 동일하다.
	{
		m_numerator = 0;
		m_denominator = 1;

		cout << "Fraction() constructor" << endl; // constructor의 실행을 확인. <-- 디버깅 모드로 확인해볼 것.
	}

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

class Fraction2
{
private:
	int m_numerator;
	int m_denominator;

public:
	// Fraction2() {}: constructor를 별도로 만들지 않는 경우 default constructor가 숨어있다.
	Fraction2() // default value가 들어간 constructor를 임의로 만들어줄 수 있다.
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	
	Fraction2(const int& num_in, const int& den_in = 1) // func.과 동일하게 default value를 넣을 수 있다.
//  Fraction2(const int& num_in = 1, const int& den_in = 1) // default constructor처럼 사용할 수 있다.
	{
		m_numerator = num_in;
		m_denominator = den_in;

	}

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

// First class 안에서 Second class type의 variable이 member로 들어있는 상황.
class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};
class First
{
	Second sec;

public:
	First()
	{
		cout << "class First constructor()" << endl;
	}

};

int main()
{
/**************** Topic 1 ****************/
	// 초기화가 없다면 이상한 값이 할당된다.
	Fraction1 frac1; 
	frac1.print(); // -858993460 / -858993460 출력.


/**************** Topic 2 ****************/
	// 초기화 (1): member variable을 public으로 바꾸어 초기화.
	Fraction1 frac2{ 0, 1 };

	// 초기화 (2)
	frac2.m_numerator = 0;
	frac2.m_denominator = 1;
	frac2.print(); // 0 / 1 출력.


/**************** Topic 3 ****************/
	// 초기화 (3): constructor를 이용하여 encapsulation을 유지하면서 초기화
	Fraction1 frac3; // frac3이 선언됨과 동시에 constructor가 실행된다.
	frac3.print();

		
/**************** Topic 4 ****************/
	/* 주의사항:
	Fraction frac3(); <-- 생성자도 함수이므로 이처럼 ()가 있어야 한다. 
	
	Fraction frac3; <-- 그러나 생성자의 parameter가 하나도 없을 경우에는 ()를 항상 빼도록 되어있다.
	--> 하나라도 constructor를 만들면 default constructor를 생성하지 않는다.
	*/
	Fraction2 frac(1,3);
	frac.print();


/**************** Topic 5 ****************/
	// 초기화하는 방법.
	/* (1) Fraction2 frac = Fraction2{1,3}; 그러나 코드가 길어지므로 권장하지 않는다.
	   (2) Fraction2 frac(1, 3)과 Fraction2 frac{1, 3}의 차이: 
	       대부분의 경우엔 비슷하나 uniform initialization인 { 1.0, 3 }는 형변환을 허용하지 않으나 ( 1.0, 3 )는 경고만 뜰 뿐 허용한다.  
		   --> { }이 더 엄격해서 좋다는 평이다. */


/**************** Topic 6 ****************/
	// class 안에 class가 있는 경우.
	First fir;
	// Second가 First의 member로 들어있기 때문에, member를 먼저 초기화하는 순서가 옳다.

	return 0;
}