/*
9.8�� "����ȯ�� �����ε� �ϱ�: static_cast; typecasts"
*/

#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	// cast operator�� �ּ����� ó���ϸ� �Ͻ��� ����ȯ�� ���� ������ �� �� �ִ�.
	operator int()
	{
		cout << "cast here" << endl;
		return m_cents;
	}
};

class Dollar
{
private:
	int m_dollar;

public:
	Dollar(const int& dollor) : m_dollar(dollor) {}

	operator Cents() // <-- class�� �̸��� ���������ν� Cents�� ����ȯ�Ѵ�.
	{
		return Cents(m_dollar * 100); // 1 dollar = 100 cents
	}
};

void printInt(const int &value)
{
	cout << value << endl;
}

int main()
{	
/**************** Topic 1 ****************/	
	Cents cent(7);
	printInt(cent);
	// ��� ������ �ǹ�.
	int value = (int)cent;
	value = int(cent);
	value = static_cast<int>(cent);

/**************** Topic 2 ****************/
	// Dollar�� Cents�� ����ȯ�ϴ� ����.
	Dollar dol(2);
	Cents cents = dol;
	printInt(cents);

	return 0;
}