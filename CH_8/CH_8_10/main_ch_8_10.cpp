/*
8.10강 "정적(static) 멤버 변수"
*/

#include <iostream>
using namespace std;

int generateID()
{
	static int s_id = 0; // 정적 변수가 함수 내에 정의가 된 경우.
	return ++s_id;
}

class Something1
{
public:
	int m_value = 1;
};

class Something2
{
public:
	static int s_value; // static member variable는 직접 초기화를 할 수 없다.
};
int Something2::s_value = 1; // 초기화하는 법. --> define in .cpp file (header file에 정의하면 컴파일 에러 발생).

class Something3
{
public:
	static const int s_value = 1; // static const일 경우 직접 초기화가 가능하다.
};
int Something3::s_value = 1; // 불가능 <-- 값을 바꿀 수 없다 = 값이 바뀌지 않도록 강제할 경우 사용.

class Something4
{
public:
	static constexpr int s_value = 1; // constexpr으로 선언할 경우 컴파일 타임에 값이 결정되어 있어야 한다. (런타임 시의 값 할당은 불가능)
};
int Something4::s_value = 1; // 불가능


int main()
{
/**************** Topic 1 ****************/
	// 함수를 이용하여 ID(고유 넘버)를 생성하는 예제
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << generateID() << endl;

/**************** Topic 2 ****************/
	// class를 이용.
	Something1 st11;
	Something1 st12;

	st11.m_value = 2;

	cout << &st11.m_value << " " << st11.m_value << endl;
	cout << &st12.m_value << " " << st12.m_value << endl;
	// --> int로 선언한 경우 주소와 값 모두 다르다.

/**************** Topic 3 ****************/
	// class와 static member variable를 이용.
	cout << &Something2::s_value << " " << Something2::s_value << endl;
	// --> 놀라운 사실: instant가 없는 경우에도 주소가 존재한다 = static이므로 직접 접근이 가능하다. 
	Something2 st21;
	Something2 st22;

	st21.s_value = 2;

	cout << &st21.s_value << " " << st21.s_value << endl;
	cout << &st22.s_value << " " << st22.s_value << endl;
	/* --> static int로 선언한 경우 주소와 값 모두 같다.
		   st3.s_value의 값만 바꿨음에도 st4.s_value도 2로 변하였다. */
	Something2::s_value = 1024; /* 또한 instant가 없이도 s_value의 값을 직접 바꿀 수 있다 
								   --> 메모리에 동적으로 존재하는 것이 아닌 정적으로 존재하기 때문에. */
	cout << &Something2::s_value << " " << Something2::s_value << endl;

/**************** Topic 4 ****************/
	// static const 또는 static constexpr member variable일 경우.
	Something3 st3;
	Something4 st4;

	return 0;
}