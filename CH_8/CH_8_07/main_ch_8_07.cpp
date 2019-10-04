/*
8.7�� "this �����Ϳ� ���� ȣ��(Chaining Member Functions)"

- class�� ���� �ؾ�� ��� Ʋ�� �����Ѵ�. 
  Q. Ʋ �ϳ�(Class)�� ���� ���� �ؾ(instance)�� ���� �� �� �ؾ�� ��� ������ �� ������?
  A. class �ȿ� �����ִ� this �����Ϳ� this �����͸� �̿��� Chaining member functions�� �̿��Ѵ�.

- ���� ȣ���� �����ϴ� �� ������ C++������ �Ҿ��� �κ��� �ִ�. 
*/

#include <iostream>
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id) // �����ڰ� int m_id�� �޾Ƶ鿩 �ʱ�ȭ���ְ� �ִ�.
	{
		// �� instance���� �ڽ��� pointer�� ������ ������, this�� �̿��Ͽ� �̸� Ȯ���� �� �ִ�. (-> : member selection operator)
		this->setID(id); // ���� �ּҸ� ������ �ִ� instance���� setID�� ����Ѵٴ� �ǹ�. == setID(id);
		this->m_id;		 // == m_id; �ڵ��� �� ���� ���� ǥ���� �ʿ䰡 �����Ƿ� this->�� ���ܳ��´�. (��� ���α׷��ֿ����� ������ this�� ������ �� ���� �ִ�.)
		
		cout << this << endl; // this �����͸� ����ϸ� �ڱ� �ڽ��� �ּҸ� ������ش�.
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

	// Calc type�� refer�� �������ְ� de-referencing�Ͽ� return ���ش�. 
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
	s2.setID(4); // ���� �ٸ� setID �Լ��� ����ϴ� ���� �ƴ϶� ��� instance�� �����ؼ� ����ϴ� ���̴�.
	
	cout << &s1 << " " << &s2 << endl; // s1�� s2�� �����ϴ� ���� ��Ȯ�� ����� �ּҸ� ���� ���̴�.

	/* ��������� �����Ͱ� �� �ִ� (���������δ� ������ ����.)
	s1.setID(2) == Simple::setID(&s1, 2)
	s2.setID(4) == Simple::setID(&s2, 4)
	--> �̸� ������ �Ǿ��ִ� Simple�� setID��,
	    s1�� pointer�� �־��ְ�,
		setID�� �ʿ��� parameter 2�� �־��ִ� ������ �۵��Ѵ�. */

/**************** Topic 2 ****************/
	// Chaining Member Functions
	Calc cal(10);
	cal.add(10);
	cal.sub(1);
	cal.mult(2);
	cal.prit();

	/* cal. �� �ݺ��ؼ� Ÿ�����ϱ� ���ŷο� �� ����� �� �ִ� trick --> Chaining member functions�� �̿�. 
	   --> �ڱ� �ڽ��� ��ȣ���� �� �ִ�. (������ ���� ȣ�� ����� ����� �� �ִ�.) */
	cal.add(10).sub(1).mult(2).prit(); // �Ǵ�
	Calc(10).add(10).sub(1).mult(2).prit();

	// �ɰ��� ������ �������ڸ�,
	Calc &temp1 = cal.add(10);
	Calc &temp2 = temp1.sub(1);
	Calc &temp3 = temp2.mult(2);
	temp3.prit();

	return 0;
}