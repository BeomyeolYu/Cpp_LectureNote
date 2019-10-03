/*
10.6강 "컨테이너 클래스(Container Classes)"

- 다른 클래스들을 담는 클래스.
- 종류가 굉장히 다양하다. https://en.wikipedia.org/wiki/Standard_Template_Library
- HW를 통해 이해하면 자료구조 학점을 잘 받을 수 있다.
*/

#include <iostream>
#include <vector>
#include <array>
using namespace std;

class IntArry
{
private:
	int m_length = 0;
	int *m_data = nullptr;

public:
	// Constructors
	// Destructors
	// initialize()
	// reset();
	// resize();
	// inserBefore(const int & value, const int & ix);
	// remove(const int & ix);
	// push_back(const int & value);
};
int main()
{
/**************** Topic 1 ****************/
	// 사례
	// IntArray my_arr{1, 3, 5, 7, 9}
	// my_arr.inserBefore(10, 1);    // 1, 10, 3, 5, 7, 9
	// my_arr.remove(3);			 // 1, 10, 3, 7, 9
	// my_arr.push_back(13);         // 1, 10, 3, 7, 9, 13


/**************** Topic 2 ****************/
	// 지금까지 사용해온 Container Classes의 예시
	std::vector<int> int_vec;
	std::array<int, 10> int_arr;
	// vector나 array와 같은 Container를 사용해왔다.

	return 0;
}
