/*
8.2�� "ĸ��ȭ(Encapsulation), ���� ������(Access specifiers), ���� �Լ�(Access functions)"

- �پ ���α׷��Ӵ� ������ ���̴� ���α׷� �ȿ��� ���� ���踦 ����ϰ� �����ϴ� ���̴�.
- ĸ��ȭ�Ͽ� �����ϴ� ���� �ٽ��̸�, �̶� ���Ǵ� ������ ���� �����ڿ� ���� �Լ��̴�.
- ������ Ÿ�� �ܰ迡���� ��� member�� public���� �����Ͽ� ������ ���� ������,
  ������ �ϰų� ū ���α׷��� ���� ���� private�� access func.�� ���ؼ� �����ϴ� ���� ��������� �����ϴ�.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date1 // struct
{
	int m_mouth1;
	int m_day1;
	int m_year1;
};

class Date2 // class
{
public: // access specifiers --> �ܺο��� class �ȿ� �ִ� member �鿡 ���������� ���� ����.
// private: //�� ���� �ܺο��� ������ �Ұ����ϴ�. --> access func.�� ���ؼ��� ������ �����ϴ�.
	int m_mouth2;
	int m_day2;
	int m_year2;
};

class Date3
{
	// private: defalut
	int m_mouth3;
	int m_day3;
	int m_year3;

public: // ���� class ���� member���, access func.�� public�̴��� private member�� ������ �� �ִ�.
	// access func.(1): setters��� �θ���.
	void setData(const int& month_input, const int& day_input, const int& year_input) 
	{
		m_mouth3 = month_input;
		m_day3 = day_input;
		m_year3 = year_input;
	}
	void setMonth(const int& month_input)
	{
		m_mouth3 = month_input;
	}
	// setDay, setYear, ...

	// access func.(2): getters��� �θ���.
	const int& getDay() // getDay�� ���� �ٲ��� �ʵ��� const�� �����ִ� ���� �Ϲ����̴�. --> ���� �ٲٰ� �ʹٸ� setDay �Լ��� ���ϵ���.
	{
		return m_day3;
	}

	void copyFrom(const Date3& original) // �ڱ� �ڽ��� type���� �޴´�.
	{
		m_mouth3 = original.m_mouth3;
		m_day3 = original.m_day3;
		m_year3 = original.m_year3;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Date1 today1;    // Date1 today {8, 4 ,2025}; �� �ʱ�ȭ ����.
	today1.m_mouth1; // struct�� member�� ������ �̸��� �����Ѵ�.

	Date2 today2;    // class
	today2.m_mouth2; // public access specifiers�� ����ϸ� �����ϴ�.

	Date3 today3;      // class
	//today3.m_mouth3; // class�� defalut�� private�̹Ƿ�, class�� ����� member�� ������ �� ����.

/**************** Topic 2 ****************/
	today3.setData(8, 4, 2025);
	cout << today3.getDay() << endl;// get = ���.

/**************** Topic 3 ****************/
	// �����ϴ� ����.
	Date3 copy; // today3�� ���� class�κ��� ������� instance������ �ּҵ� �ٸ��� ���뵵 �ٸ���.
	copy.copyFrom(today3); // = copy.setData(today3.setMonth(), today3.setDay(), today3.setYear());

/**************** Topic 4 ****************/
	// Encapsulation�� �� �ϰ� ���� public ��ϸ� member re-name���� ������� �����.
	/* class�� ���ǵ� member�� �̸��� �ٲٰ� ���� ��,
	   public���� �����ߴٸ� class �ܺο����� ��� member�� �̸��� �ٲ��־�� �Ѵ�. <--public�� �ܺο��� member�� ���� ������ �����ϹǷ�.
	   private���� �����ϰ� �ܺο����� access func.���� ������ ��� access func. �� class ���ο����� �ٲ��ָ� �ȴ�. */

	return 0;
}