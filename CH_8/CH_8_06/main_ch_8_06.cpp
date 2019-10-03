/*
8.6강 "소멸자(destructor)"

- 생성자의 반대되는 개념.
- 생성자가 스스로 직접 생성을 하기보다는 개체가 만들어질 때 생성이 되는 함수를 의미하듯,
  소멸자 또한 파괴를 한다는 의미보다는 변수가 영역을 벗어나 사라질 때(= 개체의 메모리를 해제할 때) 호출이 되는 함수를 의미한다.
- 메모리 누수 확인: Debug - Windows - Show Diagnostic Tools
*/

#include <iostream>
using namespace std;
class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in) // 생성자
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	~Simple() // 소멸자: parameter가 없다.
	{
		cout << "Destructor " << m_id << endl;
	}
};

class IntArray // array class
{
private:
	int *m_arr = nullptr; /* 동적 할당 array로 선언하였으나, 메모리 누수가 걱정되는 경우에는 vector를 사용하면 된다.
						     --> vector의 소멸자에는 내부에 메모리를 반납하는 구조가 이미 구현이 되어있다. */
	unsigned int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor " << endl;
	}

	~IntArray()
	{
		if (m_arr != nullptr) // 안전장치: nullptr을 delete할 경우에 문제가 생기기도 하므로 if 문을 걸어둔다.
			delete[] m_arr;   /* 소멸자의 주요 용도: my_int_arr이 작업 영역{}을 벗어나면,
							     스스로 소멸자 ~IntArray를 호출해서 delete를 수행하여 메모리 누수를 막는다. */
	}
};


int main()
{
/**************** Topic 1 ****************/
	// Destructor는 Constructor의 역순으로 사라진다: 메모리를 해제하기 전에 소멸자를 먼저 수행.
	Simple s1(0);
	Simple s2(1);
	

/**************** Topic 2 ****************/
	// 동적 할당의 경우 Constructor와 동일한 순서로 사라진다: delete 연산으로 메모리 해제를 요청하면 소멸자를 먼저 수행하고 메모리를 해제.
	Simple *s3 = new Simple(0);
	Simple s4(1);
	delete s3;


/**************** Topic 3 ****************/
	// while 문안에서 array를 무한히 생성할 때 delete가 없으면 메모리 누수가 생긴다.
	while (true)
	{
		IntArray my_int_arr(10000);
		//delete[] my_int_arr.m_arr; 
		/* --> 메모리 누수를 막기 위하여 delete 사용.
	       --> 그러나 delete로 .m_arr에 접근할 수 없을 뿐만 아니라 프로그래머가 항상 delete 문을 작성하기 번거롭다.
	       --> 소멸자 사용. */
	}
	

	return 0;
}