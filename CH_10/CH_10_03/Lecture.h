#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string m_name;
	
	Teacher teacher;
	std::vector<Student> students; 
	// --> Composition Relationship 관계이므로 Lecture가 사라지면 같이 사라진다.

	// Teacher *teacher;
	// std::vector<Student*> student;

public:
	Lecture(const std::string & name_in)
		: m_name(name_in)
	{}

	~Lecture()
	{
		// do NOT delete teacher
		// do NOT delete students
	}

	void assignTeacher(const Teacher & const teacher_input)
	{
		teacher = teacher_input;
	}
	/*
	void assignTeacher(const Teacher * const teacher_input)
	{
		teacher = teacher_input;
	} */

	void registerStuendt(const Student & const student_input)
	{
		students.push_back(student_input);
	}
	/*
	void registerStuendt(const Student * const student_input)
	{
		students.push_back(student_input);
	} */

	void study()
	{
		std::cout << m_name << " Study" << std::endl << std::endl;

		for (auto & element : students) // Note: 'auto element' doesn't work 
			element.setIntel(element.getIntel() + 1);
		/* --> for each 문을 사용할 때 element를 ref.로 받지 않고 value로 받아오면 value의 업데이트가 안된다. 
		for (auto & element : students) 
			element.setIntel(element.getIntel() + 1); */
	}

	friend std::ostream & operator << (std::ostream & out, const Lecture & lecture)
	{
		out << "Lecture name: " <<lecture.m_name << " " << std::endl;

		out << lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << element << std::endl;

		/*
		out << *lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << *element << std::endl; */

		return out;
	}
};