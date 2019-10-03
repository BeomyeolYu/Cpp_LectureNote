/*
8.4강 "생성자의 멤버 초기화 목록(Member Initializer List)"

-  또는 '멤버 초기화 리스트', '멤버 초기자 리스트'로 번역된다.
*/

#include <iostream>
using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in)
		: m_b(m_b_in)
	{}
};

class Something
{
private:
	int		m_i = 100;
	double	m_d = 100.0;
	char	m_c = 'F';
	int		m_arr[5] = { 100, 200, 300, 400, 500 }; // C++ 11부터는 array도 member로 추가할 수 있다.
	B		m_b{ 1024 }; // user-defined된 class가 member로 들어갈 경우.
	// --> 생성자의 우선순위가 더 높다.

public:
	Something()
		: m_i{ 1 } // Initializer List
		, m_d{ 3.14 }
		, m_c{ 'a' }
		, m_arr{ 1, 2, 3, 4, 5 }
		, m_b(m_i - 1)	// m_i - 1이므로 m_b는 1-1=0으로 초기화된다.
	{
		// Initializer List를 사용할 경우 삭제 가능하다.
		m_i *= 3;
		m_d *= 3.0;
		m_c += 3;
		// --> 삭제하지 않을 경우 initializer list 이후에 실행되며 initializer list가 무시되는 것이 아니다. 
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl;
	}
};

int main()
{
	Something som;
	som.print();

	return 0;
}