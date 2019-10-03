#pragma once

// 부모 class에서 #include를 해두면 자녀 class에서도 #include가 된다.
#include<iostream>
#include <string> 

class Person
{
private:
	std::string m_name; // header file에서는 namespace를 가급적 사용하지 않는 것이 좋다.
	/* m_name을 public 또는 protected로 선언하는 것이 더 편해 보일 수 있으나 private으로 선언해야 프로그램이 커질수록 편하므로 의도적으로 막는 것이다.
	--> 만약 모든 자녀 calss가 m_name에 접근할 수 있게 되면, m_name을 변경하고 싶을 때 모든 자녀 class에서 변경해줘야 한다. 
	--> 그래서 변수는 private으로 함수는 public으로 구현한다. */

public:
	/* m_name을 관리하는 1차적인 책임은 부모 class에 있으므로 m_name을 초기화하는 생성자는 부모 class에 있어야 한다. (m_name이 private이므로)
     --> 자녀 class에서 m_name을 초기화하는 생성자가 있을 경우 에러 발생. */
	Person(const std::string & name_in = "No name")
		: m_name(name_in)
	{}

	void setName(const std::string & name_in)
	{
		m_name = name_in;
	}

	std::string getName() const
	{
		return m_name;
	}

	void doNothing() const
	{
		using namespace std;
		cout << m_name << " is doing nothing" << endl;
	}
};