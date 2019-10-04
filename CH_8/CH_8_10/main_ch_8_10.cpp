/*
8.10�� "����(static) ��� ����"
*/

#include <iostream>
using namespace std;

int generateID()
{
	static int s_id = 0; // ���� ������ �Լ� ���� ���ǰ� �� ���.
	return ++s_id;
}

class Something1
{
public:
	int m_value = 1;
};

class Something2
{
public:
	static int s_value; // static member variable�� ���� �ʱ�ȭ�� �� �� ����.
};
int Something2::s_value = 1; // �ʱ�ȭ�ϴ� ��. --> define in .cpp file (header file�� �����ϸ� ������ ���� �߻�).

class Something3
{
public:
	static const int s_value = 1; // static const�� ��� ���� �ʱ�ȭ�� �����ϴ�.
};
int Something3::s_value = 1; // �Ұ��� <-- ���� �ٲ� �� ���� = ���� �ٲ��� �ʵ��� ������ ��� ���.

class Something4
{
public:
	static constexpr int s_value = 1; // constexpr���� ������ ��� ������ Ÿ�ӿ� ���� �����Ǿ� �־�� �Ѵ�. (��Ÿ�� ���� �� �Ҵ��� �Ұ���)
};
int Something4::s_value = 1; // �Ұ���


int main()
{
/**************** Topic 1 ****************/
	// �Լ��� �̿��Ͽ� ID(���� �ѹ�)�� �����ϴ� ����
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << generateID() << endl;

/**************** Topic 2 ****************/
	// class�� �̿�.
	Something1 st11;
	Something1 st12;

	st11.m_value = 2;

	cout << &st11.m_value << " " << st11.m_value << endl;
	cout << &st12.m_value << " " << st12.m_value << endl;
	// --> int�� ������ ��� �ּҿ� �� ��� �ٸ���.

/**************** Topic 3 ****************/
	// class�� static member variable�� �̿�.
	cout << &Something2::s_value << " " << Something2::s_value << endl;
	// --> ���� ���: instant�� ���� ��쿡�� �ּҰ� �����Ѵ� = static�̹Ƿ� ���� ������ �����ϴ�. 
	Something2 st21;
	Something2 st22;

	st21.s_value = 2;

	cout << &st21.s_value << " " << st21.s_value << endl;
	cout << &st22.s_value << " " << st22.s_value << endl;
	/* --> static int�� ������ ��� �ּҿ� �� ��� ����.
		   st3.s_value�� ���� �ٲ������� st4.s_value�� 2�� ���Ͽ���. */
	Something2::s_value = 1024; /* ���� instant�� ���̵� s_value�� ���� ���� �ٲ� �� �ִ� 
								   --> �޸𸮿� �������� �����ϴ� ���� �ƴ� �������� �����ϱ� ������. */
	cout << &Something2::s_value << " " << Something2::s_value << endl;

/**************** Topic 4 ****************/
	// static const �Ǵ� static constexpr member variable�� ���.
	Something3 st3;
	Something4 st4;

	return 0;
}