/*
5.1강 "제어 흐름 개요(Control flow)"

- 프로그래밍이란 것은 CPU에게 할 일을 지정해 주는 것이다.
*/

/*
1. 중단(Halt)
2. 점프(Jump): goto, break, continue
3. 조건 분기(Conditional branches): if, switch
4. 반복(Loops): while, do while, for
5. 예외 처리(Exceptions): try, catch, throw
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// 중단(Halt)
	cout << "I love you" << endl;

	exit(0); /* 중단(1): 긴급하게 끝낸다. 
						1) 하드웨어 관련된 코드 같은 경우에 무조건 끝내야하는 경우. 
						2) 디버깅하는 경우. */

	return 0; // 중단(2): 같은 의미로 return 이후의 코드도 주석으로 바라볼 수 있다.
	cout << "I love you" << endl;
}