/*
7.7강 "함수 오버로딩(Function Overloading)"

- Function Overloading: 동일한 이름의 Function을 여러 개 만드는 것.
*/

#include <iostream>
#include <string>
using namespace std;

/**************** Topic 1 ****************/
int add(int x, int y) {return x + y;}
double add(double x, double y) {return x + y;}
/* "주의" double add(int x, int y)와 같이 parameter가 같은 함수가 2개 있으면 오류 발생.
  --> C++에서는 return 타입이 다른 것 만으로는 Overloading이 안 되고 parameter가 달라야 한다. */

/**************** Topic 2 ****************/
int get1(int x) {}
double get1(double y) {}
// 를 ref를 사용하여 void로 선언할 수 있다.
void get2(int& x) {}	
void get2(double& y) {}
// 이 경우 parameter의 값을 돌려받는다.

/************** Topic 3 & 4 **************/
// typedef을 해도 동일한 type이라면 Overloading이 불가능하다.
typedef int my_int;
void print1(int x) {}
void print1(my_int x) {} 

// 현실적인 match 문제
// Topic 3: match가 안되는 경우.
void print2(const char *value) {} // <-- 포인터
void print2(int value) {}
// Topic 4: 정확히 딱 맞는 것이 없어서 전부 모호한 경우.
void print3(unsigned int value) {}
void print3(float value) {}

int main()
{
/**************** Topic 1 ****************/
	// (1) parameter는 다르지만 기능은 비슷한 경우에 사용.
	add(1, 2); // 컴파일러가 알아서 자료형을 보고 컴파일을 해준다.
	add(3.0, 4.0);

/**************** Topic 2 ****************/
	// (2) void와 ref를 이용하여 Overloading.
	int x;
	get2(x); // 다만, 입력인지 return 값을 가져오는 것인지 구분이 안될 수 있다.

/**************** Topic 3 ****************/
	print2(0);   // 0은 int라는 것을 정확히 알 수 있다.
	print2('a'); // 'a'를 char가 아닌 void print(int)로 인식한다.
	print2("a"); // "a"는 void print(char)에 const를 붙여줘야만 한다.

/**************** Topic 4 ****************/
	// 의도한 바를 명확하게 표현해야 Overloading를 사용할 수 있다.
	print3('a');	  // (unsigned int)'a'
	print3(0);		  // 0u
	print3(3.141592); // 3.141592f

	return 0;
}