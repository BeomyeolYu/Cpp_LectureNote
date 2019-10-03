/*
8.14강 "클래스 안에 포함된 자료형(Nested types)"

- '중첩 자료형'이라고도 부른다.
- class를 구현할 때 특정한 기능에 맞춰서 특정한 자료형을 특별히 만들어 사용해야할 때가 있다.
*/

#include <iostream>
using namespace std;

class Fruit
{
public: // Nested types: 특정 class에서만 사용되는 자료형.
	enum FruitType 
	{
		APPLE, BANANA, CHERRY,
	};

	enum class Fruittype // enum class 가능.
	{

	};

	class InnerClass // Inner Class 가능.
	{

	};

	struct InneStruct // Inner Struct 가능.
	{

	};

private:
	FruitType m_type; // FruitType이 자료형처럼 사용된다.

public:
	Fruit(FruitType type) 
		: m_type(type)
	{}

	FruitType getType() 
	{ 
		return m_type; 
	}
};

int main()
{
	Fruit apple(Fruit::APPLE);

	cout << Fruit::APPLE << endl;

	if (Fruit::APPLE == apple.getType())
	{
		cout << "Apple" << endl;
	}

	return 0;
}