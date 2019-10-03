#pragma once

//#include <string> // 반복되어도 에러가 발생하지는 않으나 제거하는 것이 이상적이다. 깔끔깔끔.
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