/*
7.7�� "�Լ� �����ε�(Function Overloading)"

- Function Overloading: ������ �̸��� Function�� ���� �� ����� ��.
*/

#include <iostream>
#include <string>
using namespace std;

/**************** Topic 1 ****************/
int add(int x, int y) {return x + y;}
double add(double x, double y) {return x + y;}
/* "����" double add(int x, int y)�� ���� parameter�� ���� �Լ��� 2�� ������ ���� �߻�.
  --> C++������ return Ÿ���� �ٸ� �� �����δ� Overloading�� �� �ǰ� parameter�� �޶�� �Ѵ�. */

/**************** Topic 2 ****************/
int get1(int x) {}
double get1(double y) {}
// �� ref�� ����Ͽ� void�� ������ �� �ִ�.
void get2(int& x) {}	
void get2(double& y) {}
// �� ��� parameter�� ���� �����޴´�.

/************** Topic 3 & 4 **************/
// typedef�� �ص� ������ type�̶�� Overloading�� �Ұ����ϴ�.
typedef int my_int;
void print1(int x) {}
void print1(my_int x) {} 

// �������� match ����
// Topic 3: match�� �ȵǴ� ���.
void print2(const char *value) {} // <-- ������
void print2(int value) {}
// Topic 4: ��Ȯ�� �� �´� ���� ��� ���� ��ȣ�� ���.
void print3(unsigned int value) {}
void print3(float value) {}

int main()
{
/**************** Topic 1 ****************/
	// (1) parameter�� �ٸ����� ����� ����� ��쿡 ���.
	add(1, 2); // �����Ϸ��� �˾Ƽ� �ڷ����� ���� �������� ���ش�.
	add(3.0, 4.0);

/**************** Topic 2 ****************/
	// (2) void�� ref�� �̿��Ͽ� Overloading.
	int x;
	get2(x); // �ٸ�, �Է����� return ���� �������� ������ ������ �ȵ� �� �ִ�.

/**************** Topic 3 ****************/
	print2(0);   // 0�� int��� ���� ��Ȯ�� �� �� �ִ�.
	print2('a'); // 'a'�� char�� �ƴ� void print(int)�� �ν��Ѵ�.
	print2("a"); // "a"�� void print(char)�� const�� �ٿ���߸� �Ѵ�.

/**************** Topic 4 ****************/
	// �ǵ��� �ٸ� ��Ȯ�ϰ� ǥ���ؾ� Overloading�� ����� �� �ִ�.
	print3('a');	  // (unsigned int)'a'
	print3(0);		  // 0u
	print3(3.141592); // 3.141592f

	return 0;
}