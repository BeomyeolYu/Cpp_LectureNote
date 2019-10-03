#pragma once

#include <string>
#include "Position2D.h"
// #include <iostream> // Position2D.h에 include 되어 있으므로.

class Monster // '전체'
{
private:
	std::string m_name; // 내부적으로 char * data, unsigned length를 받는 class이다.
	//int m_x; 
	//int m_y; // --> location을 별도의 class로 분리; 가능한 한 빨리 묶어서 분리하는 것이 좋으며 설계 단계에서 고려되면 제일 좋다.
	Position2D m_location; // Monster의 sub-class인 '부품'.
	/* 다른 클래스에도 속할 수 있는가? No의 의미
	--> Position2D 자체는 여러 class에서 재사용 하기 위해서 설계한 것이나 m_location은 Monster class에서만 사용되는 부품이다. */	      
	/* "Composition 관계"를 이용하여 Monster class를 깔끔하게 정리할 수 있고,
	   몬스터의 위치뿐만 아니라 몬스터의 체력, 용사의 위치 등을 추가할 때 유리하다. */

public:
	Monster(const std::string name_in, const Position2D & pos_in)
		: m_name(name_in), m_location(pos_in)
	{}

	void moveTo(const Position2D & pos_target)
	{
		m_location.set(pos_target);
		//m_x = x_target;
		//m_y = y_target;
	}

	friend std::ostream & operator << (std::ostream & out, const Monster & monster)
	{
		out << monster.m_name << " " << monster.m_location;
		return out;
	}
};