/*
	11.1�� "����� �⺻ (1)": Inheritance (is-a relationship) [1/2]

	- ��ü ���� ���α׷��ֿ��� ���� �߿��ϰ� �ٷ�� ����.
	- �θ� class�� ���� ���ο� �����ϸ�, Mother class�κ��� �ټ��� Child class�� �����Ͽ� ���� �� �ִ� (= derived calss).
*/

#include <iostream>
using namespace std;

// Mother class (= generalized class��� �θ���; Child class���� ����� �κе��� ���� class��� �ǹ�.)
class Mother
{
private:
	int m_i;

public:
	Mother(const int & i_in)
		: m_i(i_in)
	{
		std::cout << "Mother constructor" << std::endl;
	}

	void setValue(const int & i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

/* Mother class�� ��ӹ޴� Child class
   --> Mother class�� �ִ� ���� ��� ����� �� �ִٴ� ���� �⺻ �����̸� ���뿡 �����ϴ�.
   --> public���� ������ ���� ������ encapsulation�� �����ϴ� ���� ����. */
class Child : public Mother // derived calss��� �θ���.
{
private: // Child class�� �ڽŸ��� ��Ҹ� ������ ���� ���� private���� ����.
	double m_d;

public:
	// �߿��� ������ Constructor.
	// ����: Mohter class�� constructor�� ���� ��쿡�� Mohter class�� default constructor�� �ڵ����� ȣ���Ѵ�.
	Child(const int & i_in, const double &  d_in)
		: Mother(i_in), m_d(d_in)
	{}

	void setValue(const double & d_in) // Mother class�� ������ �̸��� �Լ��� ���� ��, �ڽſ��� ����� �Լ��� ���� ȣ���Ѵ�.
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}

	// ��� ���踦 �Ϻ��ϰ� �����ϱ� ���Ͽ� setValue�� int�� double�� ��� �Է¹޴� ����� �ִ�.
	void setValue(const int & i_in, const double & d_in)
	{
		Mother::setValue(i_in); // ����: m_i�� public �Ǵ� protected�� ������ ��쿡�� m_i = i_in;�����ε� ����.
		m_d = d_in;
	}
};

/* Mother class�� ����� ���� �ٸ� class�� ��ӹ޴´ٴ� ���䵵 ������, 
   �� ������ ���� �ٸ� class���� �ߺ��Ǵ� ����� �Ϲ�ȭ�� class�� ����� ���̴�. */
class Son : public Mother
{
};
class Daughter : public Mother
{
};


int main()
{
/**************** Topic 1 ****************/
	// Mother & Child class�� construtor�� �ּ� ó�� �� ����.
	/*
	Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child;
	child.setValue(128); // ���콺�� �ø��� double�� ǥ�õȴ�.
	cout << child.getValue() << endl;
	*/

/**************** Topic 2 ****************/
	/*
	Child child3;                  // �޸𸮸� ����� �޾ƿ� ��,
	child3.Mother::setValue(1024); // ���� �����ؼ� �־����Ƿ� �ʱ�ȭ��� �θ��� ��ƴ� --> Constructor�� �䱸��.
	// ����: Constructor�� �޸𸮰� �־����� ���� ���¿��� �޸𸮸� �Ҵ�޴� ���ÿ� Ư�� ���� �����ؼ� �ִ� �� (= �ʱ�ȭ).
	*/


/**************** Topic 3 ****************/
	Child child2(1024, 128);
	child2.Mother::setValue(1024); // �̿� ���� ������� �θ� class�� ���� ����.

	return 0;
}
