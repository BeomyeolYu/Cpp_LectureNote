/*
5.6�� "�ݺ��� do-while"

- while ���� ���ǿ� ���� ������ �ƿ� �ȵ� ���� ������ do-while ���� ������ �� ���� �����ϰ� ������ ���ɴ�.
- ���������� �˰����� �ۼ��� �� �ݵ�� �� ���� �����ؾ� �ϴ� ��� ���ȴ�.
*/

#include <iostream>
using namespace std;

int main()
{
	int selection; // must be declared outside do-while loop.

	// �Է¹��� ���ڸ� �Ǻ��� ��, ������ ó�� �� ���� ���ڸ� �Է¹޾ƾ߸� �ϹǷ� do-while �� ���.
	do
	{
		cout << "1. add" << endl;
		cout << "2. sub" << endl;
		cout << "3. mult" << endl;
		cout << "4. div" << endl;

		cin >> selection;
	} while (selection <= 0 || selection >= 5); // ������ ���̸� do-while ���� Ż���ϰ� �����̸� �ٽ� do�� �ݺ�.
	{
		cout << "You selected " << selection << endl;
	}

	return 0;
}