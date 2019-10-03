/*
1.8강 "연산자와의 첫 만남"
- 리터럴(Literal)
- 피연산자(Operand)
- 단항 연산자(unary operator)
- 이항 연산자(binary operator)
- 삼항 연산자(ternary operator)
*/
#include <iostream>

using namespace std;

int main()
{
	int x = 2; // x is a variable. (메모리 주소를 가지고 있음.)
	// 2 is a literal. 단지 숫자임. 메모리 공간을 가지는 것이 아님.
	// 등호(=)는 assignment, 대입 연산자.

	cout << "Hello, world" << endl;
	// 문자열도 literal임.

	cout << 1 + 2 << endl;
	// +는 연산자(operator)임.
	// 1도 literal이고 2도 literal이고 1+2는 표현식(expression)임.
	// 1과 2와 같이 연산을 당하는 대상을 피연산자(Operand)라고 칭함.
	// Unary operator:  Ex) -2 또는 -x, 음수로 바꾸는 연산자.
	// Binary operator: Ex) 1 + 2, 피연산자가 2개.

	int y = (x > 0) ? 1 : 2;
	// 조건 연산자(Conditional operator)는 C++ 언어의 유일한 삼항 연산자임.
	// 삼항 연산자는 비교 및 분기가 모두 포함되어 있음.
	// ( )안의 조건이 참이면 왼쪽을 실행, 거짓이면 오른쪽을 실행.
	cout << y << endl;

	return 0;
}
