/*
4.2강 "전역 변수(Global variable), 정적 변수(Static variable), 
       내부 연결(Internal linkage), 외부 연결(External linkage)"

- 전역 변수는 가급적 사용하지 않는 것이 좋다. 부득이하게 사용해야만 하는 경우에만 사용.

- (1) 블록 안에서 변수의 사용 범위가 제한된 있는 경우(=Local variable)에는 "linkage가 없다"라고 표현.
  (2) 변수를 선언했으며 해당 파일 내에서는 어디서든 사용할 수 있는 경우. = Internal linkage
  (3) .cpp 파일이 여러 개가 있으며, 한 파일에서 선언한 변수를 다른 cpp 파일에서도 사용이 가능한 경우. = External linkage
	  그러나 동일한 변수를 여러 파일에서 사용하는 것이 절대 좋지는 않다.
  즉, 여러 .cpp 파일에 흩어져있는 변수들을 linking 하면서 파일 간의 연결 관계를 만드느냐(=외부) 만들지 않느냐(=내부)의 차이.

- 가장 좋은 방향: 객체 지향 프로그래밍을 습득하여 전역 변수를 최소한으로 사용하는 것.
*/

#include <iostream>
using namespace std;

int value = 123; // Global variable. 이 파일 안에서는 어디서든 사용할 수 있다. g_value로 표시해줌으로써 실수를 줄일 수 있다.
// static int value = 123; // 전역 변수에 static을 붙임으로써 다른 cpp파일에서 사용될 수 없도록 막을 수 있다.

void doSomething() // Static variable, 정적 (지속) 변수, 실제 프로그래밍에선 잘 사용되지 않으나 디버깅하거나 테스팅할 때 자주 사용된다. (ex, 함수가 몇 번 실행되나 횟수를 체크할 때)
{
	static int a = 1; /* static의 뜻: a의 메모리가 정적으로 할당된다 = 블록 안에서 a가 다시 선언될 때 같은 메모리를 사용하며 초기화도 한 번만 실행한다.
					  -> Static variable을 선언할 때는 무조건 초기화를 동반해야 한다. 즉, static int a;(X)
					  -> Static variable은 일반적으로 외부에서 접근할 수 없다. */
	// int a = 1; /* 이라고 선언하면 함수가 반복될 때마다 메모리를 받았다가 OS에 반납하고 다시 OS로부터 할당받는 과정이 반복된다. 함수를 실행하면 초기화가 또 실행되어 2만 출력된다.
	/* int a = 1;를 전역 변수로써 할당하여 사용하면 static int와 같은 결과가 나온다. */
	++a;
	cout << a << endl;
}

/* #include "test.cpp"도 사용할 수 있으나 .cpp 파일을 직접 #include 하는 경우는 흔하지 않다.
 대신에 forward declaration을 사용; "어딘가에 doSomething_2라는 함수의 정의(=body)가 존재하므로 liking 할 때 사용하세요"라는 뜻. */
void doSomething_2(); // = extern void doSomething_2();
extern int b;

#include "MyConstants.h"

int main()
{
/********* Topic 1 *********/
	// 전역 변수(Global variable)
	cout << value << endl; // 123 출력.

	int value = 1; // Global variable과 이름이 같이 때문에 name hiding이 작동된다.
	cout << value << endl; // 1 출력.
	cout << ::value << endl; // 123 출력. 전역 연산자를 사용하여 다른 영역에 정의된 변수에 접근할 수 있다.



/********* Topic 2  *********/
	// 정적 변수(Static variable)
	int a = 10;

	doSomething(); // 2 출력. (int a = 1로 선언한 경우: 2 출력)
	doSomething(); // 3 출력. (int a = 1로 선언한 경우: 2 출력)
	doSomething(); // 4 출력. (int a = 1로 선언한 경우: 2 출력)
	// Global variable을 가급적 사용하지 않는 것이 좋은 이유 -> 11이 출력되지 않는다.


/********* Topic 3 *********/
	// 외부 연결(External linkage) with test.cpp
	/* linkage와 linking은 유사하지만, 뉘앙스 차이가 있다.
	linking은 연결 자체(N)를 뜻하고 linking은 연결을 시킨다(V)는 의미가 강함.*/
	cout << b << endl;



/********* Topic 4 *********/
	/* 전역 상수: #include "MyConstants.h"
	   동일한 header file에서 pi를 호출하였으므로 출력 결과는 같지만 메모리 주소는 다르다.
	   메모리 낭비를 불러일으킬 수 있다 
	-> 동일한 메모리는 사용하는 법: .cpp에서 초기화를 해주고 .h에서는 선언만 해준다. */
	cout << "In main.cpp " << Constants::pi << "memory adress? " << &Constants::pi << endl;

	doSomething_2();

	return 0;
}