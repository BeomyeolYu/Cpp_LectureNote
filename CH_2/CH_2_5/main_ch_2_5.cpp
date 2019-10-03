/*
2.5강 "부동소수점 수 (Floating Point Numbers)"
*/

/*
- 실수 = real number
  3.145192와 같은 정수보다 정밀한 숫자. 3은 정수로 표현할 수 있으나 0.145192는 1보다 작은 숫자라 더 정밀함.
  컴퓨터가 실수를 어떻게 다루느냐 -> Floating Point Numbers를 사용함.

- 어원: 부동은 한자어지만 바다 위에 둥둥 떠다니는(Float) 부표를 생각하면 됨.
  즉, 점이 떠다닌다 = "0." 이 떠다닌다.

- 사용법 이상으로 주의 사항을 숙지하여야 함.
*/

/*
컴퓨터에서는 실수를 정수와 마찬가지로 2진수로만 표현해야 하기 때문에 실수를 표현하는 방법은 정수에 비해 훨씬 복잡함.

1. 고정 소수점(fixed point) 방식.
실수는 보통 정수부와 소수부로 나눌 수 있음.
따라서 실수를 표현하는 가장 간단한 방식은 소수부의 자릿수를 미리 정하여, 고정된 자릿수의 소수를 표현하는 것임.
그러나, 정수부와 소수부의 자릿수가 크지 않으므로, 표현할 수 있는 범위가 매우 적다는 단점

2. 부동 소수점(floating point) 방식.
실수는 보통 정수부와 소수부로 나누지만, 가수부와 지수부로 나누어 표현할 수도 있음.
이로 인하여 매우 큰 실수까지도 표현할 수 있음.

3. 부동 소수점 방식의 오차
부동 소수점 방식을 사용하면 고정 소수점 방식보다 훨씬 더 많은 범위까지 표현할 수 있음.
하지만, 부동 소수점 방식에 의한 실수의 표현은 항상 오차가 존재한다는 단점을 가지고 있음.
부동 소수점 방식은 공식에 의해 계산되기 때문에 10진수를 정확하게 표현할 수는 없게 되어 오차가 발생함.
따라서, 컴퓨터에서 실수를 표현하는 방법은 정확한 표현이 아닌 언제나 근사치를 표현할 뿐임을 항상 명심해야 함.
*/

/* [image_01 참고]
-----------------------------------------------------------------
| Category(영역)	|   Type(형)	  |   최소 크기  |   전형적인 크기   |
-----------------------------------------------------------------
|   부동소수점   |    float	  |   4 bytes   |	  4 bytes      |
-----------------------------------------------------------------
|               |   double	  |   8 bytes   |	  8 bytes      |
-----------------------------------------------------------------
|				| long double |   8 bytes   | 8,12 or 16 bytes |
-----------------------------------------------------------------
그러나 항상 외우고 다닐 수 없으므로 사이즈를 찍는 방법을 숙지해야 함. (ch2_2와 2_3 참고)
최근에는 컴퓨팅 파워가 좋아져 주로 double을 사용하긴 하지만 2배가 되는 것이 부담이 될 때에는 float를 사용함.
파이썬은 기본적으로 double을 사용하지만 딥러닝 내부를 보면 주로 float로 작성되어 있음. */

/* [image_02 참고]
4 bytes = 32 bits.
내부적으로 메모리 32 bits를 3부분으로 나눔. 부호를 1 bit, 지수를 8 bits, 가수를 나머지.
부호 부분: 0이 +, 1이 -를 표현.
지수 부분: 0000011"1" -> 뒤에부터 2의 0제곱.
가수 부분: "1"1000... -> 앞에부터 2의 -1제곱.
10진수를 바꾸는 과정에서 bias가 사용됨. */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
	// 초기화
	float f(3.141592f); // f를 안 붙으면 자동으로 double로 인식함. -> 메모리가 2배!
	double d(3.141592); // e표기법: 3.14 = 31.4*0.1 = 31.4e-1 <-> 3.14*100 = 3.14e2 = 314
	long double ld(3.141592);

	std::cout << sizeof(f) << endl; // = 4 bytes, 사이즈 찍는 법.
	cout << sizeof(d) << endl;		// = 8 bytes.
	cout << sizeof(ld) << endl;		// = 8 bytes.

	cout << numeric_limits<float>::max() << endl; // Max 값 확인.
	cout << numeric_limits<double>::max() << endl;
	cout << numeric_limits<long double>::max() << endl;

	cout << numeric_limits<float>::min() << endl; // Min 값 확인; 표현할 수 있는 최솟값의 '절댓값'.
	cout << numeric_limits<double>::min() << endl;
	cout << numeric_limits<long double>::min() << endl;

	cout << numeric_limits<float>::lowest() << endl; // lowest 값 확인 -> 음수도 표현할 수 있음을 확인.
	cout << numeric_limits<double>::lowest() << endl;
	cout << numeric_limits<long double>::lowest() << endl;
	// 소결론: 현재 구현된 코드에서는 double과 long double이 차이가 없다.


	/******* Next topic *******/
	cout << 1.0 / 3.0 << endl; // 0.333..의 무한대로 출력되지 않고 0.333333까지만 출력됨.
	cout << std::setprecision(16); // 16자리까지 표현되길 원할 경우 precision(정밀도) 설정 변경. 출력부가 아니므로 << endl;이 필요 없음.
	cout << 1.0 / 3.0 << endl;

	float ff(123456789.0f);
	cout << std::setprecision(9);
	cout << ff << endl; 
	/* 1234567"89"이 아닌 1234567"92"로 출력됨. 8이 사라짐 (=정밀도를 잃어버렸다).
	내부적으로 2진수로 저장되므로 10진수로 생각하는 우리가 예측하기 어려운 오차가 발생함.
	작은 오차라고 생각할 수도 있으나 치명적일 수 있음. 
	이러한 현상 때문에 double을 사용하자는 의견이 있음.
	그러나 메모리를 2배 사용한다는 것은 메모리에서 CPU로 데이터를 보낼 때 부담이 2배로 늘어난다는 뜻. 
	또한 CPU 안의 가속 구조에서 부담이 되므로 double이 무조건 답은 아님.
	하지만 장기적으로는 double의 추세로 가고 있음.
	*/

	float dd(0.1);
	cout << dd << endl;
	cout << std::setprecision(12);
	cout << dd << endl; // 0.10000000001인 이유: 부동소수점 표현 방법을 이용해서 표현할 수 있는 0.1에 가장 가까운 수. 

	float d1(1.0);
	float d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
	cout << d1 << endl;
	cout << d2 << endl; // 둘 다 1로 출력되어 같아 보이나,

	cout << std::setprecision(17); // precision을 키우면
	cout << d1 << endl; // 1
	cout << d2 << endl; // 0.9999...989 로 출력됨 -> 오차가 누적됨. 즉 컴퓨터가 완벽하게 정확하진 않음.


	/******* Next topic *******/
	double zero = 0.0;
	double posinf = 5.0 / zero;	 // 수학에서는 positive 무한대가 됨.
	double neginf = -5.0 / zero; // 수학에서는 negative 무한대가 됨.
	double nan = zero / zero;	 // 수학에서는 Not a number가 됨.

	cout << posinf << endl;
	cout << neginf << endl;
	cout << nan	   << endl; // 출력값 = -nan(ind): ind = indeterminate
	// nan값이 출력되면 안되므로 이를 파악하는 것이 중요함. "isnan" 또는 "isinf"를 사용
	cout << posinf << " " << std::isinf(posinf) << endl; // 1 is ture. 
	cout << neginf << " " << std::isnan(neginf) << endl; // 0 is not ture.
	cout << nan << " " << std::isnan(nan) << endl;		 // 1 is ture.
	cout << 1.0 << " " << std::isnan(1.0) << endl; 

	return 0;
}