/*
10.6�� "�����̳� Ŭ����(Container Classes)"

- �ٸ� Ŭ�������� ��� Ŭ����.
- ������ ������ �پ��ϴ�. https://en.wikipedia.org/wiki/Standard_Template_Library
- HW�� ���� �����ϸ� �ڷᱸ�� ������ �� ���� �� �ִ�.
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
	// ���
	// IntArray my_arr{1, 3, 5, 7, 9}
	// my_arr.inserBefore(10, 1);    // 1, 10, 3, 5, 7, 9
	// my_arr.remove(3);			 // 1, 10, 3, 7, 9
	// my_arr.push_back(13);         // 1, 10, 3, 7, 9, 13


/**************** Topic 2 ****************/
	// ���ݱ��� ����ؿ� Container Classes�� ����
	std::vector<int> int_vec;
	std::array<int, 10> int_arr;
	// vector�� array�� ���� Container�� ����ؿԴ�.

	return 0;
}
