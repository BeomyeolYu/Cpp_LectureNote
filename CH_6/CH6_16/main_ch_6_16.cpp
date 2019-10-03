/*
6.16�� "�����Ϳ� ������ ��� ���� ������(Member Selection Operators)"

- �����Ϳ� ������ ����ü �Ǵ� Ŭ�������� ����� ��, ����ü/Ŭ������ ����� ������ ���� �ִ�.
- �����Ϳ� ������ �̿��Ͽ� ����� �����ϴ� ��� �����ʹ� ->, ������.�� �������.
*/

#include <iostream>
using namespace std;

struct Person
{
	int age;	   // Member variable 1
	double weigth; // Member variable 2
};

int main()
{
/**************** Topic 1 ****************/
	Person person;

	// (1) �Ϲ����� Member selection operators ��ħǥ(.)�� �̿��ϴ� ���.
	person.age = 5;
	person.weigth = 30;

	// (2) ref�� �̿��ϴ� ���.
	Person &ref = person;
	ref.age = 15;
	cout << ref.age << " " << &ref.age << endl;   // A. 

	// (3) pointer�� �̿��ϴ� ���.
	Person *ptr = &person;
	ptr->age = 30;
	// (*ptr).age = 20; // �ֱٿ��� �� ������ �ʴ´�.

	cout << ref.age << " " << &ref.age << endl;   // A. 
	cout << ptr->age << " " << &ptr->age << endl; // A. 

/**************** Topic 2 ****************/
	Person &ref2 = *ptr;
	ref2.age = 45;

	cout << &person << endl; 
	cout << &ref2 << endl;   // ref�� ref2 ��� ������ �ּҰ� ��µȴ�.
	
	return 0;
}