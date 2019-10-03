/*
2.9�� "�ɺ��� ���(Stmbolic Constants)": C++ 11 constexpr
*/

#include <iostream>
#define PRICE_PER_ITEM 30 /* C ���α׷��ֿ��� ���� ���̴� '��ũ��' (�빮�ڷ� ��ũ�θ� �����ϴ� ���� ������).
							�׷��� C++������ ��ó�����̹Ƿ� ���� ������ �������ϰ� ������� ����� �� ������ ����. */
#include"MY_CONSTANTS.h" // header file include.

using namespace std; // 'namespace�� ��ġ�� �ٲ۴�'��� �ǹ̴� ���� ������ �ٲ� ����.

void printNumber(const int my_number)  // �Լ��� input parameter�� const�� �������ν� �ٸ� ���α׷��Ӱ� ���� �ٲ� �� ������ ��.
// = printNumber(const int& my_number) // const int& �ε� ǥ���� �� ����.
{
	cout << my_number << endl;
}

int main()
{
	/******* Topic 1 *******/
	/* ����,
	double gravity{ 9.8 }
	�̶�� ������ �� �ٸ� ���α׷��Ӱ� ���� �س��� ���Ǹ� �ٲ��� �ʱ⸦ ���� ��, const�� �ٿ��� gravity�� �� �ٲ۴ٰ� ���� ���� �� ����. */
	const double gravity{ 9.8 }; 
	// = double const gravity{ 9.8 }; ������ ���� �����ϰ� �Ϲ������� const�� ������ �ٲ㵵 ������. 
	
	/*
	const double gravity; // �ʱ�ȭ���� ������ Error�� �߻�.
	gravity = 1.2;		  // �����Ǹ� �Ϸ��� �ϸ� Error�� �߻�.
	*/


	/******* Topic 2 *******/
	printNumber(123); // const�� �Լ��� parameter�ε� ���� ����.


	/******* Topic 3 *******/
	// (1) ������ �� ��(= "������ Ÿ��"��) my_const�� ���� �̹� ������. constexpr�� Ȱ���Ͽ� (2)���� �����Ͽ� ǥ���ص� �� ����.
	const int my_const(123); // = constexpr int my_const(123); 

	// (2) special_number�� ���� ��Ÿ�� �� �� (cin����) ������.
	int number;
	cin >> number;
	const int special_number(number); // "�� Ÿ��"�� �����Ǳ� ������ constexpr�� ����ϸ� ������ �߻�.
	/* [����] ��� ������� ��Ÿ������ ������ �ð������� �߿����� ���� �� ������ C++ ���� ��Ÿ�� ��� ��ſ� ������ Ÿ�� ����� �䱸�ϴ� �� ���� ��찡 �ִ�. (ex. ���� ũ�� �迭�� ���̸� �����ϴ� ���)
	�̿� ���� �� ���� Ư������ �����ϱ� ���� C++ �� constexpr�� ����������, constexpr Ű���带 ����� ����� ������ �ð� ������� �Ѵ�. */



		��ó: https://boycoding.tistory.com/156 [�ҳ��ڵ�]

	/******* Topic 4 *******/
	int num_item = 123;
	int price = num_item * PRICE_PER_ITEM; // ����� ���������� ��ũ�η� ������� �����ϴ� ����� ������� �ʴ� ���� ����.

	const int price_per_item = 30; // �߰�ȣ �������� �����ϴ� ���� Ȯ���� Ȯ���� �� ����. ���������� const ���� ǥ���ϱ� ���� k_, ceff_ ���� ���̱⵵ ��.
	int price_ = num_item * price_per_item;


	/******* Topic 5 *******/
	/* const�� ������ �����ϰų� �Ϲ�ȭ�� �ʿ��� ���� �ֱ� ������ const���� ��Ƴ��� ������ ����.
	�� ���� ��Ƴ����� ���� �����ϰ� ���� �� �ϳ��ϳ� ã���� �ٲ�� �� �ʿ䰡 �����Ƿ� ��Ƴ��� ����.

	������ namespace�� �̿��ϰ� ������ header file�� �̿��ؼ� ������: constants::pi
	-> "MY_CONSTANTS.h"�� ���� ��� ������ �����س����� �ٸ� .cpp ���Ͽ����� ������ ������ ������ ����. 
	*/
	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;

	return 0;
}

