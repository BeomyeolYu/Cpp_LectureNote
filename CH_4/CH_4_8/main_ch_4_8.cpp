/*
4.8강 "영역 제한 열거형 (열거형 클래스)"
	 Scoped Enumerations (Enum Class)

- 열거형의 단점 또는 실수의 가능성을 줄여주는 Enum Class.
- Enum Struct도 있으나 Class를 더 많이 쓴다.

- enum은 내부적으로 int와 동일하게 사용되고, 바로 int형 변수와 비교도 하고 서로 다른 enum 끼리도 비교가 가능했다.
  하지만 개발자들은 이러한 경우는 맞지 않는다고 생각하고 더 제약적인 enum을 만들어낸 것이 바로 enum class이다.
  따라서 가장 큰 차이점은 enum class는 형변환이 기존보다 제약적으로 되어 개발자의 실수로 발생할 버그를 방지하고자 하는 점과
  기존의 enum이 가지고 있던 스코프 문제를 해결하고자 한 것이다.
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
	/* int로 바꿔서 비교하기 때문에 둘이 같은 것으로 확인되지만 실수할 가능성이 커진다.
	   ---> enum class 사용 */


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

	if (color1 == fruit_) // 다른 class끼리는 비교가 불가능하다.
		cout << "Color is fruit? " << endl; 

	Color_ color2 = Color_::RED_;
	if (color1 == color2) // 같은 class끼리만 비교가 가능하다.
		cout << "Color is color? " << endl;


	return 0;
}