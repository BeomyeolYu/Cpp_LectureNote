/*
8.12강 "친구(friend) 함수 및 friend 클래스"

- 다수의 class가 상호작용하는 경우 캡슐화를 유지하기 위해서 friend keyword를 사용할 수 있다.
*/

#include <iostream>
using namespace std;

class B; // 전방 선언(forward declaration)이 없으면 B를 인식하지 못한다.

class A
{
private:
	int m_value = 1;

	friend void doSomething1(A& a); /* friend로 선언하면 private member에 접근할 수 있다.
	-> friend로 선언하지 않으면 doSomething 함수로 m_value를 출력할 수 없다. */
	friend void doSomething2(A& a, B& b);
};
void doSomething1(A& a)
{
	cout << a.m_value << endl; // private으로 선언한 m_value를 doSomething 함수로 출력하고 싶을 때 class A 내에 doSomething 함수를 friend로 선언해준다.
}

class B
{
private:
	int m_value = 2;

	friend void doSomething2(A& a, B& b); // 선언
};
void doSomething2(A& a, B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
}

class C; // friend member func.을 위한 전방 선언
class E  // friend member func.
{
public:
	void doSomething4(C& c);
};
class C
{
private:
	int m_value = 3;
	friend class D; // class D를 friend 하여 모든 것일 공개할 경우 = friend class.
	friend void E::doSomething4(C& c); /* 특정 member func.에게만 private을 공개하고 싶다 = friend member func.
									      --> 그러나, E class 내에 doSomething4가 있다는 것을 알 수 없으므로 에러가 발생. 
										  --> E::doSomething4의 정의와 선언을 분리해준다. */
};
class D // friend class
{
public:
	void doSomething3(C& c)
	{
		cout << c.m_value << endl;
	}
};
void E::doSomething4(C& c) // 정의
{
	cout << c.m_value << endl;
}

int main()
{
/**************** Topic 1 ****************/
	// friend를 이용하여 private member에 접근하는 방법.
	A a;
	doSomething1(a);


/**************** Topic 2 ****************/
	// class가 2개일 때 모두 접근하는 방법.
	B b;
	doSomething2(a, b);


/**************** Topic 3 ****************/
	// class C가 class D의 private member에 접근하는 방법.
	C c;
	D d;
	d.doSomething3(c);

	E e;
	e.doSomething4(c);

	return 0;
}