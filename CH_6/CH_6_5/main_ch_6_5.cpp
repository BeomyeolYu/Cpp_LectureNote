/*
6.5강 "정적 다차원 배열(Multi-dimensional Array)"

- 컴퓨터 속의 메모리는 1차원적인 주소를 가지고 있다 --> 단독 주택이 쭉 늘어서 있는 모양.
- 그러나 프로그래밍을 하다 보면 아파트도 필요하다 --> 1차원적인 메모리 구조를 n차원 메모리 구조처럼 사용할 수 있음.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// 1차원 배열을 2차원 배열인 것처럼 생성하는 함수.
	const int num_rows = 3;
	const int num_columns = 5;

	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
			cout << '[' << row << ']' << '[' << col << ']' << '\t';
		cout << endl;
	}
	cout << endl;

/**************** Topic 2 ****************/
	// 초기화하는 방법 (1-1) - 블록을 활용.
	int array[num_rows][num_columns] = //: row-major 방식 <-> major-row 방식 --> 수학적으로 어떻게 사용할 것인지 개념적인 문제이고 실제로는 메모리가 일렬로 쭉 늘어져있다.
	{
		{1, 2, 3, 4, 5},	  // row 0
		{6, 7, 8, },		  // row 1 <-- 채우지 않은 것은 0으로 채워진다.
		{11, 12, 13, 14, 15}, // row 2
	}; // <-- ;을 잊지 않도록 주의.
	 
	// 초기화하는 방법 (1-2) - 모든 element를 0으로 초기화.
	int array_[num_rows][num_columns] = { 0 }; // <-- { 5 };로 할당할 경우 1st element만 5로 할당되고 나머지는 0으로 채워진다.

	// 초기화하는 방법 (2) - 일일이 초기화.
	array[0][0] = 1;
	array[0][0] = 2;
	// ...

	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
		cout << array_[row][col] << '\t';
		cout << endl;

		//cout << (int)&array[row][col] << '\t'; // <-- 주소를 보면 4 bytes씩 떨어진 1차원임을 확인할 수 있다.
		//cout << endl;
	}
	cout << endl;

/**************** Topic 3 ****************/
	// 다차원 array.
	int array_3 [5][4][3];

	return 0;
}