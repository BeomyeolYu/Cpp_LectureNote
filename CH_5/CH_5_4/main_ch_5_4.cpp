/*
5.4�� "goto ��"

- CPU�� �۾��� �����ϴ� �߿� goto ���� ������ ������ ��ġ�� �̵��Ѵ�.
- �ݺ����� ����������� �ֱٿ� '���İ�Ƽ �ڵ�'�� �� �� �־ �� ������ �ʴ´�.
*/

#include <iostream>
#include <cmath> // sqrt()

using namespace std;

int main()
{
/**************** Topic 1 ****************/
	double x;

tryAgain : // label

	cout << "Enter a non-negative number" << endl;
	cin >> x;

	if (x < 0.0)		// x�� 0���� ������ sqrt ��꿡 ������ ����Ƿ� goto ������ �����Ѵ�.
		goto tryAgain;	// goto�� ������ label�� �̵��϶�.

	cout << sqrt(x) << endl;


/**************** Topic 2 ****************/
	// �� ������ �ݴ��̱� ������ y�� ���ǵ��� �ʾ� ������ �߻�.
	goto skip;

	int y = 5;

skip :

	y += 3;

	return 0;
}