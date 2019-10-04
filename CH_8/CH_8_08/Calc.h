#pragma once
// �ε����� ��츦 �����ϰ�� header file������ namespace�� ������� �ʴ´�.
#include <iostream>

class Calc
{
private:
	int m_value;

public:
	/* main .cpp�� ������������ header file�� �������� �����Ƿ� .cpp file�� �ϳ� �� �����Ͽ� �и��Ѵ�.
   --> �Լ� �̸� ���콺 �� Ŭ�� - Quick Actions and Refactoring - Move Definition Location
   --> �ڵ����� lnline���� ����ǹǷ� �ʿ信 ���� ���� Ȥ�� ���� 
      (������ �ڵ��̰ų� �ʿ信 ���� header file�� ������ .cpp���Ͽ� �������� �ʴ� ��쵵 �ִ�.) */

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