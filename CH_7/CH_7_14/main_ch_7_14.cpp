/*
7.14강 "단언하기(assert)"

- 디버깅을 할 때 assert를 통해서 runtime에 컴파일러의 도움을 받을 수 있다.
- Release 모드에서는 작동을 안 한다. (Property -> C/C++ -> Perprocessor -> Perprocessor Definitions에서 변경 가능)
  --> 프로그램이 가급적 빠르게 돌아야 하는 Release 모드에서는 assert 실행을 생략한다.
*/

#include <iostream>
#include <cassert> // assert.h
#include <array>
using namespace std;

// 예를 들어 printValue라는 API를 만들었다 (다른 프로그래머들은 내용을 모르고 사용한다).
void printValue(const std::array<int, 5> &my_array, const int &ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1);

	cout << my_array[ix] << endl;
}

int main()
{
/**************** Topic 1 ****************/
	// () 안에 필요한 조건을 넣으면 된다. --> runtime에 체크한다.
	assert(false); 

/**************** Topic 2 ****************/
	int number = 5;

	// ...

	assert(number == 5); /* 중간 과정이 어떠하던지 내 프로그램은 number가 5여야 정상 작동 한 것이다.
						    --> runtime에 체크한다. */

/**************** Topic 3 ****************/
	std::array<int, 5> my_array{ 1, 2, 3, 4, 5 };

	printValue(my_array, 100); // 100을 사용하려는 사용자가 있을 수 있다.
	// assert을 걸어주면 runtime 에러가 발생하긴 하지만 어디서 잘못되었는지 알 수 있다 --> runtime에 체크한다.

/**************** Topic 4 ****************/
	// compile time에 오류를 발생시키는 static assert
	/* compile time에서 x의 값이 바뀔 수도 있는 조건은 사용 불가능하다.
	   int x = 5;
	   x = 10;
	   static_assert(x = 5); 
	   
	--> const int x = 5인 경우에는 사용 가능하다. */
	const int x = 5;
	static_assert(x == 5, "x should be 5"); // 기록이 가능하다.

	return 0;
}