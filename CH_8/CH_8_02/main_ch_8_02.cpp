/*
8.2강 "캡슐화(Encapsulation), 접근 지정자(Access specifiers), 접근 함수(Access functions)"

- 뛰어난 프로그래머는 복잡해 보이는 프로그램 안에서 연관 관계를 깔끔하게 정리하는 것이다.
- 캡슐화하여 정리하는 것이 핵심이며, 이때 사용되는 도구가 접근 지정자와 접근 함수이다.
- 프로토 타입 단계에서는 모든 member를 public으로 선언하여 구현할 수도 있으나,
  협업을 하거나 큰 프로그램을 만들 때는 private과 access func.을 통해서 접근하는 것이 장기적으로 유리하다.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date1 // struct
{
	int m_mouth1;
	int m_day1;
	int m_year1;
};

class Date2 // class
{
public: // access specifiers --> 외부에서 class 안에 있는 member 들에 직접적으로 접근 가능.
// private: //을 쓰면 외부에서 접근이 불가능하다. --> access func.을 통해서만 접근이 가능하다.
	int m_mouth2;
	int m_day2;
	int m_year2;
};

class Date3
{
	// private: defalut
	int m_mouth3;
	int m_day3;
	int m_year3;

public: // 같은 class 안의 member라면, access func.이 public이더라도 private member를 접근할 수 있다.
	// access func.(1): setters라고 부른다.
	void setData(const int& month_input, const int& day_input, const int& year_input) 
	{
		m_mouth3 = month_input;
		m_day3 = day_input;
		m_year3 = year_input;
	}
	void setMonth(const int& month_input)
	{
		m_mouth3 = month_input;
	}
	// setDay, setYear, ...

	// access func.(2): getters라고 부른다.
	const int& getDay() // getDay로 값이 바뀌지 않도록 const로 막아주는 것이 일반적이다. --> 값을 바꾸고 싶다면 setDay 함수를 통하도록.
	{
		return m_day3;
	}

	void copyFrom(const Date3& original) // 자기 자신을 type으로 받는다.
	{
		m_mouth3 = original.m_mouth3;
		m_day3 = original.m_day3;
		m_year3 = original.m_year3;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Date1 today1;    // Date1 today {8, 4 ,2025}; 로 초기화 가능.
	today1.m_mouth1; // struct는 member와 동일한 이름을 선언한다.

	Date2 today2;    // class
	today2.m_mouth2; // public access specifiers를 사용하면 가능하다.

	Date3 today3;      // class
	//today3.m_mouth3; // class의 defalut가 private이므로, class에 선언된 member에 접근할 수 없다.

/**************** Topic 2 ****************/
	today3.setData(8, 4, 2025);
	cout << today3.getDay() << endl;// get = 출력.

/**************** Topic 3 ****************/
	// 복사하는 예제.
	Date3 copy; // today3와 같은 class로부터 만들어진 instance이지만 주소도 다르고 내용도 다르다.
	copy.copyFrom(today3); // = copy.setData(today3.setMonth(), today3.setDay(), today3.setYear());

/**************** Topic 4 ****************/
	// Encapsulation을 안 하고 전부 public 운영하면 member re-name에서 어려움이 생긴다.
	/* class에 정의된 member의 이름을 바꾸고 싶을 때,
	   public으로 선언했다면 class 외부에서도 모든 member의 이름을 바꿔주어야 한다. <--public은 외부에서 member의 직접 접근이 가능하므로.
	   private으로 선언하고 외부에서는 access func.으로 접근한 경우 access func. 등 class 내부에서만 바꿔주면 된다. */

	return 0;
}