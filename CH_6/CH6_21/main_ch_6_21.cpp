/*
6.21강 "std::vector 소개"

- 동적 배열을 대체할 수 있는 std::vector
- 장점은 메모리를 자동으로 지워주며, 자신의 size를 스스로 기억하여 함수의 파라미터로 사용할 때 편리하다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	std::array<int, 5>;     // 정적 배열은 사이즈를 정해주어야 했지만,
	std::vector<int> array; // 동적 배열은 사이즈를 추후에 정해줄 수 있다.

	// 초기화 방법 (1)
	std::vector<int> array2 = { 1, 2, 3, 4, 5 };
	cout << array2.size() << endl;

	// 초기화 방법 (2)
	std::vector<int> array3 { 1, 2, 3,};
	cout << array3.size() << endl;

/**************** Topic 2 ****************/
	// 사이즈를 필요할 때 임의로 바꿀 수도 있다.
	vector<int> arr = { 1, 2, 3, 4, 5 };

	arr.resize(10); // <-- 나머지는 0으로 할당. arr.resize(2) 등으로 줄일 수도 있다. 

	for (auto &itr : arr)
		cout << itr << " "; // A. 
	cout << endl;

	cout << arr.size() << endl; // A.
	cout << arr[1] << endl;		// A. 
	cout << arr.at(1);			// A. 

	return 0;
}