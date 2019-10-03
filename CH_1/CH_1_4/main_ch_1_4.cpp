/*
1.4�� "����� ��Ʈ������ ù ���� cin, cout"

����� ��Ʈ���� �̿��ؼ� ���� ���ϴ� ������ �ܼ� â�� ����ϰ�,
����ڷκ��� �Է��� �ޱ⵵ �ϴ� ����� �˾ƺ�.

cin = console-in
cout = console-out
endl = end-of-line
*/

#include <iostream> // cout, cin, endl; ...
#include <cstdio>	// printf

int main()
{
	using namespace std; // std�� �ݺ��ؼ� ���� ���ŷο� ��, { }���̿����� std�� �� �ᵵ �����.

	// 1��. cout
	int x = 1024;
	double pi = 3.141592;

	std::cout << "I love this lecture!\n"; // << std::endl;
	// std = namespace.
	// << = output operator.
	// \n = new line. (std::endl�� ���� ��������� ������ ����.)
	std::cout << "x is " << x << "pi is" << pi << std::endl;

	std::cout << "abc" << "\t" << "def" << std::endl;
	// \t = tab, �ڵ����� �ٸ����� ����.
	std::cout << "ab" << "\t" << "cdef" << std::endl;

	cout << "\a";
	// \a = audio �Ҹ� ���.

	// 2��. cin
	//int x; // x�� ó������ �ƹ��� ���� ���ų� garbage ������ �ʱ�ȭ�Ǿ� ����.
	
	//int x = 1;
	//cout << "Before your input, x was " << x << endl;
	
	cin >> x;
	// >> = input operator.
	// �Է¹޴´� = �����͸� �����Ѵ�.
	cout << "Your input is " << x << endl; // �Է��� ���� �����Ͽ� �����.

	return 0;
}