/*
8.12�� "ģ��(friend) �Լ� �� friend Ŭ����"

- �ټ��� class�� ��ȣ�ۿ��ϴ� ��� ĸ��ȭ�� �����ϱ� ���ؼ� friend keyword�� ����� �� �ִ�.
*/

#include <iostream>
using namespace std;

class B; // ���� ����(forward declaration)�� ������ B�� �ν����� ���Ѵ�.

class A
{
private:
	int m_value = 1;

	friend void doSomething1(A& a); /* friend�� �����ϸ� private member�� ������ �� �ִ�.
	-> friend�� �������� ������ doSomething �Լ��� m_value�� ����� �� ����. */
	friend void doSomething2(A& a, B& b);
};
void doSomething1(A& a)
{
	cout << a.m_value << endl; // private���� ������ m_value�� doSomething �Լ��� ����ϰ� ���� �� class A ���� doSomething �Լ��� friend�� �������ش�.
}

class B
{
private:
	int m_value = 2;

	friend void doSomething2(A& a, B& b); // ����
};
void doSomething2(A& a, B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
}

class C; // friend member func.�� ���� ���� ����
class E  // friend member func.
{
public:
	void doSomething4(C& c);
};
class C
{
private:
	int m_value = 3;
	friend class D; // class D�� friend �Ͽ� ��� ���� ������ ��� = friend class.
	friend void E::doSomething4(C& c); /* Ư�� member func.���Ը� private�� �����ϰ� �ʹ� = friend member func.
									      --> �׷���, E class ���� doSomething4�� �ִٴ� ���� �� �� �����Ƿ� ������ �߻�. 
										  --> E::doSomething4�� ���ǿ� ������ �и����ش�. */
};
class D // friend class
{
public:
	void doSomething3(C& c)
	{
		cout << c.m_value << endl;
	}
};
void E::doSomething4(C& c) // ����
{
	cout << c.m_value << endl;
}

int main()
{
/**************** Topic 1 ****************/
	// friend�� �̿��Ͽ� private member�� �����ϴ� ���.
	A a;
	doSomething1(a);


/**************** Topic 2 ****************/
	// class�� 2���� �� ��� �����ϴ� ���.
	B b;
	doSomething2(a, b);


/**************** Topic 3 ****************/
	// class C�� class D�� private member�� �����ϴ� ���.
	C c;
	D d;
	d.doSomething3(c);

	E e;
	e.doSomething4(c);

	return 0;
}