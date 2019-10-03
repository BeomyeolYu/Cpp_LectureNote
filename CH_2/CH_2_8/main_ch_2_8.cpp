/*
2.8�� "���ͷ� ���(literal constants)"

1. ������?
- ������, �����͸� �ӽ÷� ������ �޸� ������ �ǹ��Ѵ�.
- ������ ����� ���� �ʱ�ȭ, ���� �� �ʱ�ȭ ��� �����Ѵ�.
  (����� const ������ ��, ����� ���ÿ� �ʱ�ȭ�ؾ� �Ѵ�.)
- ������ ���α׷��� ����� ��, ����� �����Ͱ� �������.
- ���� ������ ������, �Ǽ���, ������, ���ڿ������� ������� �Ѵ�.
- tip. �����Ͷ�, ������ �ӽ÷� ����� ���� �����Ͷ�� �Ѵ�. 
  ����, ������ �ʱ�ȭ���� �ʾ� �����Ͱ� ������� �ʴ´ٸ�, ������ ���� ����.
- ������ �ʱ�ȭ�ϰ� ���� �����ǰ� �����ϴ�. 
  ������ �� �״�� ���Ƿ� ����� �޸� ������ ������ �����Ƿ�, �� �ӿ� ����Ǵ� ������ ���� ������ ��ȯ�� �����ϴ�.

2. �����?
- ����� ��ȯ���� �ʴ� ���� ���Ѵ�. ��, �ʱ�ȭ�� �Ǹ�, �ٽ� �����ǰ� �Ұ����ϴ�.
- ����� ��ȯ���� �ʴ� �� (pi, 3.14~)�� �����Ͽ� �ݺ������� ����ϱ� ���� ���δ�.
- ����� �� ������ �ִ�. literal ����� symbolic ����� �ִ�.
- ����� �ڷ����� �Ű��� ��� �Ѵ�.
- literal ����� ���� �״�� �ǹ̰� �־, �̸��� ���� ���ǵ��� ���� ����� ���Ѵ�.
- symbolic �����, ����� ��ȣȭ�Ͽ� ����ó�� �̸��� ���� ���� ����� ���Ѵ�.
*/
#include <iostream>

int main()
{
	using namespace std;

	/******* Topic 1 *******/
	float pi = 3.14f; // '3.14'�� ���� ���ڸ� ��� ǥ���ϴ� ����� literal�̶�� ��.
	/* 
	tip. float pi = 3.14�� ���� f�� �� ���̸� double�� ���ֵ� -> double�� float�� casting �ż� pi�� ���ٴ� ��.
	f ��ſ� u�� ���̸� unsigned, l(�Ǵ� L)�� ���̸� long double��� �ǹ�.
	�׷��� casting�� ��Ȯ�ϰ� ǥ�����ִ� ���� ����. EX) int i = 12323u ==> int i = (unsigned int)12324
	*/

	/******* Topic 2 *******/
	/*
	Decimal(10����)		: 0, 1, 2, 3, 4, 5, 6, 7, 8,  9,  10
	Octal(8����)			: 0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13
	Hexadecimal(16����)	: 0, 1, 2, 3, 4, 5, 6, 7, 8,  9,  A,  B, C, D, E, F, 10
	*/

	// Ex.1) Octal
	int x = 012;	   // 8������ ǥ���ϰ� ���� ��쿡�� �տ� 0�� �ٿ��� ��. 
	cout << x << endl; // �Ǽ��� �տ� 0�� ���� ���, 12�� ��µǴ� ���� �ƴ϶� 8�������� 12�� �ش�Ǵ� 10���� 10�� ��µ�.

	// Ex.2) Hexadecimal
	int y = 0xF;	// 16������ ǥ���ϰ� ���� ��쿡�� �տ� 0x�� ����. 
	cout << y << endl; 	// 16�������� F�� �ش�Ǵ� 10���� 15�� ��µ�. (cout�� 10���� ����� �⺻)

	/* 
	10������ ������� ���� ������������ 2������ ���α׷��� �ؾ� �� ���� ����.
	�̶� 2�������ٴ� 16������ ǥ���ϴ� ���� ���ϹǷ� ���� ����.
	Ex, 0011 1010 1111 1111(2����) = 3A7F(16����)
 	*/

	/******* Topic 3 *******/
	/* C++ 14�� ���� �߰��� Binary Literals
	2������ �ٷ� �Է��� �����ϸ�, ��������ǥ�� �����Ͽ� �ڵ� ���� �� ���ϰ� �Ǿ���. */
	int z = 0b1010'1111'1010;
	cout << z << endl;

	/******* Topic 4 *******/
	/* Magic number ��� �����ϱ� -> symbolic constants �̿�. */

	// Case 1.
	int num_items = 123;
	int price = num_items * 10; // 10 is empirical value. (=Magic number).
	// 10�� ���� ������ �ּ����� ���´� �ϴ��� Magic number�� �ڵ忡 ���ܳ������� ��������� ������ ���� ����.

	// Case 2.
	const int price_per_item_ = 10; //symbolic constants(��ȣ�� ���)
	int num_items_ = 123;
	int price_ = num_items_ * price_per_item_;

	return 0;
}