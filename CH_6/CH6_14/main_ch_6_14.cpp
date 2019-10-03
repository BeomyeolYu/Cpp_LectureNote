/*
6.14�� "���� ����(reference variable)"

- Ư���� ��쿡 pointer ���� ������ �ְ� ����ϱ� ���ϴ�.
- ��ü ���� ���α׷��ֿ��� ���� ���� ���ȴ�.
- ������ ����ó�� ref�� ���� �� �ִ�.
*/

#include <iostream>

using namespace std;

void doSomething(int &n) // (int n)���� �ѱ�� ���� ��ü�� �����ؾ� ������, ref�� �ѱ�� ���� ��ü�� �Ѿ�� ���̱� ������ ���縦 �� �ʿ䰡 ����.	
                         // --> �ּ������� ���縦 �� �ʿ䰡 ���� �����ս��� �� ����.
{
	cout << &n << endl; // A. 

	n = 10;
	cout << "In doSomething " << n << endl;
}

void printElements(int(&arr)[5]) // element�� ���� [5]�� �� ���� �Ѵ�.
{
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << &arr << endl; // A.
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
/**************** Topic 1 ****************/
	int value1 = 5;
	
	// Pointer
	int *ptr1 = nullptr;
	ptr1 = &value1;

	// Reference variable
	// *�� ���� �ʿ䰡 ������,
	int &ref1 = value1;   // �ݵ�� �ʱ�ȭ�� �ʿ��ϴ�. --> ���� �̸��� �־�� ������ ���� �� �ִ� ��ó��.
  //int &ref = 123;	      // ���������� ���ڿ��� �޸� �ּҸ� ���� �ʱ� ������ �� �� ����. --> �������� �� �� �ִ�.
	cout << ref1 << endl; // A. 

	ref1 = 10; // re-assign ���� = *ptr1 = 10;
	cout << value1 << " " << ref1 << endl; // A.

/**************** Topic 2 ****************/
	/* �ּ� ��� --> &value1�� &ref�� �ּҵ� ����.
				 --> &ref�� ������ �ּҸ� ���� ���� �ƴ϶� ������ �ּҸ� �����Ѵ�.
				 --> �������� ��� ������ ������ �ٸ� �ּҸ� ������ �ִ�. */
	cout << &value1 << endl; // 00EFFC80
	cout << &ref1 << endl;	 // 00EFFC80
	cout << ptr1 << endl;	 // 00EFFC80
	cout << &ptr1 << endl;   // 00EFFC74: ������ ���� ��ü�� �ּҸ� �ٸ���.

/**************** Topic 3 ****************/
	// const�� �Բ� ����ϴ� ���.
	const int value2 = 5;
	// int &ref2 = value2; // ref���� value2�� ���� ���Ƿ� �ٲ� ���� �ֱ� ������ ����� �ȵȴ�.
	const int &ref2 = value2;
		
/**************** Topic 4 ****************/
	// �Լ� ���ο��� n�� �ٲ۴� 
	int n = 5;

	cout << n << endl;
	cout << &n << endl; // �Լ������� ������ �ּҸ� ����Ѵ� = ref�� Ư¡.

	doSomething(n);
	cout << n << endl;	// �Լ��� �������͵� n�� 10���� �����ȴ�.

/**************** Topic 5 ****************/
	// array�� �Լ��� �־��� ���� ref�� ����� �� �ִ�.
	const int length = 5;
	int arr[length] = { 1, 2, 3, 4, 5 };

	cout << &arr << endl;    // A. 
	cout << &arr[1] << endl; // A. 
	printElements(arr);

/**************** Topic 6 ****************/
	// �������� ���� ������ ���� struct with ref
	Other ot;
	ot.st.v1 = 1.0;	// (1) ot�� st�� v1�� ������ �� �ڵ尡 ������ �������.

	cout << ot.st.v1 << endl;	 // A. 
	cout << &(ot.st.v1) << endl; // A.

	int &v1 = ot.st.v1;
	cout << v1 << endl;  // A.
	cout << &v1 << endl; // A.
	v1 = 1;			// (2) ref�� �̿��ϸ� ot.st.v1�� ���� ���ϼ��� ���ϰ� �ӵ��� ���������� �ʴ´�.

/**************** Topic 7 ****************/
	// ref�� ���������δ� pointer�� �����Ǿ� �ִ�.
	int value_ = 5;
	int *const ptr_ = &value_;
	int &ref_ = value_;

	*ptr_ = 10;
	ref_ = 10; // ptr_�� &ref_�� ��ɻ� �����ϴ�.
	
	// [����]
	int concept = 12;
	int *pointer = &concept;
	int &reference = concept;
	cout << concept << " = " << reference << " = " << *pointer << " = " << *&concept << endl;
	cout << &concept << " = " << &reference << " = " << pointer << endl;
	cout << &pointer << endl; // ������ ���� ���� �����̹Ƿ� �Լ� �������� �ּҰ� �ٸ���.

	return 0;
}