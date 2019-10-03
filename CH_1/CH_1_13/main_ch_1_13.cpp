/*
1.13강 "네임스페이스 (Namespace, 명칭 공간)"
- 코드 정리에도 유용하지만 객체 지향 프로그래밍 할 때 유용하게 쓰이는 개념.
- 예를 들어, "기능은 다르나 똑같은 명칭의 함수를 만들고 싶거나, 함수의 이름을 바꾸면 되지만 이름을 유지하고 싶을 때"가 있다.
- 이때 Namespace를 사용.
*/

#include <iostream> // iostream의 cin, cout 등은 std라는 네임스페이스에 포함되어 있음.(_STD_BEGIN)
using namespace std;

namespace Myspace1
{
	namespace InnerSpace // namespace 안에 namespace를 선언할 수도 있음.
	{
		int my_fuction()
		{
			return 0;
		}
	}
	int doSomething(int a, int b)
	{
		return a + b;
	}
}

int doSomething(int a, int b)
{
	return a * b;
}

int main()
{
	/*
	Myspace1::doSomething(3, 4)
	=
	using namespace Myspace1;
	doSomething(3, 4);								// 3. 이 경우에 namespace안에 있는 doSomething을 가져옴.
	*/

	/*
	Myspace1::InnerSpace::my_fuction();
	=
	using namespace Myspace1::InnerSpace;
	my_fuction();
	*/

	cout << doSomething(3, 4) << endl;				// 1. 이 경우에는 3 * 4 = 12가 출력 됨.
	cout << Myspace1::doSomething(3, 4) << endl;	// 2. "Myspace1" 네임스페이스 안에 있는 doSomething이 실행됨.

	return 0;
}
