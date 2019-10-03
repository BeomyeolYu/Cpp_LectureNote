/*
4.10�� "����ü(struct)"

- �پ��� ��ҵ��� ��� ��ġ �ϳ��� (����� ����) �ڷ����� ��ó�� ����� �� �ִ�.
- class�� �Ѿ�� ���, class�� �����ϱ� ���� �߿��� ��� ������ struct �� �����ϰ� �ִ�.
- The only difference between a struct and class in C++ is the default accessibility of member variables, methods and inheritance. 
  (Methods are functions that belongs to the class.)
  In a struct they are public; in a class they are private.
  (How does a C++ class differ from a C struct? There are a few differences.)
*/

#include <iostream>
#include <string>

using namespace std;

void printPerson(double height, float weight, int age, string name) // ��� ������ �����ϴ� ���� �δ��� �ȴ�.
{

}

struct Person 
{
	// ������ member��� �θ���.
	double height_ = 170.0;  // �⺻������ �ʱ�ȭ���� ���� �ְ� �� ���� ���� �ִ�.
	float weight_;
	int age_;
	string name_;

	void print() // struct ���� �Լ��� ������ �� �ִ�.
	{
		cout << height_ << " " << weight_ << " " << age_ << " " << name_;
		cout << endl;
	}
};
void printPs(Person ps) // ��ħǥ�� member selection operator��� �θ���.
{
	cout << ps.height_ << " " << ps.weight_ << " " << ps.age_ << " " << ps.name_;
	cout << endl;
}


// ����ü�ȿ� ����ü�� ���� ���� �ִ�.
struct Family
{
	Person me, mom, dad;
};

// �Լ��� strut�� return�� ���� �ִ�.
Person getSister()
{
	Person sister{ 2.0, 60.0, 1.6, "Yu" };

	return sister;
}

struct Employee     // Employee�� ǥ���� �� �ʿ��� �ּ����� ������ ���� 2 + (2) + 4 + 8 = 16 bytes�̴�.
{
	short	id;		// 2 bytes --> �����Ϸ��� short�� ǥ���ϱ� ������ ���Ƿ� +2�� ���Ѵ� = padding.
	int		age;	// 4 bytes
	double	wage;	// 8 bytes
};

int main()
{
/********* Topic 1 *********/
	// struct�� ������� �ʴ� ��� with void printPerson(...).
	double height;
	float weight;
	int age;
	string name;

	double height_1, height_2, height_3, height_4; // �ټ��� ǥ���� �� ���� ���� ����� �־�� �ϴ� ���� �δ��� �ȴ�.
// =double height_1[4] // array�� ����Ͽ� �����ϰ� ǥ���� �� �ִ�.


/********* Topic 2 *********/
	// struct�� ����ϴ� ��� with struct Person.
	// (1) �������� ����� �ʱ�ȭ.
	Person me;
	me.age_ = 20; 
	me.name_ = "Jack Jack";
	me.weight_ = 100.0;
	me.height_ = 2.0;

	// (2) �ֽ� ����� �ʱ�ȭ.
	Person mom{ 2.0, 60.0, 1.6, "Kang" };
	printPs(mom);
	me.print(); // �Լ��� member�� �ҷ��� �� �ִ�.


/********* Topic 3 *********/
	// struct�� �����ϱ�.
	Person me2(me);
	me2.print();

	// =
	Person me2_;
	me2_ = me;
	me2_.print();


/********* Topic 4 *********/
	// �Լ��� strut�� return �� ���� �ִ�.
	Person sister_from_func = getSister();
	sister_from_func.print();


/********* Topic 5 *********/
	Employee emp1;
	cout << sizeof(Employee) << endl; // 16 ���.

	return 0;
}