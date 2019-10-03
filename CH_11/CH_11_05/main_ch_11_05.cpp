/*
11.5�� "��Ӱ� ���� ������"
*/

#include <iostream>
using namespace std;

/**************** Topic 1 ****************/
class Base
{
public:
	int m_public;

protected:
	int m_protected;

private:
	int m_private;
};

/**************** Topic 2 ****************/
class Derived : private Base
{
public:
	Derived()
	{
		Base::m_public = 123;    // == this->m_public; == m_public;
		Base::m_protected = 123; // protected:�� �ܺο��� ����� ���� ������ �ڳ� class �������� ����� �� �ִ�.
		//Base::m_private = 123;
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		//Derived::m_public; // protected �Ǵ� private���� ��ӹ����� �� �Ŀ� �� �������� ������ �����ȴ�.
	    // ��, �θ� class���� public:int m_public;�� �����ϰ� �ڳ� class���� private���� ��ӹ��� ��� m_public�� private�� ��޵ȴ�.
		// --> �����Ϸ��� �߰����� �Լ��� �ʿ��ϴ�.
	}
};

int main()
{
/**************** Topic 1 ****************/
	Base base;

	base.m_public = 123;
	//base.m_protected = 123; // ���� �Ұ�; protected:�� �ܺο��� ����� �� ����.
	//base.m_private = 123;   // ���� �Ұ�.


/**************** Topic 2 ****************/
	Derived derived;

	//derived.m_public = 1024;    // ���� �Ұ�.
	//derived.m_protected = 1024; // ���� �Ұ�.
	//derived.m_private = 1024;   // ���� �Ұ�.

	return 0;
}
