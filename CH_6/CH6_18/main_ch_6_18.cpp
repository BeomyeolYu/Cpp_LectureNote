/*
6.1�� "���̵�(void) ������"

- Generic(��������) pointer��� �θ���.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	int   i    = 5;
	float f    = 3.0;
	char  c    = 'a';
	void  *ptr = nullptr; // void pointer�� nullptr �����ͷ� �ʱ�ȭ.

	// void pointer�� �پ��� Ÿ���� ��� �־ ������ ���� --> �ּ��̱� ������.
	ptr = &i;
	ptr = &f;
	ptr = &c;
	// �Ѱ�: void pointer�� �ּҸ� ������ �� ������ Ÿ���� �� ����� ���� --> �ּ��̱� ������.

/**************** Topic 2 ****************/
	// int Ÿ���� pointer�� �����ϸ� ������ ������ �����ϴ�.
	int *ptr_i = &i;
	cout << ptr_i << endl;	   // A. 
	cout << ptr_i + 1 << endl; // A. 

	// �׷��� void pointer�� ������ �Ұ����ϴ�. �ֳ��ϸ� +1�� �� �� �� Byte�� ���ؾ��ϴ��� �� �� ���� �����̴�.
	// cout << ptr + 1 << endl;

/**************** Topic 3 ****************/
	// &f�� ptr�� ������ �ּ��� ���� Ȯ���� �� �ִ�.
	cout << &f << " " << ptr << endl;

	// �׷��� � �ּ��̰� Ư���� ���� �ִٴ� ����� �� �� ������, ���� �������� �� �� ���� ������ �������� �Ұ����ϴ�.
	cout << *ptr << endl;

	// �ε����ϰ� �ʿ��� ��쿡 casting�� �ϸ� ������ �ϴ�.
	cout << *static_cast<float*>(ptr) << endl;

	return 0;
}