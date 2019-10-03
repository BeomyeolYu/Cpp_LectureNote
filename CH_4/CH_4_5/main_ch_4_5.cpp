/*
4.5강 "형변환 Type conversion"
- 암시적 형변환(Implicit type conversion; coersion)
  (1) numeric promotion
  (2) numeric conversion
- 명시적 형변환(Explicit type conversion; casting)
*/

#include <iostream>
#include <typeinfo>
#include <iomanip>

using namespace std;

int main()
{
/********* Topic 1 *********/
	// auto의 사용 및 잦은 형변환을 수행하는 경우 수시로 type을 확인해야 하는 경우.
	cout << typeid(4.0).name() << endl; // 괄호 사이에 들어있는 값의 type을 출력해 준다.

	int a = 123;
	cout << typeid(a).name() << endl;


	/********* Topic 2 *********/
		// 암시적 형변환(Implicit type conversion; coersion)
	int b = 123.0;
	/* 123.0은 double이지만 b는 int로 선언되었기 때문에 메모리 공간이 다르다.
	   이 경우 컴파일러는 내부적으로 int로 바꾸어 초기화를 진행한다. */


/********* Topic 3 *********/
	// numeric promotion(승진)
	float c = 1.0f;
	double d = c; // 작은 집에 사는 c를 넓은 d에서 사용하기 때문에 정밀도가 떨어질 위험은 없음으로 문제 될 것이 없다. =

	// <-> numeric conversion
	int n = 30000;
	char m = n; // m은 n을 담을 수 없어 큰 문제가 발생할 수 있다.
	cout << static_cast<int>(m) << endl; // char 타입이 표현할 수 있는 최대인 127도 아니고 엉뚱한 48이 출력된다.

	float f = 3.14;
	int i = f;
	cout << std::setprecision(12) << i << endl; // 3이 출력된다; 암시적 형변환을 할 때는 소수점 이하를 버리고 int에 넣어준다.


/********* Topic 4 *********/
	/* unsigned 형변환의 경우 예상치 못한 문제가 발생할 수 있다.
	   "5 - 10 = -5"를 수행하고 싶었는데 실수를 범하는 경우;
	   5u는 unsigned라는 의미이며 5는 signed이므로 5와 5u는 같다.
	*/
	cout << 5 - 10 << endl;	  // -5 출력.
	cout << 5u << endl;       // 5 출력.
	cout << -5u << endl;	  // 4294967291 출력.
	cout << 5u - 10 << endl;  // 4294967291 출력.
	cout << 5u - 10u << endl; // 4294967291 출력.
	/* 5u는 int로 형변환 되었다면 원하는 -5의 결과를 얻었을 테지만 형변환 또한 우선순위가 있다.
	   int가 가장 낮고, unsigned int -> long -> unsigned long
	   long long -> unsigned long long -> float -> double -> long double이 가장 높다.
	   즉, unsigned int가 int보다 우선순위가 높아 암시적 형변환을 할 수 없다. */


/********* Topic 5 *********/
	// 명시적 형변환(Explicit type conversion; casting)
	int x = int(4.0);			   // C++ style casting
	int y = (int)4.0;			   // C style casting
	int z = static_cast<int>(4.0); // 최근 추세
	// 기능상 차이는 없다.

	return 0;
}