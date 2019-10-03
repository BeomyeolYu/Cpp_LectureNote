/*
8.9강 "class와 const"
*/

#include <iostream>
#include <string>
using namespace std;

class Something
{
public:
	int m_value = 0;
	
	Something(const Something& st_in) // Default Copy Constructor <-- const로 선언된다.
	{
		m_value = st_in.m_value;
		cout << "Copy Constructor" << endl; // <-- 디버깅 모드로 확인해볼 것.
	}
	
	Something() // Constructor
	{
		cout << "Constructor" << endl;
	}

	int getValue() const /* member func.에 const라고 명확하게 표기해주면 오류가 발생하지 않는다. (const 위치 주의)
							--> 프로그래밍을 하면서 const를 붙일 수 있는 곳에 const를 붙여주는 습관이 디버깅에 좋다. */
	{ 
		return m_value; 
	}
	
	void setValue(int value) // const(X) <-- setValue 함수에는 const를 사용할 수 없다.
	{
		m_value = value;
	}
};

void print1(Something st) // print(something3)에서 something3이 st로 들어와 복사 후 초기화되는 것은 맞다.
{
	cout << &st << endl; /* 복사가 된다는 증거: 주소가 다르다 (사본) --> 주소는 다름에도 "Constructor"는 한 번만 실행된다
						    --> Default Copy Constructor가 숨어 있기 때문이다. */
	cout << st.getValue() << endl; // = cout << st.m_value << endl;
}
void print2(const Something &st) // class를 보낼 때 ref를 사용하면 주소가 같다 = 최적화
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
		return m_value; // ref를 return 하는 것이다.
	}
private:

};

// const ref를 return
// non-const ref를 return <-- 값을 바꿔줄 수 있다.

int main()
{
/**************** Topic 1 ****************/
	Something something1;
	something1.setValue(3);

	const Something something2;
	something2.setValue(3); // setValue는 m_value의 값을 바꾸는 함수이므로, class를 const로 선언하면 값을 바꿀 수 없다.
	cout << something2.getValue() << endl; /* getValue는 m_value의 값을 바꾸는 함수가 아님에도 출력할 때 에러 발생.
										      --> 컴파일러 입장에서는 m_value가 바뀌었나 바뀌지 않았나를 보는 것이 아니라,
										          member func.(= setValue, getValue)이 const가 아니냐 맞냐의 차이만 보기 때문.

/**************** Topic 2 ****************/
	/* Copy Constructor (복사 생성자): 객체의 복사가 이루어질 때 호출되는 생성자.
	   기존 값을 복사해 전달해주는 개념이므로 const로 선언하여 값이 바뀌지 않도록 한다. */
	Something something3;
	print1(something3); // Copy Constructor 호출.
	cout << &something3 << endl;
	print2(something3); // Copy Constructor가 호출되지 않는다.


/**************** Topic 3 ****************/
	// const의 유무에 따라서 overloading에 차이가 있다. <-- 자주 사용되지는 않으나 오픈 소스에 사용될 수 있다.
	Overloading OL;
	OL.getValue() = 10;

	const Overloading OL2;
	OL2.getValue(); // = 1004 불가.
	

	return 0;
}