/*
4.4강 "auto 키워드와 자료형 추론(Type inference)"

- 변수의 자료형을 매번 수동으로 결정해주는 것은 프로그래밍의 효율을 떨어트린다.
*/

#include <iostream>

auto add(int x, int y) // int + int이므로 add 함수가 int임을 추론 가능= int add(int x, int y)
{
	return x + y;
	// return x + (double)y; // 강제 형 변환을 수행하면 add는 double로 결정된다.
}

auto add(int x, int y) -> int; // Trailing Return Type (리턴 타입 추적하기)
/*
왼쪽에 있는 auto 키워드는 자리 선점의 의미이다. 실제 타입은 → 이후에 표시된 것을 따른다.
추후 template 함수를 사용할 때 유용하게 활용된다.
*/

using namespace std;

int main()
{
/********* Topic 1 *********/
	int a_ = 123; // 중복된 정보가 있다. 123도 정수도 int도 정수이다.
	auto a = 123; // 결정 요소는 초기화 정보에 포함되어있기 때문에 초기화가 없이는 auto를 사용할 수 없다.

	auto d = 123.0;	  // double로 결정.
	auto c = 1 + 2.0; // int + double = double로 결정.
	// auto를 사용할 경우 프로그래머는 추론된 자료형을 명확히 확인해두어야 한다.


/********* Topic 2 *********/
	// 함수의 리턴값에 대해서도 auto를 사용할 수 있다.
	auto result = add(1, 2); // int + int = result의 type이 자동으로 int로 결정.

	return 0;
}