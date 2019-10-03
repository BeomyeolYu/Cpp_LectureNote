/*
11.6�� "������(Derived) Ŭ������ ���ο� ��� �߰��ϱ�"
*/

#include <iostream>
using namespace std;

class Base
{
private:
protected:
	int m_value;

public:
	Base(int value)
		: m_value(value)
	{}
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{}

	void setValue(int value) // Derived class�� �Լ����� Base class�� member�� �̿��ϰ� ���� ��,
	{
		Base::m_value = value;
		// m_value�� private���� ����Ǿ��� ���� Base::m_value = value;�� ���� ������ �� ����.
		// --> m_value�� protected�� �����ϸ� ������ �� �ִ�.

		// do some work with the variable defined in Derived
	}
};

int main()
{
	return 0;
}
