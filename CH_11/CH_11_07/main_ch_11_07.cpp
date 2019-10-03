/*
11.7�� "��ӹ��� �Լ�(Inherited Functions)�� �������̵�(Overriding) �ϱ�"

- ����� ����ϴ� �Ϲ����� ��쿡 �θ� class�� �ڽ� class���� ��� �κ� ��ġ�� ����� ������ �ִ�.
  �̷� ��쿡 �����ϰ� ����� �� �ִ� function overiding.
- Overiding: �̸��� ���� �Լ��� �ڽ� class���� ���� �����ϴ� �� �Ǵ� ����� �߰��ϴ� ��.
*/

#include <iostream>
using namespace std;

class Base
{
private:
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{}

	void print() 
	{
		cout << "I'm base" << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Base & b)
	{
		cout << "I'm output of base" << endl;
		return out;
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
	void print() // ������ �������� ����ϱ� ���ؼ��� �̸��� ������ �Լ��� ����ϰ� �Ǹ� �̸� ��������� �Ѵ�.
	{
		Base::print(); // Base calss�� print�� ȣ���ϰ� Derived class�� print�� ȣ���ϴ� ���.
		//print(); // �̿� ���� ��쿡�� ���� ������ ������ �ǹǷ� ����.
		cout << "I'm derived" << endl;
	}

	/**************** Topic 2 ****************/
	// static_cast�� �̿��ϸ� Inherited functions�� operator overloading�� overriding�� �� �ִ�.
	friend std::ostream & operator << (std::ostream & out, const Derived & b)
	{
		cout << static_cast<Base>(b) ;
		cout << "I'm output of derived" << endl;
		return out;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Base base(5);
	base.print();

	Derived derived(7);
	derived.print();


/**************** Topic 2 ****************/
	Base base1(1);
	cout << base1;

	Derived derived1(2);
	cout << derived1;

	return 0;
}
