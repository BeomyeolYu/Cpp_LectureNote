/*
4.3강 "Using 문과 모호성(Ambiguity)"

- 동일한 이름이 다수 겹칠 때 컴파일러가 불만을 토로하는 것이 Ambiguity.
- 가급적 name space는namespace는 전역에서 사용하지 않는 것이 문제를 방지할 수 있다.
- 변수와 동일하게 적은 범위에서 영향을 주는 프로그래밍을 하는 것이 객체 지향 프로그래밍에서 좋은 습관이 될 수 있다.
*/

#include <iostream>

// 2개의 namespace에서 이름이 동일한 변수가 정의되었다.
namespace a
{
	int my_var(10);
	int count(123);
}

namespace b
{
	int my_var(20);
}

int main()
{
/********* Topic 1 *********/
	// using namespace std;
	using std::cout;
	using std::endl;

	cout << "Hello " << endl;


/********* Topic 2 *********/
	// 동일한 이름의 변수가 선언된 namespace를 동시에 선언한 경우.
	/*
	using namespace a;
	using namespace b;
	cout << my_var << endl; // ambiguity 오류 발생.
	*/ 

	// 해결 방법 (1): 블록으로 영역을 명확하게 나눠준다.
	{
		using namespace a;
		cout << my_var << endl;
	}
	{
		using namespace b;
		cout << my_var << endl;
	}

	// 해결 방법 (2): 영역 지정 연산자를 활용하여 해결.
	cout << a::my_var << endl;
	cout << b::my_var << endl;

/********* Topic 3 *********/
	cout << count << endl; // namespace std와 namespace a 간의 충돌이 일어남.

	return 0;
}