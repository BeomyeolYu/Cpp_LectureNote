/*
7.6�� "�ζ��� �Լ�(Inline Functions)"

- ���� ���α׷��ӵ��� �ڽ��� ���α׷��� ������ ����� �;� �ϸ�, Inline �Լ��� �̿��Ͽ� ����ȭ�� �õ��Ѵ�.
*/

#include <iostream>
using namespace std;

int min(int x, int y)     // ������ �Լ��� ���, ������ �����Ͽ� �����ϰ� return �ϴ� ������,
{
	return x > y ? y : x; // ��� �κк��� �� �ð��� ���� �ɸ� ���� �ִ�. --> �̷��� ������ ���̱� ���ؿ� inline ���.
}

inline int max(int x, int y) // inline���� �ٲ��ָ� �Լ��� �ƴ� ��ó�� �۵��Ѵ�.
{
	return x < y ? y : x; 
}

int main()
{
/**************** Topic 1 ****************/
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;
	// inline�� ����ϸ� ���� �ڵ尡 �Ʒ� "ó��" �������� �ȴ�.
	cout << (5 > 6 ? 6 : 5) << endl;
	cout << (3 > 2 ? 2 : 3) << endl;
	// --> �� ��� �Լ��� ȣ��� �ϵ� ���� local variable(ex, int x, int y)�� ����ǰ� ������ �ϵ� ������ ������ ������.

/**************** Topic 2 ****************/
	/* ���� ����.
	�׷���, inline�� ������ ����Ǵ� ���� �ƴ϶� �����Ϸ����� �����ϴ� �����̴�. �� ��� �Լ��� ���� ������ ���� �ƴϴ�.
	���� �ֱ� �������� ���� ������� ������ inline���� �����ϴ� ���� �� ���� ���δٰ� �Ǵ��� ��� inline���� �����Ѵ�.
	���� inline�� ������ ������ �� ���α׷��� Ŀ����. �� �޸� ������ ��ȯ�ϴµ� ���� �ð��� �ҿ�ǹǷ� inline�� ����� ȿ���� �� �� ���� �ִ�.
	���� ���¼ҽ����� ã�� ���� ������, inline�� ����ϸ� ������ Ȯ���ϴ� �Ǵ� �����Ѵ� �ϴ� ���� �ƴϴ�. */
	
	/*	ȫ���� ������: 
	���������δ� �ζ����� �� �ʿ䰡 �ִ°� �����Ѵ�. 
	�ڵ��� ����ȭ�� �� inline �����ϱ� �����ϸ� ���������.	Ư�� �ڽ��� �����ڶ�� ����ȭ�� inline�� ���� �ڵ� ��ũ������ �ϴ� ���� �����ϴ� ���� ����.
	�ϵ� ���� ������ �޴� ����, ���� ó�� �� ����Ʈ������ ������ �ٲپ� ����ȭ�� �ϴ� ���� �ٶ����ϴ�. */

	return 0;
}