/*
5.�� "���ǹ� if"
*/

#include <iostream>
using namespace std;

// �Լ����� if ���� Ȱ���� �� �ִ�.
int min(int x, int y)
{
	return (x > y) ? y : x;
	/* =
	if (x > y)	
		return y
	else		
		return x
	*/
}

int main()
{
/**************** Topic 1 ****************/
	int x, y;
	cin >> x >> y; // x�� y�� �ϳ��� �Է��ϴ� �����̴�.

	if (x > 10) // bool type�� ����. --> True or False
	{
		cout << x << " is greater than 10" << endl;
		cout << "It's a if loop" << endl;
	}
	else
		cout << x << " is not greater than 10" << endl; // �� ���̸� �߰�ȣ�� �����ϱ⵵ �Ѵ�.
		cout << "It's not a if loop" << endl; // = if ���� ������ �����̴� --> �� �� �̻��̶�� ������ �߰�ȣ�� �׾ƾ� �Ѵ�.


/**************** Topic 2 ****************/
	if (1) // bool ����� �� �� 0(false)�� �ƴϸ� true�� = �׻� ����Ǵ� if ��.
		int x = 5;	// int x = 5�� �������� ���ӵǴ� ���� �ƴ϶� ��� �ȿ����� �����ʿ� �����ؾ� �Ѵ�.
	else
		int x = 6;  // �׷��ٰ� if �� �ȿ��� ������ �������� ����� ���� �ƴϴ�.
	cout << x << endl; // �� x = 5�� �ƴ� 1�� ��µȴ�.


/**************** Topic 3 ****************/
	// Chaining if statements
	if (x > 10)
		cout << x << " is greater than 10" << endl;
	else
	{
		if (x < 10)
			cout << x << " is not greater than 10" << endl;
		else // if (x == 10)
			cout << x << " is exactly 10" << endl;
	}
	// �������� �󸶵��� ���������� �� ������ ���������� ���� �����ϴ� ���� ����.


/**************** Topic 4 ****************/
	// �����ϸ� �߰�ȣ�� ��Ȯ�ϰ� ������ ǥ���ϴ� ���� ����.
	if (x >= 10)
		if (x >= 20)
			cout << "A" << endl;
	else  // < -- - else�� �鿩���� ��ġ�� ������� ���� ����� if�� �����Ƿ� ����.
		cout << "B" << endl;


/**************** Topic 5 ****************/
	// ���α׷��� ����ϰ� �ߴ��ϰ� ���� ��
	if (x > 10)
		cout << "A" << endl;
	else if (x == -1)
		return 0; // <--
	else if  (x < 0)
		cout << "B" << endl;

	cout << "Hello" << endl;


/**************** Topic 6 ****************/
	// null statement
	if (x > 10); // ;�� �����ִٸ� x�� ������� ������ ����ȴ�.
	{
		cout << "null statement" << endl;
	}


/**************** Topic 7 ****************/
	if (x = 0) // => x = 0 then, if (x)
		cout << "false" << endl; // x = 0, �� false�̹Ƿ� ������� �ʴ´�.
	cout << x << endl; // x�� 0�� ���ԵǾ� 0�� ��µȴ�.

	if (x = 3) // x == 3�� �ƴ϶� x�� 3�� ���Եȴ�. �� ��� �������� ���ӵǴ� ��.
		int x = 2; // if �� �ȿ��� �����ϴ� ���� ��� �ȿ����� ���ӵ�.
	cout << x << endl; // 2�� �ƴ϶� x�� 3�� ���ԵǾ� 3�� ��µȴ�.

	
	return 0;
}