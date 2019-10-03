/*
Chapter 3. �����ڵ�
3.1�� "������ �켱������ ���չ�Ģ(Operator Precedence and Associativity)"
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
/********* Topic 1 *********/
	int x = 4 + 2 * 3;
	// ���� ���� �̷а� �����ϰ� int x = 4 + (2 * 3);


/********* Topic 2 *********/
	/* 
	Operator precedence in https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
	Precedence: �켱����
	Associativity: ���չ�Ģ

	Ex1, Precedence 5, *, /�� %�� �켱������ ������, 
	     �켱������ ���� �ͳ��� ������ ��(Associativity) Left-to-right�� ����.

	Ex2, Precedence 3, Unary plus = +1, Unary minus = -4.
	     int x = (1-2) + (-3); Right-to-left. �ֳ��ϸ� -3 ���ʿ� �ƹ��͵� ���� ����.

	Ex3, Precedence 16, Direct assignment(=) is Right-to-left.
		 int x = 4 + 2 * 3;

	Ex4, Precedence 11, ^�� ������ �ƴ� �� ������(Bitwise XOR (exclusive or))��.
		 2�� 3������ ��� #include <cmath> �� int x = std::pow(2, 3); 
		 [����] std::pow�� ��� double���̹Ƿ�, int������ ����� �Ͱų� ȿ�������� ����ϰ� ���� ���� �Լ� �Ǵ� ǥ�� ����� ���⵵ ��.

	tip. �Ϲ������� ǥ�� ��� �ܿ� �� ���� ������ ��ȣ�� ����Ͽ� �켱������ ��Ȯ�ϰ� �ڵ忡 ����.
	*/

return 0;
}