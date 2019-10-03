/*
6.13강 "포인터와 const"

- 일반 변수에 const를 붙여 일반 상수를 사용할 수 있듯이 포인터에도 const를 사용할 수 있다 (사용법에는 차이가 있다).
- 함수 파라미터로 사용할 때 값 또는 주소를 바꾸지 말라는 의지의 표현으로 사용된다.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// pointer의 기본 용법.
	int value = 5;
	int *ptr = &value; // value의 주소를 ptr에 넣어주었다.
	*ptr = 6; // 그리고 de-referencing을 해서 value 값을 바꿔줄 수도 있다.

	cout << *ptr << endl;  // A. 
	cout << value << endl; // A.

/**************** Topic 2 ****************/
	// 모두 const를 붙이는 경우.
	const int value_1 = 5;
	const int *ptr_1 = &value_1; 
	// *ptr_c = 6; // 그러나 de-referencing으로 value의 값을 할당해줄 수는 없다.
	// 그렇지만 value의 값을 못 바꾼다고해서 주소를 못 가져오는 것은 아니다.

	cout << *ptr_1 << endl; // A.

/**************** Topic 3 ****************/
	// 포인터에만 const를 붙이는 경우.
	int value_2 = 5;
	const int *ptr_2 = &value_2; 
	// *ptr_c = 6; // de-referencing으로 value의 값을 할당해줄 수는 없지만
	value_2 = 6;   // value_2를 6으로는 바꿀 수 있다.

	// 바뀐 value_2의 값을 가져오기 때문에 *ptr_2도 6이 출력된다.
	cout << value_2 << endl; // A. 
	cout << *ptr_2 << endl;  // A. 

/**************** Topic 4 ****************/
	int value1 = 5;
	const int *ptr1 = &value1; /* 내가 가리키고 있는 주소에 들어 있는 값을 바꾸지 않겠다는 의지의 표시이지,
							       ptr1에 저장되는 주소값을 바꾸지 않겠다는 의미는 아니다. */
	// *ptr1 = 7;

	int value2 = 6;
	ptr1 = &value2; // &value1으로 선언한 포인터에 다른 주소값(&value2)을 넣는 것은 된다.
	// *ptr1 = 8;   // 그렇다고 또 역참조(de-referencing)로 값을 바꾸는 것은 안된다.

/**************** Topic 5 ****************/
	// ptr에 저장되는 주소값을 바꾸지 않겠다는 진정한 의미의 const 사용: int *const
	int value3 = 5;
	int *const ptr3 = &value3;

	*ptr3 = 10; // 위의 예제들과 다르게 de-referencing이 가능하다.
	cout << *ptr3 << endl; // 10 출력.

	int value4 = 8;
	// ptr3 = &value4; // 그러나 ptr3에 저장된 주소를 바꿀 수는 없다.

/**************** Topic 6 ****************/
	// const int *const의 경우 de-referencing과 다른 주소 값 넣어주기 모두 안된다.
	int value5 = 5;
	const int *const ptr5 = &value5; // const로 선언하였기 때문에 초기화가 없으면 오류 발생.

	return 0;
}