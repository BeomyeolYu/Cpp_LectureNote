/*
2.1�� "�⺻ �ڷ��� �Ұ� (Fundamental Data Types)"
- ������ �ּ� ���� = bit = 0 �Ǵ� 1
- 8���� ������ 8 bits = 1 byte
- Char a = 'H';���� ���ڴ� 1 byte�� ǥ�� ����.
- int i = 1;�� 4 bytes�� ǥ���Ǿ���. (00000000 / 00000000 / 00000000 / 00000001)

- �پ��� �ڷ����� �����ϸ�, �ڷ������� ����Ǵ� ������� ����� �ٸ�.
- �ڷ����� ����: http://www.cplusplus.com/doc/tutorial/variables/ (Type names*���� ���Ÿ�ü�� ���� �κ��� �����ص� �����ϴٴ� ��.)
- (Signed) int�� ���� ����, 0, ���� ����(�ڿ���)��, Unsigned int�� ���� ������ 0�� ����. (Ư�� ���꿡 ���ؼ� unsigned�� �� ���� ���еǾ� ����.)
  [����] ���� ���� ���� ����(positive intefer)�� ���� ����(negative integer)�� 0�� �������� ����.
- �Ȱ��� �����ε� �پ��� Ÿ���� �����ϴ� ������ '�޸�'�� ���̰� �ֱ� ����.
  ��, ���α׷����� �������� ������ ������ ū ����(���� ��� õ�������� ����)�� �ְ� ������ ���� ���ڰ� �ִµ�,
  ���� ���� 4���ε� 10���� ����� ���� ���� ������ '�޸��� ����� �´�' Ÿ���� ����ؾ� ��. (����ϴ� ����� �Ȱ���.)
- Q. ������ ���� ū 64 bits�� �̿��ϸ� ���� �ʴ���?
  A. But, ���α׷� ���� �ӵ��� ���� ������ ���� ���� ���� ���� ����.

- �Ǽ��� �ε� �Ҽ���(Floating-point types)���� �θ��� ������ '���ں�'�� '������'�� ������ �����ϱ� ������.
- float�� int�� ������ 32 bits �������̸�, double�� float�� 2���� 64 bits�� �����.
(�Ǽ� ǥ���� ���е� ���鿡�� float�� single precision(���� ���е�), double�� double precision(2�� ���е�)�̶�� ��.)
- Bool: true or false

- ���ſ��� ��� ���� ����(�̸�, �޸� ��)�� ���� ó���� �����Ͽ����� ���뿡�� ����ϱ� ������ �����ϴ� ���� ��ȣ��. 
  ����ο� ����ΰ� ������� ������ϱ� ���� ������ ��ü�� �Լ��� ������ ���� ����; �����丵(Refactoring).
*/
#include <iostream>

int main()
{
	using namespace std;

	// Q. bValue = true �Ǵ� bValue = false�� ���� � ���� ��µɱ�?
	bool bValue = false;
	cout << (bValue ? 1 : 0) << endl;
	cout << bValue << endl; // ���������� ture�� 1, false�� 0�� ���ڷ� ������.

	char chValue = 'A';
	cout << chValue << endl;
	cout << int(chValue) << endl; // ���������� ���ڸ� 10���� ���ڷ� �ٲ��� �� �� ����.
	char chValue1 = 65;
	cout << chValue1 << endl; // �Ųٷ� 65�� �Է��ϸ� A�� ��µ�. = ���������� �ᱹ ���ڵ� ���ڷ� ǥ����. 

	// float�� double�� �������� ���Ǹ�ŭ �������� ����. -> ������ ū ������ �߻��� �� ����.
	float fValue = 3.141592f;
	/* f�� �� ���̸� warning�� �߻�. (�޼���: truncation from 'double' to 'float')
	f�� �� ���̸� double�̶�� �ǹ�. double�� float���� �޸𸮸� 2�� ��. -> �� ������.
	������ �� ���� ���� �� ������ �÷�Ʈ�� �־����� �̸� �����ϴٴ� warning.
	f�� ���δٴ� �� 4 Byte �� ���� ���� �����ϰ� ���� ���̶�� �˷���. */
	double dValue = 3.141592; // double�� f�� ������ ����.
	cout << fValue << endl; // cout�� ����Ͽ��� ������ 3.14159 ���ķ� �߸�.
	cout << dValue << endl;

	/* ��� C++������ auto�� ����ϸ� �ڵ����� �ڷ����� �����ش�.
	 fValue2, dValue2�� ���콺�� �÷�����.*/
	auto fValue2 = 3.141592f;
	auto dValue2 = 3.141592;
	cout << fValue2 << endl;
	cout << dValue2 << endl;

	// sizeof: ������ �ڷ���(Ÿ��)�� ũ�⸦ byte ������ ���ϴ� ������
	cout << sizeof(bool) << endl;
	cout << sizeof(bValue) << endl;
	cout << sizeof(fValue2) << endl;
	cout << sizeof(dValue2) << endl;

	// C++�� ���� �ʱ� ����� 3���� ����.
	int a = 123;	// copy initialization
	int b(123);		// direct initialization, ��ü ���� ���α׷��ֿ��� ����.
	int c{ 123 };	// uniform initialization, ��ü ���� ���α׷��ֿ��� ����, �ֱٿ� �����ϴ� �߼�.

	/*	int i = 3.1415; // warning�� ��. �� ��, ���������� 3.1415�� 3���� �ٲ㼭 ������. (ĳ�����̶�� �Ѵ�.)
	int d(3.14);		// �Ȱ��� warning.
	int e{ 4.5 };		// 4.5��� �Ǽ�(double)�� ������ error�� ���. (conversion from 'double' to 'int' requires a narrowing conversion)
	���, copy�� direct�� warning�� ���� �������� ���ֳ� uniform initialization�� ��� �� ���� */
	// warning �� error�� ���ִ� ��
	int i = (int)3.1415; // ���������� ĳ���� ����.
	int d((int)3.14);
	int e{ 4 };

	// ���� ���� ������ ���ÿ� �����ϴ� ��.
	int k = 0, l = 456, m = 123; // ,�� ���� ������ ������ ���� ��� ����
	int n = 0, o(456), p{ 123 }; // ���� �����ϳ� �ڵ帱 �����ϱ⿡ ���Ѱ��� ���.

	return 0;
}