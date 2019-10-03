/*
6.1�� "�迭 ���� [1 of 2] array" - Array�� �������� ����

- C++���� ������ �迭�� ����Ѵٴ� ���� ����Ʈ�� �� �游 ������ ���� �ƴ϶� ���̾� �ִ� ���� ���� �� ���� �����ٴ� �ǹ�.
*/

#include <iostream>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

enum StudentName
{
	JACKJACK,	 // = 0
	DASH,		 // = 1
	VIOLET,		 // = 2
	NUM_STUDENT, // = 3
};

int main()
{
/**************** Topic 1 ****************/
	int one_student_scores; // 1 variable
	cout << sizeof(one_student_scores) << endl; // 4 (bytes) ���.

	int student_scores[5];  // 5���� int�� �� ���� �����´ٴ� ��.
 // double student_scores[5]; // double ������ ������ ���� �ִ�.
	cout << sizeof(student_scores) << endl;	/* 20 (bytes) ��� --> '�پ��ִ� �޸�' 5�� �����Դ�.
											(cf) �����Ϳ� ���� ��쿣 �Ϸķ� �� �޸𸮸� ����� �� ���� ��쵵 �߻��Ѵ�.  */

/**************** Topic 2 ****************/
	// �ʱ�ȭ�ϴ� ��� (1)
	one_student_scores = 100;

	student_scores[0] = 100; // 1st element <-- [0] ���� �������� ����.
	student_scores[1] = 80;  // 2nd element
	student_scores[2] = 90;  // 3rd element
	student_scores[3] = 50;  // 4th element
	student_scores[4] = 0;	 // 5th element <-- [5]�� �����Ծ ������ element ��ȣ�� [4]

	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;

	// student_scores[5] = 0;
	// cout << student_scores[5] << endl;
	/* �Ǽ��� [5]�� �����ϰ� ����ϴ� ���.
	--> �����ο��� ����� �� �ް� ��½ 6��° �浵 �� ���̴� 
	--> OS�� �Ұ��� ȭ�� ���� = Runtime ������ �߻��ϰų� ���α׷��� ���� ���� �ִ�. 
	--> ���� ����ִ� �޸𸮶�� �۵��� ������ ���ǰ� �䱸�ȴ�. */

	// �ʱ�ȭ�ϴ� ��� (2)
	int my_array_1[5] = { 1, 2, 3, 4, 5 };
	int my_array_2[5] = { 1, 2 }; // �Ϻθ� �ʱ�ȭ�� ���� �ִ� <-- �ڵ����� �������� 0���� ä���ش�.
	int my_array_3[] = { 1, 2, 3, 4, 5 }; // ������ ��Ͽ��� ������ ��Ȯ�� ��쿡�� �����Ϸ��� array�� ����� �����ش�.

	// �ʱ�ȭ�ϴ� ��� (3)
	int my_array_4[] { 1, 2, 3, 4, 5 };

/**************** Topic 3 ****************/
	// �Ϲ����� int ������ ���� �����ڵ� ����� �� �ִ�.
	cout << student_scores[1] + student_scores[2] / 2.0 << endl;

/**************** Topic 4 ****************/
	// �������� �߿��� ���� struct�� array�� ����� �� �ִ�.
	cout << sizeof(Rectangle) << endl; /* 8 bytes ���. 
									   --> �׷��� ����ü �е�(padding) ������ ���� �������� �հ� ������ ���� ���� ���� �ִ�.
	/* struct padding: ���� ���ϸ� ���� ���Ͽ� �����Ϸ��� �е� ��Ʈ�� �� ������ ä�����ν� CPU�� �����ϱ� ���� �޸𸮷� ��ȯ.
	   �׷��� �޸� ���� �Ͼ�� �� ������ ���� �����Ѵ�. */

	Rectangle rect_arr[10];
	cout << sizeof(rect_arr) << endl; // 80 bytes ���.

	rect_arr[0].length = 1;
	rect_arr[0].width = 2;
	// ���� ���� ����� �� ������ �ڼ��� ������ ���� ���ǿ��� ����.

/**************** Topic 5 ****************/
	/* enum���� �Բ� Ȱ��� �� �ִ�. 
	--> �׷��� enum ������ �̸��� �ٲ� ���� �ֱ� ������ ���������� �ʴ´�. */
	cout << my_array_1[JACKJACK] << endl;
	cout << my_array_1[DASH] << endl;
	cout << my_array_1[VIOLET] << endl;

	// NUM_STUDENT�� ���������ν� �л� ���� ���ϴ���(=enum ������ �߰��Ǵ���) �ڵ������� array�� ����� ������ �� �ִ�.
	int student_scores_[NUM_STUDENT]; 
	student_scores_[JACKJACK] = 0;
	student_scores_[DASH] = 100;

/**************** Topic 6 ****************/
	// Array�� ����� �����ϴ� ���.
	// (1) Compile time(������ Ÿ��)�� �Ҵ�
	const int num_students = 10;

	// (2) Runtime(��Ÿ��)�� �Ҵ�
	/*
	int num_students = 10;
	cin >> num_students; 
	*/

	int students_scores[num_students];
		
return 0;
}