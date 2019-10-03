/*
5.7�� "�ݺ��� for"

- �ݺ� Ƚ���� �������� �� ���δ�.
- ���� ���� ���̴� �ݺ����̸�, while ���� ȣȯ�� �����ϴ�.
*/

#include <iostream>
using namespace std;

int pow(int base, int exponent)
{
	int result = 1;

	for (int count = 0; count < exponent; ++count)
		result *= base;

	return result;
}

int main()
{
/**************** Topic 1 ****************/
	for (int count = 0; count < 10; ++count) // iteration
	{ // �ڵ尡 �� ���� ��쿣 �߰�ȣ�� ��� ������.
		cout << count << endl;
	}
	// cout << count << endl; // ���� �߻�; for �� ���� �� count�� �������.


/**************** Topic 2 ****************/
	// count�� for �� ���Ŀ��� ���������� �����ϴ� ���.
	int count = 0; // ������ �ܺο� �������ش�.
	for (; count < 10; ++count) // �̶� ���� �� �κ��� ��ĭ���� ����ش�.
	{ 
		cout << count << endl; //  count = 9�� ����.
	}
	cout << count << endl; // 9�� �ƴ� 10�� ��µȴ�!! 
	/* ����! count�� 10�� ���·� count < 10;�� �����ϸ� false�̱� ������ for ���� Ż���ϴ� ���̴�.
	   statements(cout << count << endl;) ������ Inc/Dec�� ������� ����. */


/**************** Topic 3 ****************/
	//// for ���� ���� ������ Ȱ��.
	//for (; ; ++count) // = for (;true; ++count) = while(true) 
	//{
	//	cout << count << endl;
	//}


/**************** Topic 4 ****************/
	// for ���� Ȱ���� �Լ� ¥��.
	cout << pow(2, 4) << endl;


/**************** Topic 5 ****************/
	// �����ϴ� ��� with unsigned int.
	for (unsigned int count = 9; count >= 0; count -= 1)
	{
		cout << count << endl;
	}
	/* Zero ������ overflow �������� 4294967295�� �ȴ�.
	   �̴� count >= 0�̹Ƿ� for ���� Zero ���Ŀ��� ������ �ʴ´�. */

/**************** Topic 6 ****************/
	// for �� ������ �ټ��� ������ �����Ͽ� Ȱ���� �� �ִ�.
	for (int i = 0, j = 0; i < 10; ++i, j -= 2)
	{
		cout << i << " " << j << endl;
	}
	

/**************** Topic 7 ****************/
	// �ܺ� for ���� ������ ������ for �������� ����� �� �ִ�. 
	 for (int j = 0; j < 9; ++j)
		 for (int i = 0; i < 9; ++i)
		 {
			 cout << i << " " << j << endl;
		 }

	return 0;
}