/*
6.2�� "�迭 ���� [2 of 2] array" - Array�� �������� ����
*/

#include <iostream>
using namespace std;

void doSomething(int students_scores[20]) /* int students_scores[20]�� ���� �����ؼ� ���ο� ���� �޾ƿ´� = �Ź� �ּҰ� �ٸ���.
										     --> �Ź� ū array�� �����ؾ� �ϹǷ� ������ ���ϵȴ�. */
{
	cout << "Address in function " << (int)&students_scores << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	
	cout << "Size in function " << sizeof(students_scores) << endl; // ���⼭ students_scores�� array�� �ƴ϶� pointer�̴�.
}

int main()
{
/**************** Topic 1 ****************/
	// �ּҸ� ���鼭 �޸𸮰� ��� �Ҵ�Ǵ��� Ȯ��.
	const int num_students = 20; // fixed-size array ����.
	int students_scores[num_students] = { 1,2, 3, 4, 5, }; // �Ϻθ� �Ҵ�.

	cout << sizeof(students_scores[0]) << endl; // 4 bytes ���.
	cout << sizeof(students_scores) << endl;	// 80 bytes ���.

	// 16 ������ Ȯ��. --> �ּҸ� Ȯ���� ���� &�� �ٿ��ش�.
	cout << &students_scores << endl;     // array ��ü�� �ּ�. <-- ���������� 1st element�� ������ �ּҸ� ���´�.
	cout << &students_scores[0] << endl;  // 1st element�� �ּ�.
	cout << &students_scores[1] << endl;

	// 10 ������ casting.
	cout << "Address in main " << (int)&students_scores << endl;           // 5242012 <-- ���������� 1st element�� ������ �ּҸ� ���´�.
	cout << "Address in 1st element " << (int)&students_scores[0] << endl; // 5242012
	cout << "Address in 2nd element " << (int)&students_scores[1] << endl;// 5242016 <-- 1st element���� 4 bytes�� ��������.

/**************** Topic 2 ****************/
	/* �Լ� �Ķ���ͷ� array�� �־��� �� ������ ��.
	   (1) array�� �Լ� �Ķ���ͷ� �־��� �� ������ ������ ���� ��µȴ�.
	   (2) �׷��� �ּҴ� �ٸ���. */
	doSomething(students_scores); 

	/* (3) main������ �޸𸮰� 80�ε� function������ 4�̴�. 
	   --> '������'�� �ּҸ� �������� �����̴�.
	   --> array�� pointer�� ������ �� �� ���� �����̴�. */

	cout << "Size in main " << sizeof(students_scores) << endl;


	return 0;
}