/*
6.1강 "보이드(void) 포인터"

- Generic(포괄적인) pointer라고도 부른다.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	int   i    = 5;
	float f    = 3.0;
	char  c    = 'a';
	void  *ptr = nullptr; // void pointer를 nullptr 포인터로 초기화.

	// void pointer에 다양한 타입을 모두 넣어도 문제가 없다 --> 주소이기 때문에.
	ptr = &i;
	ptr = &f;
	ptr = &c;
	// 한계: void pointer로 주소를 넣으면 들어간 데이터 타입을 알 방법이 없다 --> 주소이기 때문에.

/**************** Topic 2 ****************/
	// int 타입의 pointer을 선언하면 포인터 연산이 가능하다.
	int *ptr_i = &i;
	cout << ptr_i << endl;	   // A. 
	cout << ptr_i + 1 << endl; // A. 

	// 그러나 void pointer는 연산이 불가능하다. 왜냐하면 +1를 할 때 몇 Byte를 더해야하는지 알 수 없기 때문이다.
	// cout << ptr + 1 << endl;

/**************** Topic 3 ****************/
	// &f와 ptr이 동일한 주소인 것은 확인할 수 있다.
	cout << &f << " " << ptr << endl;

	// 그러나 어떤 주소이고 특정한 값이 있다는 사실은 알 수 있지만, 무슨 값인지는 알 수 없기 때문에 역참조가 불가능하다.
	cout << *ptr << endl;

	// 부득이하게 필요한 경우에 casting을 하면 가능은 하다.
	cout << *static_cast<float*>(ptr) << endl;

	return 0;
}