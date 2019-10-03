/*
7.3�� "������ ���� �μ� ����(Passing Arguments by Reference)" - Call by Reference

- ���簡 ���� ��� ���� ����̱⵵ �ϸ� ���� ���Ͽ� ���� �ҽ����� ���� ������.
- Call by Reference�� ����ϴ� ������ �⸣�� ��κ��� ��쿡 �������� ����.
*/

#include <iostream>
#include <cmath> // sin(), cos()
#include <vector>
using namespace std;

void addOne1(int y)
{
	y = y + 1; // y�� �Լ� ������ ������ ���� �������.
	cout << "In the addOne1 " << y << " " << &y << endl; // 6 & �ּ�B
	// --> ���� ���� ȣ�⿡���� �Լ� �ȿ��� ���Ӱ� ������ �����ϰ� �����Ѵ�.
}
void addOne2(int &y) // �׷��� ref�� y�� �����ϴ� ��쿡��
{
	y = y + 1; // ���� ��ü�� ref�� �Ѿ���� ������ �״�� �����ִ�.
	cout << "In the addOne2 " << y << " " << &y << endl; // 6 & �ּ�A 

}

// degrees�� ���������� ������ ���Դٰ� ������ ��ġ�� �ʴ� �Է����� �� �� �ִ�.
void getSinCos(const double degrees, double &sin_out, double &cos_out) // �Ϲ������� �Է��� �տ� �ΰ� ����� �ڿ� �д�.
{
	// static�� ����ϸ� ������ �Լ� ������ �Ź� ���� ���ǵǴ� ���� �ƴ϶� ������ �ȴ�.
	static const double pi = 3.141592; // ���е��� ���� ������ �� �ִ�.
	const double radians = degrees * pi / 180.0; // <-- ���� ������ �ʴ� �͵��� const�� ���������� ���̴� ���� ����.

	sin_out = std::sin(radians);
	cos_out = std::sin(radians);

	/* ���� Tip: static���� ���� �κ��� ������ �� ���� �Ǵ� ���� �̿�!
    static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi;  */
}

// void foo(int &x)    // �ּҰ� ���� literal�� ��쿡�� ���� �߻�.
void foo(const int &x) // �Է¿��� const�� ���̴� ������ �ִ�.
{
	cout << x << " " << &x << endl;
}

// ������ ������ ref�� �޴� ���.
// void voo(int *&ptr) = void voo((int*) &ptr)
typedef int* pint;
void voo(pint &ptr)
{
	cout << ptr << " " << &ptr << endl;
}

void printElement1(int(&arr)[5]) {}     // ����! ���ȣ ���� element�� ���� �� �־�� �Ѵ�.
void printElement2(vector<int>& arr) {} // �ֱ� �߼��̸� ���� ����ϴ�. = const vector

int main()
{
/**************** Topic 1 ****************/
	int x = 5;
	cout << "Initial x " << x << " " << &x << endl; // 5 & �ּ�A

	addOne1(x);
	cout << "Outside the addOne1 " << x << " " << &x << endl; // 5 & �ּ�A 
	// --> x�� �״�� 5�̴�. �Լ� �������� 6���� ����. "MATLAB ���� ������, �ſ� ����"

	addOne2(x);
	cout << "Outside the addOne2 " << x << " " << &x << endl; // 6 & �ּ�A
	// --> x ��ü�� 6���� ����Ǿ����� �ּҵ� �����ϴ�. "MATLAB ������ ����"
	
/**************** Topic 2 ****************/
	/* C�� C++ ���������� �Լ��� return ���� �ϳ��ۿ� �� �� ����.
	   --> �Լ��� return ���� ���� �� �־�� �ϴ� ��Ȳ���� ref�� ����� �� �ִ�. 
	   --> ������ �̸� �����ϰ� Call by Reference�� �ؼ� ��ġ output�� ������ ��ó�� ������ �� �ִ�. */
	double sin(0.0);
	double cos(0.0);

	getSinCos(90.0, sin, cos);

	cout << sin << " " << cos << endl;
	   
/**************** Topic 3 ****************/
	// Call by Reference�� �Ѱ�: �ּ� �Ǵ� const�� �ʿ��ϴ�.
	foo(6); // <-- void foo(int &x)�� ����ϸ� �ּҰ� ���� literal�� ��쿡�� ���� �߻�.

/**************** Topic 4 ****************/
	// �����Ϳ� ���� ref�� ���� �� �ִ�.
	int y = 5;
	int *ptr = &y; // == pint ptr = &y;

	cout << &y << " " << ptr << " " << &ptr << endl;
	voo(ptr);

/**************** Topic 5 ****************/
	// array�� �Ķ���ͷ� �����ϴ� ���.
	int arr1[]{ 1, 2, 3, 4, 5 };       // (1) ���� array
	vector<int> arr2{ 1, 2, 3, 4, 5 }; // (2) std::vector

	printElement1(arr1);
	printElement2(arr2);

	return 0;
}