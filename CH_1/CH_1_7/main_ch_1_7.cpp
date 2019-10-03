/*
1.7�� "���� ����(Local Scope)"
*/
#include <iostream>

using namespace std;

int main()
{
	int x(0); // or int x = 0; x��� �޸𸮰� ������ 0�̶�� ������ �ʱ�ȭ�ȴ�.
//  int x = 1; ���� �߻�. 'x': redefinition; multiple initialization.
	cout << x << " " << &x << endl; // &�� �޸��� �ּ� ���.

	{
		int x = 0; // ���� ������ �ٸ� �޸𸮿� ���� �ĺ���. 101ȣ�� 102ȣ�� ������ ���� ���� �ִ� �Ͱ� ����.
		cout << x << " " << &x << endl;
		// Local Scope({})�� ������ ���� ���� x�� �� �� ����.
	}

	{
		int x = 1; 
		cout << x << " " << &x << endl;
	}

	cout << x << " " << &x << endl;

	{
		x = 1; // ���ο� x�� �������� �ʰ� x�� ���� �Ҵ��� ���.
		// �� ��쿡�� �״�� ���� �޸�(�ּ�)�� ���� ������.
	}

	cout << x << " " << &x << endl;

	return 0;
} //���� �߰�ȣ�� �Ѿ�� x�� �������. = ���� ����(Local Scope)


// Quiz�� ���: �Լ����� ����� �޸𸮿� ���� �� �ȿ����� ��ȿ��.
/*
void doSomething(int x)
{
	x = 123;
	cout << x << " " << &x << endl; // #2
	// ����: �ּҴ� A, ���� 123. (����)
	// ����: �ּҴ� B, ���� 123.
}

int main()
{
	int x = 0;

	cout << x << " " << &x << endl; // #1
	// ����: �ּҴ� A, ���� 0. (����)
	// ����: �ּҴ� A, ���� 0.
	doSomething(x);

	cout << x << " " << &x << endl; // #3
	// ����: �ּҴ� A, ���� 123. (����)
	// ����: �ּҴ� A, ���� 0.

	return 0;
}
*/
