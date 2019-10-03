/*
5.강 "조건문 if"
*/

#include <iostream>
using namespace std;

// 함수에도 if 문을 활용할 수 있다.
int min(int x, int y)
{
	return (x > y) ? y : x;
	/* =
	if (x > y)	
		return y
	else		
		return x
	*/
}

int main()
{
/**************** Topic 1 ****************/
	int x, y;
	cin >> x >> y; // x와 y를 하나씩 입력하는 구조이다.

	if (x > 10) // bool type이 들어간다. --> True or False
	{
		cout << x << " is greater than 10" << endl;
		cout << "It's a if loop" << endl;
	}
	else
		cout << x << " is not greater than 10" << endl; // 한 줄이면 중괄호를 생략하기도 한다.
		cout << "It's not a if loop" << endl; // = if 문과 별개의 문장이다 --> 두 줄 이상이라면 무조건 중괄호로 쌓아야 한다.


/**************** Topic 2 ****************/
	if (1) // bool 계산을 할 때 0(false)이 아니면 true다 = 항상 실행되는 if 문.
		int x = 5;	// int x = 5가 전역으로 지속되는 것이 아니라 블록 안에서만 유지됨에 유의해야 한다.
	else
		int x = 6;  // 그렇다고 if 문 안에서 변수를 대입하지 말라는 뜻은 아니다.
	cout << x << endl; // 즉 x = 5가 아닌 1이 출력된다.


/**************** Topic 3 ****************/
	// Chaining if statements
	if (x > 10)
		cout << x << " is greater than 10" << endl;
	else
	{
		if (x < 10)
			cout << x << " is not greater than 10" << endl;
		else // if (x == 10)
			cout << x << " is exactly 10" << endl;
	}
	// 문법상의 얼마든지 가능하지만 논리 구조가 복잡해지는 것은 지양하는 것이 좋다.


/**************** Topic 4 ****************/
	// 가능하면 중괄호로 명확하게 영역을 표시하는 것이 좋다.
	if (x >= 10)
		if (x >= 20)
			cout << "A" << endl;
	else  // < -- - else는 들여쓰기 위치와 상관없이 가장 가까운 if에 붙으므로 주의.
		cout << "B" << endl;


/**************** Topic 5 ****************/
	// 프로그램을 긴급하게 중단하고 싶을 때
	if (x > 10)
		cout << "A" << endl;
	else if (x == -1)
		return 0; // <--
	else if  (x < 0)
		cout << "B" << endl;

	cout << "Hello" << endl;


/**************** Topic 6 ****************/
	// null statement
	if (x > 10); // ;가 숨어있다면 x와 상관없이 무조건 실행된다.
	{
		cout << "null statement" << endl;
	}


/**************** Topic 7 ****************/
	if (x = 0) // => x = 0 then, if (x)
		cout << "false" << endl; // x = 0, 즉 false이므로 실행되지 않는다.
	cout << x << endl; // x에 0이 대입되어 0이 출력된다.

	if (x = 3) // x == 3이 아니라 x에 3이 대입된다. 이 경우 전역으로 지속되는 듯.
		int x = 2; // if 문 안에서 대입하는 것은 블록 안에서만 지속됨.
	cout << x << endl; // 2가 아니라 x에 3이 대입되어 3이 출력된다.

	
	return 0;
}