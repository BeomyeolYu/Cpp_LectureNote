/*
2.6강 "불리언(Boolean) 자료형과 조건문 if"

- Boolean: 수학자의 이름.
- Boolean 자료형은 조건을 판단할 때 많이 사용됨.
*/

#include <iostream>
using namespace std;

bool isEqual(int a, int b) // bool type을 return type으로 자주 사용함.
{
	bool result = (a == b);

	return result;
}

int main()
{
	// Boolean 자료형도 initialization과 assignment가 가능함.
	bool b1 = true;  // copy initialization
	bool b2(false);  // direct initialization
	bool b3{ true }; // uniform initialization
	b3 = false;		 // assignment

	cout << b3 << endl; // 0 출력.
	cout << b1 << endl; // 1 출력.

	cout << std::boolalpha; // 0과 1을 false과 true 문자로 출력.
	cout << b3 << endl; // false 출력.
	cout << b1 << endl; // true 출력.

	cout << std::noboolalpha; // 다시 0과 1로 출력.
	cout << b3 << endl; // 0 출력.
	cout << b1 << endl; // 1 출력.

	// !는 not 연산자.
	cout << !true << endl;  // 0 출력.
	cout << !false << endl; // 1 출력.
	cout << !b3 << endl;    // 1 출력.
	cout << !b1 << endl;    // 0 출력.


	/******* Next topic *******/
	// AND(&&) 연산자. 모두 true 면 1 출력.
	cout << (true && true) << endl;   // 1 출력.
	cout << (true && false) << endl;  // 0 출력.
	cout << (false && true) << endl;  // 0 출력.
	cout << (false && false) << endl; // 0 출력.
	// OR(||) 연산자. 하나라도 true 면 1 출력. 
	cout << (true || true) << endl;   // 1 출력.
	cout << (true || false) << endl;  // 1 출력.
	cout << (false || true) << endl;  // 1 출력.
	cout << (false || false) << endl; // 0 출력.


	/******* Next topic *******/
	if (true) // = if (3 > 1)
		cout << "This is true" << endl;
	else
	{ // 2줄 이상에서는 중괄호로 묶어줘야함.
		cout << "This is false" << endl;
		cout << "This is second line" << endl;
	}
	
	if (5) // = if (true).
	// True가 출력됨. 왜냐하면 0이면 False이고 나머지는 다 True다 <-> if (0).
		cout << "True" << endl;
	else
		cout << "False" << endl;


	/******* Next topic *******/
	cout << isEqual(1, 1) << endl; // 1 출력.
	cout << isEqual(0, 3) << endl; // 0 출력.


	/******* Next topic *******/
	bool b;
	cin >> b;
	cout << std::boolalpha;
	cout << "Your input : " << b << endl;

	return 0;
}