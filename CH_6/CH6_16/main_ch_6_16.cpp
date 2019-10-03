/*
6.16강 "포인터와 참조의 멤버 선택 연산자(Member Selection Operators)"

- 포인터와 참조를 구조체 또는 클래스에서 사용할 때, 구조체/클래스의 멤버에 접근할 수도 있다.
- 포인터와 참조를 이용하여 멤버를 선택하는 경우 포인터는 ->, 참조는.를 사용하자.
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

	// (1) 일반적인 Member selection operators 마침표(.)를 이용하는 방법.
	person.age = 5;
	person.weigth = 30;

	// (2) ref를 이용하는 방법.
	Person &ref = person;
	ref.age = 15;
	cout << ref.age << " " << &ref.age << endl;   // A. 

	// (3) pointer를 이용하는 방법.
	Person *ptr = &person;
	ptr->age = 30;
	// (*ptr).age = 20; // 최근에는 잘 쓰이지 않는다.

	cout << ref.age << " " << &ref.age << endl;   // A. 
	cout << ptr->age << " " << &ptr->age << endl; // A. 

/**************** Topic 2 ****************/
	Person &ref2 = *ptr;
	ref2.age = 45;

	cout << &person << endl; 
	cout << &ref2 << endl;   // ref와 ref2 모두 동일한 주소가 출력된다.
	
	return 0;
}