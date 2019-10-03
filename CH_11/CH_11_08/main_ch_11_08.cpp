/*
11.8�� "��ӹ��� �Լ�(Inherited Functions)�� ���߱�"

- ��ӹ��� �Լ��� ������� ���ϵ��� ���� ���.
*/

#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;
	int m_j;

public:
	Base(int value)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}

	/**************** Topic 1 ****************/
	using::Base::m_j; // using�� �̿��ϸ� Derived class�� ����ϴ� �Ϳ� ���ؼ� m_j�� public�� �ȴ�.

	/**************** Topic 2 ****************/
private:
	using::Base::print;    // ��� (1), print �ڿ� ��ȣ�� ���� �ʴ´�; do not add ().
	void print() = delete; // ��� (2)
};

int main()
{
/**************** Topic 1 ****************/
	Derived derived(1);
	// derived.m_i; // m_i�� protected�� ����Ǿ��� ������ �ܺο����� ������ �� ����.
	derived.m_j; 


/**************** Topic 2 ****************/
	// �ڽ� calss���� �Լ��� ������ ���� ���.
	Base base(5);
	base.print();
	//derived.print(); // �θ� class���� print�� public���� ����Ǿ��� ������ ������ ������ �����ϴ�. 

	return 0;
}
