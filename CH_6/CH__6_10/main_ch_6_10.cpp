/*
6.10�� "C ��� ��Ÿ���� ���ڿ� �ɺ���(symbolic) ���"

- ���ڿ��� �⺻������ ������ �迭(array)�̸�, array�� pointer�� ȣȯ�� �ȴ�.
- �����Ϸ��� �츮�� �ް����� �ϴ� ��쿡 ���ؼ� �˾ƺ���.
*/

#include <iostream>
using namespace std;

const char* getName()
{
	return "Jack Jack"; // = Topic 2
}

int main()
{
/**************** Topic 1 ****************/
	char name_ [] = "Jack Jack";
	cout << name_ << endl; // A.

	// A. array�� pointer�� ȣȯ�� �Ǵϱ� *�� �ٿ��� ����� �� ������?
    //char *name = "Jack Jack"; // ���� �߻�: "Jack Jack"�� literal�̹Ƿ� �ּҸ� ��� pointer���� ���� �� ����.
	                            // --> �׷����� �ұ��ϰ� "Jack Jack"�� ��ȣ���� ����� ����� �� �ִ�.
	const char *name = "Jack Jack"; // const�� �ٿ������ν� �����Ϸ��� �޸𸮸� ������ �ʰ� �� ����� �ִ´�.
	cout << name << endl; // A.

/**************** Topic 2 ****************/
	// �������� Ư�� (1): �̸��� �ٸ��� ���� ���.
	const char *name1 = "Jack Jack";
	const char *name2 = "Jack Jack"; // 

	cout << (uintptr_t)name1 << endl; // �ּ�: 2634024
	cout << (uintptr_t)name2 << endl; // �ּ�: 2634024
	/* �и��� *name�� *name2 �ٸ��� �����ߴµ� �ּҰ� ����.
	   --> �� �� "Jack Jack"���� �����ϹǷ� �����Ϸ��� ���� �ϳ��� �����ش�. */

/**************** Topic 3 ****************/
	// �������� Ư�� (2): �Լ��� return Ÿ�Կ� ���ڿ��� ���� ���.
	const char *name3 = getName();
	const char *name4 = getName(); // ������ �Լ� ȣ��.

	cout << (uintptr_t)name3 << endl; // �ּ�: 2634024
	cout << (uintptr_t)name4 << endl; // �ּ�: 2634024
	// --> ������ Topic 2�͵� �ּҰ� ����!

/**************** Topic 4 ****************/
	// �������� Ư�� (2-1): ���� �������� Ư��.
	int int_arr[5] = { 1, 2, 3, 4, 5 }; // int array.
	char char_arr[] = "Hello, World!";  // ���ڿ� array.
	const char *name5 = "Jack Jack";	// pointer�� array�� ȣȯ ����.

	cout << int_arr << endl;  // 00CFF9FC	   : int array�� �ּҰ� ���.
	cout << char_arr << endl; // Hello, World! : ���ڿ� array�� ���ڰ� ���.
	cout << name5 << endl;	  // Jack Jack	   : pointer�� ���ڰ� ���.
	/* --> cout������ ���ڿ� �����͸� Ư���ϰ� ǥ���ϱ� ������ ���� ���.
	   --> cout�� cout << name5 << endl;���� *name5�� �ּҸ� ����ϴ� ���� �ƴ϶� 
	       null character�� ���� �� ���� ���ڿ��� ��� ����Ѵ�. */

/**************** Topic 5 ****************/
	// �������� Ư�� (2-2): ���� �������� Ư��.
	char c = 'Q';
	cout << &c << endl;  // Topic 4�� ������ ������ &c�� �ּҸ� ����ϴ� ���� �ƴ϶� ���ڿ��� �����Ѵ�.
	cout << *&c << endl; // de-referencing�� �ϸ� ���������� 'Q'�� ����Ѵ�.

	return 0;
}