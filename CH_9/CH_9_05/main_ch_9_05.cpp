/*
9.5�� "���� ������ �����ε� �ϱ�"

- ���� �����ڴ� ����(prefix)�� ����(postfix)�� ���̰� �ִ�.
- prefix: '���� ����' �� ������ '�Ҵ�'.
- postfix: ������ '�Ҵ�' �� '���� ����'.
- ������ ���� ��� ����ص� �� ��쿡�� ���� ���� �����ڸ� ����ϸ� ���ɻ� �̵��� �� �� �ִ�.
*/

#include <iostream>
using namespace std;

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) : m_digit(digit) {}
	int getCents() const { return m_digit; }

	// prefix
	Digit & operator ++ () // ref. 
	{
		++m_digit;
		return *this; // �ڱ� �ڽ��� return �Ѵ�.
	}
	
	// postfix
	Digit operator ++ (int) // parameter�� dummy�� �־��ִ� ���� postfix�� ��Ģ�̴�.
	{
		Digit temp(m_digit); // �켱 ���� ���� �����Ѵ�.
		++m_digit; // = ++(*this); ������ ���� prefix�� ���.
		return temp; 
	}

	friend ostream& operator << (ostream &out, const Digit &d)
	{
		out << d.m_digit;
		return out;
	}
};

int main()
{
/**************** Topic 1 ****************/
	// prefix�� postfix�� ����.
	int a = 10;

	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;

/**************** Topic 2 ****************/
	Digit d(10);
	cout << ++d << endl;
	cout << d << endl;
	cout << d++ << endl;
	cout << d << endl;

	return 0;
}