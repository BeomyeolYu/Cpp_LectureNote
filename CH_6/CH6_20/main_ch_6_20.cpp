/*
6.20�� "std::array �Ұ�"

- ���� �迭�� ��ü�� �� �ִ� std::array
- #include <array> ���.
*/

#include <iostream>
#include <array>

using namespace std;

// void printLength(array<int, 5> mt_arr) // ����� ������ array�� ����ȴ�.
void printLength(array<int, 5>& my_arr)   // ref �Ǵ� pointer�� �̿�.
// void printLength(const array<int, 5>& mt_arr)// array�� ���� ������ �ʱ⸦ �ٶ� ���� const.
{
	cout << my_arr.size() << endl;
}

int main()
{
/**************** Topic 1 ****************/
	array<int, 5> my_arr = { 2, 5, 1, 4, 3 }; /* = int array[] = {1,2,3,4,5};
												 ������ ,5>�� ���ڰ� ����־�� �Ѵ�. �׷��� �Լ� �Ķ���ͷ� ����� �� �ξ� ���ϴ�. */
	// my_arr = { 0, 1, 2, 3, 4, 5}; // �ʱ�ȭ ������ ���𺸴� ���� ���� �޸� �浹�� �Ұ����ϴ�.
	my_arr = { 0, 1, 2 }; // ������ ������ ��쿡�� 0���� �ʱ�ȭ�ȴ�.

	cout << my_arr[0] << endl; // my_arr�� ���Ҵ� 5���̹Ƿ� [4]������ �����ϴ�. 
	// cout << my_arr[10] << endl; // ������ �� ���� [10]�� ������ �����ϵ� �� �ϵ� ������ �׼����� �غ���.
	cout << my_arr.at(10) << endl; // .at�� 10�� ������ ���� ó���� �ߵ��Ѵ�. ��� �ӵ��� ��������.

/**************** Topic 2 ****************/
	// ���� ��� (1): my_arr.size()
	cout << my_arr.size() << endl; // number of elements

	printLength(my_arr);

/**************** Topic 3 ****************/
	// ���� ��� (2): std::sort
	for (auto &element : my_arr) // ref�� ���̸� �߰��� ����Ǵ� ������ �����ż� ��������.
	// = for (auto element : my_arr)
		cout << element << " ";
	cout << endl;

	// sorting �ϴ� ���: begin & end
	sort(my_arr.begin(), my_arr.end());
	for (auto &element : my_arr) 
		cout << element << " ";
	cout << endl;
	// �߰������� �� ���� �ִ�.

	// ������ orting �ϴ� ���: rbegin & rend
	sort(my_arr.rbegin(), my_arr.rend());
	for (auto &element : my_arr) 
		cout << element << " ";
	cout << endl;

	return 0;
}