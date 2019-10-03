/*
6.13�� "�����Ϳ� const"

- �Ϲ� ������ const�� �ٿ� �Ϲ� ����� ����� �� �ֵ��� �����Ϳ��� const�� ����� �� �ִ� (�������� ���̰� �ִ�).
- �Լ� �Ķ���ͷ� ����� �� �� �Ǵ� �ּҸ� �ٲ��� ����� ������ ǥ������ ���ȴ�.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// pointer�� �⺻ ���.
	int value = 5;
	int *ptr = &value; // value�� �ּҸ� ptr�� �־��־���.
	*ptr = 6; // �׸��� de-referencing�� �ؼ� value ���� �ٲ��� ���� �ִ�.

	cout << *ptr << endl;  // A. 
	cout << value << endl; // A.

/**************** Topic 2 ****************/
	// ��� const�� ���̴� ���.
	const int value_1 = 5;
	const int *ptr_1 = &value_1; 
	// *ptr_c = 6; // �׷��� de-referencing���� value�� ���� �Ҵ����� ���� ����.
	// �׷����� value�� ���� �� �ٲ۴ٰ��ؼ� �ּҸ� �� �������� ���� �ƴϴ�.

	cout << *ptr_1 << endl; // A.

/**************** Topic 3 ****************/
	// �����Ϳ��� const�� ���̴� ���.
	int value_2 = 5;
	const int *ptr_2 = &value_2; 
	// *ptr_c = 6; // de-referencing���� value�� ���� �Ҵ����� ���� ������
	value_2 = 6;   // value_2�� 6���δ� �ٲ� �� �ִ�.

	// �ٲ� value_2�� ���� �������� ������ *ptr_2�� 6�� ��µȴ�.
	cout << value_2 << endl; // A. 
	cout << *ptr_2 << endl;  // A. 

/**************** Topic 4 ****************/
	int value1 = 5;
	const int *ptr1 = &value1; /* ���� ����Ű�� �ִ� �ּҿ� ��� �ִ� ���� �ٲ��� �ʰڴٴ� ������ ǥ������,
							       ptr1�� ����Ǵ� �ּҰ��� �ٲ��� �ʰڴٴ� �ǹ̴� �ƴϴ�. */
	// *ptr1 = 7;

	int value2 = 6;
	ptr1 = &value2; // &value1���� ������ �����Ϳ� �ٸ� �ּҰ�(&value2)�� �ִ� ���� �ȴ�.
	// *ptr1 = 8;   // �׷��ٰ� �� ������(de-referencing)�� ���� �ٲٴ� ���� �ȵȴ�.

/**************** Topic 5 ****************/
	// ptr�� ����Ǵ� �ּҰ��� �ٲ��� �ʰڴٴ� ������ �ǹ��� const ���: int *const
	int value3 = 5;
	int *const ptr3 = &value3;

	*ptr3 = 10; // ���� ������� �ٸ��� de-referencing�� �����ϴ�.
	cout << *ptr3 << endl; // 10 ���.

	int value4 = 8;
	// ptr3 = &value4; // �׷��� ptr3�� ����� �ּҸ� �ٲ� ���� ����.

/**************** Topic 6 ****************/
	// const int *const�� ��� de-referencing�� �ٸ� �ּ� �� �־��ֱ� ��� �ȵȴ�.
	int value5 = 5;
	const int *const ptr5 = &value5; // const�� �����Ͽ��� ������ �ʱ�ȭ�� ������ ���� �߻�.

	return 0;
}