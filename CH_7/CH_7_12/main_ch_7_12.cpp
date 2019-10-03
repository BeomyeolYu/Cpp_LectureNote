/*
7.12�� "����� �Լ� ȣ��(Recursive Function Call)"

- �ڽ��ϰ� �̸��� �Ȱ��� �Լ��� ȣ���ϴ� ��.
- Recursive�� ���� stack overflow�� �ηƴٸ� std::vector�� stackó�� ����� �� �ִ�.
- ������ �߿��� �ڵ忡���� Recursive ����� �����ϴ� ���� ����.
*/

#include <iostream>
using namespace std;

/**************** Topic 1 ****************/
void countDown(int count)
{
	cout << count << endl;

	if (count > 0) // Recursive�� ����� ���� ���� ������ �ݵ�� �������־�� �ϸ� ������ Ƚ���� �ݺ��ϴ� ��� stack overflow�� �߻��Ѵ�.
		countDown(count - 1); // Recursive: ���� �ڵ带 ���ε��� �����Ű�� �ִٰ� ������ �� �ִ�.
	/* �츮�� ���� ���α׷��� �޸𸮿� ������ �Ǿ�������, �Լ��� ȣ���� ���� �� �޸��� �ּҸ� ������ ȣ���Ѵ�.
	   ��ü�� �޸𸮴� ���� �ְ� �ּҿ� ������ �湮�ؼ� �����Ű�� ����.
	   --> � �Լ��� �޸𸮿��� CPU�� �ö󰡰�, CPU�� �Լ��� �����ϱ� ���� �ּҸ� ȣ���Ѵ�.
	   --> �� CPU�� �Լ� A�� 10�� �����ϴ� ������, �Լ� A�� B�� �����Ű�� �������� �Ǵ��ϴ� ���� �ƴ϶� �ּҸ� ����. */
}

/**************** Topic 2 ****************/
int sumTo(int sumto)
{
	if (sumto <= 0)
		return 0;
	else if (sumto <= 1)
		return 1;
	else
	{ 
		const int sum_minus_one = sumTo(sumto - 1);
		return  sum_minus_one + sumto;
	}
}

int main()
{
/**************** Topic 1 ****************/
	countDown(5);

/**************** Topic 2 ****************/
	cout << sumTo(10) << endl;

/**************** Topic 3 ****************/
	// HW: �Ǻ���ġ ��(Fibonacci numbers)

	return 0;
}