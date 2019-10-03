#pragma once

#include <string>
#include "Position2D.h"
// #include <iostream> // Position2D.h�� include �Ǿ� �����Ƿ�.

class Monster // '��ü'
{
private:
	std::string m_name; // ���������� char * data, unsigned length�� �޴� class�̴�.
	//int m_x; 
	//int m_y; // --> location�� ������ class�� �и�; ������ �� ���� ��� �и��ϴ� ���� ������ ���� �ܰ迡�� ����Ǹ� ���� ����.
	Position2D m_location; // Monster�� sub-class�� '��ǰ'.
	/* �ٸ� Ŭ�������� ���� �� �ִ°�? No�� �ǹ�
	--> Position2D ��ü�� ���� class���� ���� �ϱ� ���ؼ� ������ ���̳� m_location�� Monster class������ ���Ǵ� ��ǰ�̴�. */	      
	/* "Composition ����"�� �̿��Ͽ� Monster class�� ����ϰ� ������ �� �ְ�,
	   ������ ��ġ�Ӹ� �ƴ϶� ������ ü��, ����� ��ġ ���� �߰��� �� �����ϴ�. */

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