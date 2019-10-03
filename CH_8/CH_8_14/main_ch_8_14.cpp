/*
8.14�� "Ŭ���� �ȿ� ���Ե� �ڷ���(Nested types)"

- '��ø �ڷ���'�̶�� �θ���.
- class�� ������ �� Ư���� ��ɿ� ���缭 Ư���� �ڷ����� Ư���� ����� ����ؾ��� ���� �ִ�.
*/

#include <iostream>
using namespace std;

class Fruit
{
public: // Nested types: Ư�� class������ ���Ǵ� �ڷ���.
	enum FruitType 
	{
		APPLE, BANANA, CHERRY,
	};

	enum class Fruittype // enum class ����.
	{

	};

	class InnerClass // Inner Class ����.
	{

	};

	struct InneStruct // Inner Struct ����.
	{

	};

private:
	FruitType m_type; // FruitType�� �ڷ���ó�� ���ȴ�.

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