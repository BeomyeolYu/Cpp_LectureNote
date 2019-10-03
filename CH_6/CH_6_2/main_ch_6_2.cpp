/*
6.2강 "배열 기초 [2 of 2] array" - Array의 기초적인 사용법
*/

#include <iostream>
using namespace std;

void doSomething(int students_scores[20]) /* int students_scores[20]를 새로 선언해서 새로운 집을 받아온다 = 매번 주소가 다르다.
										     --> 매번 큰 array를 복사해야 하므로 성능이 저하된다. */
{
	cout << "Address in function " << (int)&students_scores << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	
	cout << "Size in function " << sizeof(students_scores) << endl; // 여기서 students_scores는 array가 아니라 pointer이다.
}

int main()
{
/**************** Topic 1 ****************/
	// 주소를 찍어가면서 메모리가 어떻게 할당되는지 확인.
	const int num_students = 20; // fixed-size array 정의.
	int students_scores[num_students] = { 1,2, 3, 4, 5, }; // 일부만 할당.

	cout << sizeof(students_scores[0]) << endl; // 4 bytes 출력.
	cout << sizeof(students_scores) << endl;	// 80 bytes 출력.

	// 16 진수로 확인. --> 주소를 확인할 때는 &를 붙여준다.
	cout << &students_scores << endl;     // array 자체의 주소. <-- 내부적으로 1st element와 동일한 주소를 갖는다.
	cout << &students_scores[0] << endl;  // 1st element의 주소.
	cout << &students_scores[1] << endl;

	// 10 진수로 casting.
	cout << "Address in main " << (int)&students_scores << endl;           // 5242012 <-- 내부적으로 1st element와 동일한 주소를 갖는다.
	cout << "Address in 1st element " << (int)&students_scores[0] << endl; // 5242012
	cout << "Address in 2nd element " << (int)&students_scores[1] << endl;// 5242016 <-- 1st element에서 4 bytes가 더해진다.

/**************** Topic 2 ****************/
	/* 함수 파라미터로 array를 넣었을 때 주의할 점.
	   (1) array를 함수 파라미터로 넣어줄 수 있으며 동일한 값이 출력된다.
	   (2) 그러나 주소는 다르다. */
	doSomething(students_scores); 

	/* (3) main에서는 메모리가 80인데 function에서는 4이다. 
	   --> '포인터'의 주소를 가져오기 때문이다.
	   --> array와 pointer는 뗄래야 뗄 수 없는 사이이다. */

	cout << "Size in main " << sizeof(students_scores) << endl;


	return 0;
}