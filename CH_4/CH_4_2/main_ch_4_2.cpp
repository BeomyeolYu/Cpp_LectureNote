/*
4.2�� "���� ����(Global variable), ���� ����(Static variable), 
       ���� ����(Internal linkage), �ܺ� ����(External linkage)"

- ���� ������ ������ ������� �ʴ� ���� ����. �ε����ϰ� ����ؾ߸� �ϴ� ��쿡�� ���.

- (1) ��� �ȿ��� ������ ��� ������ ���ѵ� �ִ� ���(=Local variable)���� "linkage�� ����"��� ǥ��.
  (2) ������ ���������� �ش� ���� �������� ��𼭵� ����� �� �ִ� ���. = Internal linkage
  (3) .cpp ������ ���� ���� ������, �� ���Ͽ��� ������ ������ �ٸ� cpp ���Ͽ����� ����� ������ ���. = External linkage
	  �׷��� ������ ������ ���� ���Ͽ��� ����ϴ� ���� ���� ������ �ʴ�.
  ��, ���� .cpp ���Ͽ� ������ִ� �������� linking �ϸ鼭 ���� ���� ���� ���踦 �������(=�ܺ�) ������ �ʴ���(=����)�� ����.

- ���� ���� ����: ��ü ���� ���α׷����� �����Ͽ� ���� ������ �ּ������� ����ϴ� ��.
*/

#include <iostream>
using namespace std;

int value = 123; // Global variable. �� ���� �ȿ����� ��𼭵� ����� �� �ִ�. g_value�� ǥ���������ν� �Ǽ��� ���� �� �ִ�.
// static int value = 123; // ���� ������ static�� �������ν� �ٸ� cpp���Ͽ��� ���� �� ������ ���� �� �ִ�.

void doSomething() // Static variable, ���� (����) ����, ���� ���α׷��ֿ��� �� ������ ������ ������ϰų� �׽����� �� ���� ���ȴ�. (ex, �Լ��� �� �� ����ǳ� Ƚ���� üũ�� ��)
{
	static int a = 1; /* static�� ��: a�� �޸𸮰� �������� �Ҵ�ȴ� = ��� �ȿ��� a�� �ٽ� ����� �� ���� �޸𸮸� ����ϸ� �ʱ�ȭ�� �� ���� �����Ѵ�.
					  -> Static variable�� ������ ���� ������ �ʱ�ȭ�� �����ؾ� �Ѵ�. ��, static int a;(X)
					  -> Static variable�� �Ϲ������� �ܺο��� ������ �� ����. */
	// int a = 1; /* �̶�� �����ϸ� �Լ��� �ݺ��� ������ �޸𸮸� �޾Ҵٰ� OS�� �ݳ��ϰ� �ٽ� OS�κ��� �Ҵ�޴� ������ �ݺ��ȴ�. �Լ��� �����ϸ� �ʱ�ȭ�� �� ����Ǿ� 2�� ��µȴ�.
	/* int a = 1;�� ���� �����ν� �Ҵ��Ͽ� ����ϸ� static int�� ���� ����� ���´�. */
	++a;
	cout << a << endl;
}

/* #include "test.cpp"�� ����� �� ������ .cpp ������ ���� #include �ϴ� ���� ������ �ʴ�.
 ��ſ� forward declaration�� ���; "��򰡿� doSomething_2��� �Լ��� ����(=body)�� �����ϹǷ� liking �� �� ����ϼ���"��� ��. */
void doSomething_2(); // = extern void doSomething_2();
extern int b;

#include "MyConstants.h"

int main()
{
/********* Topic 1 *********/
	// ���� ����(Global variable)
	cout << value << endl; // 123 ���.

	int value = 1; // Global variable�� �̸��� ���� ������ name hiding�� �۵��ȴ�.
	cout << value << endl; // 1 ���.
	cout << ::value << endl; // 123 ���. ���� �����ڸ� ����Ͽ� �ٸ� ������ ���ǵ� ������ ������ �� �ִ�.



/********* Topic 2  *********/
	// ���� ����(Static variable)
	int a = 10;

	doSomething(); // 2 ���. (int a = 1�� ������ ���: 2 ���)
	doSomething(); // 3 ���. (int a = 1�� ������ ���: 2 ���)
	doSomething(); // 4 ���. (int a = 1�� ������ ���: 2 ���)
	// Global variable�� ������ ������� �ʴ� ���� ���� ���� -> 11�� ��µ��� �ʴ´�.


/********* Topic 3 *********/
	// �ܺ� ����(External linkage) with test.cpp
	/* linkage�� linking�� ����������, ���ӽ� ���̰� �ִ�.
	linking�� ���� ��ü(N)�� ���ϰ� linking�� ������ ��Ų��(V)�� �ǹ̰� ����.*/
	cout << b << endl;



/********* Topic 4 *********/
	/* ���� ���: #include "MyConstants.h"
	   ������ header file���� pi�� ȣ���Ͽ����Ƿ� ��� ����� ������ �޸� �ּҴ� �ٸ���.
	   �޸� ���� �ҷ�����ų �� �ִ� 
	-> ������ �޸𸮴� ����ϴ� ��: .cpp���� �ʱ�ȭ�� ���ְ� .h������ ���� ���ش�. */
	cout << "In main.cpp " << Constants::pi << "memory adress? " << &Constants::pi << endl;

	doSomething_2();

	return 0;
}