/*
6.14강 "참조 변수(reference variable)"

- 특정한 경우에 pointer 보다 장점이 있고 사용하기 편리하다.
- 객체 지향 프로그래밍에서 아주 많이 사용된다.
- 변수의 별명처럼 ref를 사용될 수 있다.
*/

#include <iostream>

using namespace std;

void doSomething(int &n) // (int n)으로 넘기면 변수 자체를 복사해야 하지만, ref로 넘기면 변수 자체가 넘어가는 것이기 때문에 복사를 할 필요가 없다.	
                         // --> 주소조차도 복사를 할 필요가 없어 퍼포먼스가 더 좋다.
{
	cout << &n << endl; // A. 

	n = 10;
	cout << "In doSomething " << n << endl;
}

void printElements(int(&arr)[5]) // element의 개수 [5]가 꼭 들어가야 한다.
{
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << &arr << endl; // A.
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
/**************** Topic 1 ****************/
	int value1 = 5;
	
	// Pointer
	int *ptr1 = nullptr;
	ptr1 = &value1;

	// Reference variable
	// *를 붙일 필요가 없으며,
	int &ref1 = value1;   // 반드시 초기화가 필요하다. --> 원래 이름이 있어야 별명을 지을 수 있는 것처럼.
  //int &ref = 123;	      // 공식적으로 문자열은 메모리 주소를 갖지 않기 때문에 들어갈 수 없다. --> 변수만이 들어갈 수 있다.
	cout << ref1 << endl; // A. 

	ref1 = 10; // re-assign 가능 = *ptr1 = 10;
	cout << value1 << " " << ref1 << endl; // A.

/**************** Topic 2 ****************/
	/* 주소 출력 --> &value1과 &ref의 주소도 같다.
				 --> &ref가 별도의 주소를 갖는 것이 아니라 동일한 주소를 공유한다.
				 --> 포인터의 경우 포인터 변수가 다른 주소를 가지고 있다. */
	cout << &value1 << endl; // 00EFFC80
	cout << &ref1 << endl;	 // 00EFFC80
	cout << ptr1 << endl;	 // 00EFFC80
	cout << &ptr1 << endl;   // 00EFFC74: 포인터 변수 자체의 주소만 다르다.

/**************** Topic 3 ****************/
	// const와 함께 사용하는 경우.
	const int value2 = 5;
	// int &ref2 = value2; // ref에서 value2의 값을 임의로 바꿀 수도 있기 때문에 허용이 안된다.
	const int &ref2 = value2;
		
/**************** Topic 4 ****************/
	// 함수 내부에서 n을 바꾼다 
	int n = 5;

	cout << n << endl;
	cout << &n << endl; // 함수에서도 동일한 주소를 사용한다 = ref의 특징.

	doSomething(n);
	cout << n << endl;	// 함수를 빠져나와도 n이 10으로 유지된다.

/**************** Topic 5 ****************/
	// array를 함수에 넣어줄 때도 ref를 사용할 수 있다.
	const int length = 5;
	int arr[length] = { 1, 2, 3, 4, 5 };

	cout << &arr << endl;    // A. 
	cout << &arr[1] << endl; // A. 
	printElements(arr);

/**************** Topic 6 ****************/
	// 실전에서 쓸모가 굉장히 많은 struct with ref
	Other ot;
	ot.st.v1 = 1.0;	// (1) ot의 st의 v1을 접근할 때 코드가 굉장히 길어진다.

	cout << ot.st.v1 << endl;	 // A. 
	cout << &(ot.st.v1) << endl; // A.

	int &v1 = ot.st.v1;
	cout << v1 << endl;  // A.
	cout << &v1 << endl; // A.
	v1 = 1;			// (2) ref를 이용하면 ot.st.v1가 자주 쓰일수록 편리하고 속도도 느려지지도 않는다.

/**************** Topic 7 ****************/
	// ref도 내부적으로는 pointer로 구현되어 있다.
	int value_ = 5;
	int *const ptr_ = &value_;
	int &ref_ = value_;

	*ptr_ = 10;
	ref_ = 10; // ptr_과 &ref_는 기능상 동일하다.
	
	// [참고]
	int concept = 12;
	int *pointer = &concept;
	int &reference = concept;
	cout << concept << " = " << reference << " = " << *pointer << " = " << *&concept << endl;
	cout << &concept << " = " << &reference << " = " << pointer << endl;
	cout << &pointer << endl; // 포인터 변수 또한 변수이므로 함수 내에서의 주소가 다르다.

	return 0;
}