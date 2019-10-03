/*
12.3강 "overriid, final, 공변 반환형(Covariant return types)"

- 다형성을 구현할 때 유용하게 사용할 수 있는 개념.
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
	// 실수로 paramater를 int가 아닌 short으로 적었다.
	// --> 함수의 paramater가 다르면 컴파일러는 오버라이딩이 아닌 오버로딩을 한다.
	void print(short x) override { cout << "B" << endl;	}
	// --> 오버라이딩하려는 함수에 override를 의도적으로 적어주면 컴파일러가 미묘한 에러를 잡아준다.
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
	void print(int x) final { cout << "C" << endl; } // final을 적으면 하위 상속 함수에서는 오버라이딩 하지 않도록 막는다.
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
	ref.getThis()->print(); // B::getThis()가 실행되지만 A가 출력된다 --> &ref가 A이기 때문에.

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}