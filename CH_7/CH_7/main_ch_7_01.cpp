/*
7.1강 "매개변수(Parameter)와 실인자(Argument)의 구분"

- 큰 프로그램을 만들 때 함수를 잘 사용하는 것이 중요하다.
- Parameter와 Argument를 정확히 이해해야 한다.
*/

#include <iostream>
using namespace std;

// int foo = 리턴 타입은 int라는 뜻
int foo(int x, int y); // int 타입형 변수 x와 int 타입형 변수 y는 foo라는 함수의 Parameter라는 뜻.

int foo(int x, int y)
{
	return x + y;
} // x and y are destroyed here. <-- 메모리 반납 (= 지역 변수).

int main()
{
	int x = 1, y = 2;

	foo(6, 7);	   // 6, 7: arguments (actual parameters)
	foo(x, y + 1); // 1, 3: arguments

	return 0;
}