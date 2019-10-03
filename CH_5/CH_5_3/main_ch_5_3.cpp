/*
5.강 "switch-case"

- if 문과 비슷하지만 특별한 경우 더 깔끔하게 사용할 수 있는 switch-case문.
*/

#include <iostream>
using namespace std;

enum class Colors
{
	BLACK, // = 0
	WHITE, // = 1
	RED,
	GREEN,
	BLUE,
};

void printColorName(Colors color)
{
	// (1) 함수와 if 문을 이용하여 색을 print 하는 방법.
	if (color == Colors::BLACK)
	cout << "BLACK" << endl;
	// ...
	// 그러나 다수의 케이스를 모두 코딩하는 것은 복잡하므로 switch-case 문 사용.

	// (2) switch-case 문 사용.
	{
		switch (color)
		{
		case Colors::WHITE:
			cout << "WHITE";
			break;
		case Colors::RED:
			cout << "RED";
			break;
		}
	cout << endl;
	}

	// (3) Colors::WHITE가 번거로우므로 enum과 cast의 특성을 이용.
	{
		switch (static_cast<int>(color))
		{
		case 3:
			cout << "GREEN";
			break;
		case 4:
			cout << "BLUE";
			break;
		}
		cout << endl;
	}
}

int main()
{
/**************** Topic 1 ****************/
	// switch-case문의 사용법
	int x;
	cin >> x;

	{
		switch (x)
		{
		case 0:		// if 문과 다르게 해당 case 이후로 모든 case를 실행시킨다. 
			cout << "Zero";
			break;	// 이 경우 무조건 break가 필요하지만, 프로그래머의 의도에 따라 break를 안 쓰는 경우도 꽤 있다. 
		case 1:
			cout << "One";
			break;
		case 2:
			cout << "Two";
			break;
		}
		cout << endl; // endl;을 하나만 쓰는 노하우.
	}


/**************** Topic 2 ****************/
	printColorName(Colors::BLUE);


/**************** Topic 3 ****************/
	// 변수 선언 및 대입에 관한 아주 복잡한 주의 사항!
	switch (x)
	{
		int a, b;	// 선언은 할 수 있지만, 
	 // int b = 5;  // 대입(=초기화)은 할 수 없으며, = switch 문 내에서는 메모리 할당이 안된다.
	
	case 0:
		int y;		// case 다음에는 선언도 가능하고,
		b = 1;	    // 대입(초기화)도 가능하다.
		cout << b << endl;

		y = 5; // 또한 5의 범위는 case 안에서만 지속되므로
		break;
	
	case 1:
		cout << y << endl; /* y = 5로 할당되지 않는다. 
		--> 변수를 사용할 때는 가급적이면 적은 범위에서만 사용되도록 하고 직전에 정의하는 습관을 기르자. */
		cout << a << endl;
		break;
	
	default: // case에서 정의되지 않는 모든 경우의 x에 대하여 수행.
		cout << "Undefined input " << x << endl;
	}
	cout << a << endl; // 또한 switch에서 만들어진 변수는 switch 밖에선 사라진다.

	return 0;
}