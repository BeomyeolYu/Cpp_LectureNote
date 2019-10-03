/*
2.2강 "정수형 (Integers)"
--------------------------------------------------------------
Category(영역)	|  Type(형)	 |   최소 크기  |      기타		  |	
--------------------------------------------------------------
문자(character)	|    char	 |   1 byte	   |				  |	(1)
--------------------------------------------------------------
정수(integer)	|   short	 |   2 bytes   |				  |	(2)
--------------------------------------------------------------
				|    int	 |   2 bytes   |  대부분 4 bytes	  |	(3)
--------------------------------------------------------------
				|   long	 |   4 bytes   |				  |	(4)
--------------------------------------------------------------
				| long long	 |   8 byte s  |   C99/C++11 type |	(5)
--------------------------------------------------------------

(1): 문자형을 정수형에 포함한 이유는 문자도 표를 통해 숫자로 바꿔서 숫자인 것처럼 계산하기 때문.
주로 네트워크 프로그래머들이 char 타입을 정수/문자에 대한 개념보다는 1 byte의 최소 크기 저장소로 사용함.
(2),(3): integer의 '최소 크기'는 2 bytes이나 실제 사용할 때는 주로 4 bytes로 구현되어 있음.
(5): 비교적 최근에 추가됨. (C99/C++11 type)
*/

/*
int i = 1; = 4 bytes = 32 bits
| "0"0000000 | 00000000 | 00000000 | 0000000'1' |
맨 앞의 한 비트는 부호에 사용(양수라면 0, 음수라면 1)
2(2진수)의 32제곱(32 bits) 가지의 숫자를 표현할 수 있다. 

integer는 (Signed) int과 Unsigned int 정수형이 있음.
(Signed) int는 이 숫자가 양수인지 음수인지 표현할 필요가 있기 때문에 맨 앞 비트가 부호 표시에 활용됨.
그러나 Unsigned int 정수는 항상 0 또는 양수이기 때문에 부호 표시가 없음.
[Review] (Signed) int는 음의 정수, 0, 양의 정수(자연수)를, Unsigned int는 양의 정수와 0을 포함. (특정 연산에 대해서 unsigned가 더 빨라서 구분되어 있음.)
*/

#include <iostream>
#include <cmath>	// std::pow
#include <limits>	// std::numeric_limits

int main()
{
	using namespace std;

	short		s = 1; 
	int			i = 1;
	long		l = 1;
	long long	ll = 1;

	//각각의 데이터 타입이 메모리를 얼마나 사용하는지 확인.
	cout << sizeof(short) << endl;	    // 2 bytes
	cout << sizeof(int)	<< endl;		// 4 bytes
	cout << sizeof(long) << endl;		// 4 bytes
	cout << sizeof(long long) << endl;	// 8 bytes
	
	/* 계산이 쉬운 short을 이용하여 숫자의 범위를 확인. 
	short: 2 bytes = 2 * 8 bits = 16 bits.
	즉, short 타입으로 표현할 수 있는 경우의 수는 2(이진수)의 16제곱 가지의 수. 	*/
	cout << std::pow(2, sizeof(short) * 8) << endl; // 2의 16(=2 bytes * 8 bits) 제곱: 최대 65,536의 경우의 수.
	
	/* Signed short의 경우 최대 32,767가지의 경우의 수
	| "0"0000000 | 00000000 | 에서 부호(+,-)를 표현하기 위한 bit를 제외(-1). 그리고 0을 제외(-1).*/
	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;

	//short 타입이 표현할 수 있는 가장 큰 숫자를 컴파일러에게 물어보는 함수.
	cout << std::numeric_limits<short>::max() << endl;
	cout << std::numeric_limits<short>::min() << endl;
	cout << std::numeric_limits<short>::lowest() << endl;

	//[핵심!] 데이터 타입에는 제한이 있고, 표현할 수 있는 사이즈를 넘어가면 문자가 생긴다.
	short s1 = 32767;	// 예제 1
	s1 = s1 + 1;		// 32768이기를 기대함.
	cout << "Is this 32768? " << s1 << endl;	
	// 그러나 -32768이 나옴. 이를 overflow라고 함. 즉, 32767이 표현할 수 있는 가장 큰 숫자이므로 +1을 하면 꼬리를 물고 가장 작은 수인 -32768이 나옴.

	short s2 = std::numeric_limits<short>::min();	// 예제 2
	cout << "min() = " << s2 << endl;	
	s2 = s2 - 1;									// 역으로 min의 값에 -1.
	cout << "Is this -32769? " << s2 << endl;		// overflow

	//[핵심!] 데이터 타입을 잘못 선정하면 크나큰 오류가 발생한다.
	unsigned int j = -1;	// 예제 1
	cout << j << endl;		// -1은 Signed이므로 error를 띄워주거나 0으로 치환해줄 수 있음에도 4294967295로 처리함. 하나하나 error를 띄워주지 않는 C++의 장점이 단점으로.

	int k = 22 / 4;					// 예제 2
	cout << k << endl;				// 수학적인 계산 결과는 5.5이지만 정수끼리의 연산을 정수로 저장하려고 하기 때문에 5가 나옴.
	cout << float(22) / 4 << endl;	// 둘 중에 하나가 float면 float로 계산해서 5.5가 나옴. (여기서 4는 int)
	
	return 0;
}