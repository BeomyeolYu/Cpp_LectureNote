/*
3.8강 "비트 단위 연산자(Bitwise Operators)"

- 각각의 bit끼리 연산하는 연산자.
  (int끼리의 합, float끼리의 차는 타입끼리의 연산이라고 볼 수 있음.)
- 메모리를 아끼고 연산 속도를 빠르게 하기 위하여 사용함.
- unsigned를 사용하는 것이 일반적임.
*/

#include <iostream>
#include <bitset>     // <- #include

int main()
{
	using namespace std;
/********* Topic 1 *********/
	/* 
	<< : left shift
	>> : right shift
	  -> cin, cout에서의 쓰임과는 다름. 여기선 Bitwise Operators가 아니며 Bitwise Operators가 default임.
	  -> 기호의 개수에 제한이 있기 때문에 '오버 로딩'하여 사용함.
	~ : Bitwise NOT (logical not = !a)
	& : Bitwise AND
	| : Bitwise OR
	^ : Bitwise XOR
	*/


/********* Topic 2 *********/
	unsigned int a = 3;
	cout << std::bitset<4>(a) << endl; // a가 내부적으로 어떻게 2진수로 표현되는지 보여줌. 4 bits로 확인.

	// left shift
	unsigned int b = a << 1;
	cout << std::bitset<4>(b) << " in decimal " << b << endl; // 0011(=3)에서 오른쪽으로 한 칸씩 이동하고 빈자리는 0으로 채워 0110(=6)가 출력.

	// 8 bits = 1 btye
	cout << std::bitset<8>(a) << " in decimal " << a << endl;			   // 3 출력
	cout << std::bitset<8>(a << 1) << " in decimal " << (a << 1) << endl;  // 6(=3*2^1) 출력
	cout << std::bitset<8>(a << 2) << " in decimal " << (a << 2) << endl;  // 12(=3*2^2) 출력
	cout << std::bitset<8>(a << 3) << " in decimal " << (a << 3) << endl;  // 24(=3*2^3) 출력
	cout << std::bitset<8>(a << 4) << " in decimal " << (a << 4) << endl;  // 48(=3*2^4) 출력
	// left shift가 많이 쓰이는 이유: 어떤 수에 2의 제곱을 곱할 때, 곱하기 또는 power 등을 사용한 경우보다 연산이 훨씬 빠르다.


/********* Topic 3 *********/
	// right shift
	unsigned int i = 1012;
	// 16 bits
	cout << std::bitset<16>(i) << " in decimal " << i << endl;			    // 1024 출력
	cout << std::bitset<16>(i >> 1) << " in decimal " << (i >> 1) << endl;  // 512 출력
	cout << std::bitset<16>(i >> 2) << " in decimal " << (i >> 2) << endl;  // 256 출력
	cout << std::bitset<16>(i >> 3) << " in decimal " << (i >> 3) << endl;  // 128 출력
	cout << std::bitset<16>(i >> 4) << " in decimal " << (i >> 4) << endl;  // 64 출력
	// 연산 속도는 훨씬 빠르지만, 2진수 표현이므로 일반적으로 생각하는 나누기, 곱하기는 사용할 수 없음.


/********* Topic 4 *********/
	// ~ : Bitwise NOT = 보수(complement)
	cout << std::bitset<16>(i) << " in decimal " << i << endl;	    // 0000001111110100(=1024) 출력
	cout << std::bitset<16>(~i) << " in decimal " << (~i) << endl;  // 1111110000001011(=4294966283) 출력; 10진수 표현에서의 규칙성을 찾기는 어렵다.


/********* Topic 5 *********/
	// 이진수 표현: 앞에 0b를 붙인다.
	unsigned int n = 0b1100;
	unsigned int m = 0b0110;
	cout << " n is (in decimal) " << n << " m is (in decimal) " << m << endl;
	
	/* '1100' 과
	   '0110' 사이에 bit 단위로 AND, OR, XOR을 판단.

	Ex,  1100
	AND  0110
	-----------
	     0100
	*/

	// &: Bitwise AND
	cout << std::bitset<4>(n & m) << " in decimal " << (n & m) << endl; // 0100 출력.

	// | : Bitwise OR
	cout << std::bitset<4>(n | m) << " in decimal " << (n | m) << endl; // 1110 출력.

	// ^ : Bitwise XOR
	cout << std::bitset<4>(n ^ m) << " in decimal " << (n ^ m) << endl; // 1010 출력.


/********* Topic 6 *********/
	/*
	Bitwise Operators도 결합한 형태로 줄여서 사용할 수 있음.
	(1) a = a & b 와
	(2) a &= b    는 같음.
	*/


	return 0;
}