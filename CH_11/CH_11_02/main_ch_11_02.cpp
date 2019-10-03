/*
11.2강 "상속의 기본 (2)": Inheritance (is-a relationship) [2/2]

- 궁극적으로는 일반화를 추구하게 되며 상속, 다형성 등이 활용된다 --> 프로그램을 설계할 수 있게 된다.
- 선생님의 이름을 정의하기 위하여 class Teacher에도 std::string m_name이 있고, 
  학생의 이름을 정의하기 위하여 class Student에도 std::string m_name이 있는 경우 class Person으로 일반화할 수 있다.
- Class Wizard를 사용하는 경우 Base class가 의미하는 것이 부모 class이다.
  --> 객체 지향 프로그래밍에 숙달되면 부모 clss를 먼저 작성하게 된다.
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
