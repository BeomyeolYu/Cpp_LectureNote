/*
4.4�� "auto Ű����� �ڷ��� �߷�(Type inference)"

- ������ �ڷ����� �Ź� �������� �������ִ� ���� ���α׷����� ȿ���� ����Ʈ����.
*/

#include <iostream>

auto add(int x, int y) // int + int�̹Ƿ� add �Լ��� int���� �߷� ����= int add(int x, int y)
{
	return x + y;
	// return x + (double)y; // ���� �� ��ȯ�� �����ϸ� add�� double�� �����ȴ�.
}

auto add(int x, int y) -> int; // Trailing Return Type (���� Ÿ�� �����ϱ�)
/*
���ʿ� �ִ� auto Ű����� �ڸ� ������ �ǹ��̴�. ���� Ÿ���� �� ���Ŀ� ǥ�õ� ���� ������.
���� template �Լ��� ����� �� �����ϰ� Ȱ��ȴ�.
*/

using namespace std;

int main()
{
/********* Topic 1 *********/
	int a_ = 123; // �ߺ��� ������ �ִ�. 123�� ������ int�� �����̴�.
	auto a = 123; // ���� ��Ҵ� �ʱ�ȭ ������ ���ԵǾ��ֱ� ������ �ʱ�ȭ�� ���̴� auto�� ����� �� ����.

	auto d = 123.0;	  // double�� ����.
	auto c = 1 + 2.0; // int + double = double�� ����.
	// auto�� ����� ��� ���α׷��Ӵ� �߷е� �ڷ����� ��Ȯ�� Ȯ���صξ�� �Ѵ�.


/********* Topic 2 *********/
	// �Լ��� ���ϰ��� ���ؼ��� auto�� ����� �� �ִ�.
	auto result = add(1, 2); // int + int = result�� type�� �ڵ����� int�� ����.

	return 0;
}