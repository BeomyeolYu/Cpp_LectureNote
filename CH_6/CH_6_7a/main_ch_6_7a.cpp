/*
6.7�� "�� ������(Null Pointer)"

- pointer ������ ��� �ִ� �ּҷ� ã�ư��µ�, ������ pointer ������ �ּҸ� �Ҵ����� �ʾ� 
  ������ ������ ��(���� �޸𸮿� �Ҵ�� ���� �ƴ�)�� �Ҵ�Ǿ��ִ� ��� ���� �߻�.
--> �̸� �����ϱ� ���� Null Pointer
*/

#include <iostream>
#include <cstddef>
using namespace std;

void doSomething(double *ptr)
{
	cout << "address of pointer variable in doSomething(): " << &ptr << endl;

	if (ptr != nullptr)
	{
		std::cout << *ptr << std::endl;
	}
	else
	{
		std::cout << "Null ptr, do nothing" << std::endl;
	}
}

int main()
{
/**************** Topic 1 ****************/
	double *ptr_1 = 0;		  // (1) C-style
	double *ptr_2 = NULL;	  // (2) C-style
	double *ptr_3 = nullptr;  // (3) modren C++ style
	double *ptr_4{ 0 };		  // (4) modren C++ style
	double *ptr_5{ nullptr }; // (5) modren C++ style

	// null Pointer�� ����
	if (ptr_1 != nullptr)
	{
		// do something useful
		// null�� �ƴ� ��� ���ǹ��� �ڵ� ����.
	}
	else
	{
		// do nothing with ptr
		// ��, null�� �ش�Ǵ� ��� �߸� ���� ���̹Ƿ� �ƹ��͵� ���� ����.
	}

/**************** Topic 2 ****************/
	// �Լ��� �Ķ���ͷ� �Ѿ �� ���� ����.
	double *ptr{ nullptr }; 
	doSomething(ptr);	  // 00DBFD08, "Null ptr, do nothing"
	doSomething(nullptr); // 00DBFD08, "Null ptr, do nothing"

	double d = 123.4;
	doSomething(&d);	  // 00DBFD08, 123.4 
	ptr = &d;
	doSomething(ptr);	  // 00DBFD08, 123.4 
	// �ּҰ� ��� ���� ������ �Լ� ���� �޸𸮿� ����Ǳ� ������ �Լ��� �ּҸ� �������� ���ΰ�?

	cout << "address of pointer variable in main()" << &ptr << endl;
	// �����͵� �ᱹ �����̱� ������ �Լ��� �Ѿ �� ���簡 �Ǿ� �ּҰ� �ٸ���.
	
/**************** Topic 3 ****************/
	// nullptr_t: null�� �޾ƾ� �ϴ� ��쿡 ��� ����. 
	std::nullptr_t nprt; // _t = type


	return 0;
}