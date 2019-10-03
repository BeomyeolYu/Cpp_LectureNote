/*
9.6강 "첨자 연산자([], subscript operator) 오버로딩 하기"
*/

#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // 10개의 메모리 공간이 항상 확보되어 있다.
	// --> 동적 할당으로 구현할 수도 있다.

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}
	// array 자체를 pointer로 return 하는 방식 (array 자체가 pointer이므로).
	int * getList()
	{
		return m_list;
	}

	int & operator [] (const int index) // 필요에 따라 int가 아닌 string 등을 입력으로 받아야 한다.
	{
		assert(index >= 0); // assert로 막아줘야 무시무시한 런타임 에러를 막을 수 있다.
		assert(index < 10);
		return m_list[index];
	}
	// --> &로 return하는 이유: 항상 주소를 가지고 있는 L-value여야 하므로, 값을 읽기도 바꾸기도 하기 위함.

	const int & operator [] (const int index) const // const version으로 만들고 마지막에 const를 붙여 return type도 const도 막는다.
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
	// 번거로운 ()가 없어지도록 오버로딩.
	my_list[3] = 10;
	cout << my_list[3] << endl;


/**************** Topic 3 ****************/
	// const version에서 []를 호출해야 하는 경우.
	const IntList my_list1;
	my_list1[3] = 10; // const version이므로 값을 바꿀 수 없다.
	cout << my_list1[3] << endl; // const version이라도 읽을 수는 있어야 하는데 오류 발생 --> const version operator 생성.


/**************** Topic 4 ****************/
	// 가장 중요한 부분: cassert를 쓰는 것이 좋다.
	/* Q. if 문을 사용하면 되지 굳이 assert를 써야 하느냐?
	   A. subscript operator는 굉장히 많이 사용하려고 만듦으로 속도가 생명이다.
	   --> if 문을 지양하고 assert를 사용하여 성능을 높이고 디버깅을 깔끔하게 하도록 구현. */


/**************** Topic 5 ****************/
	// IntList 자체를 pointer 형태로 사용할 때 주의할 점.
	IntList *list = new IntList;

	// list->operator[];
	list[3] = 10;	 // Not OK, 의도가 다르다. 
	(*list)[3] = 10; // OK, de-referening 후 []를 호출해야 한다.

	return 0;
}