/*
6.7강 "포인터(Pointer)의 기본적인 사용법"

- C 언어 및 C++ 언어의 중요한 특징 중의 하나
- 컴퓨터가 내부에서 어떻게 작동하는지, CPU가 Memory가 어떻게 협력하는지 알려주는 열쇠.

- 단계적인 사고를 가능하게 하며 포인터의 개념을 통해 논리력을 키울 수 있다.
  --> 보물을 바로 주는 것이 아니라 보물 지도를 줄테니 보물을 찾는다는 개념.
- 하드웨어 또는 real-time 시스템에서는 알고리즘만으로는 성능 향상의 한계가 있으며, 메모리 차원에서 접근하게되면 garbage를 줄일 수 있다.
  --> 메모리에 대한 접근과 논리가 있으면 효율적인 프로그래밍이 가능하다. 탑 프로그래머는 포인터를 자유자재로 다룰 수 있다.

- 지역 변수는 '스택' 메모리를 사용하고, 동적 할당 메모리는 '힙' 메모리를 사용한다.
- 큰 메모리에 저장되어 있는 데이터 중에서 일부분을 CPU가 사용하기 위하여 메모리로부터 가져올 때는
  메모리 전체를 모두 뒤지면서 찾는 것이 아니라 필요한 데이터가 저장되어 있는 '주소'를 사용하여 직접 접근하여 가져온다.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

struct Something
{
	int a, b, c, d; // 4 x 4 = 16 bytes
};

int main()
{
/**************** Topic 1 ****************/
	int x = 5; /* 어떤 변수를 하나 선언한다는 것은,
				  이 변수가 사용할 메모리 공간을 OS로부터 주소와 함께 빌려오는 것이며,
				  빌려온 메모리 공간(주소)에 5를 할당하는 것이다. */

	cout << x << endl;
	cout << &x << endl;		 // & = address-of operator: 16진수 메모리 주소 출력
	cout << (int)&x << endl; // 10진수로 강제 casting.
	// 주소를 직접적으로 확인하는 것에 큰 의미는 없으나 메모리 주소를 변수에 담아놓으면 사용할 곳이 있다 = pointer

/**************** Topic 2 ****************/
	/* de-reference operator(*)
	- CS 분야에서는 reference라는 뜻이 광범위하게 쓰인다.
	- C 언어에서는 pointer가 있고 reference가 따로 있어 혼란스러울 수 있다.
	- reference의 의미: 간접적으로 가리키는 것.
	- pointer 또한 가리킨다는 의미로 reference의 일종으로 볼 수 있으다. 
	  --> pointer를 사용할 때 생길 수도 있는 위험성을 방지하기 위한 개념이 reference이다. */
	/* de-reference는,
	   pointer가 "저쪽 주소에 가면 이 데이터가 있어요"라고 간접적으로 기리키기만 하는 것에 대해서,
	   "그럼 내가 거기에 진짜 뭐가 있는지 내가 들여다볼게"라고 직접적으로 접근하겠다는 의미. */
	
	cout << *(&x) << endl; /* "그 주소에 정말 뭐가 있는지 보자": de-reference operator(*)
						      x의 메모리 주소에 담겨있는 5가 출력. 
							  --> operator 우선순위에 의하여 *(&x) = *&x이다. */

/**************** Topic 3 ****************/
	// pointer도 결국 주소를 저장하는 '변수'이다 --> 데이터 타입을 가지고 있다.
	// 표현 방법 (1): * 양옆에 공백.
	int * ptr_x = &x; // int형 pointer
	double d = 123.0; // double형 pointer

	// 표현 방법 (2): * 왼쪽에 붙이기 <--가장 많이 사용하는 방법
	int *ptr_y = &x, *ptr_z = &x; // 이 경우 *ptr_y와 *ptr_z에 모두 *를 붙여야 한다.
	double *ptr_d = &d;

	cout << &x << endl;		// 0099FC88 출력. 
	cout << ptr_x << endl;  // 0099FC88 출력.
	cout << *ptr_x << endl; // *를 붙이면(de-referencing) 5 출력.
	cout << *ptr_d << endl; // 123 출력.

	/* pointer의 타입을 선언하는 이유:
	   일차적으로 메모리 주소는 데이터 타입과 무관하며 중립적이다. 
	   --> 모든 타입에 대하여 pointer 사이즈가 같다 = 고정이다.
	   그러나, 
	   1) pointer 변수에 담겨 있는 주소로 찾아가고,
	   2) 주소에 담겨있는 값을 가져오는 de-referencing(*)할 때 어떤 타입으로 가져올 것인지 정의하기 위함. 
		--> 주소가 담겨 있지 않은 경우에는 쓰레기 값(실제 메모리에 할당된 값이 아닌)이 할당되기 때문에 오류 발생. */

	/* pointer를 왜 쓰는가?
	(1) 데이터가 100만 개인 array를 사용할 때, 함수 파라미터로 array를 쓰면 복사가 된다 
	   = 100만 개의 메모리가 for 문에서 돌며 복사되는 것은 상당한 부담이다.
	   -> 이때 첫 번째 주소하고 데이터가 총 몇 개 있는줄만 알면 부담이 덜하다. 
      	  즉, 우리 워크샵이 빌린 방은 101호부터 10개 빌렸다는 의미. (101호~111호)
	(2) 변수를 여기저기 사용할 때 변수를 직접보내면 부담이 되지만 주소를 보내면 덜하다. */

/**************** Topic 4 ****************/
	// #include <typeinfo>: type information
	cout << typeid(ptr_x).name() << endl; // int *가 출력.

	cout << sizeof(x) << endl;     // 4 bytes 출력.
	cout << sizeof(d) << endl;	   // 8 bytes 출력.

	cout << sizeof(&x) << endl;    // 4 bytes출력.
	cout << sizeof(&d) << endl;	   // 4 bytes출력.

	cout << sizeof(ptr_x) << endl; // 4 bytes출력.
	cout << sizeof(ptr_d) << endl; // 4 bytes출력.
	// --> 집이 크다고 해서 주소가 더 길지 않은 것과 같다.
	// x86일 때 보다 x64일 때는 주소가 8 bytes가 된다.

/**************** Topic 5 ****************/
	// struct에서의 pointer 사용에서도 주소는 고정.
	Something ss;
	Something *ptr_s;
	cout << sizeof(Something) << endl; // 16 bytes 출력.
	cout << sizeof(ptr_s) << endl;	   // 4 bytes 주소 출력.

/**************** [참고] ****************/
	int concept = 12;
	int *pointer = &concept;
	int &reference = concept;
	cout << concept << " = " << reference << " = " << *pointer << " = " << *&concept << endl;
	cout << &concept << " = " << &reference << " = " << pointer << endl;
	cout << &pointer << endl; // 포인터 변수만이 다른 주소를 가지고 있다.
	return 0;
}