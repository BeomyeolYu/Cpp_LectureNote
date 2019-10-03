/*
12.1�� "�������� �⺻ ����" 

- ��Ӱ� �����͸� �̿��Ͽ� �ڽ� Ŭ������ ��ü�� �θ� Ŭ������ �����͸� ����Ѵٸ�?
  --> �������� �����Ͽ� �ſ� �߿��� �����̴�.

- �������� ������ �� �����ϸ� ȿ������ ��� ���� ���α׷����� �� �� �ִ�.
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
	// ???�� ����: �ڽ� class�� �θ� class�� �����͸� ����ؼ� ĳ������ ���ѳ��� ȣ���� �ϸ� �ڽ��� �θ� class�� �� �˰� �۵��Ѵ�. 
	// --> �θ� class�� member function �տ� virtual�� �������ν� �ذ��� �� �ִ�.
	// --> �θ� class Ÿ���� pointer�� �ڽ� class�� ��ó�� �ൿ�ϰ� �ִ�. 

/**************** Topic 3 ****************/
	// Ver1. ���߱� ���α׷���
	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for (int i = 0; i < 5; ++i)
		cats[i].speak();
	for (int i = 0; i < 2; ++i)
		dogs[i].speak();
	// ...
	/* �׷��� ��� ���α׷��Ӱ� �Ǹ� for ���� ���������� ���� �� �־�� �Ѵ�
	   --> Cat class�� Dog class ��� Animal class�κ��� �����Ǿ����Ƿ� Animal �����͸� �̿��� �� �ִ�. */

	// Ver2. ��� ���α׷���
	Animal *my_animals[] = { &cats[0], &cats[1], &cats[2], &cats[3], &cats[4],
							&dogs[0], &dogs[1] };  // Animall class�� ������
	for (int i = 0; i < 7; ++i)
		my_animals[i]->speak();
	// --> array �Ǵ� container�� ����Ͽ� �� ȿ�������� ���α׷��� �� �� �ִ�.

	return 0;
}