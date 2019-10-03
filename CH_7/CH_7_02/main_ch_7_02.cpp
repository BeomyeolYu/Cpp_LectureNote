/*
7.2�� "���� ���� ����(Passing Arguments by Value)" - Call by Value
*/

#include <iostream>

using namespace std;

void doSomething(int y)
{
	cout << "In func " << y << " " << &y << endl;
}

int main()
{
/**************** Topic 1 ****************/
	doSomething(5); // �Լ��� 'ȣ��'�ϸ� literal �� �ϳ�(5)�� int y�� ����ȴ�.
	/* �������� ����: 
	   doSomething�̶�� �Լ��� ȣ���Ϸ��� parameter�� y��� ���� ���޵Ǿ�� �Ѵ�.
	   --> doSomething�� ����Ǹ鼭 ���������� int y�� ����ȴ�.
	   --> y ������ �޸𸮿� 5��� ���� ���簡 �Ǿ� �ʱ�ȭ�� �ȴ�. */

/**************** Topic 2 ****************/
	// ȥ�������� ���: ������ ����ϴ� ���. 
	int x = 6;
	cout << "In main " << x << " " << &x << endl; // &y�� &x�� �ٸ���.

	doSomething(x); /* ��, ������ ���޵Ǵ� ���� x��� ������ �ƴϰ� x��� ������ ����ִ� value�� ���޵ȴ�.
					   --> 6�̶�� ���� argument�ν� doSomething�� parameter�� ���޵ȴ�. */
	doSomething(x + 1); // 7�̶�� value�� argument�ν� ���ȴ�.

/**************** Topic 3 ****************/
	// ����: �Ϲ������� �Լ��� parameter�� �ܺο� ������ ��ġ�� �ʴ´�.
	// ����: ������ �� ����. �ܺο� ������ ��ġ�� ���� ���� �ִ�. --> ����/�ּҿ� ���� ���޷� ����.

	return 0;
}