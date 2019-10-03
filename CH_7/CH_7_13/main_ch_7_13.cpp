/*
7.13강 "방어적 프로그래밍의 개념(Defensive Programming)"

- 많은 사람이 사용하는 소프트웨어를 만들 때, 사용자가 어떻게 사용을 하던지 정상적으로 작동하도록 프로그래밍 하는 것.
- 실패의 경험을 통해 성장하는 영역이다. 막혔을 때 답을 거저먹길 구하기보다는 끝까지 물고 늘어지자.
- 컴파일러의 도움을 받을 수 있도록 프로그래밍 하는 습관을 기르자.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// syntax errors(문법 오류): 컴파일러가 상당수 잡아준다.
	// int x <-- // ;을 붙이지 못한 경우.

/**************** Topic 2 ****************/
	// semantic errors(문맥/의미/논리적 오류): 컴파일러가 잡아주기 어려우므로 프로그래머가 꼼꼼히 점검해야 한다.
	int y;
	cin >> y;

	if (y >= 5) // x >= 5에서 실행되는 if 문을 짰지만,
		cout << "x is greater than 5 " << endl; // "5 보다 크다"라고 출력하게 되어있다.
	// --> 논리적인 오류가 발생한다.

/**************** Topic 3 ****************/
	// violated assumptions(가정 위반 오류): 사용자가 의도한 바와 다른 방식으로 프로그램을 사용한다
	string hello = "Hello, my name is Jack jack";
	
	cout << "Input from 0 to " << hello.size() - 1 << endl; // (1) 경고문

	while (true) // (2) 방어적 프로그래밍
	{
		int ix;
		cin >> ix;

		if (ix >= 0 && ix <= hello.size() - 1)
		{
			cout << hello[ix] << endl; // [28] 이상을 cin 하면 runtime 에러가 발생한다.
			break;
		}
		else
			cout << "Please try again" << endl;
	}

	return 0;
}