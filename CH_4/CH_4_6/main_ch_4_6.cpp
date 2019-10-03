/*
4.6�� "���ڿ� std string �Ұ�(std::string)"
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
/********* Topic 1 *********/
	cout << "Hello, world" << endl; // ���콺�� �ø��� const char[13]�� ǥ�õȴ�.
	/* ���⼭ []�� �迭(array).
	���ڴ� 12�������� [13] ���� ǥ���Ǵ� ������ �� �ڿ� "����"�� ǥ���ϴ� �� ���̴� ���ڰ� �����ִ�. */


/********* Topic 2 *********/
	const char mt_strs [] = "Hello, World"; /* (1) �⺻������ ���Ǵ� ���. */
	const string my_hello = "Hello, World"; /* (2) ���α׷����� ���Ǹ� ���Ͽ� �����Ǵ� string�� ����ϴ� ���.  <-- #include <string>
											      '����� ���� �ڷ���'������ �������� �Ǹ��� �������� �⺻ �ڷ���ó�� ���δ�.
											      [1] �ʱ�ȭ ��� */
	const string my_hello_("Hello, World");    // [2] �ʱ�ȭ ���
	const string my_hello__{ "Hello, World" }; // [3] �ʱ�ȭ ���

	cout << my_hello << endl;



/********* Topic 3 *********/
	string my_ID = "123"; /*  123�� �̿��� ������ �������� �ʴ� = �����ν� ��޵��� �ʴ´�.
	string my_ID = 123;      ��, ���� �߻� --> ������ ���ڿ��� "�Ͻ���" ����ȯ ���ִ� ����� ���� ������. (�ٲ� ���� �ִ�) */



/********* Topic 4 *********/
	// string�� �Է� ���; Jack Jack�� �Է��Ͻÿ�.
	cout << "Your name? : ";
	std::string name; // = std::string name;
	cin >> name;
	cout << "Your age? : ";
	string age;
	cin >> age;
	cout << name << " " << age << " " << endl;

	/* Jack Jack�� �Է��ϸ� �� ���� name�� age ���ÿ� Jack Jack�� �Էµȴ�.
	�ֳ��ϸ� cin�� ��ĭ�� "�Է� �� �޾Ҵ�"��� �����Ͽ� ���ۿ� ��Ƶ״ٰ� 2��° cin�� �Ѱ��ֱ� �����̴�.
	---> getline�� ����Ͽ� �ذ��� �� �ִ�; line ������ �ԷµǸ� ���� ĥ ������ �Է��� ��ġ�� �ʴ´�. */
	cout << "Your name? : ";
	string name_;
	std::getline(std::cin, name_);
	cout << "Your age? : ";
	string age_;
	std::getline(std::cin, age_); 
	cout << name_ << " " << age_ << " " << endl;


/********* Topic 5 *********/
	// Topic 4�� ���������� name�� int�� ���.
	cout << "Your age? : ";
	int _age; // int�� ��쿡�� ���ۿ� ����ִ� ������ �߻��Ѵ�.
	cin >> _age;
	// std::getline(std::cin, _name); // std::getline�� int�� ����� �� �������� �ذ�å�� �ƴϴ�.
	std::cin.ignore(32767, '/n'); /* \n�� ���� ������ �ִ� 32767���� �Է¹޴� �۾��� �����ع������ �ǹ�.
								  --> 32767 = 2����Ʈ int�� ǥ���� ������ ���� ū singed vlaue ��.
   =std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n'); */ // 32767�̶�� ���� �ѹ��� ������� �ʴ� ���.
	
	cout << "Your name? : ";
	string _name;
	std::getline(std::cin, _name);
	cout << _name << " " << _age << " " << endl;

	
/********* Topic 6 *********/
	// string�� ���� ������ �����س��ұ� ������ ���ڿ����� ���ϱ� ���� �����ϴ�.
	string a("Hello, ");
	string b("World");
	string hw = a + b; // append(�����̴�)��� �θ���.

	hw += " I'm good";

	cout << hw << endl; // Hello, World I'm good ���.


/********* Topic 7 *********/
	// ���� ���� ������ �� �ִ�.
	cout << a.length() << endl; // 7 ���. (������ array�� [8]�̴�; ���ڿ��� ���� ǥ���ϴ� null character�� �����ֱ� ������)

	return 0;
}