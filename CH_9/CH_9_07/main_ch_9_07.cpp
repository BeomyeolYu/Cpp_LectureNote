/*
9.7�� "��ȣ ������(parenthesis,()) �����ε��� �Լ� ��ü(Func. object(Functor))"

- ��ȣ �����ڴ� Ư¡�� �Լ��� ȣ���� �� ����Ѵ�.
  --> ��ȣ �����ڸ� �����ε��ϸ� ��ġ �Լ��� ��ü(Functor)�� ��ó�� ����� �� �ִ�.
  --> �Լ��� ȣ���ϵ� ��ü�� ȣ���� �� �ִ�.
  --> �Ϲ� �Լ��ʹ� �޸� ��� ������ ��� �Լ��� ���� �� ������ �˰��� ó���� ������.
*/

#include <iostream>
using namespace std;

class Accumulator // = ����, ����
{
private:
	int m_counter = 0;

public:
	int operator()(int i) 
	{
		return (m_counter += i); // m_counter�� i�� ���ϰ� m_counter�� return.
	}
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl; // 20�� 0�� ���ϴ� ���� �ƴ϶� 10�� ��������.
	cout << acc(20) << endl; // ��ġ ��ü acc�� �Լ�ó�� ȣ��Ǵ� ���� Functor��� �θ���.

	return 0;
}