/*
Chapter 4. 변수 범위와 더 다양한 변수형
4.1강 "지역 변수의 범위(Scope)와 지속기간(Duration)" - 블록(복합문), 명칭 공간, 이름 충돌, 이름 숨기기

- 지속기간 = 메모리의 지속기간.
            변수를 선언하면 OS에게 메모리를 요청하여 사용하며, 더 이상 사용할 수 없는 곳으로 넘어가면 메모리를 반납하고 사라진다.
 -> 때문에 범위와 지속기간이 함께간다. (동적 할당의 개념에서는 범위와 지속기간이 분리됨.)
*/

#include <iostream>

// namespace 사용(1): 동일한 내용이어도 namespace를 사용함으로써 확실히 다름을 표현할 수 있다.
namespace work1
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}
namespace work2
{
	int a = 1;
	void doSomething() // void doSomething(int b), 함수의 이름은 똑같으나 파라미터가 다르면 충돌이 일어나지 않는다.
	{
		a += 5;
	}
}

// namespace 사용(2): 겹겹이 쌓인 namespace를 깔끔하도록 코딩 (C++ 17버전부터 적용).
namespace work3
{
	namespace work33 
	{
		namespace work333
		{
			int a = 1;
			void doSomething()
			{
				a += 3;
			}
		}
	}
}
// =
namespace work4::work44::work444
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

int main()
{
	using namespace std;
/********* Topic 1 *********/
	// apple = 1; // (1-1) 선언 오류 발생.
	int apple = 5; // 선언된 시점부터 apple 변수를 사용할 수 있다. 메모리 공간을 OS로부터 할당받는다.
	cout << apple << endl;

	{ // 중괄호를 블록(block)이라고 칭한다.
		apple = 1;
		cout << apple << endl;
	}

	cout << apple << endl;

	{
		int apple = 3; 
		cout << apple << endl;
	} // 위의 int apple은 이름은 같지만 블록 밖에서는 사라진다. (= 지속기간이 끝남)

	cout << apple << endl;
	cout << endl;

/********* Topic 2 *********/
	/* 
	:: = 영역 또는 범위 지정 연산자(scope resolution operator).
	C++에서 가장 우선순위가 높은 연산자로써, 여러 범위에서 사용된 식별자(identifier)를 식별하고 구분하는데 사용.*/
	
	work1::a;
	work1::doSomething();

	work2::a;
	work2::doSomething();

	work4::work44::work444::doSomething();

	return 0;
}

// apple = 3; // (1-2) apple이 선언된 중괄호를 벗어났기 때문에(=메모리가 반납되었기 때문에) 오류 발생.