/*
6.8강 "포인터와 정적 배열"

- 결론부터 말하면 포인터와 정적 배열은 같다.
- 편의상의 문법적 차이가 있다.
*/

#include <iostream>
using namespace std;

void printArray(int array[]) // []이 있어서 입력이 array처럼 보이지만 pointer이다.
// = void printArray(int *array)
{
	cout << sizeof(array) << endl;  // 함수 안에서 array의 size를 확인하는 경우.
	cout << *array << endl;			// array[0]의 9 출력.

	*array = 100; // de-referencing 후에 값을 100으로 변경
}	

struct MyStruct
{
	int array_[5] = { 10, 8, 6, 4, 2 };
};
void doSomething(MyStruct ms) 
{
	cout << sizeof(ms.array_) << endl; // array가 struct나 calss 안에 있을 때는 pointer로 강제 변환 되지 않는다.
}
int main()
{
/**************** Topic 1 ****************/
	int array[5] = { 9, 7, 5, 3, 1 };

	cout << array[0] << " " << array[1] << endl; // 9와 7이 출력됨.

	// array는 사실 array[0]의 주소를 담는 pointer이다. 
	cout << array << endl;     // 값이 16진수가 출력됨!
	cout << &array[0] << endl; // 위와 값이 같다.
	
/**************** Topic 2 ****************/
	// array가 pointer가 동일하다면 de-referencing 할 수 있는가?
	cout << *array << endl; // YES, { 9, 7, 5, 3, 1 }가 아닌 9가 출력된다.

	int *ptr = array;
	cout << ptr << endl;	// array와 동일한 메모리 주소가 출력된다.
	cout << *ptr << endl;	// 9가 출력된다.
	cout << &(ptr) << endl; // 단, ptr 자체의 주소를 출력하면 array와 다르다.
													
	// 문자열 array의 경우에는?
	char name[] = "jackjack";
	cout << *name << endl; // 문자형 pointer이므로 가장 첫 글자 j가 출력된다. 

/**************** Topic 3 ****************/
	// 문법상의 차이.
	cout << sizeof(array) << endl; // 20 bytes 출력 
	cout << sizeof(ptr) << endl;   /* 4 bytes 출력
								      왜냐하면 pointer 변수 자체의 사이즈는 4 bytes로 고정이기 때문.(x86 기준)
								      array를 int 선언해주었기 때문에 4 bytes가 아니다! */
	// 문제가 되는 경우.
	printArray(array); // 20 bytes가 아니라 4 bytes가 출력된다.

/**************** Topic 4 ****************/
	// pointer를 쓰면 함수 안에서 바꾼 값이 함수 밖에서도 바뀐다.
	// C 언어에서 자주 쓰이는 용법이며, C++에서는 동일한 용법을 reference로 수행한다.
	cout << array[0] << " " << *array << endl; // 9가 아닌 100이 출력된다.

/**************** Topic 5 ****************/
	// 포인터 연산
	cout << *ptr << " " << *(ptr + 1) << endl; // 9+1=10이 아니라 7이 출력된다.

/**************** Topic 6 ****************/
	// 구조체 안에 array를 들어있는 경우.
	MyStruct ms;
	cout << ms.array_[0] << endl; // 10 출력.

	cout << sizeof(ms.array_) << endl; // 20 bytes 출력.
	doSomething(ms); // 함수 안에서도 20 bytes 출력. 

	return 0;
}