/*
9.12�� "�̴ϼȶ����� ����Ʈ(initializer list): std::initializer_list"

- �⺻ �ڷ������� array�� ���� �� initializer list�� �̿��ؼ� ���� ���ϰ� �ʱ�ȭ�ߴ� ��ó��,
  class�� ���� ����� ���� �ڷ������� ������, ���� ������ ���� ���� ���� ���ϰ� ����� �� �ִ�.
*/

#include <iostream>
#include <cassert>
#include <initializer_list> // <-- include
using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int *m_data = nullptr; // �޸� ���� �Ҵ�.

public:
	IntArray(unsigned length) // ���̸� �Է����� ������ �޸𸮸� ����ִ� ������.
		: m_length(length)
	{
		m_data = new int[length];
	}

	IntArray(const std::initializer_list<int> &list)
		: IntArray(list.size())
	{
		int count = 0;
		for (auto & element : list)
		{
			m_data[count] = element;
			++count;
			// == C style: m_data[count++] = element;
		}

		/* // error
		for (unsigned count = 0; count < list.size(); ++count)
		m_data[count] = list[count];  */
	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	// TODO: assingment operator =�� �Բ� overload ���ִ� ���� ����.

	friend ostream & operator << (ostream & out, IntArray & arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}
};

int main()
{
	int my_arr[5] = { 1, 2, 3, 4, 5 };          // ���� �ڷ��� & ���� �Ҵ� ��� initializer list�� �̿��Ͽ� ���ϰ� �ʱ�ȭ ����.
	int *my_arr2 = new int[5]{ 1, 2, 3, 4, 5 }; // ���� �Ҵ��� ��쿡�� ��� ����.

	auto il = { 10, 20, 30 }; // auto�� �����ϰ� il�� ���콺�� �ø��� std::initializer_list<int>���� Ȯ�� ����.

	IntArray int_array{ 1, 2, 3, 4, 5 }; // == IntArray int_array = { 1, 2, 3, 4, 5 };
	cout << int_array << endl;

	return 0;
}