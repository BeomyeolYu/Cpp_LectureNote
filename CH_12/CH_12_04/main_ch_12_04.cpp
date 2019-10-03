/*
12.4�� "���� �Ҹ���"

- ��� ���������� �ڽ� class�� �ڽ��� �����ڸ� ��������� �Ҹ��ڴ� ���� �Ҹ��ڸ� ����ϴ� ���� ����.
*/

#include <iostream>
using namespace std;

class Base
{
public:
	//~Base()
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int *m_array;

public:
	Derived(int length)
	{
		m_array = new int[length]; // �����ڿ��� ���� �޸� �Ҵ�.
	}

	//~Derived()
	virtual ~Derived()
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Derived derived1(5); // �Ҹ��� ȣ�� ������ ������ ȣ�� ������ �ݴ��̴�.
	
/**************** Topic 2 ****************/
	// �������� ����ϴ� ���.
	Derived *derived2 = new Derived(5);
	Base *base = derived2;
	delete base; // �Ϲ������� derived class�� �ټ��̹Ƿ� base calss�� delete�Ѵ�.
	// �׷��� base�� �Ҹ��ڸ� ȣ��ȴ� --> derived�� �Ҹ��ڰ� ȣ����� �����Ƿ� �޸� ������ �߻�.
	// --> base calss�� �Ҹ��ڸ� virtual�� ������ָ� ��� �Ҹ��ڰ� ȣ��ȴ� (derived class���� �ٿ��ָ� �������� ����.)
	
	return 0;
}
