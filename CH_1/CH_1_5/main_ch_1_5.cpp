/*
1.5�� "�Լ����� ù ����"
*/

#include <iostream>

using namespace std;

int addTwoNumbers(int num_a, int num_b) // �Լ�(function)�� �̸� ����� ������ �ڼ��� ����� ��.
// num_a�� num_b�� �Ű�����(parameters)��� �θ�.
{
	int sum = num_a + num_b; 
	/* int sum = num_a * num_b; ���ϱ�� ���� �ٲ� ���� ����. 
	   �̶� �Լ� �̸� ���� ���콺 ��Ŭ�� �� Rename �Ͽ� multiplyTwoNumber�� �ٲ� �� ����.
	   F11�� �������� debugging�ϴ� �������� sum�� ���� -858993460�� ���� ������ ���� garbage ����. */

	return sum; // = ��ȯ�� �Ǵ� ���ϰ�(return values).
	// ����� ���(����) �ϰڴ�. �Լ��� Ÿ�԰� �����ϴ� ���� Ÿ���� ���ƾ� ��.
}

// �Է°� ���(����)�� ���� �Լ��� ����
void printHelloWorld() // or printHelloWorld(void)
{
	cout << "Hello World" << endl;

	return; // ���(����)�� ���� ��쿡�� return���� ���� ���� ����.

	cout << "Hello World2" << endl;
	//�׷��� "Hello World2"�� ������� ����. (debugging�� �ϸ� Ȯ�� ����.)
}

int addTwoNumbers1(int a, int b)
{
	printHelloWorld(); // �Լ� �ȿ��� �Լ��� ȣ���� �� ����.
	return a + b;
}

int main()
{
	cout << 1 + 2 << endl;
	cout << 3 + 4 << endl;
	cout << 8 + 13 << endl;
	// �Ѱ��� ������ �ݺ������� ����� ���� �Լ��� �����.

	cout << addTwoNumbers(1, 2) << endl;
	// 1�� 2�� ���� �μ�(arguments)��� �θ�.
	cout << addTwoNumbers(3, 4) << endl;
	cout << addTwoNumbers(8, 13) << endl;
	// �극��ũ ����Ʈ�� ���� �� F11�� ������ �Լ� ������ ��.
	
	cout << "Hello World" << endl;
	printHelloWorld();

	int sum1 = addTwoNumbers1(1, 2);
	cout << sum1 << endl;

	return 0;
}