/*
7.8�� "�Ű������� �⺻��(Default Parameters)"

- Parameter�� ���� �� ���� �� �Ź� �� �־��ִ� ���� ���ŷο� �� �����Ƿ� ���� ��� argument�� �������� �� �ִ�.
- Default parameter, Optinal parameter, Default argument ������ �Ҹ���.
*/

#include <iostream>
#include <string>
using namespace std;

/**************** Topic 1 ****************/
void print1(int x = 0) // "x�� �Է��� ���� �� 0�� �־��ּ���." <-- 0 �̿ܿ��� �⺻���� ������ �� �ִ�.
{
	cout << x << " " << endl;
}
void print2(int x, int y = 20, int z = 30) // �ټ��� parameter���� default�� ������ ���� ������ �����Ͽ� ���� �� ������, ������ parameter���� ������ default�� ������� �Ѵ�.
{
	cout << x << " " << y << " " << z << endl;
}

/**************** Topic 2 ****************/
void print(int x = 10, int y = 20, int z = 30) {} // in header

/**************** Topic 3 ****************/
void print3(std::string str) {}
void print3(char ch = ' ') {} // default parameter�� ������ �ִ�.

void print4(int x) {} // ambiguous
void print4(int x, int y = 20) {} // default parameter�� �����ϸ� ������ ������ �������.

int main()
{
/**************** Topic 1 ****************/
	print1(100); // 100 ���.
	print1();	 // default 0 ���.

	print2(100); // �ϳ��� x���� argument�� ����.
	print2(100, 200);
	print2(100, 200, 300);
	
/**************** Topic 2 ****************/
	// ������ �� 1: declaration�� definition�� �и��� ���.
	/*���� �Լ��� header file�� ���� definition �Ǵ� ��찡 ����.
	  .hpp���� ���ǵ� �Լ��� .cpp���� declaration�� �� ��, default Parameter�� .hpp�� .cpp �߿� �� ���� �־��־�� �Ѵ�.
	  --> ������ header file���� definition�� declaration �� default Parameter�� �� ���� ���ش� */
	 
/**************** Topic 3 ****************/
	// ������ �� 2: default parameter�� �Լ� �����ε��� ������ �ش�.
	print3(); // ���콺�� ������ void print3(char ch = '')�� �����Ѵ�.

	print4(10);

	return 0;
}