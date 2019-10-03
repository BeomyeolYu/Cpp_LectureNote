/*
9.7강 "괄호 연산자(parenthesis,()) 오버로딩과 함수 객체(Func. object(Functor))"

- 괄호 연산자는 특징상 함수를 호출할 때 사용한다.
  --> 괄호 연산자를 오버로딩하면 마치 함수가 객체(Functor)인 것처럼 사용할 수 있다.
  --> 함수를 호출하듯 객체를 호출할 수 있다.
  --> 일반 함수와는 달리 멤버 변수와 멤버 함수를 가질 수 있으며 알고리즘 처리가 빠르다.
*/

#include <iostream>
using namespace std;

class Accumulator // = 누적, 축적
{
private:
	int m_counter = 0;

public:
	int operator()(int i) 
	{
		return (m_counter += i); // m_counter에 i를 더하고 m_counter를 return.
	}
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl; // 20을 0에 더하는 것이 아니라 10에 더해진다.
	cout << acc(20) << endl; // 마치 객체 acc가 함수처럼 호출되는 것을 Functor라고 부른다.

	return 0;
}