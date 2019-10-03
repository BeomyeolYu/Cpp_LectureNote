/*
7.8강 "매개변수의 기본값(Default Parameters)"

- Parameter가 여러 개 있을 때 매번 다 넣어주는 것은 번거로울 수 있으므로 원할 경우 argument를 생략해줄 수 있다.
- Default parameter, Optinal parameter, Default argument 등으로 불린다.
*/

#include <iostream>
#include <string>
using namespace std;

/**************** Topic 1 ****************/
void print1(int x = 0) // "x의 입력이 없을 때 0을 넣어주세요." <-- 0 이외에도 기본값을 정해줄 수 있다.
{
	cout << x << " " << endl;
}
void print2(int x, int y = 20, int z = 30) // 다수의 parameter에도 default를 정해줄 수는 있으며 선택하여 정할 수 있으나, 마지막 parameter에는 무조건 default를 정해줘야 한다.
{
	cout << x << " " << y << " " << z << endl;
}

/**************** Topic 2 ****************/
void print(int x = 10, int y = 20, int z = 30) {} // in header

/**************** Topic 3 ****************/
void print3(std::string str) {}
void print3(char ch = ' ') {} // default parameter를 가지고 있다.

void print4(int x) {} // ambiguous
void print4(int x, int y = 20) {} // default parameter를 제거하면 컴파일 에러가 사라진다.

int main()
{
/**************** Topic 1 ****************/
	print1(100); // 100 출력.
	print1();	 // default 0 출력.

	print2(100); // 하나면 x에만 argument가 들어간다.
	print2(100, 200);
	print2(100, 200, 300);
	
/**************** Topic 2 ****************/
	// 주의할 점 1: declaration과 definition이 분리된 경우.
	/*보통 함수는 header file에 따로 definition 되는 경우가 많다.
	  .hpp에서 정의된 함수를 .cpp에서 declaration을 할 때, default Parameter는 .hpp와 .cpp 중에 한 번만 넣어주어야 한다.
	  --> 보통은 header file에서 definition와 declaration 및 default Parameter을 한 번에 해준다 */
	 
/**************** Topic 3 ****************/
	// 주의할 점 2: default parameter가 함수 오버로딩에 영향을 준다.
	print3(); // 마우스를 얹으면 void print3(char ch = '')를 선택한다.

	print4(10);

	return 0;
}