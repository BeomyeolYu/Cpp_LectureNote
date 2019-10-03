/*
1.10강 "선언(Declaration)과 정의(Definition)의 분리"

- 좋은 프로그래머가 되기 위한 코드 정리 기술. (Ex, 다수의 함수를 선언하여 main 함수가 묻힌 경우.)
*/
#include <iostream>

using namespace std;

// 함수의 최소한의 정보를 담고 있는 prototype을 이용해서 앞으로 빼놓는다.
int add(int a, int b); // 전방 선언(forward declaration).
int subtract(int a, int b);

int main()
{
	cout << add(1, 2) << endl;
	cout << subtract(1, 2) << endl;
	/* 함수 이름 위에서 마우스 우클릭 후 Go To Definition(F12)를 누르면 기능 확인 가능.
	 프로젝트가 여러 파일로 이루어진 경우에는 우클릭 후 Peek Definition(Alt+F12)를 선택.*/
	return 0;
}

// definition
int add(int a, int b) // prototype
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

int subtract(int a, int b)
{
	return a - b;
}

