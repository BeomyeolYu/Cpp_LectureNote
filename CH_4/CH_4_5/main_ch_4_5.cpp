/*
4.5�� "����ȯ Type conversion"
- �Ͻ��� ����ȯ(Implicit type conversion; coersion)
  (1) numeric promotion
  (2) numeric conversion
- ����� ����ȯ(Explicit type conversion; casting)
*/

#include <iostream>
#include <typeinfo>
#include <iomanip>

using namespace std;

int main()
{
/********* Topic 1 *********/
	// auto�� ��� �� ���� ����ȯ�� �����ϴ� ��� ���÷� type�� Ȯ���ؾ� �ϴ� ���.
	cout << typeid(4.0).name() << endl; // ��ȣ ���̿� ����ִ� ���� type�� ����� �ش�.

	int a = 123;
	cout << typeid(a).name() << endl;


	/********* Topic 2 *********/
		// �Ͻ��� ����ȯ(Implicit type conversion; coersion)
	int b = 123.0;
	/* 123.0�� double������ b�� int�� ����Ǿ��� ������ �޸� ������ �ٸ���.
	   �� ��� �����Ϸ��� ���������� int�� �ٲپ� �ʱ�ȭ�� �����Ѵ�. */


/********* Topic 3 *********/
	// numeric promotion(����)
	float c = 1.0f;
	double d = c; // ���� ���� ��� c�� ���� d���� ����ϱ� ������ ���е��� ������ ������ �������� ���� �� ���� ����. =

	// <-> numeric conversion
	int n = 30000;
	char m = n; // m�� n�� ���� �� ���� ū ������ �߻��� �� �ִ�.
	cout << static_cast<int>(m) << endl; // char Ÿ���� ǥ���� �� �ִ� �ִ��� 127�� �ƴϰ� ������ 48�� ��µȴ�.

	float f = 3.14;
	int i = f;
	cout << std::setprecision(12) << i << endl; // 3�� ��µȴ�; �Ͻ��� ����ȯ�� �� ���� �Ҽ��� ���ϸ� ������ int�� �־��ش�.


/********* Topic 4 *********/
	/* unsigned ����ȯ�� ��� ����ġ ���� ������ �߻��� �� �ִ�.
	   "5 - 10 = -5"�� �����ϰ� �;��µ� �Ǽ��� ���ϴ� ���;
	   5u�� unsigned��� �ǹ��̸� 5�� signed�̹Ƿ� 5�� 5u�� ����.
	*/
	cout << 5 - 10 << endl;	  // -5 ���.
	cout << 5u << endl;       // 5 ���.
	cout << -5u << endl;	  // 4294967291 ���.
	cout << 5u - 10 << endl;  // 4294967291 ���.
	cout << 5u - 10u << endl; // 4294967291 ���.
	/* 5u�� int�� ����ȯ �Ǿ��ٸ� ���ϴ� -5�� ����� ����� ������ ����ȯ ���� �켱������ �ִ�.
	   int�� ���� ����, unsigned int -> long -> unsigned long
	   long long -> unsigned long long -> float -> double -> long double�� ���� ����.
	   ��, unsigned int�� int���� �켱������ ���� �Ͻ��� ����ȯ�� �� �� ����. */


/********* Topic 5 *********/
	// ����� ����ȯ(Explicit type conversion; casting)
	int x = int(4.0);			   // C++ style casting
	int y = (int)4.0;			   // C style casting
	int z = static_cast<int>(4.0); // �ֱ� �߼�
	// ��ɻ� ���̴� ����.

	return 0;
}