/*
3.5�� "���� ������ (Relational Operators)"

- Ex, >  <  ==  != ��
- tip. �ּ��� ����� ���� ���� ����.
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
/********* Topic 1 *********/
	//while (true)
	//{
		int x, y;
		cin >> x >> y;
		cout << "Your input values are : " << x << " " << y << endl;

		if (x == y)
			cout << "equal" << endl;
		if (x != y)
			cout << "not equal " << endl;
		if (x > y)
			cout << "x is greater than y" << endl;
		if (x < y)
			cout << "x is less than y" << endl;
		if (x >= y)
			cout << "x is greater than y or equal to y" << endl;
		if (x <= y)
			cout << "x is less than y or equal to y" << endl;
	//}

/********* Topic 2 *********/
	/*
	int ������ ���꿣 ū ������ �߻����� ����.
	�׷��� ������ ��! 
	�ε��Ҽ���(floating point numbers)������ ���꿡�� ū ������ �߻��� �� ����.
	*/

	double d1(100 - 99.99); // = 0.001.
	double d2(10 - 9.99);	// = 0.001.
	cout << d1 << endl;		// 0.001 ���.
	cout << d2 << endl;		// 0.001 ���.

	if (d1 == d2)
		cout << "equal" << endl;
	else
	{
		cout << "not equal" << endl; // not equal�� ��µ�.

		if (d1 > d2) cout << "d1 > d2" << endl;
		else // if(d1 < d2) because d1 != d2
			cout << "d1 < d2" << endl;	
	}

	cout << std::abs(d1 - d2) << endl; // 5.32907e-15�� ���� �̼��� ������ �߻� <= ��ġ�ؼ��а� ������ ���.
	/* ��ġ ������ ��� ������ �� �ִ°�? Ex) ������ �Ѱ踦 ���� �������ش�. */
	const double epsilon = 1e-10; // �׷���, epsilon�� �� ���� �о��� domain knowledge�� ���� ����.

	if (std::abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;

	return 0;
}