/*
6.21�� "std::vector �Ұ�"

- ���� �迭�� ��ü�� �� �ִ� std::vector
- ������ �޸𸮸� �ڵ����� �����ָ�, �ڽ��� size�� ������ ����Ͽ� �Լ��� �Ķ���ͷ� ����� �� ���ϴ�.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	std::array<int, 5>;     // ���� �迭�� ����� �����־�� ������,
	std::vector<int> array; // ���� �迭�� ����� ���Ŀ� ������ �� �ִ�.

	// �ʱ�ȭ ��� (1)
	std::vector<int> array2 = { 1, 2, 3, 4, 5 };
	cout << array2.size() << endl;

	// �ʱ�ȭ ��� (2)
	std::vector<int> array3 { 1, 2, 3,};
	cout << array3.size() << endl;

/**************** Topic 2 ****************/
	// ����� �ʿ��� �� ���Ƿ� �ٲ� ���� �ִ�.
	vector<int> arr = { 1, 2, 3, 4, 5 };

	arr.resize(10); // <-- �������� 0���� �Ҵ�. arr.resize(2) ������ ���� ���� �ִ�. 

	for (auto &itr : arr)
		cout << itr << " "; // A. 
	cout << endl;

	cout << arr.size() << endl; // A.
	cout << arr[1] << endl;		// A. 
	cout << arr.at(1);			// A. 

	return 0;
}