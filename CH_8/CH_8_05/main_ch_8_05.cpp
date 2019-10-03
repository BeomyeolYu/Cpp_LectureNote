/*
8.5�� "���� ������(Delegating Constructors)"

- �����ڰ� �ٸ� �����ڸ� ����ϴ� ��.
*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int		m_id;
	string	m_name;

public:
	// m_name�� �ʱ�ȭ�ϰ� ���� ��� �����ڰ� �����ڸ� ������ �� �ִ�.
	Student(const string& name_in)
		// : m_id(0), m_name(name_in) // line 24�� �ߺ��ǰ� �ʱ�ȭ�ϴ� ���� �����ϴ�.
		: Student(0, name_in)
	{}

	Student(const int& id_in, const string& name_in)
		: m_id(id_in), m_name(name_in)
	{}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};

// ���� �����ڸ� ������� �ʰ� �ʱ�ȭ �Լ��� ������ ����Ͽ� ������ ����� �����ϴ� ���.
class Student2
{
private:
	int		m_id2;
	string	m_name2;

public:
	Student2(const string& name_in2)
	{
		init(0, name_in2);
	}

	Student2(const int& id_in2, const string& name_in2)
	{
		init(id_in2, name_in2);
	}

	void init(const int& id_in2, const string& name_in2)
	{
		m_id2 = id_in2;
		m_name2 = name_in2;
	}

	void print()
	{
		cout << m_id2 << " " << m_name2 << endl;
	}
};

int main()
{
	Student st1(0, "Jack Jack");
	st1.print();

	Student st2("Jane");
	st2.print();

	return 0;
}