/*
7.12강 "재귀적 함수 호출(Recursive Function Call)"

- 자신하고 이름이 똑같은 함수를 호출하는 것.
- Recursive로 인한 stack overflow가 두렵다면 std::vector를 stack처럼 사용할 수 있다.
- 성능이 중요한 코드에서는 Recursive 사용을 조심하는 것이 좋다.
*/

#include <iostream>
using namespace std;

/**************** Topic 1 ****************/
void countDown(int count)
{
	cout << count << endl;

	if (count > 0) // Recursive을 사용할 때는 종료 조건을 반드시 설정해주어야 하며 과도한 횟수를 반복하는 경우 stack overflow가 발생한다.
		countDown(count - 1); // Recursive: 같은 코드를 따로따로 실행시키고 있다고 생각할 수 있다.
	/* 우리가 만든 프로그램은 메모리에 저장이 되어있으며, 함수를 호출할 때는 그 메모리의 주소를 가지고 호출한다.
	   본체인 메모리는 따로 있고 주소에 잠깐잠깐 방문해서 실행시키는 개념.
	   --> 어떤 함수가 메모리에서 CPU로 올라가고, CPU가 함수를 실행하기 위해 주소를 호출한다.
	   --> 즉 CPU는 함수 A를 10번 실행하는 것인지, 함수 A와 B를 실행시키는 것인지를 판단하는 것이 아니라 주소만 본다. */
}

/**************** Topic 2 ****************/
int sumTo(int sumto)
{
	if (sumto <= 0)
		return 0;
	else if (sumto <= 1)
		return 1;
	else
	{ 
		const int sum_minus_one = sumTo(sumto - 1);
		return  sum_minus_one + sumto;
	}
}

int main()
{
/**************** Topic 1 ****************/
	countDown(5);

/**************** Topic 2 ****************/
	cout << sumTo(10) << endl;

/**************** Topic 3 ****************/
	// HW: 피보나치 수(Fibonacci numbers)

	return 0;
}