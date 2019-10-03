/*
11.6강 "유도된(Derived) 클래스에 새로운 기능 추가하기"
*/

#include <iostream>
using namespace std;

class Base
{
private:
protected:
	int m_value;

public:
	Base(int value)
		: m_value(value)
	{}
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{}

	void setValue(int value) // Derived class의 함수에서 Base class의 member를 이용하고 싶을 때,
	{
		Base::m_value = value;
		// m_value가 private으로 선언되었을 때는 Base::m_value = value;로 직접 접근할 수 없다.
		// --> m_value를 protected로 선언하면 접근할 수 있다.

		// do some work with the variable defined in Derived
	}
};

int main()
{
	return 0;
}
