/*
7.4�� "�ּҿ� ���� �μ� ����(Passing Arguments by Address)" - Call by Address

- ref�� ���� ���� ���ٰ� ������ ���� ������ C ��� �ڵ������� �ݵ�� �ʿ�������,
  array���� �Ҽ��� �����͸� ���� ��, ������ ���ΰ� ����Ǵ� �ͺ��� �ּҰ� ����Ǵ� ���� ȿ�����̹Ƿ� ���ȴ�.
*/

#include <iostream>
using namespace std;

// foo(5)�� ���, const�� ��ġ�� ������� �ּҸ� �־��־�� �Ѵ�.
/* void foo(const int *ptr)
   void foo(int * const ptr) */
void foo(int *ptr)
{
	cout << *ptr << " " << ptr << endl; // *ptr�� de-referencing, ptr�� adress ���� ����!
	cout << "In the func. " << &ptr << endl; // ������ ���� ���� �����̹Ƿ� �Լ� �������� �ּҰ� �ٸ���.
}
// �ֳ��ϸ�
typedef int* pint;  // typedef�� �̿��Ͽ� int*�� �ϳ��� ������ �����Ͽ� ���������� �� �� �ִ�.
void foo2(pint ptr) // �̶�, ptr�� '�ּҶ�� �ϳ��� ��'��'���� ���� ����'�� ���� Ȯ���� �� �ִ�.
{
	// ��, �ּҶ�� Ư���� ���� ��� ���� �� �ϳ��� ������. �ܼ��� �ּҰ��� ���簡 �� ���̴�.
}

// �����͸� �̿��ؼ� ref�� �����ϰ� �Լ��� output�� ��ó�� ����� �� �ִ�. --> �ǿ����� ���鿡���� ref�� �� ����.
void getSinCos(double degrees, double *sin_out, double *cos_out)
{
	*sin_out = 1.0; // <-- de-referencing ���� �ٲ��־�� �Ѵ�.
	*cos_out = 2.0;
	/* "����" ��ĩ�ϸ� ref�� �����͸� �����ϰ� ������ �� �ִ�.
	    �׷��� ref�� ������ �ּҸ� ����ϴ� �ݸ� �����ʹ� ���� ���� �����̴�. */
	cout << sin_out << " " << cos_out << endl;   // cout << &sin << " " << &cos << endl;�ʹ� �����ϴ�.
	cout << &sin_out << " " << &cos_out << endl; // �׷��� ������ ���� ��ü�� �ּҴ� �ٸ���.
}

// Call by Address�� ����: array�� �Ķ���ͷ� ����� �� & const ���.
void arrayAddress(const int *arr, const int *ptr, int length)
{
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;

	arr[0] = 1.0; // <-- ���ȣ�� de-referencing�� �ǹ��ϸ� const�� �ٿ����Ƿ� �Ұ����ϴ�.
	// = *ptr = 1
}

int main()
{
/**************** Topic 1 ****************/
	int value = 5;
	cout << value << " " << &value << endl;

	int *ptr = &value;
	cout << "In the main " << &ptr << endl; // <-- ptr ����(=������ ����)�� �ּҰ� func.�� main���� �ٸ���.

	foo(ptr);    // ��� 1.
	foo(&value); // ��� 2.

/**************** Topic 2 ****************/
	// �Ѱ��� 1.
	foo(5); // �ּҸ� �־��־�� �ϹǷ� � ��쿡�� �Ұ����ϴ�. <-- ref���� ������.

/**************** Topic 3 ****************/
	// �Ѱ��� 2.
	// �Լ��� ����� ���� �ּҷ� �ٲ㼭 �־���� �Ѵ�.
	double degrees = 30;
	double sin, cos;
	getSinCos(degrees, &sin, &cos); // <-- �ּҸ� �Է��ؾ� �Ѵ�.

	cout << sin << " " << cos << endl;   // <-- �Լ� ���ο��� �ٲ��� ���� �ܺο��� ������ ��ģ��.
	cout << &sin << " " << &cos << endl; // <-- �����Ϳ� ref�� ������! �����ʹ� ������ ������ �ּҰ� �ٸ���.

	return 0;
}