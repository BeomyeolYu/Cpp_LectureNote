/*
Chapter 3. 연산자들
3.1강 "연산자 우선순위와 결합법칙(Operator Precedence and Associativity)"
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
/********* Topic 1 *********/
	int x = 4 + 2 * 3;
	// 기초 수학 이론과 동일하게 int x = 4 + (2 * 3);


/********* Topic 2 *********/
	/* 
	Operator precedence in https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
	Precedence: 우선순위
	Associativity: 결합법칙

	Ex1, Precedence 5, *, /와 %는 우선순위가 같으며, 
	     우선순위가 같은 것끼리 만났을 때(Associativity) Left-to-right로 연산.

	Ex2, Precedence 3, Unary plus = +1, Unary minus = -4.
	     int x = (1-2) + (-3); Right-to-left. 왜냐하면 -3 왼쪽에 아무것도 없기 때문.

	Ex3, Precedence 16, Direct assignment(=) is Right-to-left.
		 int x = 4 + 2 * 3;

	Ex4, Precedence 11, ^는 제곱이 아닌 논리 연산자(Bitwise XOR (exclusive or))임.
		 2의 3제곱의 경우 #include <cmath> 후 int x = std::pow(2, 3); 
		 [참고] std::pow의 경우 double형이므로, int형으로 만들고 싶거나 효율적으로 계산하고 싶을 때는 함수 또는 표를 만들어 쓰기도 함.

	tip. 일반적으로 표를 모두 외울 수 없기 때문에 괄호를 사용하여 우선순위를 명확하게 코드에 남김.
	*/

return 0;
}