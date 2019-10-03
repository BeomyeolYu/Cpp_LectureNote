/*
1.13�� "���ӽ����̽� (Namespace, ��Ī ����)"
- �ڵ� �������� ���������� ��ü ���� ���α׷��� �� �� �����ϰ� ���̴� ����.
- ���� ���, "����� �ٸ��� �Ȱ��� ��Ī�� �Լ��� ����� �Ͱų�, �Լ��� �̸��� �ٲٸ� ������ �̸��� �����ϰ� ���� ��"�� �ִ�.
- �̶� Namespace�� ���.
*/

#include <iostream> // iostream�� cin, cout ���� std��� ���ӽ����̽��� ���ԵǾ� ����.(_STD_BEGIN)
using namespace std;

namespace Myspace1
{
	namespace InnerSpace // namespace �ȿ� namespace�� ������ ���� ����.
	{
		int my_fuction()
		{
			return 0;
		}
	}
	int doSomething(int a, int b)
	{
		return a + b;
	}
}

int doSomething(int a, int b)
{
	return a * b;
}

int main()
{
	/*
	Myspace1::doSomething(3, 4)
	=
	using namespace Myspace1;
	doSomething(3, 4);								// 3. �� ��쿡 namespace�ȿ� �ִ� doSomething�� ������.
	*/

	/*
	Myspace1::InnerSpace::my_fuction();
	=
	using namespace Myspace1::InnerSpace;
	my_fuction();
	*/

	cout << doSomething(3, 4) << endl;				// 1. �� ��쿡�� 3 * 4 = 12�� ��� ��.
	cout << Myspace1::doSomething(3, 4) << endl;	// 2. "Myspace1" ���ӽ����̽� �ȿ� �ִ� doSomething�� �����.

	return 0;
}
