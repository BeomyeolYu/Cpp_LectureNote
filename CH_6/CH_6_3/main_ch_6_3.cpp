/*
6.3강 " 배열과 반복문"

- array의 연속적 메모리 특성은 반복문을 이용한 array를 처리에 용이하다.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// (1) array를 사용하지 않는 경우.
	const int num_students = 5;
	int score0 = 84;
	int score1 = 92;
	int score2 = 76;
	int score3 = 81;
	int score4 = 56;

	int total_score1 = score0 + score1 + score2 + score3 + score4;

	double avg_score = static_cast<double>(total_score1) / num_students; // 정밀한 avg_score를 double로 구하고자 static_cast 수행.
	cout << avg_score << endl;
	/* [참고] double(total_score) / num_students != double(total_score / num_students)
	      --> total_score이 num_students으로 (= 정수 나눗셈이) 딱 떨어지지 않는 경우엔 정보가 소실될 수 있다. */

/**************** Topic 2 ****************/
	// (2) array를 사용하는 경우.
	int scores[] = { 84, 92, 76, 81, 56 }; 
	const int numstudents = sizeof(scores) / sizeof(int); // --> 5 = 4*5 / 4 
	// == int scores[num_students] = { 84, 92, 76, 81, 56 };
	 
	int total_score2 = 0;

	for (int i = 0; i < numstudents; i++)
	{
		total_score2 += scores[i];
	}
	
	double avgscore = static_cast<double>(total_score2) / numstudents;

/**************** Topic 3 ****************/
	// 최고 득점자를 찾는 구문.
	int total_score3 = 0;
	int max_score = 0;
	
	for (int i = 0; i < numstudents; i++) 
	// < 대신에 <=를 하면 numstudents에 사전에 할당하지 않는 메모리를 임의로 사용하는 것이기 때문에 런타임 오류가 발생한다.
	{
		total_score3 += scores[i];

		max_score = (max_score < scores[i]) ? scores[i] : max_score;
		cout << max_score << endl; // = if ( max_score < scores[i]) max_score = scores[i];
	}

	return 0;
}