/*
9.3�� "���� ������(+, -, !) �����ε� �ϱ�"
*/

#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	bool operator ! () const
	{
		// ������ return �� �������� ���ƿ� ���� �����ȴ�. --> ���� ���� ��츦 true�� ���ٰ� ����.
		return (m_cents == 0) ? true : false;
	}

	friend std::ostream& operator << (std::ostream &out, const Cents &cents)
	{
		out << cents.m_cents;
		return out; 
	}
};

int main()
{
/**************** Topic 1 ****************/
	int a = 6;
	cout << -a << endl;

	Cents cents1(6);
	cout << -cents1 << endl;
	cout << -Cents(-10) << endl;

/**************** Topic 2 ****************/
	// not operator�� return type�� bool�̴�.
	cout << !a << endl;

	Cents cents2(0);
	cout << !cents1 << " " << !cents2 << endl;


	return 0;
}