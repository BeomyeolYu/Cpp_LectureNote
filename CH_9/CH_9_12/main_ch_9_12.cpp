/*
9.12강 "이니셜라이져 리스트(initializer list): std::initializer_list"

- 기본 자료형으로 array를 만들 때 initializer list를 이용해서 값을 편하게 초기화했던 것처럼,
  class와 같은 사용자 정의 자료형에서 생성자, 대입 연산자 등을 만들 때도 편리하게 사용할 수 있다.
*/

#include <iostream>
#include <cassert>
#include <initializer_list> // <-- include
using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int *m_data = nullptr; // 메모리 동적 할당.

public:
	IntArray(unsigned length) // 길이를 입력으로 받으면 메모리를 잡아주는 생성자.
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

	// TODO: assingment operator =도 함께 overload 해주는 것이 좋다.

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
	int my_arr[5] = { 1, 2, 3, 4, 5 };          // 기존 자료형 & 정적 할당 경우 initializer list를 이용하여 편하게 초기화 수행.
	int *my_arr2 = new int[5]{ 1, 2, 3, 4, 5 }; // 동적 할당인 경우에도 사용 가능.

	auto il = { 10, 20, 30 }; // auto로 선언하고 il에 마우스를 올리면 std::initializer_list<int>임을 확인 가능.

	IntArray int_array{ 1, 2, 3, 4, 5 }; // == IntArray int_array = { 1, 2, 3, 4, 5 };
	cout << int_array << endl;

	return 0;
}