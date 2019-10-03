/*
4.7강 "열거형(Enumerated types)"

- 생각보다 많이 사용된다.
- int로 저장하는 것 같지만 100% 호환되지는 않으며 casting을 사용할 수 있다.
*/

#include <iostream>
#include <typeinfo>

// 게임에서 공격을 받으면 피해치를 계산하는 함수.
int computeDamage(int weapon_id) // 어떤 무기로 공격받았냐에 따라 데미지가 다르다.
{
	if (weapon_id == 0) // sowrd
	{
		return 1;
	}

	if (weapon_id == 1) // hammer
	{
		return 2;
	}
	// ...
} 
/* 그러나 프로그래머가 모든 번호를 암기하기 어려우므로, 
   열겨형을 사용하여 이를 기호적으로 표현할 수 있다. */

//enum = Enumerate tpye, header file로 만들어서 #include하는 경우가 대부분.
enum Color // 사용자 정의 자료형(user-defined data type)이다. 
{	
	// 일반적으로 대문자로 선언한다.
	COROR_BLACK,   // 마우스를 올리면 enum Color::COROR_BLACK = 0
	COLOR_RED,	   // enum Color::COROR_BLACK = 1
	COLOR_BLUE,	   // = 2
	COLOR_GREEN,   // = 3
	COLOR_SKYBLUE, // = 4
	BLUE, // 다른 블록에 묶여있어도 전역 변수처럼 작동하기 때문에 오류가 발생한다.

}; // ;가 없으면 오류가 발생하니 주의.

enum Feeling
{
	HAPPY = -3, // 수동으로 할당하면 -3부터 번호가 붙여진다.
	JOY,		// -2
	TIRED = 5,	
	SAD = 5,	// 동일한 숫자를 할당하는 것이 가능은 하지만 구분은 불가능하여 같은 것으로 인식된다.
	// BLUE, 
};

using namespace std;

int main()
{
/********* Topic 1 *********/
	// Color를 data type처럼 사용한다.
	Color paint = COROR_BLACK; // 초기화하는 것을 확인할 수 있다.
	Color house(COROR_BLACK);
	Color appe{ COROR_BLACK }; // 위의 두 초기화와 뉘앙스 차이가 있다 --> 클래스 강의에서.


/********* Topic 2 *********/
	Color my_color = COLOR_GREEN;
	cout << my_color << " " << COLOR_GREEN << endl; // 내부적으로 정수로 저장된다.
	
	// 그러나 Color에 정수를 할당할 수는 없다.
    Color my_color = 1; // 오류 발생.

	int color_id = COROR_BLACK;
	cout << color_id + 2 << " " << COROR_BLACK + 2 << endl; // int type 할당은 된다.
    Color my_color = color_id; // 오류 발생. 
	Color my_color = static_cast<Color>(3); // 캐스팅하여 할당하는 방법.

/********* Topic 3 *********/
	// cin으로 값을 직접 받아올 수는 없다.
	cin >> my_color;  // 오류 발생.

	// 우회하여 입력하는 방법.
	int in_number;
	cin >> in_number;
	if (in_number == 0) my_color = COROR_BLACK;
	// 또는 캐스팅하여
	if (in_number == static_cast<Color>(1)) my_color = static_cast<Color>(1);


	return 0;
}