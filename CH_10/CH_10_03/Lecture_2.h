#pragma once

#include <vector>
#include "Student_2.h"
#include "Teacher_2.h"

class Lecture
{
private:
	std::string m_name;

	// Teacher teacher;
	// std::vector<Student> students;

	Teacher *teacher;
	std::vector<Student*> students;
	// --> 주소로 받아오므로 Lecture가 사라져도 같이 사라지지 않는다.

public:
	Lecture(const std::string & name_in)
		: m_name(name_in)
	{}

	~Lecture()
	{
		// do NOT delete teacher
		// do NOT delete students
	}

	/*
	void assignTeacher(const Teacher & const teacher_input)
	{
		teacher = teacher_input; 
	} */
	
	void assignTeacher(Teacher * const teacher_input)
	{
		teacher = teacher_input;
	} 

	/*
	void registerStuendt(const Student & const student_input)
	{
		students.push_back(student_input);
		// &student_input != &student[0]: 복사해서 넣었기 때문에 주소가 다르다 --> 주소를 받아오는 식으로 코드를 변경하면 된다.
	} */
	
	void registerStuendt(Student * const student_input)
	{
		students.push_back(student_input);
	} 

	void study()
	{
		std::cout << m_name << " Study" << std::endl << std::endl;
		/*
		for (auto & element : students) // Note: 'auto element' doesn't work 
			element.setIntel(element.getIntel() + 1); */

		for (auto & element : students) // Note: 'auto element' works
			element->setIntel(element->getIntel() + 1); 
	}

	friend std::ostream & operator << (std::ostream & out, const Lecture & lecture)
	{
		out << "Lecture name: " << lecture.m_name << " " << std::endl;

		/*
		out << lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << element << std::endl; */

		
		out << *lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << *element << std::endl; // de-referencing 후 출력

		return out;
	}
};