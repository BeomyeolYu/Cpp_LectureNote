#include <iostream>
#include "MyConstants.h"

extern int b = 3;

void doSomething_2()
{
	using namespace std;

	cout << "In test.cpp " << Constants::pi << "memory adress ? " << &Constants::pi << endl;
}