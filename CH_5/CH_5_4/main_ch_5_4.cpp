/*
5.4강 "goto 문"

- CPU가 작업을 수행하던 중에 goto 문을 만나면 지정된 위치로 이동한다.
- 반복문의 조상격이지만 최근엔 '스파게티 코드'가 될 수 있어서 잘 사용되지 않는다.
*/

#include <iostream>
#include <cmath> // sqrt()

using namespace std;

int main()
{
/**************** Topic 1 ****************/
	double x;

tryAgain : // label

	cout << "Enter a non-negative number" << endl;
	cin >> x;

	if (x < 0.0)		// x가 0보다 작으면 sqrt 계산에 문제가 생기므로 goto 문으로 방지한다.
		goto tryAgain;	// goto를 만나면 label로 이동하라.

	cout << sqrt(x) << endl;


/**************** Topic 2 ****************/
	// 논리 순서가 반대이기 때문에 y가 정의되지 않아 오류가 발생.
	goto skip;

	int y = 5;

skip :

	y += 3;

	return 0;
}