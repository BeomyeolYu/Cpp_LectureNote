/*
Chapter 4. ���� ������ �� �پ��� ������
4.1�� "���� ������ ����(Scope)�� ���ӱⰣ(Duration)" - ���(���չ�), ��Ī ����, �̸� �浹, �̸� �����

- ���ӱⰣ = �޸��� ���ӱⰣ.
            ������ �����ϸ� OS���� �޸𸮸� ��û�Ͽ� ����ϸ�, �� �̻� ����� �� ���� ������ �Ѿ�� �޸𸮸� �ݳ��ϰ� �������.
 -> ������ ������ ���ӱⰣ�� �Բ�����. (���� �Ҵ��� ���信���� ������ ���ӱⰣ�� �и���.)
*/

#include <iostream>

// namespace ���(1): ������ �����̾ namespace�� ��������ν� Ȯ���� �ٸ��� ǥ���� �� �ִ�.
namespace work1
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}
namespace work2
{
	int a = 1;
	void doSomething() // void doSomething(int b), �Լ��� �̸��� �Ȱ����� �Ķ���Ͱ� �ٸ��� �浹�� �Ͼ�� �ʴ´�.
	{
		a += 5;
	}
}

// namespace ���(2): ����� ���� namespace�� ����ϵ��� �ڵ� (C++ 17�������� ����).
namespace work3
{
	namespace work33 
	{
		namespace work333
		{
			int a = 1;
			void doSomething()
			{
				a += 3;
			}
		}
	}
}
// =
namespace work4::work44::work444
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

int main()
{
	using namespace std;
/********* Topic 1 *********/
	// apple = 1; // (1-1) ���� ���� �߻�.
	int apple = 5; // ����� �������� apple ������ ����� �� �ִ�. �޸� ������ OS�κ��� �Ҵ�޴´�.
	cout << apple << endl;

	{ // �߰�ȣ�� ���(block)�̶�� Ī�Ѵ�.
		apple = 1;
		cout << apple << endl;
	}

	cout << apple << endl;

	{
		int apple = 3; 
		cout << apple << endl;
	} // ���� int apple�� �̸��� ������ ��� �ۿ����� �������. (= ���ӱⰣ�� ����)

	cout << apple << endl;
	cout << endl;

/********* Topic 2 *********/
	/* 
	:: = ���� �Ǵ� ���� ���� ������(scope resolution operator).
	C++���� ���� �켱������ ���� �����ڷν�, ���� �������� ���� �ĺ���(identifier)�� �ĺ��ϰ� �����ϴµ� ���.*/
	
	work1::a;
	work1::doSomething();

	work2::a;
	work2::doSomething();

	work4::work44::work444::doSomething();

	return 0;
}

// apple = 3; // (1-2) apple�� ����� �߰�ȣ�� ����� ������(=�޸𸮰� �ݳ��Ǿ��� ������) ���� �߻�.