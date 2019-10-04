/*
8.7강 "this 포인터와 연쇄 호출(Chaining Member Functions)"

- class를 흔히 붕어빵을 찍는 틀에 비유한다. 
  Q. 틀 하나(Class)가 여러 개의 붕어빵(instance)을 찍을 때 각 붕어빵을 어떻게 구분할 수 있을까?
  A. class 안에 숨어있는 this 포인터와 this 포인터를 이용한 Chaining member functions을 이용한다.

- 연쇄 호출을 권장하는 언어도 있으나 C++에서는 불안한 부분이 있다. 
*/

#include <iostream>
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id) // 생성자가 int m_id를 받아들여 초기화해주고 있다.
	{
		// 각 instance들은 자신의 pointer를 가지고 있으며, this를 이용하여 이를 확인할 수 있다. (-> : member selection operator)
		this->setID(id); // 현재 주소를 가지고 있는 instance에서 setID를 사용한다는 의미. == setID(id);
		this->m_id;		 // == m_id; 코딩을 할 때는 굳이 표현할 필요가 없으므로 this->를 숨겨놓는다. (고급 프로그래밍에서는 강제로 this를 꺼내야 할 수도 있다.)
		
		cout << this << endl; // this 포인터를 사용하면 자기 자신의 주소를 출력해준다.
	}

	void setID(int id) { m_id = id; } // == { this->m_id = id; }
	int getID() { return m_id; }
};

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}
	/*
	void add(int value) { m_value += value; }
	void sub(int value) { m_value -= value; }
	void mult(int value) { m_value *= value; }
	*/

	// Calc type의 refer를 선언해주고 de-referencing하여 return 해준다. 
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	void prit()
	{
		cout << m_value << endl;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4); // 각자 다른 setID 함수를 사용하는 것이 아니라 모든 instance가 공유해서 사용하는 것이다.
	
	cout << &s1 << " " << &s2 << endl; // s1과 s2를 구분하는 가장 명확한 방법은 주소를 찍어보는 것이다.

	/* 개념상으로 포인터가 들어가 있다 (문법상으로는 오류가 있음.)
	s1.setID(2) == Simple::setID(&s1, 2)
	s2.setID(4) == Simple::setID(&s2, 4)
	--> 미리 선언이 되어있는 Simple의 setID에,
	    s1의 pointer를 넣어주고,
		setID에 필요한 parameter 2를 넣어주는 식으로 작동한다. */

/**************** Topic 2 ****************/
	// Chaining Member Functions
	Calc cal(10);
	cal.add(10);
	cal.sub(1);
	cal.mult(2);
	cal.prit();

	/* cal. 을 반복해서 타이핑하기 번거로울 때 사용할 수 있는 trick --> Chaining member functions을 이용. 
	   --> 자기 자신을 재호출할 수 있다. (기존의 개별 호출 방법도 사용할 수 있다.) */
	cal.add(10).sub(1).mult(2).prit(); // 또는
	Calc(10).add(10).sub(1).mult(2).prit();

	// 쪼개서 개념을 이해하자면,
	Calc &temp1 = cal.add(10);
	Calc &temp2 = temp1.sub(1);
	Calc &temp3 = temp2.mult(2);
	temp3.prit();

	return 0;
}