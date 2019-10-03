/*
9.6�� "÷�� ������([], subscript operator) �����ε� �ϱ�"
*/

#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // 10���� �޸� ������ �׻� Ȯ���Ǿ� �ִ�.
	// --> ���� �Ҵ����� ������ ���� �ִ�.

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}
	// array ��ü�� pointer�� return �ϴ� ��� (array ��ü�� pointer�̹Ƿ�).
	int * getList()
	{
		return m_list;
	}

	int & operator [] (const int index) // �ʿ信 ���� int�� �ƴ� string ���� �Է����� �޾ƾ� �Ѵ�.
	{
		assert(index >= 0); // assert�� ������� ���ù����� ��Ÿ�� ������ ���� �� �ִ�.
		assert(index < 10);
		return m_list[index];
	}
	// --> &�� return�ϴ� ����: �׻� �ּҸ� ������ �ִ� L-value���� �ϹǷ�, ���� �б⵵ �ٲٱ⵵ �ϱ� ����.

	const int & operator [] (const int index) const // const version���� ����� �������� const�� �ٿ� return type�� const�� ���´�.
	{
		assert(index >= 0); 
		assert(index < 10);
		return m_list[index];
	}
	//
};

int main()
{
/**************** Topic 1 ****************/
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;

	my_list.getList()[3] = 10;
	cout << my_list.getList()[3] << endl;


/**************** Topic 2 ****************/
	// ���ŷο� ()�� ���������� �����ε�.
	my_list[3] = 10;
	cout << my_list[3] << endl;


/**************** Topic 3 ****************/
	// const version���� []�� ȣ���ؾ� �ϴ� ���.
	const IntList my_list1;
	my_list1[3] = 10; // const version�̹Ƿ� ���� �ٲ� �� ����.
	cout << my_list1[3] << endl; // const version�̶� ���� ���� �־�� �ϴµ� ���� �߻� --> const version operator ����.


/**************** Topic 4 ****************/
	// ���� �߿��� �κ�: cassert�� ���� ���� ����.
	/* Q. if ���� ����ϸ� ���� ���� assert�� ��� �ϴ���?
	   A. subscript operator�� ������ ���� ����Ϸ��� �������� �ӵ��� �����̴�.
	   --> if ���� �����ϰ� assert�� ����Ͽ� ������ ���̰� ������� ����ϰ� �ϵ��� ����. */


/**************** Topic 5 ****************/
	// IntList ��ü�� pointer ���·� ����� �� ������ ��.
	IntList *list = new IntList;

	// list->operator[];
	list[3] = 10;	 // Not OK, �ǵ��� �ٸ���. 
	(*list)[3] = 10; // OK, de-referening �� []�� ȣ���ؾ� �Ѵ�.

	return 0;
}