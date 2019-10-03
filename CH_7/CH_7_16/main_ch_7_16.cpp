/*
7.16강 "생략부호(Ellipsis)"

- 발음이 '일립시스'에 가깝다 --> 발음 기호 확인.
- '함수의 parameter의 개수가 정해져 있지 않았으면 좋겠다' 싶을 때 활용 가능.
- 사용하기 위험하고 디버깅이 어려워 초보자에겐 사용을 권장하지 않는다.
*/

#include <iostream>
#include <cstdarg> // for ellipsis
using namespace std;

// count 개수만큼의 argument를 평균 내주는 함수.
double findAverage(int count, ...) // type을 알려주는 parameter 하나와 ...
{
	double sum = 0;

	va_list list; // 마우스를 얹으면 char로 받는 것을 확인할 수 있다.

	va_start(list, count); // count: 함수로 들어오는 argument가 몇 개인지 알려줘야 한다.
	
	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int); // int로 변환을 해준다.

	va_end(list); // 끝났다.

	return sum / count;
}

int main()
{
/**************** Topic 1 ****************/
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl; // 첫 번째 parameter의 개수이다.
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl; /* 실제로 넣어준 건 5개인데 10을 argument로 넣어주었다.
													--> -8.26776e+07가 출력되는 오류가 발생한다. 
													--> 개수를 맞춰줘야 하는 위험성이 존재한다. */

	return 0;
}