/*
4.10강 "구조체(struct)"

- 다양한 요소들을 묶어서 마치 하나의 (사용자 정의) 자료형인 것처럼 사용할 수 있다.
- class로 넘어가는 길목, class를 이해하기 위한 중요한 모든 개념을 struct 가 포함하고 있다.
- The only difference between a struct and class in C++ is the default accessibility of member variables, methods and inheritance. 
  (Methods are functions that belongs to the class.)
  In a struct they are public; in a class they are private.
  (How does a C++ class differ from a C struct? There are a few differences.)
*/

#include <iostream>
#include <string>

using namespace std;

void printPerson(double height, float weight, int age, string name) // 모든 변수를 정의하는 것은 부담이 된다.
{

}

struct Person 
{
	// 각각을 member라고 부른다.
	double height_ = 170.0;  // 기본값으로 초기화해줄 수도 있고 안 해줄 수도 있다.
	float weight_;
	int age_;
	string name_;

	void print() // struct 내에 함수를 선언할 수 있다.
	{
		cout << height_ << " " << weight_ << " " << age_ << " " << name_;
		cout << endl;
	}
};
void printPs(Person ps) // 마침표를 member selection operator라고 부른다.
{
	cout << ps.height_ << " " << ps.weight_ << " " << ps.age_ << " " << ps.name_;
	cout << endl;
}


// 구조체안에 구조체를 넣을 수도 있다.
struct Family
{
	Person me, mom, dad;
};

// 함수가 strut를 return할 수도 있다.
Person getSister()
{
	Person sister{ 2.0, 60.0, 1.6, "Yu" };

	return sister;
}

struct Employee     // Employee를 표현할 때 필요한 최소한의 데이터 양은 2 + (2) + 4 + 8 = 16 bytes이다.
{
	short	id;		// 2 bytes --> 컴파일러가 short를 표현하기 쉽도록 임의로 +2를 더한다 = padding.
	int		age;	// 4 bytes
	double	wage;	// 8 bytes
};

int main()
{
/********* Topic 1 *********/
	// struct을 사용하지 않는 경우 with void printPerson(...).
	double height;
	float weight;
	int age;
	string name;

	double height_1, height_2, height_3, height_4; // 다수를 표현할 때 또한 각각 만들어 주어야 하는 것이 부담이 된다.
// =double height_1[4] // array를 사용하여 동일하게 표현할 수 있다.


/********* Topic 2 *********/
	// struct을 사용하는 경우 with struct Person.
	// (1) 고전적인 방식의 초기화.
	Person me;
	me.age_ = 20; 
	me.name_ = "Jack Jack";
	me.weight_ = 100.0;
	me.height_ = 2.0;

	// (2) 최신 방식의 초기화.
	Person mom{ 2.0, 60.0, 1.6, "Kang" };
	printPs(mom);
	me.print(); // 함수도 member로 불러올 수 있다.


/********* Topic 3 *********/
	// struct에 대입하기.
	Person me2(me);
	me2.print();

	// =
	Person me2_;
	me2_ = me;
	me2_.print();


/********* Topic 4 *********/
	// 함수가 strut를 return 할 수도 있다.
	Person sister_from_func = getSister();
	sister_from_func.print();


/********* Topic 5 *********/
	Employee emp1;
	cout << sizeof(Employee) << endl; // 16 출력.

	return 0;
}