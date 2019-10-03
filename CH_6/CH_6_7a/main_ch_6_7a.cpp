/*
6.7강 "널 포인터(Null Pointer)"

- pointer 변수에 담겨 있는 주소로 찾아갔는데, 사전에 pointer 변수에 주소를 할당하지 않아 
  임의의 쓰레기 값(실제 메모리에 할당된 값이 아닌)이 할당되어있는 경우 오류 발생.
--> 이를 방지하기 위한 Null Pointer
*/

#include <iostream>
#include <cstddef>
using namespace std;

void doSomething(double *ptr)
{
	cout << "address of pointer variable in doSomething(): " << &ptr << endl;

	if (ptr != nullptr)
	{
		std::cout << *ptr << std::endl;
	}
	else
	{
		std::cout << "Null ptr, do nothing" << std::endl;
	}
}

int main()
{
/**************** Topic 1 ****************/
	double *ptr_1 = 0;		  // (1) C-style
	double *ptr_2 = NULL;	  // (2) C-style
	double *ptr_3 = nullptr;  // (3) modren C++ style
	double *ptr_4{ 0 };		  // (4) modren C++ style
	double *ptr_5{ nullptr }; // (5) modren C++ style

	// null Pointer의 사용법
	if (ptr_1 != nullptr)
	{
		// do something useful
		// null이 아닌 경우 유의미한 코드 실행.
	}
	else
	{
		// do nothing with ptr
		// 즉, null에 해당되는 경우 잘못 들어온 값이므로 아무것도 하지 마라.
	}

/**************** Topic 2 ****************/
	// 함수의 파라미터로 넘어갈 때 더욱 유용.
	double *ptr{ nullptr }; 
	doSomething(ptr);	  // 00DBFD08, "Null ptr, do nothing"
	doSomething(nullptr); // 00DBFD08, "Null ptr, do nothing"

	double d = 123.4;
	doSomething(&d);	  // 00DBFD08, 123.4 
	ptr = &d;
	doSomething(ptr);	  // 00DBFD08, 123.4 
	// 주소가 모두 같은 이유는 함수 또한 메모리에 저장되기 때문에 함수의 주소를 가져오는 것인가?

	cout << "address of pointer variable in main()" << &ptr << endl;
	// 포인터도 결국 변수이기 때문에 함수로 넘어갈 때 복사가 되어 주소가 다르다.
	
/**************** Topic 3 ****************/
	// nullptr_t: null만 받아야 하는 경우에 사용 가능. 
	std::nullptr_t nprt; // _t = type


	return 0;
}