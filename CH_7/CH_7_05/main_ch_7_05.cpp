/*
7.5강 "다양한 반환 값들(Returning values)" - 값, 참조, 주소, 구조체, 튜플(Tuple)

- 함수가 계산한 결과, 즉 반환 값을 어떻게 받을 것인가?
*/

#include <iostream>
#include <array>
#include <tuple>
using namespace std;

// (1) 값에 의한 전달
int getValue1(int x1) // return 타입은 int이다.
{
	int value1 = x1 * 2; // int value가 선언이 되고, 6으로 초기화가 된다.
	return value1;       // 함수 밖으로 전달이 된다.
}

// (2) 주소에 의한 전달
int* getValue2(int x2) // int*로 타입을 바꿔주고,
{
	int value2 = x2 * 2; 
	return &value2;    // return 값을 주소로 바꿔준다.
}
int* allocateMemory(int size)
{
	return new int[size];
}

// (3) 참조에 의한 전달
int& getValue3(int x3) // int&로 타입을 바꿔준다.
{
	int value3 = x3 * 2; 
	return value3;    
}
int& get(std::array<int, 100>& my_array, int ix)// 함수에서 특정 element의 ix의 ref를 return해준다.
{
	return my_array[ix];
}

// struct를 이용한 여러 개의 return 값 반환, 특히 C style에서 주로 사용됨.
struct S
{
	int a, b;
	double c, d;
};
S getStruct()
{
	S my_s{ 1, 2, 3.0, 4.0 };
	return my_s;
}

// tuple을 이용한 여러 개의 return 값 반환.
std::tuple<int, double> getTuple() // <>에 원하는 return 타입을 넣어주며, std::tuple<int, double> 자체가 사용자 정의 자료형처럼 작용한다.
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}

int main()
{
/**************** Topic 1 ****************/
	// 1. Return by value
	int value1 = getValue1(3); // getValue1 함수의 결과로 도출된 6이 main의 int value에 복사해서 들어간다.
	/* 장점: 명쾌하다.
	   단점: 선언과 복사가 반복적으로 나타나므로 속도가 저하된다; 특히 array, class, struct 등을 사용할 때. */

/**************** Topic 2 ****************/
	// 2. Return by address에서의 주의 사항: 실용적인 방안은 CH_7_04
	// (1) 주소로 직접 받는 방법
	int *value2 = getValue2(3); // 함수가 끝나면 사라질 변수 value2의 주소를 받아오는 것은 매우 위험하다.
	cout << *value2 << endl;    // 값은 출력되지만 지양할 것.

	// (2) de-referencing을 이용해서 값을 받는 방법
	int value3 = *getValue2(3); // 함수가 끝나면 사라질 변수 value2를 de-referencing 하는 것은 안전하지 않으므로 권장하지 않는다.
	cout << value3 << endl;     // 값은 출력되지만 지양할 것.

	// (참고) 특이한 방식으로 사용된다. ex) design pattern
	int *array = allocateMemory(1024);
	delete[] array;

/**************** Topic 3 ****************/
	// 3. Return by reference
	int value4 = getValue3(5);

	// 주의사항: &value4
	// int &value4 = getValue3(5);

	// ref와 func. 간의 유용한 사용법.
	std::array<int, 100> my_array; // 우선 메모리를 안전하게 잡아둔 채로,
	my_array[30] = 10; // 특정 element의 값을 바꿀 수 있다.
	// 이를 동일하게 func. 을 이용하여 표현한다면,
	get(my_array, 30) = 1024; // return 값인 get(my_arrat,30)을 하나의 변수처럼 사용하여 1024를 선언.
	get(my_array, 30) *= 10;  // func. 을 이용하여 값을 편리하게 계산한다.
	cout << my_array[30] << endl;
	
/**************** Topic 4 ****************/
	// 여러 개의 return 값을 받는 방법 (1): struct
	S my_s = getStruct();
	my_s.b;
	cout << my_s.a << " " << my_s.d << endl;

/**************** Topic 5 ****************/
	// 여러 개의 return 값을 받는 방법 (2): tuple
	std::tuple<int, double> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl; // = a
	cout << std::get<1>(my_tp) << endl; // = d

	// C++ 17 버전에서 사용법.
	auto[a, d] = getTuple();
	cout << a << endl;
	cout << d << endl;

	return 0;
}