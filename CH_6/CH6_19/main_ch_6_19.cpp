/*
6.19�� "���� �����Ϳ� ���� ������ �迭"

- int **ptr, int ***ptr(����), int ****ptr(����), ...

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
	// ������ ���� �����̰� �ּҸ� ������ �����Ƿ� �����Ϳ� ���� �����͸� ���� �� �ִ� = ���� ������.
	int *ptr = nullptr;
	int **ptrptr = nullptr;

	int value = 5;

	ptr = &value;
	ptrptr = &ptr;

	// cout << ������ �ּ� << ������ << ������ ���� �ڽ��� �ּ� << endl;
	cout << ptr << " " << *ptr << " " << &ptr << endl;          // A. 
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl; // A. 
	cout << **ptrptr  << endl; // = *(*ptrptr)					// A. 
	
/**************** Topic 2 ****************/
	// ���� �����͸� Ȱ���� 2���� ����� ���� �޸� �Ҵ����� ����. 
	// �ʱ��� �ڵ�.
	const int row = 3;
	const int col = 5;

	const int s2da[row][col] = // s2da = static 2D array
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	}; // <-- ; ���̱�

	// int *r1 = new int[col]; // �ʱ�ȭ�� �� ���־��� ������ ������ ���� ����ִ�.
	int *r1 = new int[col] {1, 2, 3, 4, 5};
	int *r2 = new int[col] {6, 7, 8, 9, 10};
	int *r3 = new int[col] {11, 12, 13, 14, 15};
	
	cout << r1 << " " << *r1 << endl; // *r1 = 1
	cout << r2 << " " << *r2 << endl; // *r2 = 6
	cout << r3 << " " << *r3 << endl; // *r3 = 11

	// ���� �����͸� ����ؼ� int �������� array�� �����.
	int **rows = new int*[row] {r1, r2, r3};
	cout << row << " " << *rows << " "  << **rows << endl;
	
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; c++)
			cout << rows[r][c] << " ";
		cout << endl;
	}

	// delete���� ������ �߿��ϴ�.
	delete[] r1; // <-- delete r1�� ����ϸ� �޸� ���� ���� ������ �߻��ϹǷ� ����.
	delete[] r2;
	delete[] r3;
	delete[] rows;

/**************** Topic 3 ****************/
	// ����� �ڵ�.
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
	/* ���� �����͸� ������� �ʴ� 2���� ��� ���� = 1���� ���� �迭�� �̿��Ͽ� 2���� ��� ����.
	   --> �����Ϳ� �����͸� ����ϴ� ���� �δ㽺����Ƿ�; ��κ��� ���п��� �̷��� ����Ѵ�. */

	int *matrix = new int[row*col];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; c++)
			matrix[c + col*r] = s2da[r][c]; // 1���� array 3���� 2���� arrayó�� ����.
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