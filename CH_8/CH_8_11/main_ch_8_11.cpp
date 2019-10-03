/*
8.11강 "정적(static) 멤버 함수"

- C++에서 하나의 class에서 생성된 instance는 각각 독립된 메모리 공간에 저장된 자신만의 멤버 변수를 가지지만, 멤버 함수는 모든 인스턴스가 공유한다.
*/

class Something1
{
public: // Topic 1
	static int s_value; // static 맴버 변수는 주소가 하나뿐이며 같은 class에서 생성된 모든 instance에서 접근이 가능하다.
	// int s_value;     // <--> non-static 변수와는 성질이 다르다.

public:
	int getValue()
	{
		return s_value;
	}
};

class Something2
{
private: // Topic 2
	static int s_value; 
	int m_value;

public:
	static int getValue() // <-- static으로 선언한다.
	{
		return s_value;
		// return this->s_value; // non-static member func.에서는 this pointer로 접근할 수 있는 모든 것이 불가능.
		// return m_value;       // Ex) 오류 발생 --> static member func.에서는 m_value에 접근할 수 없다.
	}

	int temp() // 기능은 동일하지만 static이 아니다.
	{						  // 
		return this->s_value; /* this pointer은 non-static member func.에서만 사용할 수 있다.
							     --> this pointer: 특정 instance의 주소를 받아 사용한다.
								 --> 대부분의 경우에 this pointer가 숨어있으나 사용자의 편의를 위하여 생략할 수 있다. */
		// return this->s_value + this->m_value; // Ex) this pointer 활용 방법
	}

};
int Something1::s_value = 1024; // 초기화
int Something2::s_value = 1024;

class Something3
{
public:
	class _init // inner class
	{
	public:
		_init() // constructor
		{
			s_value = 9876;
		}
	};

private:
	static int s_value;
	int m_value;

	static _init s_initializer; // initializer를 static으로 선언해준다.

public:
	Something3()
		: m_value(123)
		// , s_value(1024) 
		/* --> static member variable은 생성자(constructor)에서 초기화해줄 수 없다. 
		   --> 19년 기준 static constructor가 존재하지 않으므로 inner class를 사용하여 초기화해주어야 한다. */
	{}

	static int getValue() 
	{
		return s_value;
	}
};
int Something3::s_value;
Something3::_init Something3::s_initializer;

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// public: static int s_value; 일 때,
	cout << Something1::s_value << endl; // s_value는 static이므로 특정 instance와 상관없이( = Something s1;를 선언하지 않고도) 직접 접근이 가능.

	Something1 s1;
	cout << s1.getValue() << endl;     // = s1.getValue()를 통하여 s_value에 접근.
	cout << s1.s_value << endl;        // = s1.getValue()를 통하지 않고 s_value에 직접 접근하여 사용 가능.

	cout << &Something1::s_value << endl; // 주소가 
	cout << &s1.s_value << endl;          // 동일하다.


/**************** Topic 2 ****************/
	// private:	static int s_value; 일 때,
	cout << Something2::s_value << endl;    // private으로 선언될 경우에는 instance를 거치지 않고는 직접 접근할 수 없다.
	cout << Something2::getValue() << endl; // --> static member func.인 getValue를 통해서 접근 가능.

	Something2 s2;
	cout << s2.getValue() << endl;     // s2.getValue()를 통해서는 s_value에 접근 가능.
	cout << s2.s_value << endl;        // private의 경우 s_value에 직접 접근이 불가능하며 s2.getValue()를 통해서만 접근이 가능.


/**************** Topic 3 ****************/
	// member func.의 pointer를 가져오는 법 --> member func.은 각 instant에 대해 별개의 주소를 갖는 것이 아니라 공유한다.
	// (1) non-static member func.
	int (Something2::*fptr1)() = &Something2::temp; // ::temp is non-static.
	cout << (s2.*fptr1)() << endl; // non-static member func.은 instant에 종속이 되는 형태로 구현이 되어있으므로 s2.(= dispointer)이 필요하다.

	// (2) staitc member func. 
	int (*fptr2)() = &Something2::getValue; // 특정 instant로 연결을 안 시켜줘도(= 상관없는 형태로) pointer를 가져온다.
	cout << fptr2() << endl;
	

/**************** Topic 4 ****************/
	// inner class를 이용한 static member variable의 초기화
	cout << Something3::getValue() << endl;

	return 0;
}