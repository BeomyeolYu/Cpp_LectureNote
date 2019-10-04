#pragma once
// 부득이한 경우를 제외하고는 header file에서는 namespace를 사용하지 않는다.
#include <iostream>

class Calc
{
private:
	int m_value;

public:
	/* main .cpp는 간단해졌으나 header file이 간단하지 않으므로 .cpp file을 하나 더 생성하여 분리한다.
   --> 함수 이름 마우스 우 클릭 - Quick Actions and Refactoring - Move Definition Location
   --> 자동으로 lnline으로 선언되므로 필요에 따라 삭제 혹은 유지 
      (연구용 코드이거나 필요에 따라서 header file을 별도의 .cpp파일에 분할하지 않는 경우도 있다.) */

	Calc(int init_value);

	Calc& add(int value);
	Calc& sub(int value);
	Calc& mult(int value);
	void prit();

	/* "Original"
	Calc(int init_value)
		: m_value(init_value)
	{}

	Calc& add(int value) 
	{ 
		m_value += value; 
		return *this; 
	}
	Calc& sub(int value) 
	{ 
		m_value -= value; 
		return *this; 
	}
	Calc& mult(int value) 
	{ 
		m_value *= value; 
		return *this; 
	}

	void prit()
	{
		cout << m_value << endl;
	}
	*/
};