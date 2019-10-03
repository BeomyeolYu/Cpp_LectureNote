#pragma once

// �θ� class���� #include�� �صθ� �ڳ� class������ #include�� �ȴ�.
#include<iostream>
#include <string> 

class Person
{
private:
	std::string m_name; // header file������ namespace�� ������ ������� �ʴ� ���� ����.
	/* m_name�� public �Ǵ� protected�� �����ϴ� ���� �� ���� ���� �� ������ private���� �����ؾ� ���α׷��� Ŀ������ ���ϹǷ� �ǵ������� ���� ���̴�.
	--> ���� ��� �ڳ� calss�� m_name�� ������ �� �ְ� �Ǹ�, m_name�� �����ϰ� ���� �� ��� �ڳ� class���� ��������� �Ѵ�. 
	--> �׷��� ������ private���� �Լ��� public���� �����Ѵ�. */

public:
	/* m_name�� �����ϴ� 1������ å���� �θ� class�� �����Ƿ� m_name�� �ʱ�ȭ�ϴ� �����ڴ� �θ� class�� �־�� �Ѵ�. (m_name�� private�̹Ƿ�)
     --> �ڳ� class���� m_name�� �ʱ�ȭ�ϴ� �����ڰ� ���� ��� ���� �߻�. */
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