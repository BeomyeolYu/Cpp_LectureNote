/*
5.�� "switch-case"

- if ���� ��������� Ư���� ��� �� ����ϰ� ����� �� �ִ� switch-case��.
*/

#include <iostream>
using namespace std;

enum class Colors
{
	BLACK, // = 0
	WHITE, // = 1
	RED,
	GREEN,
	BLUE,
};

void printColorName(Colors color)
{
	// (1) �Լ��� if ���� �̿��Ͽ� ���� print �ϴ� ���.
	if (color == Colors::BLACK)
	cout << "BLACK" << endl;
	// ...
	// �׷��� �ټ��� ���̽��� ��� �ڵ��ϴ� ���� �����ϹǷ� switch-case �� ���.

	// (2) switch-case �� ���.
	{
		switch (color)
		{
		case Colors::WHITE:
			cout << "WHITE";
			break;
		case Colors::RED:
			cout << "RED";
			break;
		}
	cout << endl;
	}

	// (3) Colors::WHITE�� ���ŷο�Ƿ� enum�� cast�� Ư���� �̿�.
	{
		switch (static_cast<int>(color))
		{
		case 3:
			cout << "GREEN";
			break;
		case 4:
			cout << "BLUE";
			break;
		}
		cout << endl;
	}
}

int main()
{
/**************** Topic 1 ****************/
	// switch-case���� ����
	int x;
	cin >> x;

	{
		switch (x)
		{
		case 0:		// if ���� �ٸ��� �ش� case ���ķ� ��� case�� �����Ų��. 
			cout << "Zero";
			break;	// �� ��� ������ break�� �ʿ�������, ���α׷����� �ǵ��� ���� break�� �� ���� ��쵵 �� �ִ�. 
		case 1:
			cout << "One";
			break;
		case 2:
			cout << "Two";
			break;
		}
		cout << endl; // endl;�� �ϳ��� ���� ���Ͽ�.
	}


/**************** Topic 2 ****************/
	printColorName(Colors::BLUE);


/**************** Topic 3 ****************/
	// ���� ���� �� ���Կ� ���� ���� ������ ���� ����!
	switch (x)
	{
		int a, b;	// ������ �� �� ������, 
	 // int b = 5;  // ����(=�ʱ�ȭ)�� �� �� ������, = switch �� �������� �޸� �Ҵ��� �ȵȴ�.
	
	case 0:
		int y;		// case �������� ���� �����ϰ�,
		b = 1;	    // ����(�ʱ�ȭ)�� �����ϴ�.
		cout << b << endl;

		y = 5; // ���� 5�� ������ case �ȿ����� ���ӵǹǷ�
		break;
	
	case 1:
		cout << y << endl; /* y = 5�� �Ҵ���� �ʴ´�. 
		--> ������ ����� ���� �������̸� ���� ���������� ���ǵ��� �ϰ� ������ �����ϴ� ������ �⸣��. */
		cout << a << endl;
		break;
	
	default: // case���� ���ǵ��� �ʴ� ��� ����� x�� ���Ͽ� ����.
		cout << "Undefined input " << x << endl;
	}
	cout << a << endl; // ���� switch���� ������� ������ switch �ۿ��� �������.

	return 0;
}