/*
3.3강 "증감 연산자(increment decrement operators)"

- 많이 쓰이고 쉽지만 실수로 인한 심각한 오류를 범하기 쉽다.
*/

#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
/********* Topic 1 *********/
	int x = 5;
	int y = ++x;
	cout << y << endl; // 5 + 1 = 6

	int n = --x;
	int m = x--;
	cout << n << endl;
	cout << m << endl; // --는 앞과 뒤에 모두 붙일 수 있음.


/********* Topic 2 *********/
	int b = 6, d = 6;
	/* cout << b << " " << d << endl;	  // 6과 6이 출력.
	   cout << ++b << " " << --d << endl; // 7과 5가 출력.
	*/

	cout << b++ << " " << d-- << endl; // 6과 6이 출력
	cout << b << " " << d << endl;     // (1) 7과 5가 출력
	/* 앞에 ++가 붙은 경우에는 b에는 먼저 1을 더한 다음에 출력함.
	그러나 뒤에 붙은 경우에는 b를 먼저 cout에 보낸 다음에 1이 더해짐.
	그러므로 (1)에서 b에는 7과 5가 출력됨.
	*/
	cout << ++b << " " << --d << endl; // 8과 4이 출력.


/********* Topic 3 *********/
	int w = 1;
	int v = add(w, ++w);
	cout << v << endl; // do not use this form. w가 서로 영향을 주어 3이 아닌 4가 출력됨.

	int a = 1, c = 1;
	int l = add(a, ++c);
	cout << l << endl; // a와 c는 서로 영향을 주지 않기 때문에 정상적으로 4가 아닌 3이 출력됨.

	return 0;
}