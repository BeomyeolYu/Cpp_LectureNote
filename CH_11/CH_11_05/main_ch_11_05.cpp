/*
11.5강 "상속과 접근 지정자"
*/

#include <iostream>
using namespace std;

/**************** Topic 1 ****************/
class Base
{
public:
	int m_public;

protected:
	int m_protected;

private:
	int m_private;
};

/**************** Topic 2 ****************/
class Derived : private Base
{
public:
	Derived()
	{
		Base::m_public = 123;    // == this->m_public; == m_public;
		Base::m_protected = 123; // protected:는 외부에서 사용할 수는 없지만 자녀 class 내에서는 사용할 수 있다.
		//Base::m_private = 123;
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		//Derived::m_public; // protected 또는 private으로 상속받으면 비교 후에 더 제한적인 범위로 지정된다.
	    // 즉, 부모 class에서 public:int m_public;로 선언하고 자녀 class에서 private으로 상속받을 경우 m_public은 private로 취급된다.
		// --> 접근하려면 추가적인 함수가 필요하다.
	}
};

int main()
{
/**************** Topic 1 ****************/
	Base base;

	base.m_public = 123;
	//base.m_protected = 123; // 접근 불가; protected:는 외부에서 사용할 수 없다.
	//base.m_private = 123;   // 접근 불가.


/**************** Topic 2 ****************/
	Derived derived;

	//derived.m_public = 1024;    // 접근 불가.
	//derived.m_protected = 1024; // 접근 불가.
	//derived.m_private = 1024;   // 접근 불가.

	return 0;
}
