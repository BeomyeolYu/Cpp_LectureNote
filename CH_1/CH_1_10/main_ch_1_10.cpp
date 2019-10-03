/*
1.10�� "����(Declaration)�� ����(Definition)�� �и�"

- ���� ���α׷��Ӱ� �Ǳ� ���� �ڵ� ���� ���. (Ex, �ټ��� �Լ��� �����Ͽ� main �Լ��� ���� ���.)
*/
#include <iostream>

using namespace std;

// �Լ��� �ּ����� ������ ��� �ִ� prototype�� �̿��ؼ� ������ �����´�.
int add(int a, int b); // ���� ����(forward declaration).
int subtract(int a, int b);

int main()
{
	cout << add(1, 2) << endl;
	cout << subtract(1, 2) << endl;
	/* �Լ� �̸� ������ ���콺 ��Ŭ�� �� Go To Definition(F12)�� ������ ��� Ȯ�� ����.
	 ������Ʈ�� ���� ���Ϸ� �̷���� ��쿡�� ��Ŭ�� �� Peek Definition(Alt+F12)�� ����.*/
	return 0;
}

// definition
int add(int a, int b) // prototype
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

int subtract(int a, int b)
{
	return a - b;
}

