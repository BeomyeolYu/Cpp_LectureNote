/*
6.17�� "C++11 For-each �ݺ���" - C++ 11

- array�� for ������ ���� �� �����ϰ� ������ �� �ִ� ���.
*/

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 12, 21, 34, 55, 89 };
	
	// for (int i = 0; i < ...; i++) // for ���� iter Ƚ���� �˱� ���� �ʾҴ�.
	// ...

/**************** Topic 2 ****************/
	// output: number���� fibonacci�� �ִ� ���ҵ��� �� ���� ���´�.
	// int�� auto�ε� ���� ����Ѵ�.
	for (const int number : fibonacci) // = for (auto number : fibonacci)
		cout << number << " ";
	cout << endl;

/**************** Topic 3 ****************/
	// change array value --> ref�� ������ ��.
	for (int &number : fibonacci) // = for (auto &number : fibonacci)
		number *= 10;
	for (const int number : fibonacci) // = for (const auto number : fibonacci)
		cout << number << " ";
	cout << endl;

/**************** Topic 4 ****************/
	// array���� Max �� ã��. 
	int max_number = numeric_limits<int>::lowest(); // int���� ���� �� �ִ� �ּҰ�.
	// lowest�� �־��� Ÿ��(int)�� ���� ���� ���ڸ� return ���ش�.

	for (const auto &n : fibonacci)
		max_number = max(max_number, n); // �� �������� ū �� ��ȯ
	cout << max_number << endl;

/**************** Topic 5 ****************/
	/* array�� ���� �Ҵ��ϸ� For-each�� ����� �� ����.
	   ��ſ� vector ���; vector�� ���� �Ҵ��� ���� ���� ����� �� �ֵ��� std::�� ����ִ�.
	   ���� �Ҵ� �迭 ��ſ� vector�� ����� �� �ִ�. */

	vector<int> fibonacci_ = { 0, 1, 1, 2, 3, 5, 8, 12, 21, 34, 55, 89 };

	return 0;
}