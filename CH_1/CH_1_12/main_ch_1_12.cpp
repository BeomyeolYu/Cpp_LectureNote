/*
1.12�� "��� ����(guard)�� �ʿ��� ����"
- ������ ���α׷��� ���� �� �ſ� �߿���.
- ����� "�׳� ��� ���带 ���� �ȴ�."
- head�� ���� .h ���ϰ� body�� ���� .cpp ���Ϸ� �и��Ǿ� ���� �� �� �߿� �ϳ��� ������ ��ŷ ����(linking Error)�� �߻�.
*/
#include <iostream>
#include "my_work.h"
#include "add.h" // header guard�� ���� ���, my_work.h�� add.h�� ����Ǿ� �����Ƿ� �̰��� �� �����ϸ� ���� ���� ������ �߻�.

using namespace std;

int main()
{
	doSomething();

	return 0;
}
