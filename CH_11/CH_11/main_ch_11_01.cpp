/*
	11.1강 "상속의 기본 (1)": Inheritance (is-a relationship) [1/2]

	- 객체 지향 프로그래밍에서 가장 중요하게 다루는 개념.
	- 부모 class의 생존 여부와 무관하며, Mother class로부터 다수의 Child class를 유도하여 만들 수 있다 (= derived calss).
*/

#include <iostream>
using namespace std;

// Mother class (= generalized class라고도 부른다; Child class들의 공통된 부분들을 묶은 class라는 의미.)
class Mother
{
private:
	int m_i;

public:
	Mother(const int & i_in)
		: m_i(i_in)
	{
		std::cout << "Mother constructor" << std::endl;
	}

	void setValue(const int & i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

/* Mother class를 상속받는 Child class
   --> Mother class에 있는 것을 모두 사용할 수 있다는 것이 기본 개념이며 재사용에 용이하다.
   --> public으로 선언할 수도 있으나 encapsulation을 유지하는 것이 좋다. */
class Child : public Mother // derived calss라고도 부른다.
{
private: // Child class가 자신만의 요소를 가지고 있을 때는 private으로 선언.
	double m_d;

public:
	// 중요한 개념인 Constructor.
	// 참고: Mohter class에 constructor가 없는 경우에는 Mohter class의 default constructor를 자동으로 호출한다.
	Child(const int & i_in, const double &  d_in)
		: Mother(i_in), m_d(d_in)
	{}

	void setValue(const double & d_in) // Mother class와 동일한 이름의 함수가 있을 때, 자신에게 선언된 함수를 먼저 호출한다.
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}

	// 상속 관계를 완벽하게 유지하기 위하여 setValue에 int와 double을 모두 입력받는 방법이 있다.
	void setValue(const int & i_in, const double & d_in)
	{
		Mother::setValue(i_in); // 참고: m_i를 public 또는 protected로 선언한 경우에는 m_i = i_in;만으로도 가능.
		m_d = d_in;
	}
};

/* Mother class를 만들고 여러 다른 class가 상속받는다는 개념도 있지만, 
   원 개념은 여러 다른 class에서 중복되는 기능을 일반화된 class로 만드는 것이다. */
class Son : public Mother
{
};
class Daughter : public Mother
{
};


int main()
{
/**************** Topic 1 ****************/
	// Mother & Child class의 construtor를 주석 처리 후 실행.
	/*
	Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child;
	child.setValue(128); // 마우스를 올리면 double로 표시된다.
	cout << child.getValue() << endl;
	*/

/**************** Topic 2 ****************/
	/*
	Child child3;                  // 메모리를 만들고 받아온 뒤,
	child3.Mother::setValue(1024); // 값을 복사해서 넣었으므로 초기화라고 부르긴 어렵다 --> Constructor가 요구됨.
	// 참고: Constructor는 메모리가 주어지지 않은 상태에서 메모리를 할당받는 동시에 특정 값을 복사해서 넣는 것 (= 초기화).
	*/


/**************** Topic 3 ****************/
	Child child2(1024, 128);
	child2.Mother::setValue(1024); // 이와 같은 방법으로 부모 class에 접근 가능.

	return 0;
}
