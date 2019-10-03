/*
4.7�� "������(Enumerated types)"

- �������� ���� ���ȴ�.
- int�� �����ϴ� �� ������ 100% ȣȯ������ ������ casting�� ����� �� �ִ�.
*/

#include <iostream>
#include <typeinfo>

// ���ӿ��� ������ ������ ����ġ�� ����ϴ� �Լ�.
int computeDamage(int weapon_id) // � ����� ���ݹ޾ҳĿ� ���� �������� �ٸ���.
{
	if (weapon_id == 0) // sowrd
	{
		return 1;
	}

	if (weapon_id == 1) // hammer
	{
		return 2;
	}
	// ...
} 
/* �׷��� ���α׷��Ӱ� ��� ��ȣ�� �ϱ��ϱ� �����Ƿ�, 
   �������� ����Ͽ� �̸� ��ȣ������ ǥ���� �� �ִ�. */

//enum = Enumerate tpye, header file�� ���� #include�ϴ� ��찡 ��κ�.
enum Color // ����� ���� �ڷ���(user-defined data type)�̴�. 
{	
	// �Ϲ������� �빮�ڷ� �����Ѵ�.
	COROR_BLACK,   // ���콺�� �ø��� enum Color::COROR_BLACK = 0
	COLOR_RED,	   // enum Color::COROR_BLACK = 1
	COLOR_BLUE,	   // = 2
	COLOR_GREEN,   // = 3
	COLOR_SKYBLUE, // = 4
	BLUE, // �ٸ� ��Ͽ� �����־ ���� ����ó�� �۵��ϱ� ������ ������ �߻��Ѵ�.

}; // ;�� ������ ������ �߻��ϴ� ����.

enum Feeling
{
	HAPPY = -3, // �������� �Ҵ��ϸ� -3���� ��ȣ�� �ٿ�����.
	JOY,		// -2
	TIRED = 5,	
	SAD = 5,	// ������ ���ڸ� �Ҵ��ϴ� ���� ������ ������ ������ �Ұ����Ͽ� ���� ������ �νĵȴ�.
	// BLUE, 
};

using namespace std;

int main()
{
/********* Topic 1 *********/
	// Color�� data typeó�� ����Ѵ�.
	Color paint = COROR_BLACK; // �ʱ�ȭ�ϴ� ���� Ȯ���� �� �ִ�.
	Color house(COROR_BLACK);
	Color appe{ COROR_BLACK }; // ���� �� �ʱ�ȭ�� ���ӽ� ���̰� �ִ� --> Ŭ���� ���ǿ���.


/********* Topic 2 *********/
	Color my_color = COLOR_GREEN;
	cout << my_color << " " << COLOR_GREEN << endl; // ���������� ������ ����ȴ�.
	
	// �׷��� Color�� ������ �Ҵ��� ���� ����.
    Color my_color = 1; // ���� �߻�.

	int color_id = COROR_BLACK;
	cout << color_id + 2 << " " << COROR_BLACK + 2 << endl; // int type �Ҵ��� �ȴ�.
    Color my_color = color_id; // ���� �߻�. 
	Color my_color = static_cast<Color>(3); // ĳ�����Ͽ� �Ҵ��ϴ� ���.

/********* Topic 3 *********/
	// cin���� ���� ���� �޾ƿ� ���� ����.
	cin >> my_color;  // ���� �߻�.

	// ��ȸ�Ͽ� �Է��ϴ� ���.
	int in_number;
	cin >> in_number;
	if (in_number == 0) my_color = COROR_BLACK;
	// �Ǵ� ĳ�����Ͽ�
	if (in_number == static_cast<Color>(1)) my_color = static_cast<Color>(1);


	return 0;
}