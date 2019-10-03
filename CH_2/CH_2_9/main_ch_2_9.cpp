/*
2.9강 "심볼릭 상수(Stmbolic Constants)": C++ 11 constexpr
*/

#include <iostream>
#define PRICE_PER_ITEM 30 /* C 프로그래밍에서 자주 쓰이는 '매크로' (대문자로 매크로를 선언하는 것이 관습임).
							그러나 C++에서는 전처리기이므로 적용 범위가 광범위하고 디버깅이 어려워 잘 사용되지 않음. */
#include"MY_CONSTANTS.h" // header file include.

using namespace std; // 'namespace의 위치를 바꾼다'라는 의미는 적용 범위를 바꾼 것임.

void printNumber(const int my_number)  // 함수의 input parameter에 const를 붙임으로써 다른 프로그래머가 값을 바꿀 수 없도록 함.
// = printNumber(const int& my_number) // const int& 로도 표현할 수 있음.
{
	cout << my_number << endl;
}

int main()
{
	/******* Topic 1 *******/
	/* 만약,
	double gravity{ 9.8 }
	이라고 선언한 후 다른 프로그래머가 내가 해놓은 정의를 바꾸지 않기를 원할 때, const를 붙여서 gravity는 못 바꾼다고 고정 지을 수 있음. */
	const double gravity{ 9.8 }; 
	// = double const gravity{ 9.8 }; 포인터 등을 제외하고 일반적으로 const의 순서를 바꿔도 괜찮음. 
	
	/*
	const double gravity; // 초기화하지 않으면 Error가 발생.
	gravity = 1.2;		  // 재정의를 하려고 하면 Error가 발생.
	*/


	/******* Topic 2 *******/
	printNumber(123); // const는 함수의 parameter로도 자주 쓰임.


	/******* Topic 3 *******/
	// (1) 컴파일 할 때(= "컴파일 타임"에) my_const의 값이 이미 결정됨. constexpr를 활용하여 (2)번과 구분하여 표기해둘 수 있음.
	const int my_const(123); // = constexpr int my_const(123); 

	// (2) special_number의 값은 런타임 할 때 (cin으로) 결정됨.
	int number;
	cin >> number;
	const int special_number(number); // "런 타임"에 결정되기 때문에 constexpr를 사용하면 에러가 발생.
	/* [참고] 사실 상수값이 런타임인지 컴파일 시간인지는 중요하지 않을 수 있으나 C++ 에는 런타임 상수 대신에 컴파일 타임 상수를 요구하는 몇 가지 경우가 있다. (ex. 고정 크기 배열의 길이를 정의하는 경우)
	이와 같이 더 많은 특수성을 제공하기 위해 C++ 은 constexpr을 도입했으며, constexpr 키워드를 사용한 상수는 컴파일 시간 상수여야 한다. */



		출처: https://boycoding.tistory.com/156 [소년코딩]

	/******* Topic 4 *******/
	int num_item = 123;
	int price = num_item * PRICE_PER_ITEM; // 기능은 구현되지만 매크로로 상수값을 적용하는 방법은 사용하지 않는 것이 좋음.

	const int price_per_item = 30; // 중괄호 내에서만 적용하는 것을 확실히 확인할 수 있음. 관습적으로 const 임을 표현하기 위해 k_, ceff_ 등을 붙이기도 함.
	int price_ = num_item * price_per_item;


	/******* Topic 5 *******/
	/* const를 변수로 변경하거나 일반화가 필요할 수도 있기 때문에 const들을 모아놓는 경향이 있음.
	한 곳에 모아놓으면 값을 변경하고 싶을 때 하나하나 찾으며 바꿔야 할 필요가 없으므로 모아놔야 좋음.

	별도로 namespace를 이용하고 별도의 header file을 이용해서 정리함: constants::pi
	-> "MY_CONSTANTS.h"과 같이 헤더 파일을 정의해놓으면 다른 .cpp 파일에서도 재사용이 가능한 장점이 있음. 
	*/
	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;

	return 0;
}

