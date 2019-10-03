/*
2.7�� "������(Char type)"

- ���ڷ� ���ڷ� ǥ���ϴ� ���: ASCII TABLE ����.
  (1~32�������� unprintable character�� ȭ�鿡 ����� �ȵ�.)
*/

#include <iostream>
#include <limits>

int main()
{
	using namespace std;

	/******* Topic 1 *******/
	char c1(65);  // same as c1 = 65; c1{65};
	char c2('A'); // �� ���ڸ� ǥ���� ���� ��������ǥ, ���ڿ��� ǥ���� ���� ū����ǥ. "Hello, World".

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl; // = casting.
	/*
	(Type) casting: �� ��ȯ

	���α׷����� �ϴ� ���� ���� �ٸ� �������� ������ �ϴ� ������ �ʿ�� �ϰ� ��.
	���� ��� double�� ������ ���� int�� ������ �����ϰų�, float�� ������ double�� ������ ���� �����ϴ� �� ��.

	 int a;
	 double b;
	 b = 2.4;
	 a = b; **** Error ****
	-> Casting
	 b = 2.4;
	 a = (int)b;
	*/

	/******* Topic 2 *******/
	// C-style casting
	cout << (char)65 << endl;
	cout << (int)'A' << endl;

	// Cpp-style casting
	cout << char(65) << endl; // 65�� char�� �ٲ۴ٴ� ���亸�ٴ� 65�� �ʱ�ȭ�� char�� char(65)�� ���� ����ٴ� �ǹ�.
	cout << int('A') << endl;

	// ���� 2���� ������ ��ȯ�� �ϴ� ������ ���ϰ� Static cast�� �⺻������ ��ȯ�� �� �����Ϸ����� ������ ������ �̸� üũ �� ���ּ����� ������ ���ϴ�.
	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;

	/******* Topic 3 *******/
	// static_cast�� ������ ���� ���� ����.
	// static_cast�� �ص� ���� ������ ����� ���� �ٲ����� ����.
	char ch(97);
	cout << ch << endl;
	cout << static_cast<int>(ch) << endl;
	cout << ch << endl;

	/******* Topic 4 *******/
	// c1�� ����� 1���ڸ� ���� �� �ֱ� ������ 3����(abc)�� �Է��ص� ���� �� ����.
	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;
	// ���� 2���ڴ� string opeator�� buffer��� �ӽ� ����ҿ� �����ִ�. �� ��� ������ ���� �߰��ϸ� ��.
	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;
	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;

	/******* Topic 5 *******/
	cout << sizeof(char) << endl; // 1
	cout << (int)std::numeric_limits<char>::max() << endl; // 127
	cout << (int)std::numeric_limits<char>::lowest() << endl; // -128

	cout << sizeof(unsigned char) << endl;  // 1
	cout << (int)std::numeric_limits<unsigned char>::max() << endl; // 255
	cout << (int)std::numeric_limits<unsigned char>::lowest() << endl; // 0

	/******* Topic 6 *******/
	cout << int('/n') << endl; // new line = 10(ASCII TABLE)
	cout << "This is the first line \n second line";

	cout << int('/t') << endl; // tab = 9(ASCII TABLE)
	cout << "This is the first line \t second line";

	cout << int('/a') << endl; // audio 
	cout << "This is the first line \a second line";

	return 0;
}