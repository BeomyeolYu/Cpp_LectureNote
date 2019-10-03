/*
7.5�� "�پ��� ��ȯ ����(Returning values)" - ��, ����, �ּ�, ����ü, Ʃ��(Tuple)

- �Լ��� ����� ���, �� ��ȯ ���� ��� ���� ���ΰ�?
*/

#include <iostream>
#include <array>
#include <tuple>
using namespace std;

// (1) ���� ���� ����
int getValue1(int x1) // return Ÿ���� int�̴�.
{
	int value1 = x1 * 2; // int value�� ������ �ǰ�, 6���� �ʱ�ȭ�� �ȴ�.
	return value1;       // �Լ� ������ ������ �ȴ�.
}

// (2) �ּҿ� ���� ����
int* getValue2(int x2) // int*�� Ÿ���� �ٲ��ְ�,
{
	int value2 = x2 * 2; 
	return &value2;    // return ���� �ּҷ� �ٲ��ش�.
}
int* allocateMemory(int size)
{
	return new int[size];
}

// (3) ������ ���� ����
int& getValue3(int x3) // int&�� Ÿ���� �ٲ��ش�.
{
	int value3 = x3 * 2; 
	return value3;    
}
int& get(std::array<int, 100>& my_array, int ix)// �Լ����� Ư�� element�� ix�� ref�� return���ش�.
{
	return my_array[ix];
}

// struct�� �̿��� ���� ���� return �� ��ȯ, Ư�� C style���� �ַ� ����.
struct S
{
	int a, b;
	double c, d;
};
S getStruct()
{
	S my_s{ 1, 2, 3.0, 4.0 };
	return my_s;
}

// tuple�� �̿��� ���� ���� return �� ��ȯ.
std::tuple<int, double> getTuple() // <>�� ���ϴ� return Ÿ���� �־��ָ�, std::tuple<int, double> ��ü�� ����� ���� �ڷ���ó�� �ۿ��Ѵ�.
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}

int main()
{
/**************** Topic 1 ****************/
	// 1. Return by value
	int value1 = getValue1(3); // getValue1 �Լ��� ����� ����� 6�� main�� int value�� �����ؼ� ����.
	/* ����: �����ϴ�.
	   ����: ����� ���簡 �ݺ������� ��Ÿ���Ƿ� �ӵ��� ���ϵȴ�; Ư�� array, class, struct ���� ����� ��. */

/**************** Topic 2 ****************/
	// 2. Return by address������ ���� ����: �ǿ����� ����� CH_7_04
	// (1) �ּҷ� ���� �޴� ���
	int *value2 = getValue2(3); // �Լ��� ������ ����� ���� value2�� �ּҸ� �޾ƿ��� ���� �ſ� �����ϴ�.
	cout << *value2 << endl;    // ���� ��µ����� ������ ��.

	// (2) de-referencing�� �̿��ؼ� ���� �޴� ���
	int value3 = *getValue2(3); // �Լ��� ������ ����� ���� value2�� de-referencing �ϴ� ���� �������� �����Ƿ� �������� �ʴ´�.
	cout << value3 << endl;     // ���� ��µ����� ������ ��.

	// (����) Ư���� ������� ���ȴ�. ex) design pattern
	int *array = allocateMemory(1024);
	delete[] array;

/**************** Topic 3 ****************/
	// 3. Return by reference
	int value4 = getValue3(5);

	// ���ǻ���: &value4
	// int &value4 = getValue3(5);

	// ref�� func. ���� ������ ����.
	std::array<int, 100> my_array; // �켱 �޸𸮸� �����ϰ� ��Ƶ� ä��,
	my_array[30] = 10; // Ư�� element�� ���� �ٲ� �� �ִ�.
	// �̸� �����ϰ� func. �� �̿��Ͽ� ǥ���Ѵٸ�,
	get(my_array, 30) = 1024; // return ���� get(my_arrat,30)�� �ϳ��� ����ó�� ����Ͽ� 1024�� ����.
	get(my_array, 30) *= 10;  // func. �� �̿��Ͽ� ���� ���ϰ� ����Ѵ�.
	cout << my_array[30] << endl;
	
/**************** Topic 4 ****************/
	// ���� ���� return ���� �޴� ��� (1): struct
	S my_s = getStruct();
	my_s.b;
	cout << my_s.a << " " << my_s.d << endl;

/**************** Topic 5 ****************/
	// ���� ���� return ���� �޴� ��� (2): tuple
	std::tuple<int, double> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl; // = a
	cout << std::get<1>(my_tp) << endl; // = d

	// C++ 17 �������� ����.
	auto[a, d] = getTuple();
	cout << a << endl;
	cout << d << endl;

	return 0;
}