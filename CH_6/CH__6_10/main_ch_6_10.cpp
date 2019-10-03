/*
6.10강 "C 언어 스타일의 문자열 심볼릭(symbolic) 상수"

- 문자열은 기본적으로 문자의 배열(array)이며, array는 pointer와 호환이 된다.
- 컴파일러가 우리를 햇갈리게 하는 경우에 대해서 알아본다.
*/

#include <iostream>
using namespace std;

const char* getName()
{
	return "Jack Jack"; // = Topic 2
}

int main()
{
/**************** Topic 1 ****************/
	char name_ [] = "Jack Jack";
	cout << name_ << endl; // A.

	// A. array와 pointer는 호환이 되니까 *만 붙여서 사용할 순 없나요?
    //char *name = "Jack Jack"; // 오류 발생: "Jack Jack"은 literal이므로 주소를 담는 pointer에는 담을 수 없다.
	                            // --> 그럼에도 불구하고 "Jack Jack"을 기호적인 상수로 사용할 수 있다.
	const char *name = "Jack Jack"; // const를 붙여줌으로써 컴파일러가 메모리를 없애지 않고 꽉 붙잡고 있는다.
	cout << name << endl; // A.

/**************** Topic 2 ****************/
	// 예외적인 특성 (1): 이름만 다르고 값은 경우.
	const char *name1 = "Jack Jack";
	const char *name2 = "Jack Jack"; // 

	cout << (uintptr_t)name1 << endl; // 주소: 2634024
	cout << (uintptr_t)name2 << endl; // 주소: 2634024
	/* 분명히 *name과 *name2 다르게 선언했는데 주소가 같다.
	   --> 둘 다 "Jack Jack"으로 동일하므로 컴파일러가 방을 하나만 내어준다. */

/**************** Topic 3 ****************/
	// 예외적인 특성 (2): 함수의 return 타입에 문자열을 넣은 경우.
	const char *name3 = getName();
	const char *name4 = getName(); // 동일한 함수 호출.

	cout << (uintptr_t)name3 << endl; // 주소: 2634024
	cout << (uintptr_t)name4 << endl; // 주소: 2634024
	// --> 심지어 Topic 2와도 주소가 같다!

/**************** Topic 4 ****************/
	// 예외적인 특성 (2-1): 문자 포인터의 특성.
	int int_arr[5] = { 1, 2, 3, 4, 5 }; // int array.
	char char_arr[] = "Hello, World!";  // 문자열 array.
	const char *name5 = "Jack Jack";	// pointer는 array와 호환 가능.

	cout << int_arr << endl;  // 00CFF9FC	   : int array는 주소가 출력.
	cout << char_arr << endl; // Hello, World! : 문자열 array는 문자가 출력.
	cout << name5 << endl;	  // Jack Jack	   : pointer는 문자가 출력.
	/* --> cout에서는 문자열 포인터를 특수하게 표현하기 때문에 나온 결과.
	   --> cout이 cout << name5 << endl;에서 *name5의 주소를 출력하는 것이 아니라 
	       null character를 만날 때 까지 문자열을 계속 출력한다. */

/**************** Topic 5 ****************/
	// 예외적인 특성 (2-2): 문자 포인터의 특성.
	char c = 'Q';
	cout << &c << endl;  // Topic 4와 동일한 이유로 &c의 주소를 출력하는 것이 아니라 문자열로 간주한다.
	cout << *&c << endl; // de-referencing을 하면 정상적으로 'Q'를 출력한다.

	return 0;
}