/*
7.2강 "값에 의한 전달(Passing Arguments by Value)" - Call by Value
*/

#include <iostream>

using namespace std;

void doSomething(int y)
{
	cout << "In func " << y << " " << &y << endl;
}

int main()
{
/**************** Topic 1 ****************/
	doSomething(5); // 함수를 '호출'하면 literal 값 하나(5)가 int y로 복사된다.
	/* 내부적인 절차: 
	   doSomething이라는 함수를 호출하려면 parameter인 y라는 값이 전달되어야 한다.
	   --> doSomething이 실행되면서 내부적으로 int y가 선언된다.
	   --> y 변수의 메모리에 5라는 값이 복사가 되어 초기화가 된다. */

/**************** Topic 2 ****************/
	// 혼란스러운 경우: 변수를 사용하는 경우. 
	int x = 6;
	cout << "In main " << x << " " << &x << endl; // &y와 &x가 다르다.

	doSomething(x); /* 즉, 실제로 전달되는 것은 x라는 변수가 아니고 x라는 변수에 들어있는 value만 전달된다.
					   --> 6이라는 값이 argument로써 doSomething의 parameter로 전달된다. */
	doSomething(x + 1); // 7이라는 value가 argument로써 사용된다.

/**************** Topic 3 ****************/
	// 장점: 일반적으로 함수는 parameter가 외부에 영향을 미치지 않는다.
	// 단점: 장점이 곧 단점. 외부에 영향을 미치고 싶을 때가 있다. --> 참조/주소에 의한 전달로 보완.

	return 0;
}