/*
7.3강 "참조에 의한 인수 전달(Passing Arguments by Reference)" - Call by Reference

- 강사가 가장 즐겨 쓰는 방식이기도 하며 가장 편리하여 오픈 소스에서 자주 등장함.
- Call by Reference를 사용하는 습관을 기르면 대부분의 경우에 문제없이 좋다.
*/

#include <iostream>
#include <cmath> // sin(), cos()
#include <vector>
using namespace std;

void addOne1(int y)
{
	y = y + 1; // y는 함수 밖으로 나가는 순간 사라진다.
	cout << "In the addOne1 " << y << " " << &y << endl; // 6 & 주소B
	// --> 값에 의한 호출에서는 함수 안에서 새롭게 변수를 선언하고 복사한다.
}
void addOne2(int &y) // 그러나 ref로 y를 전달하는 경우에는
{
	y = y + 1; // 변수 자체가 ref가 넘어오기 때문에 그대로 남아있다.
	cout << "In the addOne2 " << y << " " << &y << endl; // 6 & 주소A 

}

// degrees는 구조상으로 안으로 들어왔다가 영향을 미치지 않는 입력임을 알 수 있다.
void getSinCos(const double degrees, double &sin_out, double &cos_out) // 일반적으로 입력을 앞에 두고 출력을 뒤에 둔다.
{
	// static을 사용하면 변수가 함수 내에서 매번 새로 정의되는 것이 아니라 재사용이 된다.
	static const double pi = 3.141592; // 정밀도가 높게 설정할 수 있다.
	const double radians = degrees * pi / 180.0; // <-- 값이 변하지 않는 것들은 const를 습관적으로 붙이는 것이 좋다.

	sin_out = std::sin(radians);
	cos_out = std::sin(radians);

	/* 연산 Tip: static으로 묶인 부분은 연산이 한 번만 되는 것을 이용!
    static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi;  */
}

// void foo(int &x)    // 주소가 없는 literal의 경우에는 오류 발생.
void foo(const int &x) // 입력에는 const를 붙이는 성향이 있다.
{
	cout << x << " " << &x << endl;
}

// 포인터 변수를 ref로 받는 방법.
// void voo(int *&ptr) = void voo((int*) &ptr)
typedef int* pint;
void voo(pint &ptr)
{
	cout << ptr << " " << &ptr << endl;
}

void printElement1(int(&arr)[5]) {}     // 주의! 대괄호 내에 element의 수가 들어가 있어야 한다.
void printElement2(vector<int>& arr) {} // 최근 추세이며 더욱 깔끔하다. = const vector

int main()
{
/**************** Topic 1 ****************/
	int x = 5;
	cout << "Initial x " << x << " " << &x << endl; // 5 & 주소A

	addOne1(x);
	cout << "Outside the addOne1 " << x << " " << &x << endl; // 5 & 주소A 
	// --> x는 그대로 5이다. 함수 내에서만 6으로 변경. "MATLAB 과의 차이점, 매우 주의"

	addOne2(x);
	cout << "Outside the addOne2 " << x << " " << &x << endl; // 6 & 주소A
	// --> x 자체가 6으로 변경되었으며 주소도 동일하다. "MATLAB 에서의 사용법"
	
/**************** Topic 2 ****************/
	/* C와 C++ 문법에서는 함수가 return 값을 하나밖에 줄 수 없다.
	   --> 함수가 return 값을 여러 개 주어야 하는 상황에서 ref를 사용할 수 있다. 
	   --> 변수를 미리 선언하고 Call by Reference를 해서 마치 output이 나오는 것처럼 구현할 수 있다. */
	double sin(0.0);
	double cos(0.0);

	getSinCos(90.0, sin, cos);

	cout << sin << " " << cos << endl;
	   
/**************** Topic 3 ****************/
	// Call by Reference의 한계: 주소 또는 const가 필요하다.
	foo(6); // <-- void foo(int &x)로 사용하면 주소가 없는 literal의 경우에는 오류 발생.

/**************** Topic 4 ****************/
	// 포인터에 대한 ref를 보낼 수 있다.
	int y = 5;
	int *ptr = &y; // == pint ptr = &y;

	cout << &y << " " << ptr << " " << &ptr << endl;
	voo(ptr);

/**************** Topic 5 ****************/
	// array를 파라미터로 전달하는 방법.
	int arr1[]{ 1, 2, 3, 4, 5 };       // (1) 정적 array
	vector<int> arr2{ 1, 2, 3, 4, 5 }; // (2) std::vector

	printElement1(arr1);
	printElement2(arr2);

	return 0;
}