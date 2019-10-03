/*
7.11�� "std::vector�� ����ó�� ����ϱ�"

- ���� �Ҵ� �޸𸮸� ���� �����ϴ� �ͺ��� std::vector�� ����ϴ� ���� ���ϴ�.

1) vector�� stack���� ����ϴ� ����: .reserve �س����� capacity�� ���÷� �ø� �ʿ䰡 ���� new & delete�� ���ʿ��ϹǷ� �ӵ��� ��������.
--> size�� �ø��� ���̴� ���·� ����� �� �ִ�.
--> ����: reserve�� �ʹ� ũ�� ������ �޸𸮰� ����� �� �ִ� (�ֽ� ��ǻ�Ϳ����� ���� ������ ���ϴ�).

2) vector�� �� ����ϴ� ���: ���������� new�� delete�� �ּ������� ����ϴ� ��.
--> heap�� �޸𸮿� ������ ��ƿ���(new) �ݳ��ϴ�(delete) ������ ���� �����Ƿ� ���� ���� �ʴ� ���� ����.
*/

#include <iostream>
#include <vector>
using namespace std;

void printStack(const std::vector<int> &stack)
{
	for (auto &e : stack)
		cout << e << " ";
	cout << endl;
}

int main()
{
/**************** Topic 1 ****************/
	std::vector<int> v1;		    // ������ vector ����
	std::vector<int> v2{ 1, 2, 3 }; // + �ʱ�ȭ
	/* ���������δ� ������ ����ϴ� (���������� �ʴ�).
	   int *v_ptr = new int[3]{1, 2, 3}; */

/**************** Topic 2 ****************/
	/* vector���� size�� capacity�� �ִ�.
	   capacity ������ŭ �޸𸮸� ������ ������, size�� '���߿��� �� ���� ����Ѵ�'��� �ǹ��̴�. */

	v2.resize(2); // resize�� �� ���� ���

	for (auto &e : v2) // v2�� ����� ���缭 for-each ���� �ݺ��Ǵ� ���̴�.
		cout << e << " ";
	cout << endl;
		
	cout << v2.size() << " " << v2.capacity() << endl; 
	// resize�� ū ���: capacity = size = 10
	// resize�� ���� ���: capacity�� 3���� �����ϰ� ����� ���� size�� 2�̴�.

	cout << v2[2] << endl;    // (1) vector�� 0���� �����ϸ� v2.resize(2)�� �����Ƿ� v2[2]�� ���� ���̴� --> Runtime error �߻�.
	cout << v2.at(2) << endl; // (2) Runtime error �߻�.
	int *ptr = v2.data();
	cout << ptr[2] << endl;	  // (3) ������ int�� �����͸� �����ͼ� Ȯ���غ��� v2[2]�� 3�� ������ �ִµ� ���� ô �� ���̴�.
	// --> �� ���� ������ new & delete�ϸ� �ӵ��� �������Ƿ� �޸𸮴� �״�� ������ �ִ´�. ��, size�� 2�ε� capacity�� 3�� ���̴�.

/**************** Topic 3 ****************/
	// capacity�� ������ Ű��� ���.
	v2.resize(10); // resize�� �� ū ���

	for (auto &e : v2) 
		cout << e << " "; // �������� 0���� ä������.
	cout << endl;

	v2.reserve(1024); // .reserve = �޸��� �뷮�� �̸� Ȯ���صΰڴٴ� �ǹ�.
	cout << v2.size() << " " << v2.capacity() << endl;
	// --> resize ���� ���� ���Ұ� �߰��� ��, reserve�� ����� ������ �����ִٸ� ���� �޸𸮸� �޾ƿ��� ��ü�ϴ� �۾��� �ʿ� �����Ƿ� �ӵ��� ��������.

/**************** Topic 4 ****************/
	// stackó�� ����ϴ� ��� 
	std::vector<int> stack; // ��� ȣ�⿡ ���� stack overflow�� ���� ���� vector�� stack���� ����ϴ� ��찡 �ִ�.
	// v2.reserve(1024);

	// Stack�� �� �״�� �״´ٴ� �ǹ��̴�. �״� ���� push, ������ ���� pop �Ѵ� ��� �θ���.
	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(7);
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
}