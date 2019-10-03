/*
4.8�� "���� ���� ������ (������ Ŭ����)"
	 Scoped Enumerations (Enum Class)

- �������� ���� �Ǵ� �Ǽ��� ���ɼ��� �ٿ��ִ� Enum Class.
- Enum Struct�� ������ Class�� �� ���� ����.

- enum�� ���������� int�� �����ϰ� ���ǰ�, �ٷ� int�� ������ �񱳵� �ϰ� ���� �ٸ� enum ������ �񱳰� �����ߴ�.
  ������ �����ڵ��� �̷��� ���� ���� �ʴ´ٰ� �����ϰ� �� �������� enum�� ���� ���� �ٷ� enum class�̴�.
  ���� ���� ū �������� enum class�� ����ȯ�� �������� ���������� �Ǿ� �������� �Ǽ��� �߻��� ���׸� �����ϰ��� �ϴ� ����
  ������ enum�� ������ �ִ� ������ ������ �ذ��ϰ��� �� ���̴�.
*/

#include <iostream>

using namespace std;

int main()
{
/********* Topic 1 *********/
	enum Color
	{
		RED,
		BLUE,
	};

	enum Fruit
	{
		BANANA,
		APPLE,
	};

	Color color = RED;
	Fruit fruit = BANANA;

	if (color == fruit)
		cout << "Color is fruit? " << endl;
	/* int�� �ٲ㼭 ���ϱ� ������ ���� ���� ������ Ȯ�ε����� �Ǽ��� ���ɼ��� Ŀ����.
	   ---> enum class ��� */


/********* Topic 2 *********/
	enum class Color_
	{
		RED_,
		BLUE,
	};

	enum class Fruit_
	{
		BANANA_,
		APPLE_,
	};

	Color_ color1 = Color_::RED_;
	Fruit_ fruit_ = Fruit_::BANANA_;

	if (color1 == fruit_) // �ٸ� class������ �񱳰� �Ұ����ϴ�.
		cout << "Color is fruit? " << endl; 

	Color_ color2 = Color_::RED_;
	if (color1 == color2) // ���� class������ �񱳰� �����ϴ�.
		cout << "Color is color? " << endl;


	return 0;
}