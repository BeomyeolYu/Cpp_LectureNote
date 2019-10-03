/*
12.3�� "overriid, final, ���� ��ȯ��(Covariant return types)"

- �������� ������ �� �����ϰ� ����� �� �ִ� ����.
*/

#include <iostream>
using namespace std;

/**************** Topic 1 ****************/
class A1
{
public:
	virtual void print(int x) { cout << "A" << endl; }
};
class B1 : public A1
{
public:
	//void print(short x) { cout << "B" << endl; }
	// �Ǽ��� paramater�� int�� �ƴ� short���� ������.
	// --> �Լ��� paramater�� �ٸ��� �����Ϸ��� �������̵��� �ƴ� �����ε��� �Ѵ�.
	void print(short x) override { cout << "B" << endl;	}
	// --> �������̵��Ϸ��� �Լ��� override�� �ǵ������� �����ָ� �����Ϸ��� �̹��� ������ ����ش�.
};

/**************** Topic 2 ****************/
class A2
{
public:
	virtual void print(int x) { cout << "A" << endl; }
};
class B2 : public A2
{
public:
	void print(int x) override { cout << "B" << endl; }
};
class C2 : public B2
{
public:
	void print(int x) final { cout << "C" << endl; } // final�� ������ ���� ��� �Լ������� �������̵� ���� �ʵ��� ���´�.
};
class D2 : public C2
{
public:
	void print(int x) override { cout << "D" << endl; }
};

/**************** Topic 3 ****************/
class A3
{
public:
	void print() { cout << "A" << endl; }
	virtual A3* getThis() { 
		cout << "A::getThis()" << endl;
		return this; }
};
class B3 : public A3
{
public:
	void print() { cout << "B" << endl; }
	virtual B3* getThis() {
		cout << "B::getThis()" << endl;
		return this; }
};

int main()
{
/**************** Topic 3 ****************/
	A3 a;
	B3 b;

	A3 &ref = b;
	b.getThis()->print();
	ref.getThis()->print(); // B::getThis()�� ��������� A�� ��µȴ� --> &ref�� A�̱� ������.

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}