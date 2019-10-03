/*
1.7강 "지역 범위(Local Scope)"
*/
#include <iostream>

using namespace std;

int main()
{
	int x(0); // or int x = 0; x라는 메모리가 잡히고 0이라는 값으로 초기화된다.
//  int x = 1; 에러 발생. 'x': redefinition; multiple initialization.
	cout << x << " " << &x << endl; // &는 메모리의 주소 출력.

	{
		int x = 0; // 값은 같으나 다른 메모리에 대한 식별자. 101호와 102호에 동일한 짐이 들어와 있는 것과 같다.
		cout << x << " " << &x << endl;
		// Local Scope({})를 나오는 순간 위의 x를 쓸 수 없음.
	}

	{
		int x = 1; 
		cout << x << " " << &x << endl;
	}

	cout << x << " " << &x << endl;

	{
		x = 1; // 새로운 x를 선언하지 않고 x에 값만 할당한 경우.
		// 이 경우에는 그대로 같은 메모리(주소)에 값이 유지됨.
	}

	cout << x << " " << &x << endl;

	return 0;
} //닫힌 중괄호를 넘어서면 x는 사라진다. = 지역 범위(Local Scope)


// Quiz의 결론: 함수에서 선언된 메모리와 값은 그 안에서만 유효함.
/*
void doSomething(int x)
{
	x = 123;
	cout << x << " " << &x << endl; // #2
	// 범답: 주소는 A, 값은 123. (오답)
	// 정답: 주소는 B, 값은 123.
}

int main()
{
	int x = 0;

	cout << x << " " << &x << endl; // #1
	// 범답: 주소는 A, 값은 0. (정답)
	// 정답: 주소는 A, 값은 0.
	doSomething(x);

	cout << x << " " << &x << endl; // #3
	// 범답: 주소는 A, 값은 123. (오답)
	// 정답: 주소는 A, 값은 0.

	return 0;
}
*/
