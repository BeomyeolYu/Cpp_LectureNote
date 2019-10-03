/*
3.6강 "논리 연산자(logical operators)"
*/

#include <iostream>
using namespace std;

int main()
{
/********* Topic 1 *********/
	// logical NOT: !x
	bool x = true;
	cout << "!x is " << !x << endl; // 0 출력.

	// logical AND: &&
	bool y = false;
	//cout << x && y << endl; 괄호로 연산 우선순위를 정해주지 않으면 endl에서 에러 발생.
	cout << "x && y is " << (x && y) << endl; // 0 출력.

	// logical OR: ||
	cout << "x || y is " << (x || y) << endl; // 1 출력.


/********* Topic 2 *********/
	// 게임 캐릭터가 총알을 맞았을 때,
	bool hit = true;
	int health = 10;

	if (hit == true && health < 20) // 2개의 if 문으로 나누는 것보다 논리연산자를 사용하는 것을 권장함.
	// = if (hit && health < 20) 
	{
		cout << "die " << endl;
	}
	else
		health -= 20;


/********* Topic 3 *********/
	// 0(false)을 제외하고 모두 true임.
	int n = 5;
	int m = 7;
	cout << !n << " " << m << endl;

	// Case 1: 5와 7을 다른 값임에도 5와 7이 ture bool로 형 변환이 되면서 
	// " n equals m "이 출력되니 의도가 잘못 전달될 수 있다.
	if (!n == m)
	{
		cout << " Case 1: n does not equal m (correct) " << endl;
	}
	else
		cout << " Case 1: n equals m (incorrect) " << endl;
	
	// Case 2: 정답 1 (괄호의 중요성).
	if (!(n == m)) 
	{
		cout << " Case 2: n does not equal m (correct) " << endl;
	}
	else
		cout << " Case 2: n equals m (incorrect) " << endl;

	// Case 3: 정답 2 (연산자의 중요성).
	if (n != m)
	{
		cout << " Case 3: n does not equal m (correct) " << endl;
	}
	else
		cout << " Case 3: n equals m (incorrect) " << endl;


/********* Topic 4 *********/
	int v = 1;

	if (v == 0 || v == 1)
		cout << "v is 0 or 1" << endl;


/********* Topic 5 *********/
	/* 실용적인 면에서 중요한 short-circuit evaluation.
	논리연산을 할 때에 앞 연산자의 결과에 따라 뒤 연산자의 실행 여부가 결정되는 계산 방식을 뜻함.
	앞의 연산을 통해 뒤의 연산의 실행가능성을 보장하고 런타임 에러와 같은 상황을 방지할 수 있음.
	가벼운 연산을 앞에 두고 비싼 연산을 뒤로 배치하여 전체적인 연산 횟수를 줄일 수 있음. (최적화)
	*/

	int i = 1;
	int j = 2;

	if (i == 1 && j++ == 2)
	{
		// do something
	}

	cout << j << endl;


/********* Topic 6 *********/
	bool a = true;
	bool b = false;

	// De Morgan's Law
	!(a && b); // -(1)
	!a && !b;  // -(2)
	// (1)과 (2)는 같지 않음. = 분배 법칙이 성립하지 않음.
	!a || !b;  // -(3)
	// (1)과 (3)이 같음.

    // XOR operator
	/*false, false = false
	  false, true = true
	  true, flase = true
      true, true = false*/
	cout << " XOR operator: " << (a != b) << endl;


/********* Topic 7 *********/
	bool v1 = true;
	bool v2 = false;
	bool v3 = false;

	bool r1 = v1 || v2 && v2;
	bool r2 = (v1 || v2) && v3;
	cout << " r1 is " << r1 << endl; // -[1], 1 출력.
	cout << " r2 is " << r2 << endl; // -[2], 0 출력.
	// [1]과 [2]가 동일한 연산인 것 같지만 ||는 우선순위가 14이고 &&는 우선순위가 13임.
	bool r3 = v1 || (v2 && v2); // [1]과 같음.
	cout << " r3 is " << r3 << endl; // 연산자 사이에는 괄호를 해주는 것이 좋음.


	return 0;
}