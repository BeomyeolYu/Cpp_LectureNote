/*
8.3�� "������(Constructors)"

- Constructor�� ������ instant�� �������� ���Ѵ�. 
  �׷���, constructor�� instant�� ��ü������ �����ϴ� ���� �ƴϴ�. 
- Constructor�� construction �� �� ȣ��Ǵ� �Լ��̴�. 
*/

#include <iostream>
using namespace std;

class Fraction1
{
 private: // member variable���� encapsulation �Ͽ� �ǲ� ���ܳ��Ҵ�.
// public: // Topic 2�� �ʱ�ȭ (1), (2)�ÿ� public���� �ٲ�� ��.
	int m_numerator;
	int m_denominator;

public: 
	Fraction1() // constructor: return Ÿ���� ���� class�� �̸��� �����ϴ�.
	{
		m_numerator = 0;
		m_denominator = 1;

		cout << "Fraction() constructor" << endl; // constructor�� ������ Ȯ��. <-- ����� ���� Ȯ���غ� ��.
	}

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

class Fraction2
{
private:
	int m_numerator;
	int m_denominator;

public:
	// Fraction2() {}: constructor�� ������ ������ �ʴ� ��� default constructor�� �����ִ�.
	Fraction2() // default value�� �� constructor�� ���Ƿ� ������� �� �ִ�.
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	
	Fraction2(const int& num_in, const int& den_in = 1) // func.�� �����ϰ� default value�� ���� �� �ִ�.
//  Fraction2(const int& num_in = 1, const int& den_in = 1) // default constructoró�� ����� �� �ִ�.
	{
		m_numerator = num_in;
		m_denominator = den_in;

	}

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

// First class �ȿ��� Second class type�� variable�� member�� ����ִ� ��Ȳ.
class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};
class First
{
	Second sec;

public:
	First()
	{
		cout << "class First constructor()" << endl;
	}

};

int main()
{
/**************** Topic 1 ****************/
	// �ʱ�ȭ�� ���ٸ� �̻��� ���� �Ҵ�ȴ�.
	Fraction1 frac1; 
	frac1.print(); // -858993460 / -858993460 ���.


/**************** Topic 2 ****************/
	// �ʱ�ȭ (1): member variable�� public���� �ٲپ� �ʱ�ȭ.
	Fraction1 frac2{ 0, 1 };

	// �ʱ�ȭ (2)
	frac2.m_numerator = 0;
	frac2.m_denominator = 1;
	frac2.print(); // 0 / 1 ���.


/**************** Topic 3 ****************/
	// �ʱ�ȭ (3): constructor�� �̿��Ͽ� encapsulation�� �����ϸ鼭 �ʱ�ȭ
	Fraction1 frac3; // frac3�� ����ʰ� ���ÿ� constructor�� ����ȴ�.
	frac3.print();

		
/**************** Topic 4 ****************/
	/* ���ǻ���:
	Fraction frac3(); <-- �����ڵ� �Լ��̹Ƿ� ��ó�� ()�� �־�� �Ѵ�. 
	
	Fraction frac3; <-- �׷��� �������� parameter�� �ϳ��� ���� ��쿡�� ()�� �׻� ������ �Ǿ��ִ�.
	--> �ϳ��� constructor�� ����� default constructor�� �������� �ʴ´�.
	*/
	Fraction2 frac(1,3);
	frac.print();


/**************** Topic 5 ****************/
	// �ʱ�ȭ�ϴ� ���.
	/* (1) Fraction2 frac = Fraction2{1,3}; �׷��� �ڵ尡 ������Ƿ� �������� �ʴ´�.
	   (2) Fraction2 frac(1, 3)�� Fraction2 frac{1, 3}�� ����: 
	       ��κ��� ��쿣 ����ϳ� uniform initialization�� { 1.0, 3 }�� ����ȯ�� ������� ������ ( 1.0, 3 )�� ��� �� �� ����Ѵ�.  
		   --> { }�� �� �����ؼ� ���ٴ� ���̴�. */


/**************** Topic 6 ****************/
	// class �ȿ� class�� �ִ� ���.
	First fir;
	// Second�� First�� member�� ����ֱ� ������, member�� ���� �ʱ�ȭ�ϴ� ������ �Ǵ�.

	return 0;
}