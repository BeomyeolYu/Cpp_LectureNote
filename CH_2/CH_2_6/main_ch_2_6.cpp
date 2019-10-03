/*
2.6�� "�Ҹ���(Boolean) �ڷ����� ���ǹ� if"

- Boolean: �������� �̸�.
- Boolean �ڷ����� ������ �Ǵ��� �� ���� ����.
*/

#include <iostream>
using namespace std;

bool isEqual(int a, int b) // bool type�� return type���� ���� �����.
{
	bool result = (a == b);

	return result;
}

int main()
{
	// Boolean �ڷ����� initialization�� assignment�� ������.
	bool b1 = true;  // copy initialization
	bool b2(false);  // direct initialization
	bool b3{ true }; // uniform initialization
	b3 = false;		 // assignment

	cout << b3 << endl; // 0 ���.
	cout << b1 << endl; // 1 ���.

	cout << std::boolalpha; // 0�� 1�� false�� true ���ڷ� ���.
	cout << b3 << endl; // false ���.
	cout << b1 << endl; // true ���.

	cout << std::noboolalpha; // �ٽ� 0�� 1�� ���.
	cout << b3 << endl; // 0 ���.
	cout << b1 << endl; // 1 ���.

	// !�� not ������.
	cout << !true << endl;  // 0 ���.
	cout << !false << endl; // 1 ���.
	cout << !b3 << endl;    // 1 ���.
	cout << !b1 << endl;    // 0 ���.


	/******* Next topic *******/
	// AND(&&) ������. ��� true �� 1 ���.
	cout << (true && true) << endl;   // 1 ���.
	cout << (true && false) << endl;  // 0 ���.
	cout << (false && true) << endl;  // 0 ���.
	cout << (false && false) << endl; // 0 ���.
	// OR(||) ������. �ϳ��� true �� 1 ���. 
	cout << (true || true) << endl;   // 1 ���.
	cout << (true || false) << endl;  // 1 ���.
	cout << (false || true) << endl;  // 1 ���.
	cout << (false || false) << endl; // 0 ���.


	/******* Next topic *******/
	if (true) // = if (3 > 1)
		cout << "This is true" << endl;
	else
	{ // 2�� �̻󿡼��� �߰�ȣ�� ���������.
		cout << "This is false" << endl;
		cout << "This is second line" << endl;
	}
	
	if (5) // = if (true).
	// True�� ��µ�. �ֳ��ϸ� 0�̸� False�̰� �������� �� True�� <-> if (0).
		cout << "True" << endl;
	else
		cout << "False" << endl;


	/******* Next topic *******/
	cout << isEqual(1, 1) << endl; // 1 ���.
	cout << isEqual(0, 3) << endl; // 0 ���.


	/******* Next topic *******/
	bool b;
	cin >> b;
	cout << std::boolalpha;
	cout << "Your input : " << b << endl;

	return 0;
}