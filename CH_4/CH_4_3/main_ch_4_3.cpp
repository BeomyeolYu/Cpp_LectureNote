/*
4.3�� "Using ���� ��ȣ��(Ambiguity)"

- ������ �̸��� �ټ� ��ĥ �� �����Ϸ��� �Ҹ��� ����ϴ� ���� Ambiguity.
- ������ name space��namespace�� �������� ������� �ʴ� ���� ������ ������ �� �ִ�.
- ������ �����ϰ� ���� �������� ������ �ִ� ���α׷����� �ϴ� ���� ��ü ���� ���α׷��ֿ��� ���� ������ �� �� �ִ�.
*/

#include <iostream>

// 2���� namespace���� �̸��� ������ ������ ���ǵǾ���.
namespace a
{
	int my_var(10);
	int count(123);
}

namespace b
{
	int my_var(20);
}

int main()
{
/********* Topic 1 *********/
	// using namespace std;
	using std::cout;
	using std::endl;

	cout << "Hello " << endl;


/********* Topic 2 *********/
	// ������ �̸��� ������ ����� namespace�� ���ÿ� ������ ���.
	/*
	using namespace a;
	using namespace b;
	cout << my_var << endl; // ambiguity ���� �߻�.
	*/ 

	// �ذ� ��� (1): ������� ������ ��Ȯ�ϰ� �����ش�.
	{
		using namespace a;
		cout << my_var << endl;
	}
	{
		using namespace b;
		cout << my_var << endl;
	}

	// �ذ� ��� (2): ���� ���� �����ڸ� Ȱ���Ͽ� �ذ�.
	cout << a::my_var << endl;
	cout << b::my_var << endl;

/********* Topic 3 *********/
	cout << count << endl; // namespace std�� namespace a ���� �浹�� �Ͼ.

	return 0;
}