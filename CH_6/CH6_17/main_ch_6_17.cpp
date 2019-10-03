/*
6.17강 "C++11 For-each 반복문" - C++ 11

- array를 for 문으로 돌릴 때 간편하게 구현할 수 있는 방법.
*/

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 12, 21, 34, 55, 89 };
	
	// for (int i = 0; i < ...; i++) // for 문의 iter 횟수를 알기 쉽지 않았다.
	// ...

/**************** Topic 2 ****************/
	// output: number에는 fibonacci에 있는 원소들이 한 번씩 들어온다.
	// int를 auto로도 많이 사용한다.
	for (const int number : fibonacci) // = for (auto number : fibonacci)
		cout << number << " ";
	cout << endl;

/**************** Topic 3 ****************/
	// change array value --> ref로 만들어야 함.
	for (int &number : fibonacci) // = for (auto &number : fibonacci)
		number *= 10;
	for (const int number : fibonacci) // = for (const auto number : fibonacci)
		cout << number << " ";
	cout << endl;

/**************** Topic 4 ****************/
	// array에서 Max 값 찾기. 
	int max_number = numeric_limits<int>::lowest(); // int형이 가질 수 있는 최소값.
	// lowest는 주어진 타입(int)의 가장 낮은 숫자를 return 해준다.

	for (const auto &n : fibonacci)
		max_number = max(max_number, n); // 비교 연산으로 큰 값 반환
	cout << max_number << endl;

/**************** Topic 5 ****************/
	/* array를 동적 할당하면 For-each를 사용할 수 없다.
	   대신에 vector 사용; vector는 동적 할당을 아주 쉽게 사용할 수 있도록 std::에 들어있다.
	   동적 할당 배열 대신에 vector를 사용할 수 있다. */

	vector<int> fibonacci_ = { 0, 1, 1, 2, 3, 5, 8, 12, 21, 34, 55, 89 };

	return 0;
}