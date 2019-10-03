#pragma once

//#include <string> // �ݺ��Ǿ ������ �߻������� ������ �����ϴ� ���� �̻����̴�. ������.
#include "Person.h"

class Teacher : public Person
{
private:
	//std::string m_name;

public:
	Teacher(const std::string & name_in = "No name")
		//: m_name(name_in)
		: Person(name_in)
	{}

	void teach()
	{
		using namespace std;
		cout << getName() << " is teaching" << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Teacher & teacher)
	{
		//out << teacher.m_name;
		out << teacher.getName();
		return out;
	}
};