/*
6.19강 "다중 포인터와 동적 다차원 배열"

- int **ptr, int ***ptr(삼중), int ****ptr(사중), ...

- de-reference pointer to int to get int value.
  int* ptr = &value;
  cout << *ptr; 

- first de-reference to get pointer to int, second dereference to get int value.
  int** ptrptr = &ptr; 
  cout << **ptrptr; 
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// 포인터 또한 변수이고 주소를 가지고 있으므로 포인터에 대한 포인터를 만들 수 있다 = 이중 포인터.
	int *ptr = nullptr;
	int **ptrptr = nullptr;

	int value = 5;

	ptr = &value;
	ptrptr = &ptr;

	// cout << 변수의 주소 << 역참조 << 포인터 변수 자신의 주소 << endl;
	cout << ptr << " " << *ptr << " " << &ptr << endl;          // A. 
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl; // A. 
	cout << **ptrptr  << endl; // = *(*ptrptr)					// A. 
	
/**************** Topic 2 ****************/
	// 이중 포인터를 활용한 2차원 행렬을 동적 메모리 할당으로 구현. 
	// 초급자 코드.
	const int row = 3;
	const int col = 5;

	const int s2da[row][col] = // s2da = static 2D array
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	}; // <-- ; 붙이기

	// int *r1 = new int[col]; // 초기화를 안 해주었기 때문에 쓰레기 값이 들어있다.
	int *r1 = new int[col] {1, 2, 3, 4, 5};
	int *r2 = new int[col] {6, 7, 8, 9, 10};
	int *r3 = new int[col] {11, 12, 13, 14, 15};
	
	cout << r1 << " " << *r1 << endl; // *r1 = 1
	cout << r2 << " " << *r2 << endl; // *r2 = 6
	cout << r3 << " " << *r3 << endl; // *r3 = 11

	// 이중 포인터를 사용해서 int 포인터의 array를 만든다.
	int **rows = new int*[row] {r1, r2, r3};
	cout << row << " " << *rows << " "  << **rows << endl;
	
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; c++)
			cout << rows[r][c] << " ";
		cout << endl;
	}

	// delete에는 순서가 중요하다.
	delete[] r1; // <-- delete r1를 사용하면 메모리 누수 등의 오류가 발생하므로 주의.
	delete[] r2;
	delete[] r3;
	delete[] rows;

/**************** Topic 3 ****************/
	// 고급자 코드.
	int **matrix = new int*[row];

	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; c++)
			matrix[r][c] = s2da[r][c];
	}

	// print all elements
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; c++)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	// delete
	for (int r = 0; r < row; ++r)
		delete[] matrix[r];

	delete[] matrix;

/**************** Topic 4 ****************/
	/* 이중 포인터를 사용하지 않는 2차원 행렬 구현 = 1차원 동적 배열을 이용하여 2차원 행렬 구현.
	   --> 포인터에 포인터를 사용하는 것이 부담스러우므로; 대부분의 수학에서 이렇게 사용한다. */

	int *matrix = new int[row*col];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; c++)
			matrix[c + col*r] = s2da[r][c]; // 1차원 array 3개를 2차원 array처럼 구현.
	}

	// print all elements
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; c++)
			cout << matrix[c + col * r] << " ";
		cout << endl;
	}
	
	delete[] matrix;
//
	return 0;
}