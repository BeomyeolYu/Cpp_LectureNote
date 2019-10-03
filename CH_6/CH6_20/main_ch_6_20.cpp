/*
6.20강 "std::array 소개"

- 정적 배열을 대체할 수 있는 std::array
- #include <array> 사용.
*/

#include <iostream>
#include <array>

using namespace std;

// void printLength(array<int, 5> mt_arr) // 실행될 때마다 array가 복사된다.
void printLength(array<int, 5>& my_arr)   // ref 또는 pointer를 이용.
// void printLength(const array<int, 5>& mt_arr)// array의 값이 변하지 않기를 바랄 때는 const.
{
	cout << my_arr.size() << endl;
}

int main()
{
/**************** Topic 1 ****************/
	array<int, 5> my_arr = { 2, 5, 1, 4, 3 }; /* = int array[] = {1,2,3,4,5};
												 단점은 ,5>에 숫자가 들어있어야 한다. 그러나 함수 파라미터로 사용할 때 훨씬 편리하다. */
	// my_arr = { 0, 1, 2, 3, 4, 5}; // 초기화 개수가 선언보다 많을 때는 메모리 충돌로 불가능하다.
	my_arr = { 0, 1, 2 }; // 개수가 부족한 경우에는 0으로 초기화된다.

	cout << my_arr[0] << endl; // my_arr의 원소는 5개이므로 [4]까지만 가능하다. 
	// cout << my_arr[10] << endl; // 선언할 수 없는 [10]을 넣으면 가능하든 안 하든 무조건 액세스를 해본다.
	cout << my_arr.at(10) << endl; // .at은 10이 넘으면 예외 처리를 발동한다. 대신 속도가 느려진다.

/**************** Topic 2 ****************/
	// 편리한 기능 (1): my_arr.size()
	cout << my_arr.size() << endl; // number of elements

	printLength(my_arr);

/**************** Topic 3 ****************/
	// 편리한 기능 (2): std::sort
	for (auto &element : my_arr) // ref를 붙이면 중간에 복사되는 과정이 생략돼서 빨라진다.
	// = for (auto element : my_arr)
		cout << element << " ";
	cout << endl;

	// sorting 하는 방법: begin & end
	sort(my_arr.begin(), my_arr.end());
	for (auto &element : my_arr) 
		cout << element << " ";
	cout << endl;
	// 중간까지만 할 수도 있다.

	// 역으로 orting 하는 방법: rbegin & rend
	sort(my_arr.rbegin(), my_arr.rend());
	for (auto &element : my_arr) 
		cout << element << " ";
	cout << endl;

	return 0;
}