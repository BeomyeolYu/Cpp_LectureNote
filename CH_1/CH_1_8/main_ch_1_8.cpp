/*
1.8�� "�����ڿ��� ù ����"
- ���ͷ�(Literal)
- �ǿ�����(Operand)
- ���� ������(unary operator)
- ���� ������(binary operator)
- ���� ������(ternary operator)
*/
#include <iostream>

using namespace std;

int main()
{
	int x = 2; // x is a variable. (�޸� �ּҸ� ������ ����.)
	// 2 is a literal. ���� ������. �޸� ������ ������ ���� �ƴ�.
	// ��ȣ(=)�� assignment, ���� ������.

	cout << "Hello, world" << endl;
	// ���ڿ��� literal��.

	cout << 1 + 2 << endl;
	// +�� ������(operator)��.
	// 1�� literal�̰� 2�� literal�̰� 1+2�� ǥ����(expression)��.
	// 1�� 2�� ���� ������ ���ϴ� ����� �ǿ�����(Operand)��� Ī��.
	// Unary operator:  Ex) -2 �Ǵ� -x, ������ �ٲٴ� ������.
	// Binary operator: Ex) 1 + 2, �ǿ����ڰ� 2��.

	int y = (x > 0) ? 1 : 2;
	// ���� ������(Conditional operator)�� C++ ����� ������ ���� ��������.
	// ���� �����ڴ� �� �� �бⰡ ��� ���ԵǾ� ����.
	// ( )���� ������ ���̸� ������ ����, �����̸� �������� ����.
	cout << y << endl;

	return 0;
}
