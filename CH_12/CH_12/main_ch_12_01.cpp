/*
12.1강 "다형성의 기본 개념" 

- 상속과 포인터를 이용하여 자식 클래스의 객체에 부모 클래스의 포인터를 사용한다면?
  --> 다형성과 관련하여 매우 중요한 질문이다.

- 다형성의 개념을 잘 이해하면 효율적인 상속 구조 프로그래밍을 할 수 있다.
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const
	//void speck() const
	{
		cout << m_name << " ???" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof" << endl;
	}
};

int main()
{
/**************** Topic 1 ****************/
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

/**************** Topic 2 ****************/
	Animal *ptr_animal1 = &cat;
	Animal *ptr_anmial2 = &dog;
	
	cout << &cat << endl;
	cout << &dog << endl;

	ptr_animal1->speak();
	ptr_anmial2->speak();
	// ???인 이유: 자식 class를 부모 class의 포인터를 사용해서 캐스팅을 시켜놓고 호출을 하면 자신이 부모 class인 줄 알고 작동한다. 
	// --> 부모 class의 member function 앞에 virtual을 붙임으로써 해결할 수 있다.
	// --> 부모 class 타입의 pointer가 자식 class인 것처럼 행동하고 있다. 

/**************** Topic 3 ****************/
	// Ver1. 초중급 프로그래머
	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for (int i = 0; i < 5; ++i)
		cats[i].speak();
	for (int i = 0; i < 2; ++i)
		dogs[i].speak();
	// ...
	/* 그러나 고급 프로그래머가 되면 for 문의 개수조차도 줄일 수 있어야 한다
	   --> Cat class와 Dog class 모두 Animal class로부터 유도되었으므로 Animal 포인터를 이용할 수 있다. */

	// Ver2. 고급 프로그래머
	Animal *my_animals[] = { &cats[0], &cats[1], &cats[2], &cats[3], &cats[4],
							&dogs[0], &dogs[1] };  // Animall class의 포인터
	for (int i = 0; i < 7; ++i)
		my_animals[i]->speak();
	// --> array 또는 container를 사용하여 더 효율적으로 프로그래밍 할 수 있다.

	return 0;
}