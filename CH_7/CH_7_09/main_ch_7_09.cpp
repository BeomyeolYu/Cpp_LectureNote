/*
7.9�� "�Լ� ������(Function Pointers)"

- ������ ����� ���� �����͸� �Ѿ� �Լ��� ���� �����Ϳ� ���Ͽ� �н�.
- ��ü ���� ���α׷��ֿ��� �������� ������ �� �Լ� �������� ������ ū ������ �ȴ�.
- ȫ���� �������� �ֱ� �Լ� �����ͺ��� #include <functional>�� ���� ����.
*/

#include <iostream>
#include <array>
#include <functional> // C++ 11 ���� ����.
using namespace std;

/************ Topic 1, 2 & 3 ************/
int func() { 
	cout << "Adress of func function: " << func << endl;
	return 5; 
}
int goo() {	
	cout << "Adress of goo function: " << goo << endl;
	return 10; 
}

/**************** Topic 4 ****************/
int func_(int x) {
	return 5;
}

/**************** Topic 5 ****************/
bool isEven(const int& number) {
	if (number % 2 == 0) return true;
	else return false;
}
bool isOdd(const int& number) {
	if (number % 2 != 0) return true;
	else return false;
}
typedef bool(*check_fun_t)(const int&); // �Լ� �����͵� typedef�� �̿��ؼ� �ٿ��� ����� �� �ִ�.
// = using check_fun_t = bool(*)(const int&); // Type alias�� �̿��ؼ� �����ϰ� ������ �� �ִ�.

void printNumbers(const array<int, 10> &my_array,
	check_fun_t check_fcn = isEven) // default parameter ���� ����.
{
	for (auto element : my_array) // for-each�� �̿��� ¦�� �Ǵ� Ȧ���� ����ϴ� ����.
	{
		if (check_fcn(element) == true) cout << element;
	}
	cout << endl;
}

/**************** Topic 6 ****************/
void printNumbers_(const array<int, 10> &my_array,
	std::function<bool(const int&)> check_fcn)
{
	for (auto element : my_array)
	{
		if (check_fcn(element) == true) cout << element;
	}
	cout << endl;
}

int main()
{
/**************** Topic 1 ****************/
	// �Լ��� �������̸�, �Լ��� �޸𸮿� ���� ����ȴ� (= �Լ��� �ּҸ� ������ �ִ�).
	cout << func() << endl; // 5 ���.
	cout << func << endl;	// ��ȣ�� ���� ��� �ּ� 00BB125D ���.

/**************** Topic 2 ****************/
	// �Լ� �����͸� �����ϴ� ���.
	// func �Լ��� ������ int ��, func �Լ��� parameter�� ���� ������ (), funptr�� ������ó�� ����� ����
	// int(*fcnptr)(); --> �Լ� �������� Ÿ���� ������ �Լ��� return Ÿ�԰� ��ġ�ؾ� �Ѵ�.
	// �ʱ�ȭ�ϴ� ���.
	int(*fcnptr)() = func;

/**************** Topic 3 ****************/
	// �Լ� �����͸� �߰��� �ٲ�ġ���� ���� �ִ�.
	cout << fcnptr() << endl; // �Լ� �����͸� �����ϸ� 5�� ���.
	cout << &fcnptr << endl;  // A.
	cout << fcnptr << endl;   // A.

	fcnptr = goo;			  // �ٸ� �ּҸ� �־��� �� �ִ�.
	cout << fcnptr() << endl; // A.
	cout << &fcnptr << endl;  // A.
	cout << fcnptr << endl;   // A.

/**************** Topic 4 ****************/
	// �Լ��� parameter�� �ִ� ���
	int(*fcnptr_)(int) = func_; // parameter�� �ִ� �Լ� �����ͷ� �����ؾ� �Ѵ�.
	cout << fcnptr_(1) << endl; // parameter ���� ()�� ����θ� ���� �߻�.

	fcnptr_ = goo; // goo�� func_�� parameter�� �޶� ���� �߻�.
    // ��, return type�� parameter type�� ��ġ�ؾ� �Լ� �����͸� ������ �� �ִ�.

/**************** Topic 5 ****************/
	// �Լ� �����͸� �Լ��� parameter�� ���� ���� �ִ�.
	std::array<int, 10> my_array{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		
	printNumbers(my_array);
	printNumbers(my_array, isOdd);	// parameter�� �Լ��� ���� �� �ִ�.

/**************** Topic 6 ****************/
	// #include <functional>
	std::function<bool(const int&)> fcnptr_ = isEven;
	printNumbers_(my_array, fcnptr_);

	fcnptr_ = isOdd; // Topic 1~5 �ּ� ó�� �� ����.
	printNumbers_(my_array, fcnptr_);

	return 0;
}