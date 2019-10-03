/*
1.5강 "함수와의 첫 만남"
*/

#include <iostream>

using namespace std;

int addTwoNumbers(int num_a, int num_b) // 함수(function)의 이름 명명은 가급적 자세히 적어야 함.
// num_a와 num_b를 매개변수(parameters)라고 부름.
{
	int sum = num_a + num_b; 
	/* int sum = num_a * num_b; 곱하기로 쉽게 바꿀 수도 있음. 
	   이때 함수 이름 위에 마우스 우클릭 후 Rename 하여 multiplyTwoNumber로 바꿀 수 있음.
	   F11을 눌러가며 debugging하는 과정에서 sum의 값이 -858993460과 같이 나오는 것은 garbage 값임. */

	return sum; // = 반환값 또는 리턴값(return values).
	// 결과를 출력(리턴) 하겠다. 함수의 타입과 리턴하는 값의 타입이 같아야 함.
}

// 입력과 출력(리턴)이 없는 함수도 있음
void printHelloWorld() // or printHelloWorld(void)
{
	cout << "Hello World" << endl;

	return; // 출력(리턴)이 없는 경우에도 return만을 써줄 수는 있음.

	cout << "Hello World2" << endl;
	//그러나 "Hello World2"는 실행되지 않음. (debugging을 하면 확인 가능.)
}

int addTwoNumbers1(int a, int b)
{
	printHelloWorld(); // 함수 안에서 함수를 호출할 수 있음.
	return a + b;
}

int main()
{
	cout << 1 + 2 << endl;
	cout << 3 + 4 << endl;
	cout << 8 + 13 << endl;
	// 한가지 패턴이 반복적으로 수행될 때는 함수를 사용함.

	cout << addTwoNumbers(1, 2) << endl;
	// 1과 2의 값을 인수(arguments)라고 부름.
	cout << addTwoNumbers(3, 4) << endl;
	cout << addTwoNumbers(8, 13) << endl;
	// 브레이크 포인트를 찍은 후 F11을 누르면 함수 안으로 들어감.
	
	cout << "Hello World" << endl;
	printHelloWorld();

	int sum1 = addTwoNumbers1(1, 2);
	cout << sum1 << endl;

	return 0;
}