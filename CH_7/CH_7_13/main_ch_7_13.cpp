/*
7.13�� "����� ���α׷����� ����(Defensive Programming)"

- ���� ����� ����ϴ� ����Ʈ��� ���� ��, ����ڰ� ��� ����� �ϴ��� ���������� �۵��ϵ��� ���α׷��� �ϴ� ��.
- ������ ������ ���� �����ϴ� �����̴�. ������ �� ���� �����Ա� ���ϱ⺸�ٴ� ������ ���� �þ�����.
- �����Ϸ��� ������ ���� �� �ֵ��� ���α׷��� �ϴ� ������ �⸣��.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// syntax errors(���� ����): �����Ϸ��� ���� ����ش�.
	// int x <-- // ;�� ������ ���� ���.

/**************** Topic 2 ****************/
	// semantic errors(����/�ǹ�/���� ����): �����Ϸ��� ����ֱ� �����Ƿ� ���α׷��Ӱ� �Ĳ��� �����ؾ� �Ѵ�.
	int y;
	cin >> y;

	if (y >= 5) // x >= 5���� ����Ǵ� if ���� ®����,
		cout << "x is greater than 5 " << endl; // "5 ���� ũ��"��� ����ϰ� �Ǿ��ִ�.
	// --> ������ ������ �߻��Ѵ�.

/**************** Topic 3 ****************/
	// violated assumptions(���� ���� ����): ����ڰ� �ǵ��� �ٿ� �ٸ� ������� ���α׷��� ����Ѵ�
	string hello = "Hello, my name is Jack jack";
	
	cout << "Input from 0 to " << hello.size() - 1 << endl; // (1) ���

	while (true) // (2) ����� ���α׷���
	{
		int ix;
		cin >> ix;

		if (ix >= 0 && ix <= hello.size() - 1)
		{
			cout << hello[ix] << endl; // [28] �̻��� cin �ϸ� runtime ������ �߻��Ѵ�.
			break;
		}
		else
			cout << "Please try again" << endl;
	}

	return 0;
}