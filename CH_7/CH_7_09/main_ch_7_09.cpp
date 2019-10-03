/*
7.9강 "함수 포인터(Function Pointers)"

- 기존에 배웠던 변수 포인터를 넘어 함수에 대한 포인터에 대하여 학습.
- 객체 지향 프로그래밍에서 다형성을 이해할 때 함수 포인터의 개념은 큰 도움이 된다.
- 홍정모 교수님은 최근 함수 포인터보다 #include <functional>을 많이 쓴다.
*/

#include <iostream>
#include <array>
#include <functional> // C++ 11 부터 제공.
using namespace std;

/************ Topic 1, 2 & 3 ************/
int func() { 
	cout << "Adress of func function: " << func << endl;
	return 5; 
}
int goo() {	
	cout << "Adress of goo function: " << goo << endl;
	return 10; 
}

/**************** Topic 4 ****************/
int func_(int x) {
	return 5;
}

/**************** Topic 5 ****************/
bool isEven(const int& number) {
	if (number % 2 == 0) return true;
	else return false;
}
bool isOdd(const int& number) {
	if (number % 2 != 0) return true;
	else return false;
}
typedef bool(*check_fun_t)(const int&); // 함수 포인터도 typedef를 이용해서 줄여서 사용할 수 있다.
// = using check_fun_t = bool(*)(const int&); // Type alias를 이용해서 동일하게 구현할 수 있다.

void printNumbers(const array<int, 10> &my_array,
	check_fun_t check_fcn = isEven) // default parameter 설정 가능.
{
	for (auto element : my_array) // for-each를 이용한 짝수 또는 홀수만 출력하는 구문.
	{
		if (check_fcn(element) == true) cout << element;
	}
	cout << endl;
}

/**************** Topic 6 ****************/
void printNumbers_(const array<int, 10> &my_array,
	std::function<bool(const int&)> check_fcn)
{
	for (auto element : my_array)
	{
		if (check_fcn(element) == true) cout << element;
	}
	cout << endl;
}

int main()
{
/**************** Topic 1 ****************/
	// 함수도 포인터이며, 함수도 메모리에 들어가서 실행된다 (= 함수도 주소를 가지고 있다).
	cout << func() << endl; // 5 출력.
	cout << func << endl;	// 괄호가 없는 경우 주소 00BB125D 출력.

/**************** Topic 2 ****************/
	// 함수 포인터를 선언하는 방법.
	// func 함수와 동일한 int 형, func 함수에 parameter가 없기 때문에 (), funptr은 변수명처럼 사용자 설정
	// int(*fcnptr)(); --> 함수 포인터의 타입은 대입한 함수의 return 타입과 일치해야 한다.
	// 초기화하는 방법.
	int(*fcnptr)() = func;

/**************** Topic 3 ****************/
	// 함수 포인터를 중간에 바꿔치기할 수도 있다.
	cout << fcnptr() << endl; // 함수 포인터를 실행하면 5가 출력.
	cout << &fcnptr << endl;  // A.
	cout << fcnptr << endl;   // A.

	fcnptr = goo;			  // 다른 주소를 넣어줄 수 있다.
	cout << fcnptr() << endl; // A.
	cout << &fcnptr << endl;  // A.
	cout << fcnptr << endl;   // A.

/**************** Topic 4 ****************/
	// 함수에 parameter가 있는 경우
	int(*fcnptr_)(int) = func_; // parameter가 있는 함수 포인터로 선언해야 한다.
	cout << fcnptr_(1) << endl; // parameter 없이 ()로 비워두면 에러 발생.

	fcnptr_ = goo; // goo와 func_의 parameter가 달라서 에러 발생.
    // 즉, return type과 parameter type이 일치해야 함수 포인터를 선언할 수 있다.

/**************** Topic 5 ****************/
	// 함수 포인터를 함수의 parameter로 넣을 수도 있다.
	std::array<int, 10> my_array{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		
	printNumbers(my_array);
	printNumbers(my_array, isOdd);	// parameter로 함수를 넣을 수 있다.

/**************** Topic 6 ****************/
	// #include <functional>
	std::function<bool(const int&)> fcnptr_ = isEven;
	printNumbers_(my_array, fcnptr_);

	fcnptr_ = isOdd; // Topic 1~5 주석 처리 후 실행.
	printNumbers_(my_array, fcnptr_);

	return 0;
}