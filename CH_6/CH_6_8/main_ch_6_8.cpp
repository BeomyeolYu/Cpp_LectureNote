/*
6.8�� "�����Ϳ� ���� �迭"

- ��к��� ���ϸ� �����Ϳ� ���� �迭�� ����.
- ���ǻ��� ������ ���̰� �ִ�.
*/

#include <iostream>
using namespace std;

void printArray(int array[]) // []�� �־ �Է��� arrayó�� �������� pointer�̴�.
// = void printArray(int *array)
{
	cout << sizeof(array) << endl;  // �Լ� �ȿ��� array�� size�� Ȯ���ϴ� ���.
	cout << *array << endl;			// array[0]�� 9 ���.

	*array = 100; // de-referencing �Ŀ� ���� 100���� ����
}	

struct MyStruct
{
	int array_[5] = { 10, 8, 6, 4, 2 };
};
void doSomething(MyStruct ms) 
{
	cout << sizeof(ms.array_) << endl; // array�� struct�� calss �ȿ� ���� ���� pointer�� ���� ��ȯ ���� �ʴ´�.
}
int main()
{
/**************** Topic 1 ****************/
	int array[5] = { 9, 7, 5, 3, 1 };

	cout << array[0] << " " << array[1] << endl; // 9�� 7�� ��µ�.

	// array�� ��� array[0]�� �ּҸ� ��� pointer�̴�. 
	cout << array << endl;     // ���� 16������ ��µ�!
	cout << &array[0] << endl; // ���� ���� ����.
	
/**************** Topic 2 ****************/
	// array�� pointer�� �����ϴٸ� de-referencing �� �� �ִ°�?
	cout << *array << endl; // YES, { 9, 7, 5, 3, 1 }�� �ƴ� 9�� ��µȴ�.

	int *ptr = array;
	cout << ptr << endl;	// array�� ������ �޸� �ּҰ� ��µȴ�.
	cout << *ptr << endl;	// 9�� ��µȴ�.
	cout << &(ptr) << endl; // ��, ptr ��ü�� �ּҸ� ����ϸ� array�� �ٸ���.
													
	// ���ڿ� array�� ��쿡��?
	char name[] = "jackjack";
	cout << *name << endl; // ������ pointer�̹Ƿ� ���� ù ���� j�� ��µȴ�. 

/**************** Topic 3 ****************/
	// �������� ����.
	cout << sizeof(array) << endl; // 20 bytes ��� 
	cout << sizeof(ptr) << endl;   /* 4 bytes ���
								      �ֳ��ϸ� pointer ���� ��ü�� ������� 4 bytes�� �����̱� ����.(x86 ����)
								      array�� int �������־��� ������ 4 bytes�� �ƴϴ�! */
	// ������ �Ǵ� ���.
	printArray(array); // 20 bytes�� �ƴ϶� 4 bytes�� ��µȴ�.

/**************** Topic 4 ****************/
	// pointer�� ���� �Լ� �ȿ��� �ٲ� ���� �Լ� �ۿ����� �ٲ��.
	// C ���� ���� ���̴� ����̸�, C++������ ������ ����� reference�� �����Ѵ�.
	cout << array[0] << " " << *array << endl; // 9�� �ƴ� 100�� ��µȴ�.

/**************** Topic 5 ****************/
	// ������ ����
	cout << *ptr << " " << *(ptr + 1) << endl; // 9+1=10�� �ƴ϶� 7�� ��µȴ�.

/**************** Topic 6 ****************/
	// ����ü �ȿ� array�� ����ִ� ���.
	MyStruct ms;
	cout << ms.array_[0] << endl; // 10 ���.

	cout << sizeof(ms.array_) << endl; // 20 bytes ���.
	doSomething(ms); // �Լ� �ȿ����� 20 bytes ���. 

	return 0;
}