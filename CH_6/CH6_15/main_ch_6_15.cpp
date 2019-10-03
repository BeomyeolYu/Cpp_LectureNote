/*
6.15강 "참조와 const"

- ref+const는 pointer+const보다 좀 더 편하게 사용할 수 있다.  
*/

#include <iostream>
using namespace std;

void doSomething(int& x) // ref를 함수의 입력으로 사용.
{
	cout << x << endl;
}

void doSomething_const(const int& x) // const ref를 입력으로 사용.
{
	cout << x << endl;
}

int main()
{
/**************** Topic 1 ****************/
	// Case 1: 불가
	const int x1 = 5;
	int &ref_x1 = x1;

	// Case 2: 허용
	const int x2 = 5;
	const int &ref_x2 = x2;

	// Case 3: 허용
	int x3 = 5;
	const int &ref_x3 = x3;
	const int &ref = ref_x3;

/**************** Topic 2 ****************/
	// Case 1: 불가
	int &ref1 = 3 + 4; // ref에는 반드시 주소가 할당되어야 한다.

	// Case 2: 허용
	const int &ref2 = 3 + 4; // 그러나 const를 붙이면 가능하다.
	cout << ref2 << endl;  // A. 
	cout << &ref2 << endl; // A. 

/**************** Topic 3 ****************/
	// 특히 함수의 파라미터로 사용할 때 편리하다.
	int a = 1;
	
	doSomething(a);
	doSomething(1); // const가 아니면 변수만 입력받을 수 있다.

	doSomething_const(a);
	doSomething_const(1);
	doSomething_const(a + 3);
	doSomething_const(3 * 4); // const를 붙이면 literal을 직접 입력 가능.

	return 0;
}