/*
5.5�� "�ݺ��� while"
*/

#include <iostream>

using namespace std;

int main()
{
/**************** Topic 1 ****************/
	cout << "While-loop test" << endl;
	int count = 0; // ī���͸� ����.

	while (true)   // ��ȣ ���� ������ true��� �۵�, false��� �۵��Ѵ�. ����ó�� ������ ������ �� ���� true �Ǵ� 1�� �����Ѵ�.
	{
		cout << count << endl; // cout << ++count << endl; = cout << count++ << endl;
		++count; // = count++

		if (count == 10) break; // ���� ���� Ż��.
	}
	// =
	while (count < 10) // ���� ����.
	{
		cout << count << endl;
		++count; 
	}


/**************** Topic 2 ****************/
	// ���� ����! count�� unsigned int�� ���. 
	unsigned int count_ = 10;

	while (count_ >= 0)
	{
		if (count_ == 0)
		{
			cout << "Zero";
		}
		else
		{
			cout << count_ << " ";
		}
		count_--; // Zero ���Ϸ� overflow ������ �߻��Ѵ�. ������ �Ǹ鼭 -1�� 4294967295�� ���.
	}
	/* 
	int�� ���� ���� ������ ������ �� �ִ� ���� ����̳� unsigned int�� ������� ����� ���� �ƴϴ�.
	-> ����ȭ�� �ϰ� �Ǹ� ���α׷��� ����� �����ս��� ���¥�� �ȴ�.
	-> �ڹٳ� ���̽��� ������ ������ �Ѱ谡 �ִ� = c �迭 �� ����ִ� ����.
	-> ���� unsigned int�� signed int���� ������, ������ ��� unsigned int�� �����Ѵ�.
	*/


/**************** Topic 3 ****************/
	// n ���� �� ���� report�� �ϴ� trick. NN code���� �ַ� ���δ�.
	count = 1;

	while (count < 100)
	{
		if (count % 5 == 0)
			cout << "Hello " << count << endl;
		++count;
	}


	return 0;
}