/*
2.3강 "C++ 11 고정 너비 정수 (Fixed-width Integers)"
C++ 표준에서는 데이터 사이즈의 '최소 사이즈'만 규정을 하고 있기 때문에 플랫폼마다 또는 컴파일러마다 실제 구현된 사이즈가 다른 문제가 발생함.
예를 들어서 int 형의 경우 보통은 4 bytes이지만 2 bytes로 규정되기도 함.

불확실성의 존재는 프로그래밍할 때의 부담이 되기 때문에 C++ 11부터는 어떤 플랫폼이던지 똑같은 데이터 사이즈를 사용하는 고정 너비 정수가 채택됨.
당장에 쓰지 않더라도 나중에 멀티 플랫폼 프로그래밍을 할 때 자주 논의됨.
*/

#include <iostream> 
// #include <cstdint> : cstdint은 #include <iostream>에 포함되어 있음.

int main()
{
	using namespace std;

	// 초록색 글자 위에 마우스를 얹으면 데이터 타입이 보임.
	std::int16_t i(5);		// 16 bits = 2 bytes 타입으로 바꿔줌 = short
	std::int8_t myint = 65; // 8 bits = 1 byte 타입으로 바꿔줌 = char
	cout << myint << endl;	// Answer is A, not 65.
	/* 65가 아니라 A가 출력됨. int가 쓰여있지만 int가 아님을 유의. 
	이 때문에 헷갈리지 않도록 int8_t는 쓰지 말고 char를 쓰자는 의견이 있음. */

	std::int_fast8_t fi(5);		// fast: 8 bits 사이즈 중에 가장 빠른 타입을 선정.
	std::int_least64_t fl(5);	// least: 적어도 64 bits를 갖는 데이터 타입을 선정.

	return 0;
}