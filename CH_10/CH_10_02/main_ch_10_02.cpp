/*
10.2�� "���� ����(Composition)"

- ���� �ӿ��� ���Ͱ� ����ϴ� ����.
*/

#include "Monster.h"
// #include <iostream> // Monster.h�� include �Ǿ� �����Ƿ�.
using namespace std;

int main()
{
	Monster mon1("Sanson", Position2D(0, 0));
	cout << mon1 << endl;

	// while (1) // game loop
	{
		// event
		mon1.moveTo(Position2D(1, 1));
		cout << mon1 << endl;
	}
	/* ����� ���縦 Ŭ������ ����? Yes�� �ǹ�
	--> mon1.m_location���� mon1�� ������ m_location�� �������. */

	return 0;
}
