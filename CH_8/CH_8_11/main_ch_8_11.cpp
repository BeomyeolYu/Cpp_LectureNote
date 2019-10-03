/*
8.11�� "����(static) ��� �Լ�"

- C++���� �ϳ��� class���� ������ instance�� ���� ������ �޸� ������ ����� �ڽŸ��� ��� ������ ��������, ��� �Լ��� ��� �ν��Ͻ��� �����Ѵ�.
*/

class Something1
{
public: // Topic 1
	static int s_value; // static �ɹ� ������ �ּҰ� �ϳ����̸� ���� class���� ������ ��� instance���� ������ �����ϴ�.
	// int s_value;     // <--> non-static �����ʹ� ������ �ٸ���.

public:
	int getValue()
	{
		return s_value;
	}
};

class Something2
{
private: // Topic 2
	static int s_value; 
	int m_value;

public:
	static int getValue() // <-- static���� �����Ѵ�.
	{
		return s_value;
		// return this->s_value; // non-static member func.������ this pointer�� ������ �� �ִ� ��� ���� �Ұ���.
		// return m_value;       // Ex) ���� �߻� --> static member func.������ m_value�� ������ �� ����.
	}

	int temp() // ����� ���������� static�� �ƴϴ�.
	{						  // 
		return this->s_value; /* this pointer�� non-static member func.������ ����� �� �ִ�.
							     --> this pointer: Ư�� instance�� �ּҸ� �޾� ����Ѵ�.
								 --> ��κ��� ��쿡 this pointer�� ���������� ������� ���Ǹ� ���Ͽ� ������ �� �ִ�. */
		// return this->s_value + this->m_value; // Ex) this pointer Ȱ�� ���
	}

};
int Something1::s_value = 1024; // �ʱ�ȭ
int Something2::s_value = 1024;

class Something3
{
public:
	class _init // inner class
	{
	public:
		_init() // constructor
		{
			s_value = 9876;
		}
	};

private:
	static int s_value;
	int m_value;

	static _init s_initializer; // initializer�� static���� �������ش�.

public:
	Something3()
		: m_value(123)
		// , s_value(1024) 
		/* --> static member variable�� ������(constructor)���� �ʱ�ȭ���� �� ����. 
		   --> 19�� ���� static constructor�� �������� �����Ƿ� inner class�� ����Ͽ� �ʱ�ȭ���־�� �Ѵ�. */
	{}

	static int getValue() 
	{
		return s_value;
	}
};
int Something3::s_value;
Something3::_init Something3::s_initializer;

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// public: static int s_value; �� ��,
	cout << Something1::s_value << endl; // s_value�� static�̹Ƿ� Ư�� instance�� �������( = Something s1;�� �������� �ʰ�) ���� ������ ����.

	Something1 s1;
	cout << s1.getValue() << endl;     // = s1.getValue()�� ���Ͽ� s_value�� ����.
	cout << s1.s_value << endl;        // = s1.getValue()�� ������ �ʰ� s_value�� ���� �����Ͽ� ��� ����.

	cout << &Something1::s_value << endl; // �ּҰ� 
	cout << &s1.s_value << endl;          // �����ϴ�.


/**************** Topic 2 ****************/
	// private:	static int s_value; �� ��,
	cout << Something2::s_value << endl;    // private���� ����� ��쿡�� instance�� ��ġ�� �ʰ�� ���� ������ �� ����.
	cout << Something2::getValue() << endl; // --> static member func.�� getValue�� ���ؼ� ���� ����.

	Something2 s2;
	cout << s2.getValue() << endl;     // s2.getValue()�� ���ؼ��� s_value�� ���� ����.
	cout << s2.s_value << endl;        // private�� ��� s_value�� ���� ������ �Ұ����ϸ� s2.getValue()�� ���ؼ��� ������ ����.


/**************** Topic 3 ****************/
	// member func.�� pointer�� �������� �� --> member func.�� �� instant�� ���� ������ �ּҸ� ���� ���� �ƴ϶� �����Ѵ�.
	// (1) non-static member func.
	int (Something2::*fptr1)() = &Something2::temp; // ::temp is non-static.
	cout << (s2.*fptr1)() << endl; // non-static member func.�� instant�� ������ �Ǵ� ���·� ������ �Ǿ������Ƿ� s2.(= dispointer)�� �ʿ��ϴ�.

	// (2) staitc member func. 
	int (*fptr2)() = &Something2::getValue; // Ư�� instant�� ������ �� �����൵(= ������� ���·�) pointer�� �����´�.
	cout << fptr2() << endl;
	

/**************** Topic 4 ****************/
	// inner class�� �̿��� static member variable�� �ʱ�ȭ
	cout << Something3::getValue() << endl;

	return 0;
}