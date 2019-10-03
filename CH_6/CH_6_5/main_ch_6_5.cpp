/*
6.5�� "���� ������ �迭(Multi-dimensional Array)"

- ��ǻ�� ���� �޸𸮴� 1�������� �ּҸ� ������ �ִ� --> �ܵ� ������ �� �þ �ִ� ���.
- �׷��� ���α׷����� �ϴ� ���� ����Ʈ�� �ʿ��ϴ� --> 1�������� �޸� ������ n���� �޸� ����ó�� ����� �� ����.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// 1���� �迭�� 2���� �迭�� ��ó�� �����ϴ� �Լ�.
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
	// �ʱ�ȭ�ϴ� ��� (1-1) - ����� Ȱ��.
	int array[num_rows][num_columns] = //: row-major ��� <-> major-row ��� --> ���������� ��� ����� ������ �������� �����̰� �����δ� �޸𸮰� �Ϸķ� �� �þ����ִ�.
	{
		{1, 2, 3, 4, 5},	  // row 0
		{6, 7, 8, },		  // row 1 <-- ä���� ���� ���� 0���� ä������.
		{11, 12, 13, 14, 15}, // row 2
	}; // <-- ;�� ���� �ʵ��� ����.
	 
	// �ʱ�ȭ�ϴ� ��� (1-2) - ��� element�� 0���� �ʱ�ȭ.
	int array_[num_rows][num_columns] = { 0 }; // <-- { 5 };�� �Ҵ��� ��� 1st element�� 5�� �Ҵ�ǰ� �������� 0���� ä������.

	// �ʱ�ȭ�ϴ� ��� (2) - ������ �ʱ�ȭ.
	array[0][0] = 1;
	array[0][0] = 2;
	// ...

	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
		cout << array_[row][col] << '\t';
		cout << endl;

		//cout << (int)&array[row][col] << '\t'; // <-- �ּҸ� ���� 4 bytes�� ������ 1�������� Ȯ���� �� �ִ�.
		//cout << endl;
	}
	cout << endl;

/**************** Topic 3 ****************/
	// ������ array.
	int array_3 [5][4][3];

	return 0;
}