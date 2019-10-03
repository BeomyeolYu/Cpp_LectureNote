/*
2.1강 "기본 자료형 소개 (Fundamental Data Types)"
- 정보의 최소 단위 = bit = 0 또는 1
- 8개를 묶으면 8 bits = 1 byte
- Char a = 'H';에서 문자는 1 byte로 표현 가능.
- int i = 1;은 4 bytes로 표현되었음. (00000000 / 00000000 / 00000000 / 00000001)

- 다양한 자료형이 존재하며, 자료형마다 저장되는 사이즈와 방식이 다름.
- 자료형의 종류: http://www.cplusplus.com/doc/tutorial/variables/ (Type names*에서 이탤릭체로 쓰인 부분은 생략해도 무방하다는 뜻.)
- (Signed) int는 음의 정수, 0, 양의 정수(자연수)를, Unsigned int는 양의 정수와 0을 포함. (특정 연산에 대해서 unsigned가 더 빨라서 구분되어 있음.)
  [참고] 수학 용어에서 양의 정수(positive intefer)나 음의 정수(negative integer)는 0을 포함하지 않음.
- 똑같은 정수인데 다양한 타입이 존재하는 이유는 '메모리'에 차이가 있기 때문.
  즉, 프로그래머의 관점에서 숫자의 범위가 큰 숫자(예를 들어 천문학적인 숫자)가 있고 범위가 작은 숫자가 있는데,
  집의 방이 4개인데 10명의 사람을 넣을 수는 없듯이 '메모리의 사이즈에 맞는' 타입을 사용해야 함. (사용하는 방법은 똑같음.)
- Q. 무조건 가장 큰 64 bits를 이용하면 되지 않느냐?
  A. But, 프로그램 연산 속도를 위해 가급적 작은 것을 쓰는 것이 좋음.

- 실수를 부동 소수점(Floating-point types)으로 부르는 이유는 '숫자부'와 '지수부'를 나누어 저장하기 때문임.
- float는 int와 동일한 32 bits 사이즈이며, double은 float는 2배인 64 bits를 사용함.
(실수 표현의 정밀도 측면에서 float를 single precision(단일 정밀도), double을 double precision(2배 정밀도)이라고도 함.)
- Bool: true or false

- 과거에는 모든 변수 선언(이름, 메모리 등)을 가장 처음에 선언하였으나 현대에는 사용하기 직전에 선언하는 것을 선호함. 
  선언부와 실행부가 가까워야 디버깅하기 좋고 별도의 객체나 함수로 빼내기 좋기 때문; 리펙토링(Refactoring).
*/
#include <iostream>

int main()
{
	using namespace std;

	// Q. bValue = true 또는 bValue = false에 따라 어떤 값이 출력될까?
	bool bValue = false;
	cout << (bValue ? 1 : 0) << endl;
	cout << bValue << endl; // 내부적으로 ture를 1, false을 0인 숫자로 저장함.

	char chValue = 'A';
	cout << chValue << endl;
	cout << int(chValue) << endl; // 내부적으로 문자를 10진수 숫자로 바꿈을 알 수 있음.
	char chValue1 = 65;
	cout << chValue1 << endl; // 거꾸로 65를 입력하면 A가 출력됨. = 내부적으로 결국 문자도 숫자로 표현함. 

	// float와 double은 수학적인 정의만큼 정밀하지 않음. -> 굉장히 큰 오류가 발생할 수 있음.
	float fValue = 3.141592f;
	/* f를 안 붙이면 warning이 발생. (메세지: truncation from 'double' to 'float')
	f를 안 붙이면 double이라는 의미. double은 float보다 메모리를 2배 씀. -> 더 정밀함.
	정밀한 더 높은 값을 덜 정밀한 플로트에 넣었으니 이를 감수하다는 warning.
	f를 붙인다는 건 4 Byte 쓸 것을 내가 감안하고 쓰는 것이라고 알려줌. */
	double dValue = 3.141592; // double은 f를 붙지지 않음.
	cout << fValue << endl; // cout을 사용하였기 때문에 3.14159 이후로 잘림.
	cout << dValue << endl;

	/* 모던 C++에서는 auto를 사용하면 자동으로 자료형을 정해준다.
	 fValue2, dValue2에 마우스를 올려보라.*/
	auto fValue2 = 3.141592f;
	auto dValue2 = 3.141592;
	cout << fValue2 << endl;
	cout << dValue2 << endl;

	// sizeof: 변수의 자료형(타입)의 크기를 byte 단위로 구하는 연산자
	cout << sizeof(bool) << endl;
	cout << sizeof(bValue) << endl;
	cout << sizeof(fValue2) << endl;
	cout << sizeof(dValue2) << endl;

	// C++은 변수 초기 방법이 3가지 있음.
	int a = 123;	// copy initialization
	int b(123);		// direct initialization, 객체 지향 프로그래밍에서 유용.
	int c{ 123 };	// uniform initialization, 객체 지향 프로그래밍에서 유용, 최근에 권장하는 추세.

	/*	int i = 3.1415; // warning이 뜸. 이 때, 내부적으로 3.1415를 3으로 바꿔서 저장함. (캐스팅이라고 한다.)
	int d(3.14);		// 똑같은 warning.
	int e{ 4.5 };		// 4.5라는 실수(double)을 넣으면 error가 뜬다. (conversion from 'double' to 'int' requires a narrowing conversion)
	결론, copy와 direct는 warning만 띄우고 컴파일은 해주나 uniform initialization의 경우 안 해줌 */
	// warning 및 error를 없애는 법
	int i = (int)3.1415; // 인위적으로 캐스팅 수행.
	int d((int)3.14);
	int e{ 4 };

	// 여러 가지 변수를 동시에 선언하는 법.
	int k = 0, l = 456, m = 123; // ,는 같은 데이터 형태일 때만 사용 가능
	int n = 0, o(456), p{ 123 }; // 위와 동일하나 코드릴 이해하기에 편한가를 고민.

	return 0;
}