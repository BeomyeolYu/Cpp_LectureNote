/*
12.강 ""

-
*/

#include <iostream>
using namespace std;

int main()
{
	/**************** Topic 1 ****************/


	/**************** Topic 2 ****************/


	/**************** Topic 3 ****************/


	/**************** Topic 4 ****************/


	/**************** Topic 5 ****************/
	return 0;
}

//------------------------------------------------------------------------------------------------------------------
//void doSomething(int& x) // ref를 함수의 입력으로 사용.
//{
//	cout << x << endl;
//}

//void doSomething_const(const int& x) // const ref를 입력으로 사용.
//{
//	cout << x << endl;
//}
//	// 특히 함수의 파라미터로 사용할 때 편리하다.
//	int a = 1;

//doSomething(a);
//doSomething(1); // const가 아니면 변수만 입력받을 수 있다.

//doSomething_const(a);
//doSomething_const(1);
//doSomething_const(a + 3);
//doSomething_const(3 * 4); // const를 붙이면 literal을 직접 입력 가능.
//------------------------------------------------------------------------------------------------------------------
/// 포인터 변수를 ref로 받는 방법.
/// void voo(int *&ptr) = void voo((int*) &ptr)
//typedef int* pint;
//void voo(pint &ptr)
//{
//	cout << ptr << " " << &ptr << endl;
//}
//
//// 포인터에 대한 ref를 보낼 수 있다.
//int y = 5;
//int *ptr = &y; // == pint ptr = &y;
//
//cout << &y << " " << ptr << " " << &ptr << endl;
//voo(ptr);
//------------------------------------------------------------------------------------------------------------------