/*
11.7강 "상속받은 함수(Inherited Functions)를 오버라이딩(Overriding) 하기"

- 상속을 사용하는 일반적인 경우에 부모 class와 자식 class간에 상당 부분 겹치는 기능을 가지고 있다.
  이런 경우에 유용하게 사용할 수 있는 function overiding.
- Overiding: 이름이 같은 함수를 자식 class에서 새로 정의하는 것 또는 기능을 추가하는 것.
*/

#include <iostream>
using namespace std;

class Base
{
private:
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{}

	void print() 
	{
		cout << "I'm base" << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Base & b)
	{
		cout << "I'm output of base" << endl;
		return out;
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
	void print() // 유용한 다형성을 사용하기 위해서는 이름이 동일한 함수를 사용하게 되며 이를 구분해줘야 한다.
	{
		Base::print(); // Base calss의 print도 호출하고 Derived class의 print도 호출하는 방법.
		//print(); // 이와 같은 경우에는 무한 루프에 빠지게 되므로 주의.
		cout << "I'm derived" << endl;
	}

	/**************** Topic 2 ****************/
	// static_cast를 이용하면 Inherited functions의 operator overloading을 overriding할 수 있다.
	friend std::ostream & operator << (std::ostream & out, const Derived & b)
	{
		cout << static_cast<Base>(b) ;
		cout << "I'm output of derived" << endl;
		return out;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Base base(5);
	base.print();

	Derived derived(7);
	derived.print();


/**************** Topic 2 ****************/
	Base base1(1);
	cout << base1;

	Derived derived1(2);
	cout << derived1;

	return 0;
}
