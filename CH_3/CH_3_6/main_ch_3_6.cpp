/*
3.6�� "�� ������(logical operators)"
*/

#include <iostream>
using namespace std;

int main()
{
/********* Topic 1 *********/
	// logical NOT: !x
	bool x = true;
	cout << "!x is " << !x << endl; // 0 ���.

	// logical AND: &&
	bool y = false;
	//cout << x && y << endl; ��ȣ�� ���� �켱������ �������� ������ endl���� ���� �߻�.
	cout << "x && y is " << (x && y) << endl; // 0 ���.

	// logical OR: ||
	cout << "x || y is " << (x || y) << endl; // 1 ���.


/********* Topic 2 *********/
	// ���� ĳ���Ͱ� �Ѿ��� �¾��� ��,
	bool hit = true;
	int health = 10;

	if (hit == true && health < 20) // 2���� if ������ ������ �ͺ��� �������ڸ� ����ϴ� ���� ������.
	// = if (hit && health < 20) 
	{
		cout << "die " << endl;
	}
	else
		health -= 20;


/********* Topic 3 *********/
	// 0(false)�� �����ϰ� ��� true��.
	int n = 5;
	int m = 7;
	cout << !n << " " << m << endl;

	// Case 1: 5�� 7�� �ٸ� ���ӿ��� 5�� 7�� ture bool�� �� ��ȯ�� �Ǹ鼭 
	// " n equals m "�� ��µǴ� �ǵ��� �߸� ���޵� �� �ִ�.
	if (!n == m)
	{
		cout << " Case 1: n does not equal m (correct) " << endl;
	}
	else
		cout << " Case 1: n equals m (incorrect) " << endl;
	
	// Case 2: ���� 1 (��ȣ�� �߿伺).
	if (!(n == m)) 
	{
		cout << " Case 2: n does not equal m (correct) " << endl;
	}
	else
		cout << " Case 2: n equals m (incorrect) " << endl;

	// Case 3: ���� 2 (�������� �߿伺).
	if (n != m)
	{
		cout << " Case 3: n does not equal m (correct) " << endl;
	}
	else
		cout << " Case 3: n equals m (incorrect) " << endl;


/********* Topic 4 *********/
	int v = 1;

	if (v == 0 || v == 1)
		cout << "v is 0 or 1" << endl;


/********* Topic 5 *********/
	/* �ǿ����� �鿡�� �߿��� short-circuit evaluation.
	�������� �� ���� �� �������� ����� ���� �� �������� ���� ���ΰ� �����Ǵ� ��� ����� ����.
	���� ������ ���� ���� ������ ���డ�ɼ��� �����ϰ� ��Ÿ�� ������ ���� ��Ȳ�� ������ �� ����.
	������ ������ �տ� �ΰ� ��� ������ �ڷ� ��ġ�Ͽ� ��ü���� ���� Ƚ���� ���� �� ����. (����ȭ)
	*/

	int i = 1;
	int j = 2;

	if (i == 1 && j++ == 2)
	{
		// do something
	}

	cout << j << endl;


/********* Topic 6 *********/
	bool a = true;
	bool b = false;

	// De Morgan's Law
	!(a && b); // -(1)
	!a && !b;  // -(2)
	// (1)�� (2)�� ���� ����. = �й� ��Ģ�� �������� ����.
	!a || !b;  // -(3)
	// (1)�� (3)�� ����.

    // XOR operator
	/*false, false = false
	  false, true = true
	  true, flase = true
      true, true = false*/
	cout << " XOR operator: " << (a != b) << endl;


/********* Topic 7 *********/
	bool v1 = true;
	bool v2 = false;
	bool v3 = false;

	bool r1 = v1 || v2 && v2;
	bool r2 = (v1 || v2) && v3;
	cout << " r1 is " << r1 << endl; // -[1], 1 ���.
	cout << " r2 is " << r2 << endl; // -[2], 0 ���.
	// [1]�� [2]�� ������ ������ �� ������ ||�� �켱������ 14�̰� &&�� �켱������ 13��.
	bool r3 = v1 || (v2 && v2); // [1]�� ����.
	cout << " r3 is " << r3 << endl; // ������ ���̿��� ��ȣ�� ���ִ� ���� ����.


	return 0;
}