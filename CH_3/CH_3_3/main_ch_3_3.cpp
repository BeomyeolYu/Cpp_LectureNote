/*
3.3�� "���� ������(increment decrement operators)"

- ���� ���̰� ������ �Ǽ��� ���� �ɰ��� ������ ���ϱ� ����.
*/

#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
/********* Topic 1 *********/
	int x = 5;
	int y = ++x;
	cout << y << endl; // 5 + 1 = 6

	int n = --x;
	int m = x--;
	cout << n << endl;
	cout << m << endl; // --�� �հ� �ڿ� ��� ���� �� ����.


/********* Topic 2 *********/
	int b = 6, d = 6;
	/* cout << b << " " << d << endl;	  // 6�� 6�� ���.
	   cout << ++b << " " << --d << endl; // 7�� 5�� ���.
	*/

	cout << b++ << " " << d-- << endl; // 6�� 6�� ���
	cout << b << " " << d << endl;     // (1) 7�� 5�� ���
	/* �տ� ++�� ���� ��쿡�� b���� ���� 1�� ���� ������ �����.
	�׷��� �ڿ� ���� ��쿡�� b�� ���� cout�� ���� ������ 1�� ������.
	�׷��Ƿ� (1)���� b���� 7�� 5�� ��µ�.
	*/
	cout << ++b << " " << --d << endl; // 8�� 4�� ���.


/********* Topic 3 *********/
	int w = 1;
	int v = add(w, ++w);
	cout << v << endl; // do not use this form. w�� ���� ������ �־� 3�� �ƴ� 4�� ��µ�.

	int a = 1, c = 1;
	int l = add(a, ++c);
	cout << l << endl; // a�� c�� ���� ������ ���� �ʱ� ������ ���������� 4�� �ƴ� 3�� ��µ�.

	return 0;
}