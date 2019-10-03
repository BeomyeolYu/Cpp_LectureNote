/*
10.2강 "구성 관계(Composition)"

- 게임 속에서 몬스터가 출몰하는 예제.
*/

#include "Monster.h"
// #include <iostream> // Monster.h에 include 되어 있으므로.
using namespace std;

int main()
{
	Monster mon1("Sanson", Position2D(0, 0));
	cout << mon1 << endl;

	// while (1) // game loop
	{
		// event
		mon1.moveTo(Position2D(1, 1));
		cout << mon1 << endl;
	}
	/* 멤버의 존재를 클래스가 관리? Yes의 의미
	--> mon1.m_location에서 mon1이 죽으면 m_location도 사라진다. */

	return 0;
}
