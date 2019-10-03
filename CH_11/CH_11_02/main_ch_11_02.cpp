/*
11.2�� "����� �⺻ (2)": Inheritance (is-a relationship) [2/2]

- �ñ������δ� �Ϲ�ȭ�� �߱��ϰ� �Ǹ� ���, ������ ���� Ȱ��ȴ� --> ���α׷��� ������ �� �ְ� �ȴ�.
- �������� �̸��� �����ϱ� ���Ͽ� class Teacher���� std::string m_name�� �ְ�, 
  �л��� �̸��� �����ϱ� ���Ͽ� class Student���� std::string m_name�� �ִ� ��� class Person���� �Ϲ�ȭ�� �� �ִ�.
- Class Wizard�� ����ϴ� ��� Base class�� �ǹ��ϴ� ���� �θ� class�̴�.
  --> ��ü ���� ���α׷��ֿ� ���޵Ǹ� �θ� clss�� ���� �ۼ��ϰ� �ȴ�.
*/

#include "Student.h"
#include "Teacher.h"

int main()
{
/**************** Topic 1 ****************/
	Student stu1("Jack Jack");
	stu1.setName("Jack");
	stu1.getName();

	Teacher tea1("Dr. Lee");
	tea1.setName("Dr. Kim");

	std::cout << tea1.getName() << std::endl; // Dr. Kim

	std::cout << stu1 << std::endl; // Jack 0
	std::cout << tea1 << std::endl; // Dr. Kim

	stu1.doNothing(); // Jack is doing nothing
	tea1.doNothing(); // Dr.Kim is doing nothing

	stu1.study(); // Jack is studying
	tea1.teach(); // Dr.Kim is teaching

	Person per1;
	per1.setName("Mr. Incredible");
	per1.getName();
	// per1.study(); // error
	// per1.teach(); // error

	return 0;
}
