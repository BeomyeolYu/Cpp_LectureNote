/*
3.2강 "산술 연산자(Arithmetic Operators)"
- 산수와 미세한 차이가 있어서 주의할 점이 있음.
*/

#include <iostream>

using namespace std;

int main()
{
/********* Topic 1 *********/
	int x = 7;
	// 컴파일러는 공백을 무시하기 때문에 에러가 발생하지는 않지만, 가독성을 위하여 단항 연산자는 꼭 붙여 쓰는 것이 좋음.
	int y = -x; // vs.
	int z = 1 - - x;

/********* Topic 2 *********/
	int m = 4;
	int n = x % m; // 나머지 연산자.
	cout << x / m << " " << n << endl; // 몫과 나머지 출력.

	/* int 나머지와 float 나머지는 다름.
	- int 나누기 int는 int가 나옴.
	- 하나라도 float 면 float가 나옴. */
	cout << x / m << endl;				 // = 1 (int)
	cout << float(x) / m << endl;		 // = 1.75 (float)
	cout << x / float(m) << endl;		 // = 1.75 (float)
	cout << float(x) / float(m) << endl; // = 1.75 (float)


/********* Topic 3 *********/
	cout << -5 / 2 << endl;
	/* Q. 답이 -2.5면 -2일까? -3일까? 
	   Ans. C++ 11부터 버림(절삭)을 해서 -2가 출력 */
	
	cout << -5 % 2 << endl; // 나머지 = -1
	/* 나머지의 경우에는 왼쪽 수의 부호를 따라가도록 정해짐. */


/********* Topic 4 *********/
	int i = x; // 대입 연산자: x 변수가 가지고 있는 메모리의 정보(7)를 i 변수가 가리키고 있는 메모리에 복사하라.
	i += y; // i = i + y; 코드의 양을 줄이기 위함과 가독성을 높이기 위하여 사용.
	// -= , *= , /=, %= 등.

	return 0;
}