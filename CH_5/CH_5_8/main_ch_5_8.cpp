/*
5.8�� "break, continue"

- ����ġ ���� ������ break �ǰų� continue �� �� �ֱ� ������ ��� �ÿ� �� ������ ����Ǿ�� �Ѵ�.
- �⺻���� switch ������ ���ȴ�.
*/

#include <iostream>
using namespace std;

void breakOrReturn()
{
	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'b')
			break;

		if (ch == 'r')
			return; // �Լ� ���� = Hello�� ��� �� �ȴ�.
	}

	cout << "Hello" << endl;
}

int main()
{
/**************** Topic 1 ****************/
	int count = 0;
	while (true)
	{
		cout << count << endl;
		if (count == 10) break; // break�� �⺻ ����: �ڵ� ����� Ż���Ѵ�.
		count++;
	}


/**************** Topic 2 ****************/
	//break�� while ���� �����ϰ�, return�� �Լ��� �����Ѵ�.
	breakOrReturn();


/**************** Topic 3 ****************/
	// continue�� ����Ͽ� Ȧ���� ����� �ϴ� for ��.
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0) continue; /*for ���� ���ٰ� if ���� �����ϴ� ��쿡 continue�� ����Ǿ� 
								  �ϴܺ��� �ڵ带 �������� �ʰ� i�� ������Ű�� �κ����� �ٷ� �̵��Ѵ�. */
		cout << i << endl;
	}


/**************** Topic 4 ****************/
	// continue�� do-while ���� �Բ� ���� ���� ���ǰ� �ʿ��ϴ�.
	int count(0);
	do
	{
		if (count == 5)
			continue;

		cout << count << endl;
	 // count++; // ���� �� �Ǵ� ����.
	}/*  while (count < 10); // �������� �߰�ȣ �ȿ� ������ continue ���ϰ� ���õǱ� ������ �߰�ȣ �ܺο� ����. 
							--> ������ �״���̱� ������ ���� ������ ������. */
	while (++count < 10); // �ذ� ���: while ���� �������� �߰��� ���� �ִ�.


/**************** Topic 5 ****************/
	// break�� ���� ������ �ɾ��ֱ� �� ������ �����ִ� ����: Ư���� Ű�� �޾��� �� �ݺ����� �������´�.
	// ��� 1) flag�� ����ϴ� ���
	bool escape_flag = false;
	while (!escape_flag)
	{
		char ch; // while ���ȿ����� ������ ������ �� ������ �ڵ尡 ������������ ������ ������ ���� �ִ� --> ������ ���ִ� ���� ����.
		cin >> ch;

		cout << ch << " " << count << endl;

		if (ch == 'x')
			escape_flag = true;
	}

	// ��� 2) break�� ����ϴ� ���
	while (true)
	{
		char ch;
		cin >> ch;

		cout << ch << " " << count << endl;

		if (ch == 'x')
			break;
	}

	return 0;
}