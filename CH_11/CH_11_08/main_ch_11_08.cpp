/*
11.8강 "상속받은 함수(Inherited Functions)를 감추기"

- 상속받은 함수를 사용하지 못하도록 막는 방법.
*/

#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;
	int m_j;

public:
	Base(int value)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}

	/**************** Topic 1 ****************/
	using::Base::m_j; // using을 이용하면 Derived class가 사용하는 것에 한해서 m_j는 public이 된다.

	/**************** Topic 2 ****************/
private:
	using::Base::print;    // 방법 (1), print 뒤에 괄호를 넣지 않는다; do not add ().
	void print() = delete; // 방법 (2)
};

int main()
{
/**************** Topic 1 ****************/
	Derived derived(1);
	// derived.m_i; // m_i가 protected로 선언되었기 때문에 외부에서는 접근할 수 없다.
	derived.m_j; 


/**************** Topic 2 ****************/
	// 자식 calss에서 함수의 접근을 막는 방법.
	Base base(5);
	base.print();
	//derived.print(); // 부모 class에서 print가 public으로 선언되었기 때문에 원래는 접근이 가능하다. 

	return 0;
}
