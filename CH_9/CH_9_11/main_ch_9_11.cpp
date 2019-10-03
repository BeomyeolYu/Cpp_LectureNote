/*
9.11강 "대입 연산자 오버로딩, 깊은 복사(Deep copy) vs. 얕은 복사(Shallow copy)"

- 동적 할당된 메모리에 대한 포인터 변수를 멤버로써 가지고 있는 클래스의 경우,
  복사를 하거나 대입을 할 때 깊은 복사냐 얕은 복사냐에 따라 대입 연산자 오버로딩 또는 복사 생성자 구현이 까다로워진다.

- 최근에는 std::string 등 라이브러리의 사용으로 인해 이 문제에 대하여 직접적으로 고민할 경우는 거의 없으나, 이러한 문제가 존재함은 인지해야 한다.
*/

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class MyString
{
// private
public: // 주소를 확인하기 위하여 public으로 선언하였다. --> 멤버 변수들은 private으로 선언하는 것이 캡슐화에 좋다.
	char *m_data = nullptr;
	int m_length = 0;

	std::string data; 

public:
	MyString(const char *source = "") // 문자열을 받아들인다.
	{
		assert(source);	// 문자열이 비었다면 assert로 단언.

		m_length = std::strlen(source) + 1; // + 1: 글자 수 외 null character를 추가하기 위함.
		m_data = new char[m_length];		// 글자 수만큼 m_data를 동적 할당. 

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	~MyString()
	{
		delete[] m_data; // 소멸자에서 메모리를 지운다 <-- 메모리 누수를 막기 위해 new와 delete는 쌍이다.
	}

	char * getSring() { return m_data; }
	int getLength() { return m_length; }
};

class MyString1
{
public: 
	char *m_data = nullptr;
	int m_length = 0;

public:
	MyString1(const char *source = "") 
	{
		assert(source);	

		m_length = std::strlen(source) + 1; 
		m_data = new char[m_length];		

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	MyString1(const MyString1 &source) // 자기 자신이 parameter인 copy constructor.
	{
		cout << "Copy constructor" << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr) // (1) source가 메모리를 가지고 있을 경우,
		{
			m_data = new char[m_length]; // (2) 메모리 주소를 새로 할당받고,

			for (int i = 0; i < m_length; ++i) // 추가로 source가 가지고 있는 것을 복사한다. --> Deep copy
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr; // 과거 문법으로 m_data = 0;라고도 표현한다.
	}
	
	MyString1& operator = (const MyString1 & source) // Assingment operator
	{
		// shallow copy
		/* this->m_data = source.m_data;
		   this->m_length = source.m_length; */ // 자동으로 이와 같이 복사하지만, 동적 할당된 메모리가 연관되어 있을 때는 이처럼 프로그래밍을 하면 안 된다. 

		cout << "Assingment operator" << endl;

		if (this == &source) // prevent self-assignment
			return *this;    // --> copy constructor에서는 발생하지 않는 경우로, 대입 연산자는 자신을 자신에 대입할 수 있기 때문에 이를 막아줘야 한다.
	
		delete[] m_data; // constructor는 자신이 처음 생성되는 것이기 때문에 이전에 동적 메모리를 가지고 있을 가능성이 없으나, assignment operator는 이전에 가지고 있을 수도 있기 때문에 delete.

		// Deep copy
		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i) 
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}

	~MyString1()
	{
		delete[] m_data; 
	}

	char * getSring() { return m_data; }
	int getLength() { return m_length; }
};


int main()
{
/**************** Topic 1 ****************/
	// Shallow copy: 주소값을 복사한다.
	MyString hello("Hello"); // 생성자에서 메모리를 받는다.

	cout << (int*)hello.m_data << endl; // new를 통해 할당받은 메모리의 주소 출력 --> char type을 숫자로 보기위해 int로 casting.
	cout << hello.getSring() << endl;

	{
		MyString copy = hello; // scope안에 local variable을 생성하여 copy --> 대입 연산자가 아닌 default 복사 생성자가 호출된다 --> point의 경우 주소를 복사.
		cout << (int*)copy.m_data << endl; 
		cout << copy.getSring() << endl;
		// new가 없이 메모리를 복사하였으므로 같은 주소이나 heap에는 메모리가 한 덩어리뿐이다.
	} // copy는 scope를 벗어나면 사라진다 --> delete[]를 통해 메모리 삭제.

	cout << hello.getSring() << endl; // 메모리가 삭제된 상태에서 getSring을 실행하니 硼硼硼硼硼硼硼硼? 오류 발생. 

	// 결론: 동적 메모리 할당을 사용하는 경우에는 멤버에 포인터가 있으므로 copy constructor나 assignment operator를 오버로딩할 때 주의가 필요하다.


/**************** Topic 2 ****************/
	// Deep copy: 메모리 주소를 새로 할당받고 복사한다.
	MyString1 hello1("Hello"); 
	cout << (int*)hello1.m_data << endl;
	cout << hello1.getSring() << endl;
	{
		MyString1 copy1 = hello1;
		cout << (int*)copy1.m_data << endl; // Shallow copy는 주소가 동일하나 Deep copy는 다르다.
		cout << copy1.getSring() << endl;	
	} 
	cout << hello1.getSring() << endl; 


/**************** Topic 3 ****************/
	// 대입 연산자 오버로딩 또한 copy constructor와 개념은 유사하지만 차이점이 존재한다.
	// --> 특히 호출되는 경우가 다르다.

	// Copy constructor가 호출되는 경우.
	MyString1 str1 = hello1; // Assingment operator로 보임에도 copy constructor가 실행된다.
	MyString1 str2(hello1);  // 위와 동일하지만 copy constructor가 호출됨이 분명하게 보이도록 프로그래밍하면 좋다.

	// Assingment operator가 호출되는 경우.
	MyString1 str3; // 여기서 우선 생성자가 호출되었으며,
	str3 = hello1;  // 대입만 되는 경우에 copy constructor가 호출된다.

	return 0;
}