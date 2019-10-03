/*
6.6�� "C��� ��Ÿ���� �迭 ���ڿ�"
*/

#include <iostream>
#include <cstring> 

using namespace std;

int main()
{
/**************** Topic 1 ****************/
	char myString[] = "string"; // ���콺�� �ø��� char myString[7] = 6���� + null character(\0)

	// null character(\0)�� ���ԵǾ� �ִٴ� ����.
	for (int i = 0; i < 7; ++i)
	{
		cout << myString[i] << endl; // �������� �� ���̴� ���ڰ� �ϳ� �ִ�.
		// ASCII
		cout << (int)myString[i] << endl; // �������� 0�� ��µȴ� --> 115�� s, 0�� NUL in ASCII table.
		// sizeof
		cout << sizeof(myString) / sizeof(myString[0]) << endl; // null character�� �����Ͽ� ����� 7�̴�.
	}

/**************** Topic 2 ****************/
	// cin�� �̿��� ���ڿ� �Է�.
	char cinString[255]; // �� ���ڰ� �Էµ��� �𸣱� ������ ���� ū ���ڸ� ��´�. 
	
	cin.getline(cinString, 255); // buffer ����.
	cinString[0] = 'A';  // ù ��° ���ڰ� ������ A�� �ٲ��.
	cinString[10] = '\0'; /* char�� �迭�� �� ���ڿ��� ����� ���� ���� �Ͻÿ� ��µǴ� ���� �ƴ϶�,
						    null character�� ������ �������� ��µǴ� ���̴�(=��� �ߴ�). */
	int ix = 0;
	while (true) // cinString�� ����ִ� ���ڿ��� ��� ����ϴ� ����.
	{
		if (cinString[ix] == '\0') break; /* �Ҵ�� 255���� ������ ��� ���ٰ� null�� ������ �������Ͷ�.
										   --> ��ĭ(32)�� null(0)�� �ּҰ� �ٸ���. */
		cout << cinString[ix] << " " << (int)cinString[ix] << endl;
		++ix;
	}

/**************** Topic 3 ****************/
	// #include <cstring>�� �̿��� �������� c��� ��Ÿ�� �ڵ�.
	char source[] = "Copy this! ";
	char dest[50]; // destination <--��ǥ, �ִ� 50���ڰ� ���� �� �ִ�.
	
	strcpy(dest, source); /* strcpy = string copy; source�� �ִ� ���� destination�� ���翡 �ִ� �Լ�.
						    --> �׷��� ���콺�� �ø��� source���� const�� �پ��ִ�. */
	cout << source << endl;
	cout << dest << endl;

	/* �׷��� source���� dest�� ������ (ex, char dest[5];) �޸𸮸� ħ���ϹǷ� Runtime error�� �߻��Ѵ�.
	   �̸� �����ϱ� ���Ͽ� �ֱٿ� strcpy_s�� �ݰ��������� ����ϵ��� �Ǹ��ϰ� �ִ�. */
	strcpy_s(dest, 50, source); // s = secured, �ִ� ������ ���� �� �ִ� �޸𸮸� �Է��ؾ� �Ѵ�.

/**************** Topic 4 ****************/
	// �߰����� c��� ��Ÿ�� �Լ�.
	
	/* strcat(): cat = concatenate(��Ʈ�� ����)
	   string2�� string1�� �����ϰ� �� ���ڷ� ��� ��Ʈ���� ����. */
	strcat(dest, source);
	cout << source << endl;
	cout << dest << endl;

	/* strcmp(): cmp = compare
	   if ���� �������� ����� �� �ſ� ���ǰ� �ʿ���. 
	   --> cout < 0: string1�� string2���� ����: 
		   cout = 0: string1�� string2�� ���� = if ���� false
	       cout > 0: string1�� string2���� ŭ = if ���� ture   
    */
	cout << strcmp(dest, source) << endl; // 1 ���
	
	return 0;
}