/*
12.4강 "가상 소멸자"

- 상속 구조에서의 자식 class는 자신의 생성자를 사용했지만 소멸자는 가상 소멸자를 사용하는 것이 좋다.
*/

#include <iostream>
using namespace std;

class Base
{
public:
	//~Base()
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int *m_array;

public:
	Derived(int length)
	{
		m_array = new int[length]; // 생성자에서 동적 메모리 할당.
	}

	//~Derived()
	virtual ~Derived()
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Derived derived1(5); // 소멸자 호출 순서는 생성자 호출 순서와 반대이다.
	
/**************** Topic 2 ****************/
	// 다형성을 사용하는 경우.
	Derived *derived2 = new Derived(5);
	Base *base = derived2;
	delete base; // 일반적으로 derived class는 다수이므로 base calss를 delete한다.
	// 그러나 base의 소멸자만 호출된다 --> derived의 소멸자가 호출되지 않으므로 메모리 누수가 발생.
	// --> base calss의 소멸자를 virtual로 만들어주면 모든 소멸자가 호출된다 (derived class에도 붙여주면 가독성에 좋다.)
	
	return 0;
}
