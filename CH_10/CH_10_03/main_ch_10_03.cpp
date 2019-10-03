/*
10.3�� "���� ����(Aggregation)"

- Composition Relationship�� �����ϰ� ����ȭ�� �߰��� ���� ���� ������ Aggregation Relationship���� ������ ���� �ִ�.
- ��, �л�ó���� ���� ������ �ּҸ� �����ϴ� Aggregation Relationship�� ����� �� ����.
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
	// Composition Relationship (Aggregation���� �񱳸� ����)
	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(Teacher("Prof. Hong"));
	lec1.registerStuendt(Student("Jack Jack", 0)); // �̸��� ���� �ɷ� �Ҵ�
	lec1.registerStuendt(Student("Dash", 1));
	lec1.registerStuendt(Student("Violet", 2));

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(Teacher("Prof. Good"));
	lec2.registerStuendt(Student("Jack Jack", 0)); // 3���� �л� �߿� lec2�� �����ϴ� �л��� Jack Jack���̴�.
		
	// test
	{
		cout << lec1 << endl;
		cout << lec2 << endl;

	// event
		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}
	/* lec2�� ���� �Ŀ� Jack Jack�� ������ �ö�� �ϴµ� ����ȭ���� �ʾҴ�.
	--> lec1�� lec2�� Jack Jack�� �ּҰ� �ٸ��� Composition Relationship�̱� ������ �߻��ϴ� �����. */


/**************** Topic 2 ****************/
	// TODO: Implement Aggregation Relationship
	// Teacher�� Student�� ���������� �����Ѵ�.
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

		lec2.study(); // �ּҸ� �̿��ϱ� ������ ������ Jack Jack���� �νĵȴ�.

		cout << lec1 << endl;
		cout << lec2 << endl;
	}


/**************** Topic 3 ****************/
	/*
	int main() { } 
	�� ����� local variable�� Teacher�� Student�� �������.
	������� �ʰ� �ϰ� ���� ��� ���� �Ҵ����� �����ϸ� �ȴ�. */

	Teacher *teacher1_ = new Teacher("Prof. Hong");
	Teacher *teacher2_ = new Teacher("Prof. Good");
	Student *std1_ = new Student("Jack Jack", 0);
	Student *std2_ = new Student("Dash", 1);
	Student *std3_ = new Student("Violet", 2);

	Lecture lec1_("Introduction to Computer Programming");
	lec1_.assignTeacher(teacher1_); // &�� �ʿ����.
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

	// ���� �Ҵ��̹Ƿ� delete memory�� �ʼ�.
	delete teacher1_;
	delete teacher2_;
	delete std1_;
	delete std2_;
	delete std3_;


/**************** Topic 4 ****************/
	// TDOD: class HobbyClub

	/* ����� ���縦 Ŭ������ ����? No�� �ǹ�
	--> �ּҸ� �̿��ϹǷ� Lecture�� ������� Teacher�� Student�� ������� �ʴ´�. */

	return 0;
}
