/*
9.8강 "형변환을 오버로딩 하기: static_cast; typecasts"
*/

#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	// cast operator를 주석으로 처리하면 암시적 형변환이 되지 않음을 볼 수 있다.
	operator int()
	{
		cout << "cast here" << endl;
		return m_cents;
	}
};

class Dollar
{
private:
	int m_dollar;

public:
	Dollar(const int& dollor) : m_dollar(dollor) {}

	operator Cents() // <-- class의 이름을 적어줌으로써 Cents로 형변환한다.
	{
		return Cents(m_dollar * 100); // 1 dollar = 100 cents
	}
};

void printInt(const int &value)
{
	cout << value << endl;
}

int main()
{	
/**************** Topic 1 ****************/	
	Cents cent(7);
	printInt(cent);
	// 모두 동일한 의미.
	int value = (int)cent;
	value = int(cent);
	value = static_cast<int>(cent);

/**************** Topic 2 ****************/
	// Dollar를 Cents로 형변환하는 예제.
	Dollar dol(2);
	Cents cents = dol;
	printInt(cents);

	return 0;
}