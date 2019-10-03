/*
6.15�� "������ const"

- ref+const�� pointer+const���� �� �� ���ϰ� ����� �� �ִ�.  
*/

#include <iostream>
using namespace std;

void doSomething(int& x) // ref�� �Լ��� �Է����� ���.
{
	cout << x << endl;
}

void doSomething_const(const int& x) // const ref�� �Է����� ���.
{
	cout << x << endl;
}

int main()
{
/**************** Topic 1 ****************/
	// Case 1: �Ұ�
	const int x1 = 5;
	int &ref_x1 = x1;

	// Case 2: ���
	const int x2 = 5;
	const int &ref_x2 = x2;

	// Case 3: ���
	int x3 = 5;
	const int &ref_x3 = x3;
	const int &ref = ref_x3;

/**************** Topic 2 ****************/
	// Case 1: �Ұ�
	int &ref1 = 3 + 4; // ref���� �ݵ�� �ּҰ� �Ҵ�Ǿ�� �Ѵ�.

	// Case 2: ���
	const int &ref2 = 3 + 4; // �׷��� const�� ���̸� �����ϴ�.
	cout << ref2 << endl;  // A. 
	cout << &ref2 << endl; // A. 

/**************** Topic 3 ****************/
	// Ư�� �Լ��� �Ķ���ͷ� ����� �� ���ϴ�.
	int a = 1;
	
	doSomething(a);
	doSomething(1); // const�� �ƴϸ� ������ �Է¹��� �� �ִ�.

	doSomething_const(a);
	doSomething_const(1);
	doSomething_const(a + 3);
	doSomething_const(3 * 4); // const�� ���̸� literal�� ���� �Է� ����.

	return 0;
}