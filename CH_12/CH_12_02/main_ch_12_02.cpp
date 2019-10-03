/*
12.2�� "���� �Լ�(Virtual Function)�� ������(Polymorphism)"

- �������� ������ ���� Virtual�̶�� keyword�� ��� ������ Ȱ��ȴ�.
- virtual �Լ��� ����ϰ� ȣ��Ǵ� �Լ��� ����� ��� ���� ���ϸ� �ʷ��ϹǷ� �� �ʿ��� ���� �����ϰ� ����ϴ� ���� ����.
  --> virtual keyword�� stack�� �׿��� �Ϲ����� ȣ�� ����� �ƴϰ� virtual table���� �Լ��� ã�� ����̹Ƿ� ������.
*/

#include <iostream>
using namespace std;

// �Ϲ������� �ǹ������� ����� 2�� ������ �ִ��̴�.
class A
{
public:
	void print() { cout << "A" << endl; }
	virtual void print_v() { cout << "A" << endl; }
};
class B : public A
//class B // ��ӹ��� ������ Hierarchical ������ ������. 
{
public:
	void print() { cout << "B" << endl; }
	void print_v() { cout << "B" << endl; } // = virtual void print_v() { cout << "B" << endl; } --> ���������� virtual�� �ٿ��ش�.
};
class C : public B
{
public:
	void print() { cout << "C" << endl; }
	void print_v() { cout << "C" << endl; } // = virtual void print_v() { cout << "C" << endl; }
	//virtual int print_v() { cout << "C" << endl; return 0; }
	// --> �������̵��� �� �� return Ÿ���� �ٸ���(void vs. int) �����ϵ��� �ʴ´�.
};
class D : public C
{
public:
	void print() { cout << "D" << endl; }
	void print_v() { cout << "D" << endl; } // = virtual void print_v() { cout << "D" << endl; }
	// --> virtual keyword�� ��� class�� �Լ��� �ٿ������ν� ����� ȿ�� �� �������� �����ų �� �ִ�.
};

int main()
{
/**************** Topic 1 ****************/
	A a; 
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();

/**************** Topic 2 ****************/
	A &ref1 = b;
	ref1.print(); // B class�� b�� �ް� �������� ref�� A class�� �״ٴ� ������ A�� ��ó�� �۵��ȴ�.
			 
	B &ref2 = d;
	ref2.print(); // D class�� d�� ��쿡�� B�� ��ó�� �۵��Ѵ�.

/**************** Topic 3 ****************/
	// virtual keyword�� �̿������ν� �ذ��� �� �ִ�.
	ref1.print_v(); 	
	/* �ǹ�: B class�� ������� �ν���Ʈ b�� A�� ref�� �Ҵ��ߴµ� A class �ȿ� ����ִ� �Լ��� virtual�� ��쿡�� 
	        ��ӹ��� class������ �������̵� �� �Լ��� ����Ѵ�. */
	ref2.print_v();
	// --> B class, C class�� print_v�� virtual�� �������� �ʾ������� Hierarchical �����̹Ƿ� D�� ��µȴ�.

	return 0;
}