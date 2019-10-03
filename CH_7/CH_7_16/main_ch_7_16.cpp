/*
7.16�� "������ȣ(Ellipsis)"

- ������ '�ϸ��ý�'�� ������ --> ���� ��ȣ Ȯ��.
- '�Լ��� parameter�� ������ ������ ���� �ʾ����� ���ڴ�' ���� �� Ȱ�� ����.
- ����ϱ� �����ϰ� ������� ����� �ʺ��ڿ��� ����� �������� �ʴ´�.
*/

#include <iostream>
#include <cstdarg> // for ellipsis
using namespace std;

// count ������ŭ�� argument�� ��� ���ִ� �Լ�.
double findAverage(int count, ...) // type�� �˷��ִ� parameter �ϳ��� ...
{
	double sum = 0;

	va_list list; // ���콺�� ������ char�� �޴� ���� Ȯ���� �� �ִ�.

	va_start(list, count); // count: �Լ��� ������ argument�� �� ������ �˷���� �Ѵ�.
	
	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int); // int�� ��ȯ�� ���ش�.

	va_end(list); // ������.

	return sum / count;
}

int main()
{
/**************** Topic 1 ****************/
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl; // ù ��° parameter�� �����̴�.
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl; /* ������ �־��� �� 5���ε� 10�� argument�� �־��־���.
													--> -8.26776e+07�� ��µǴ� ������ �߻��Ѵ�. 
													--> ������ ������� �ϴ� ���輺�� �����Ѵ�. */

	return 0;
}