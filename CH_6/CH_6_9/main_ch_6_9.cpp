/*
6.9�� "������ ����� �迭 �ε���(Indexing)"
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
//	- double�� ���: 8 bytes �� �̵�.
//	double value = 7.0;
//	double *ptr = &value;
//
//	- short�� ���: 2 bytes �� �̵�.
//	short value = 7;
//	short *ptr = &value;
//	*/
//
//	// uintptr_t: unsigned int pointer type
//	cout << uintptr_t(ptr) << endl; // = cout << (int)ptr << endl; 10���� �ּ�.
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
//	// pointer ����	
//	cout << uintptr_t(ptr - 2) << endl; // 3799804 = Base -8
//	cout << uintptr_t(ptr - 1) << endl; // 3799808 = Base -4
//	cout << uintptr_t(ptr) << endl;		// 3799812 = Base
//	cout << uintptr_t(ptr + 1) << endl; // 3799816 = Base +4
//	cout << uintptr_t(ptr + 2) << endl; // 3799820 = Base +8
//	// --> data type�� ���� �� ĭ�� �̵�; int value�̹Ƿ� 4 bytes �� �̵�.
//
///**************** Topic 3 ****************/
//	// array�� ����ϴ� ���.
//	int array[] = { 9, 7, 5, 3, 1 };
//
//	cout << array[0] << " " << (uintptr_t)&array[0] << endl; // 9 11926552
//	cout << array[1] << " " << (uintptr_t)&array[1] << endl; // A. 
//	cout << array[2] << " " << (uintptr_t)&array[2] << endl; // A. 
//	cout << array[3] << " " << (uintptr_t)&array[3] << endl; // A. 
//	// --> array������ 4 bytes �� ������ �̿����ִ�.
//
//	// ���� ������ for ������ �ۼ�.
//	for(int i = 0; i < 5; ++i)
//		cout << array[i] << " " << (uintptr_t)&array[i] << endl;
//
//	// ���� ������ pointer�� �̿��Ͽ� �ۼ� --> array�� ����� ���� �ּҰ� �����ϴ�!
//	int *ptr = array;
//	for (int i = 0; i < 5; ++i)
//		cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;  // 9 11926552 ...
//
/**************** Topic 4 ****************/
	// ���ڿ��� ���.
	char name[] = "Jack Jack"; // ���� array ���� pointer�̴�.
	const int n_name = sizeof(name) / sizeof(char); // ���� ���� ã�� ��.
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