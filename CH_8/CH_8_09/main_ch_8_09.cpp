/*
8.9�� "class�� const"
*/

#include <iostream>
#include <string>
using namespace std;

class Something
{
public:
	int m_value = 0;
	
	Something(const Something& st_in) // Default Copy Constructor <-- const�� ����ȴ�.
	{
		m_value = st_in.m_value;
		cout << "Copy Constructor" << endl; // <-- ����� ���� Ȯ���غ� ��.
	}
	
	Something() // Constructor
	{
		cout << "Constructor" << endl;
	}

	int getValue() const /* member func.�� const��� ��Ȯ�ϰ� ǥ�����ָ� ������ �߻����� �ʴ´�. (const ��ġ ����)
							--> ���α׷����� �ϸ鼭 const�� ���� �� �ִ� ���� const�� �ٿ��ִ� ������ ����뿡 ����. */
	{ 
		return m_value; 
	}
	
	void setValue(int value) // const(X) <-- setValue �Լ����� const�� ����� �� ����.
	{
		m_value = value;
	}
};

void print1(Something st) // print(something3)���� something3�� st�� ���� ���� �� �ʱ�ȭ�Ǵ� ���� �´�.
{
	cout << &st << endl; /* ���簡 �ȴٴ� ����: �ּҰ� �ٸ��� (�纻) --> �ּҴ� �ٸ����� "Constructor"�� �� ���� ����ȴ�
						    --> Default Copy Constructor�� ���� �ֱ� �����̴�. */
	cout << st.getValue() << endl; // = cout << st.m_value << endl;
}
void print2(const Something &st) // class�� ���� �� ref�� ����ϸ� �ּҰ� ���� = ����ȭ
{
	cout << &st << endl;
	cout << st.getValue() << endl;
}

class Overloading
{
public:
	string m_value = "default";
	
	string& getValue()
	{
		cout << "non-const version" << endl;
		return m_value;
	}

	const string& getValue() const
	{
		cout << "const version" << endl;
		return m_value; // ref�� return �ϴ� ���̴�.
	}
private:

};

// const ref�� return
// non-const ref�� return <-- ���� �ٲ��� �� �ִ�.

int main()
{
/**************** Topic 1 ****************/
	Something something1;
	something1.setValue(3);

	const Something something2;
	something2.setValue(3); // setValue�� m_value�� ���� �ٲٴ� �Լ��̹Ƿ�, class�� const�� �����ϸ� ���� �ٲ� �� ����.
	cout << something2.getValue() << endl; /* getValue�� m_value�� ���� �ٲٴ� �Լ��� �ƴԿ��� ����� �� ���� �߻�.
										      --> �����Ϸ� ���忡���� m_value�� �ٲ���� �ٲ��� �ʾҳ��� ���� ���� �ƴ϶�,
										          member func.(= setValue, getValue)�� const�� �ƴϳ� �³��� ���̸� ���� ����.

/**************** Topic 2 ****************/
	/* Copy Constructor (���� ������): ��ü�� ���簡 �̷���� �� ȣ��Ǵ� ������.
	   ���� ���� ������ �������ִ� �����̹Ƿ� const�� �����Ͽ� ���� �ٲ��� �ʵ��� �Ѵ�. */
	Something something3;
	print1(something3); // Copy Constructor ȣ��.
	cout << &something3 << endl;
	print2(something3); // Copy Constructor�� ȣ����� �ʴ´�.


/**************** Topic 3 ****************/
	// const�� ������ ���� overloading�� ���̰� �ִ�. <-- ���� �������� ������ ���� �ҽ��� ���� �� �ִ�.
	Overloading OL;
	OL.getValue() = 10;

	const Overloading OL2;
	OL2.getValue(); // = 1004 �Ұ�.
	

	return 0;
}