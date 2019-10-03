/*
7.4강 "주소에 의한 인수 전달(Passing Arguments by Address)" - Call by Address

- ref에 비해 쓸모가 없다고 생각될 수도 있으나 C 언어 코딩에서는 반드시 필요했으며,
  array에서 소수의 데이터를 보낼 때, 데이터 전부가 복사되는 것보다 주소가 복사되는 것이 효율적이므로 사용된다.
*/

#include <iostream>
using namespace std;

// foo(5)의 경우, const의 위치와 상관없이 주소만 넣어주어야 한다.
/* void foo(const int *ptr)
   void foo(int * const ptr) */
void foo(int *ptr)
{
	cout << *ptr << " " << ptr << endl; // *ptr는 de-referencing, ptr은 adress 임을 주의!
	cout << "In the func. " << &ptr << endl; // 포인터 변수 또한 변수이므로 함수 내에서의 주소가 다르다.
}
// 왜냐하면
typedef int* pint;  // typedef를 이용하여 int*을 하나의 변수로 선언하여 직관적으로 볼 수 있다.
void foo2(pint ptr) // 이때, ptr도 '주소라는 하나의 값'을'값에 의한 전달'한 것을 확인할 수 있다.
{
	// 즉, 주소라는 특수한 값을 담고 있을 뿐 하나의 변수다. 단순히 주소값이 복사가 된 것이다.
}

// 포인터를 이용해서 ref와 동일하게 함수의 output인 것처럼 사용할 수 있다. --> 실용적인 측면에서는 ref가 더 좋다.
void getSinCos(double degrees, double *sin_out, double *cos_out)
{
	*sin_out = 1.0; // <-- de-referencing 값을 바꿔주어야 한다.
	*cos_out = 2.0;
	/* "주의" 자칫하면 ref와 포인터를 동일하게 생각할 수 있다.
	    그러나 ref는 동일한 주소를 사용하는 반면 포인터는 값에 의한 전달이다. */
	cout << sin_out << " " << cos_out << endl;   // cout << &sin << " " << &cos << endl;와는 동일하다.
	cout << &sin_out << " " << &cos_out << endl; // 그러나 포인터 변수 자체의 주소는 다르다.
}

// Call by Address의 장점: array를 파라미터로 사용할 때 & const 사용.
void arrayAddress(const int *arr, const int *ptr, int length)
{
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;

	arr[0] = 1.0; // <-- 대괄호는 de-referencing을 의미하며 const를 붙였으므로 불가능하다.
	// = *ptr = 1
}

int main()
{
/**************** Topic 1 ****************/
	int value = 5;
	cout << value << " " << &value << endl;

	int *ptr = &value;
	cout << "In the main " << &ptr << endl; // <-- ptr 변수(=포인터 변수)의 주소가 func.과 main에서 다르다.

	foo(ptr);    // 방법 1.
	foo(&value); // 방법 2.

/**************** Topic 2 ****************/
	// 한계점 1.
	foo(5); // 주소를 넣어주어야 하므로 어떤 경우에도 불가능하다. <-- ref와의 차이점.

/**************** Topic 3 ****************/
	// 한계점 2.
	// 함수로 사용할 때도 주소로 바꿔서 넣어줘야 한다.
	double degrees = 30;
	double sin, cos;
	getSinCos(degrees, &sin, &cos); // <-- 주소를 입력해야 한다.

	cout << sin << " " << cos << endl;   // <-- 함수 내부에서 바꿔진 값이 외부에도 영향을 미친다.
	cout << &sin << " " << &cos << endl; // <-- 포인터와 ref의 차이점! 포인터는 포인터 변수의 주소가 다르다.

	return 0;
}