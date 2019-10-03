/*
12.2강 "가상 함수(Virtual Function)와 다형성(Polymorphism)"

- 다형성을 구현할 때는 Virtual이라는 keyword와 상속 구조가 활용된다.
- virtual 함수를 빈번하게 호출되는 함수에 사용할 경우 성능 저하를 초래하므로 꼭 필요한 곳에 적절하게 사용하는 것이 좋다.
  --> virtual keyword는 stack에 쌓여서 일반적인 호출 방식이 아니고 virtual table에서 함수를 찾는 방식이므로 느리다.
*/

#include <iostream>
using namespace std;

// 일반적으로 실무에서의 상속은 2번 정도가 최대이다.
class A
{
public:
	void print() { cout << "A" << endl; }
	virtual void print_v() { cout << "A" << endl; }
};
class B : public A
//class B // 상속받지 않으면 Hierarchical 구조가 깨진다. 
{
public:
	void print() { cout << "B" << endl; }
	void print_v() { cout << "B" << endl; } // = virtual void print_v() { cout << "B" << endl; } --> 관습적으로 virtual를 붙여준다.
};
class C : public B
{
public:
	void print() { cout << "C" << endl; }
	void print_v() { cout << "C" << endl; } // = virtual void print_v() { cout << "C" << endl; }
	//virtual int print_v() { cout << "C" << endl; return 0; }
	// --> 오버라이딩을 할 때 return 타입이 다르면(void vs. int) 컴파일되지 않는다.
};
class D : public C
{
public:
	void print() { cout << "D" << endl; }
	void print_v() { cout << "D" << endl; } // = virtual void print_v() { cout << "D" << endl; }
	// --> virtual keyword를 모든 class의 함수에 붙여줌으로써 디버깅 효율 및 가독성을 증대시킬 수 있다.
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
	ref1.print(); // B class의 b를 받고 있음에도 ref를 A class에 뒀다는 이유로 A인 것처럼 작동된다.
			 
	B &ref2 = d;
	ref2.print(); // D class의 d인 경우에도 B인 것처럼 작동한다.

/**************** Topic 3 ****************/
	// virtual keyword를 이용함으로써 해결할 수 있다.
	ref1.print_v(); 	
	/* 의미: B class로 만들어진 인스턴트 b를 A의 ref에 할당했는데 A class 안에 들어있는 함수가 virtual일 경우에는 
	        상속받은 class에서의 오버라이딩 된 함수를 사용한다. */
	ref2.print_v();
	// --> B class, C class의 print_v를 virtual로 선언하지 않았음에도 Hierarchical 구조이므로 D가 출력된다.

	return 0;
}