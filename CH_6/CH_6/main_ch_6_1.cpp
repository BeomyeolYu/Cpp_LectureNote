/*
6.1강 "배열 기초 [1 of 2] array" - Array의 기초적인 사용법

- C++에서 변수의 배열을 사용한다는 것은 아파트의 한 방만 빌리는 것이 아니라 연이어 있는 여러 방을 한 번에 빌린다는 의미.
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
	cout << sizeof(one_student_scores) << endl; // 4 (bytes) 출력.

	int student_scores[5];  // 5개의 int를 한 번에 빌려온다는 뜻.
 // double student_scores[5]; // double 등으로 선언할 수도 있다.
	cout << sizeof(student_scores) << endl;	/* 20 (bytes) 출력 --> '붙어있는 메모리' 5개 빌려왔다.
											(cf) 빅데이터와 같은 경우엔 일렬로 된 메모리를 사용할 수 없는 경우도 발생한다.  */

/**************** Topic 2 ****************/
	// 초기화하는 방법 (1)
	one_student_scores = 100;

	student_scores[0] = 100; // 1st element <-- [0] 부터 시작함을 주의.
	student_scores[1] = 80;  // 2nd element
	student_scores[2] = 90;  // 3rd element
	student_scores[3] = 50;  // 4th element
	student_scores[4] = 0;	 // 5th element <-- [5]로 빌려왔어도 마지막 element 번호는 [4]

	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;

	// student_scores[5] = 0;
	// cout << student_scores[5] << endl;
	/* 실수로 [5]를 선언하고 출력하는 경우.
	--> 집주인에게 허락을 안 받고 슬쩍 6번째 방도 쓴 것이다 
	--> OS가 불같이 화를 낸다 = Runtime 에러가 발생하거나 프로그램이 터질 수도 있다. 
	--> 만약 비어있는 메모리라면 작동은 되지만 주의가 요구된다. */

	// 초기화하는 방법 (2)
	int my_array_1[5] = { 1, 2, 3, 4, 5 };
	int my_array_2[5] = { 1, 2 }; // 일부만 초기화할 수도 있다 <-- 자동으로 나머지는 0으로 채워준다.
	int my_array_3[] = { 1, 2, 3, 4, 5 }; // 오른쪽 블록에서 개수가 명확한 경우에는 컴파일러가 array의 사이즈를 정해준다.

	// 초기화하는 방법 (3)
	int my_array_4[] { 1, 2, 3, 4, 5 };

/**************** Topic 3 ****************/
	// 일반적인 int 사용법과 같이 연산자도 사용할 수 있다.
	cout << student_scores[1] + student_scores[2] / 2.0 << endl;

/**************** Topic 4 ****************/
	// 무엇보다 중요한 것은 struct에 array를 사용할 수 있다.
	cout << sizeof(Rectangle) << endl; /* 8 bytes 출력. 
									   --> 그러나 구조체 패딩(padding) 때문에 변수 사이즈의 합과 언제나 같지 않을 수도 있다.
	/* struct padding: 성능 저하를 막기 위하여 컴파일러가 패딩 비트로 빈 공간을 채움으로써 CPU가 접근하기 쉬운 메모리로 변환.
	   그러나 메모리 낭비가 일어나는 등 문제점 또한 존재한다. */

	Rectangle rect_arr[10];
	cout << sizeof(rect_arr) << endl; // 80 bytes 출력.

	rect_arr[0].length = 1;
	rect_arr[0].width = 2;
	// 위와 같이 사용할 수 있으며 자세한 설명은 이후 강의에서 설명.

/**************** Topic 5 ****************/
	/* enum과도 함께 활용될 수 있다. 
	--> 그러나 enum 변수의 이름이 바뀔 수도 있기 때문에 권장하지는 않는다. */
	cout << my_array_1[JACKJACK] << endl;
	cout << my_array_1[DASH] << endl;
	cout << my_array_1[VIOLET] << endl;

	// NUM_STUDENT를 정해줌으로써 학생 수가 변하더라도(=enum 변수가 추가되더라도) 자동적으로 array의 사이즈를 정해줄 수 있다.
	int student_scores_[NUM_STUDENT]; 
	student_scores_[JACKJACK] = 0;
	student_scores_[DASH] = 100;

/**************** Topic 6 ****************/
	// Array의 사이즈를 결정하는 방법.
	// (1) Compile time(컴파일 타임)에 할당
	const int num_students = 10;

	// (2) Runtime(런타임)에 할당
	/*
	int num_students = 10;
	cin >> num_students; 
	*/

	int students_scores[num_students];
		
return 0;
}