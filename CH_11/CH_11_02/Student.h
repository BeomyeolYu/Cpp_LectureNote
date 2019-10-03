#pragma once

//#include<iostream>
//#include <string>
#include "Person.h"

class Student : public Person
{
private:
	//std::sting m_name
	int m_intel; // intelligence

public:
	Student(const std::string & name_in = "No name", const int & intel_in = 0)
		//: m_name(name_in), m_intel(intel_in)
		:Person(name_in), m_intel(intel_in)
	{}

	void setIntel(const int & intel_in)
	{
		m_intel = intel_in;
	}

	int getIntel()
	{
		return m_intel;
	}

	void study()
	{
		using namespace std;
		cout << getName() << " is studying" << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Student & student)
	{
		//out << student.m_name << " " << student.m_intel;
		out << student.getName() << " " << student.m_intel;
		return out;
	}
};