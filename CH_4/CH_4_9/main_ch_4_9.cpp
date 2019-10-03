/*
4.9강 "자료형에게 가명 붙여주기(Type aliases = 가명)"

- 문맥적으로 가명보다는 별명에 조금 더 가깝다.
- 기본적으로
   1) 긴 자료형을 짧게 줄일 수 있다.
   2) 같은 문맥에서 읽기가 편하다.
   3) 유지보수가 쉽다. 
*/

#include <iostream>
#include <vector>
#include <cstdint> // 고정 너비 정수

using namespace std;

int main()
{
/********* Topic 1 *********/
	// 거리와 관련된 변수들을 double type으로 선언할 때 유용하다. 
	// 주석을 달 수도 있지만, 별명을 붙임으로써 특징을 표현할 수도 있다.

	typedef double distance_t; // 관습적으로 type name이라는 뜻의 _t를 붙인다.

	double     my_distance; // 표현 1) my_distance를 double로 쓰겠다.
	distance_t home2work;   // 표현 2) 내 프로그램에서는 distance_t를 double로 쓰겠다.
	distance_t home2school;
	// 컴파일러 입장에서는 표현 1)과 표현 2)는 같으며 프로그래밍 편의에 의해서만 사용됨.


/********* Topic 2 *********/
	// Type aliases를 사용하면 코드의 유지 관리에서도 도움이 된다.
	typedef float distance_t; // double을 float로 바꾸고 싶은 경우
	distance_t home2work;	  // 모든 변수 하나하나 바꿔주지 않아도 된다.
	distance_t home2school;


/********* Topic 3 *********/
	// Template와도 유용하게 사용할 수 있다
	std::vector<std::pair<std::string, int> > pairlist1; // 하나의 자료형으로 생각할 수 있다.
	vector<pair<string, int> > pairlist2;
	vector<pair<string, int> > pairlist3; 
	// ...

	// typedef로 간결하게 표현할 수 있다.
	typedef vector<pair<string, int> > pairlist_t;
	pairlist_t pairlist1;
	pairlist_t pairlist2;
	pairlist_t pairlist3;
	// ...

	// using 또한 동일한 기능으로 사용할 수 있으나 내부적으로는 완전히 다르다.
	using pairlist_t = vector<pair<string, int> > ;
	pairlist_t pairlist1;
	pairlist_t pairlist2;
	pairlist_t pairlist3;
	// ...


/********* Topic 4 *********/
	/* 참고. 고정 너비 정수 (Fixed-width Integers)
	   고정 너비 변수에서 플랫폼에 독립적인 코딩을 할 때도 사용할 수 있다. */
	std::int8_t i(97); // 8 bits = 1 byte 타입으로 바꿔줌 = char
	cout << i << endl;	// Answer is a, not 97.

	return 0;
}