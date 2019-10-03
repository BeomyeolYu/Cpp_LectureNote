/*
10.3강 "집합 관계(Aggregation)"

- Composition Relationship로 설계하고 동기화를 추가로 해줄 수도 있지만 Aggregation Relationship으로 구현할 수도 있다.
- 단, 분산처리할 때는 동일한 주소를 공유하는 Aggregation Relationship을 사용할 수 없다.
*/

#include <iostream>
#include <vector>
#include <string>
// #include "Lecture.h"
#include "Lecture_2.h"
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// Composition Relationship (Aggregation과의 비교를 위함)
	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(Teacher("Prof. Hong"));
	lec1.registerStuendt(Student("Jack Jack", 0)); // 이름과 지적 능력 할당
	lec1.registerStuendt(Student("Dash", 1));
	lec1.registerStuendt(Student("Violet", 2));

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(Teacher("Prof. Good"));
	lec2.registerStuendt(Student("Jack Jack", 0)); // 3명의 학생 중에 lec2를 수강하는 학생은 Jack Jack뿐이다.
		
	// test
	{
		cout << lec1 << endl;
		cout << lec2 << endl;

	// event
		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}
	/* lec2를 수강 후에 Jack Jack의 지능이 올라야 하는데 동기화되지 않았다.
	--> lec1와 lec2의 Jack Jack의 주소가 다르고 Composition Relationship이기 때문에 발생하는 어려움. */


/**************** Topic 2 ****************/
	// TODO: Implement Aggregation Relationship
	// Teacher와 Student를 개별적으로 생성한다.
	Teacher teacher1("Prof. Hong");
	Teacher teacher2("Prof. Good");
	Student std1("Jack Jack", 0);
	Student std2("Dash", 1);
	Student std3("Violet", 2);

	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(&teacher1);
	lec1.registerStuendt(&std1); 
	lec1.registerStuendt(&std2);
	lec1.registerStuendt(&std3);

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(&teacher2);
	lec2.registerStuendt(&std1); 

	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		lec2.study(); // 주소를 이용하기 때문에 동일한 Jack Jack으로 인식된다.

		cout << lec1 << endl;
		cout << lec2 << endl;
	}


/**************** Topic 3 ****************/
	/*
	int main() { } 
	을 벗어나면 local variable인 Teacher와 Student는 사라진다.
	사라지지 않게 하고 싶은 경우 동적 할당으로 선언하면 된다. */

	Teacher *teacher1_ = new Teacher("Prof. Hong");
	Teacher *teacher2_ = new Teacher("Prof. Good");
	Student *std1_ = new Student("Jack Jack", 0);
	Student *std2_ = new Student("Dash", 1);
	Student *std3_ = new Student("Violet", 2);

	Lecture lec1_("Introduction to Computer Programming");
	lec1_.assignTeacher(teacher1_); // &가 필요없다.
	lec1_.registerStuendt(std1_);
	lec1_.registerStuendt(std2_);
	lec1_.registerStuendt(std3_);

	Lecture lec2_("Computational Thinking");
	lec2_.assignTeacher(teacher2_);
	lec2_.registerStuendt(std1_);

	{
		cout << lec1_ << endl;
		cout << lec2_ << endl;

		lec2_.study();

		cout << lec1_ << endl;
		cout << lec2_ << endl;
	}

	// 동적 할당이므로 delete memory가 필수.
	delete teacher1_;
	delete teacher2_;
	delete std1_;
	delete std2_;
	delete std3_;


/**************** Topic 4 ****************/
	// TDOD: class HobbyClub

	/* 멤버의 존재를 클래스가 관리? No의 의미
	--> 주소를 이용하므로 Lecture가 사라져도 Teacher와 Student는 사라지지 않는다. */

	return 0;
}
