#include <iostream>
int	main(void)
{
	int x = 2; //2 ���� �͵��� literal(���ͷ�) �̶�� �θ�.
	// x�� y�� ������� �θ�.
	// x��� �̸����� "�޸�" ����. �� x��� ������ ������ 2�� ����.
	// ����) ������ ����صδ� �޸�, ������ ������ �����ϴ� CPU.
	int y = x + 3; // Expressions: (ǥ��)��

	std::cout << y; // #include <iostream>�� �������� ��� ��� ����.
	// cout, endl�� iostream ���̺귯������ �ҷ��� ����.
	std::cout << y << std::endl; // "std::endl": �ٹٲ�
	// "std": namespace 
	// "std::"�� �ǹ�: namespace�ȿ� ����ִ� cout�� ������ �� �ְԵ�.
	// "<<": stream �Ǵ� output operator(��� ������)��� �θ�.

	std::cout << 1 + 2 << std::endl;

	return 0;
}