/*
8.4�� "�������� ��� �ʱ�ȭ ���(Member Initializer List)"

-  �Ǵ� '��� �ʱ�ȭ ����Ʈ', '��� �ʱ��� ����Ʈ'�� �����ȴ�.
*/

#include <iostream>
using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in)
		: m_b(m_b_in)
	{}
};

class Something
{
private:
	int		m_i = 100;
	double	m_d = 100.0;
	char	m_c = 'F';
	int		m_arr[5] = { 100, 200, 300, 400, 500 }; // C++ 11���ʹ� array�� member�� �߰��� �� �ִ�.
	B		m_b{ 1024 }; // user-defined�� class�� member�� �� ���.
	// --> �������� �켱������ �� ����.

public:
	Something()
		: m_i{ 1 } // Initializer List
		, m_d{ 3.14 }
		, m_c{ 'a' }
		, m_arr{ 1, 2, 3, 4, 5 }
		, m_b(m_i - 1)	// m_i - 1�̹Ƿ� m_b�� 1-1=0���� �ʱ�ȭ�ȴ�.
	{
		// Initializer List�� ����� ��� ���� �����ϴ�.
		m_i *= 3;
		m_d *= 3.0;
		m_c += 3;
		// --> �������� ���� ��� initializer list ���Ŀ� ����Ǹ� initializer list�� ���õǴ� ���� �ƴϴ�. 
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl;
	}
};

int main()
{
	Something som;
	som.print();

	return 0;
}