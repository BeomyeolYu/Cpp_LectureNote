/*
6.9강 "포인터 연산과 배열 인덱싱(Indexing)"
*/

#include <iostream>
using namespace std;

int main()
{
///**************** Topic 1 ****************/
//	int value = 7;
//	int *ptr = &value;
//
//	/* 
//	- double인 경우: 8 bytes 씩 이동.
//	double value = 7.0;
//	double *ptr = &value;
//
//	- short인 경우: 2 bytes 씩 이동.
//	short value = 7;
//	short *ptr = &value;
//	*/
//
//	// uintptr_t: unsigned int pointer type
//	cout << uintptr_t(ptr) << endl; // = cout << (int)ptr << endl; 10진수 주소.
//
//	// Quiz.
//	cout << value << endl;  // A. 
//	cout << &value << endl; // A. 
//	cout << ptr << endl;    // A. 
//	cout << *ptr << endl;   // A. 
//	cout << &ptr << endl;   // A. 
//
//	cout << uintptr_t(ptr) << endl;    // A. 
//	cout << uintptr_t(&ptr) << endl;   // A. 
//
///**************** Topic 2 ****************/
//	// pointer 연산	
//	cout << uintptr_t(ptr - 2) << endl; // 3799804 = Base -8
//	cout << uintptr_t(ptr - 1) << endl; // 3799808 = Base -4
//	cout << uintptr_t(ptr) << endl;		// 3799812 = Base
//	cout << uintptr_t(ptr + 1) << endl; // 3799816 = Base +4
//	cout << uintptr_t(ptr + 2) << endl; // 3799820 = Base +8
//	// --> data type에 따라 한 칸씩 이동; int value이므로 4 bytes 씩 이동.
//
///**************** Topic 3 ****************/
//	// array에 사용하는 경우.
//	int array[] = { 9, 7, 5, 3, 1 };
//
//	cout << array[0] << " " << (uintptr_t)&array[0] << endl; // 9 11926552
//	cout << array[1] << " " << (uintptr_t)&array[1] << endl; // A. 
//	cout << array[2] << " " << (uintptr_t)&array[2] << endl; // A. 
//	cout << array[3] << " " << (uintptr_t)&array[3] << endl; // A. 
//	// --> array에서도 4 bytes 씩 나란히 이웃해있다.
//
//	// 같은 연산을 for 문으로 작성.
//	for(int i = 0; i < 5; ++i)
//		cout << array[i] << " " << (uintptr_t)&array[i] << endl;
//
//	// 같은 연산을 pointer를 이용하여 작성 --> array를 사용한 경우와 주소가 동일하다!
//	int *ptr = array;
//	for (int i = 0; i < 5; ++i)
//		cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;  // 9 11926552 ...
//
/**************** Topic 4 ****************/
	// 문자열의 경우.
	char name[] = "Jack Jack"; // 정적 array 또한 pointer이다.
	const int n_name = sizeof(name) / sizeof(char); // 원소 개수 찾는 법.
	char *ptr = name;

	// Quiz.
	cout << "Q1. " << name << endl;       // A. 
	cout << "Q2. " << name[0] << endl;    // A. 
	cout << "Q3. " << &name << endl;	  // A. 
	cout << "Q4. " << &name[1] << endl;   // A. 
	cout << "Q5. " << &(name[0]) << endl; // A. 
	cout << "Q6. " << ptr << endl;	      // A. 
	cout << "Q7. " << &ptr << endl;	      // A. 
	cout << "Q8. " << *ptr << endl;	      // A. 

	for (int i = 0; i < n_name; ++i)
	{
		cout << *(ptr + i); 
	}
		
	return 0;
}