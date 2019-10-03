/*
8.5강 "위임 생성자(Delegating Constructors)"

- 생성자가 다른 생성자를 사용하는 것.
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
	// m_name만 초기화하고 싶은 경우 생성자가 생성자를 가져올 수 있다.
	Student(const string& name_in)
		// : m_id(0), m_name(name_in) // line 24와 중복되게 초기화하는 것은 위험하다.
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

// 위임 생성자를 사용하지 않고 초기화 함수를 별도로 사용하여 동일한 기능을 구현하는 방법.
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