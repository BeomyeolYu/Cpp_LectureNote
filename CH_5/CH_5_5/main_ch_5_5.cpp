/*
5.5강 "반복문 while"
*/

#include <iostream>

using namespace std;

int main()
{
/**************** Topic 1 ****************/
	cout << "While-loop test" << endl;
	int count = 0; // 카운터를 정의.

	while (true)   // 괄호 안의 조건이 true라면 작동, false라면 작동한다. 서버처럼 무한히 돌려야 할 때는 true 또는 1을 대입한다.
	{
		cout << count << endl; // cout << ++count << endl; = cout << count++ << endl;
		++count; // = count++

		if (count == 10) break; // 무한 루프 탈출.
	}
	// =
	while (count < 10) // 조건 지정.
	{
		cout << count << endl;
		++count; 
	}


/**************** Topic 2 ****************/
	// 주의 사항! count가 unsigned int인 경우. 
	unsigned int count_ = 10;

	while (count_ >= 0)
	{
		if (count_ == 0)
		{
			cout << "Zero";
		}
		else
		{
			cout << count_ << " ";
		}
		count_--; // Zero 이하로 overflow 문제가 발생한다. 음수가 되면서 -1에 4294967295가 출력.
	}
	/* 
	int를 쓰면 많은 문제를 방지할 수 있는 것은 사실이나 unsigned int를 사용하지 말라는 것은 아니다.
	-> 최적화를 하게 되면 프로그래밍 언어의 퍼포먼스를 쥐어짜게 된다.
	-> 자바나 파이썬은 쉽지만 연산의 한계가 있다 = c 계열 언어가 살아있는 이유.
	-> 또한 unsigned int가 signed int보다 빠르며, 벡터의 경우 unsigned int로 선언한다.
	*/


/**************** Topic 3 ****************/
	// n 번에 한 번씩 report를 하는 trick. NN code에서 주로 쓰인다.
	count = 1;

	while (count < 100)
	{
		if (count % 5 == 0)
			cout << "Hello " << count << endl;
		++count;
	}


	return 0;
}