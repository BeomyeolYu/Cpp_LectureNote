/*
4.9�� "�ڷ������� ���� �ٿ��ֱ�(Type aliases = ����)"

- ���������� �����ٴ� ���� ���� �� ������.
- �⺻������
   1) �� �ڷ����� ª�� ���� �� �ִ�.
   2) ���� ���ƿ��� �бⰡ ���ϴ�.
   3) ���������� ����. 
*/

#include <iostream>
#include <vector>
#include <cstdint> // ���� �ʺ� ����

using namespace std;

int main()
{
/********* Topic 1 *********/
	// �Ÿ��� ���õ� �������� double type���� ������ �� �����ϴ�. 
	// �ּ��� �� ���� ������, ������ �������ν� Ư¡�� ǥ���� ���� �ִ�.

	typedef double distance_t; // ���������� type name�̶�� ���� _t�� ���δ�.

	double     my_distance; // ǥ�� 1) my_distance�� double�� ���ڴ�.
	distance_t home2work;   // ǥ�� 2) �� ���α׷������� distance_t�� double�� ���ڴ�.
	distance_t home2school;
	// �����Ϸ� ���忡���� ǥ�� 1)�� ǥ�� 2)�� ������ ���α׷��� ���ǿ� ���ؼ��� ����.


/********* Topic 2 *********/
	// Type aliases�� ����ϸ� �ڵ��� ���� ���������� ������ �ȴ�.
	typedef float distance_t; // double�� float�� �ٲٰ� ���� ���
	distance_t home2work;	  // ��� ���� �ϳ��ϳ� �ٲ����� �ʾƵ� �ȴ�.
	distance_t home2school;


/********* Topic 3 *********/
	// Template�͵� �����ϰ� ����� �� �ִ�
	std::vector<std::pair<std::string, int> > pairlist1; // �ϳ��� �ڷ������� ������ �� �ִ�.
	vector<pair<string, int> > pairlist2;
	vector<pair<string, int> > pairlist3; 
	// ...

	// typedef�� �����ϰ� ǥ���� �� �ִ�.
	typedef vector<pair<string, int> > pairlist_t;
	pairlist_t pairlist1;
	pairlist_t pairlist2;
	pairlist_t pairlist3;
	// ...

	// using ���� ������ ������� ����� �� ������ ���������δ� ������ �ٸ���.
	using pairlist_t = vector<pair<string, int> > ;
	pairlist_t pairlist1;
	pairlist_t pairlist2;
	pairlist_t pairlist3;
	// ...


/********* Topic 4 *********/
	/* ����. ���� �ʺ� ���� (Fixed-width Integers)
	   ���� �ʺ� �������� �÷����� �������� �ڵ��� �� ���� ����� �� �ִ�. */
	std::int8_t i(97); // 8 bits = 1 byte Ÿ������ �ٲ��� = char
	cout << i << endl;	// Answer is a, not 97.

	return 0;
}