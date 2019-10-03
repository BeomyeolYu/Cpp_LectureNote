/*
6.3�� " �迭�� �ݺ���"

- array�� ������ �޸� Ư���� �ݺ����� �̿��� array�� ó���� �����ϴ�.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// (1) array�� ������� �ʴ� ���.
	const int num_students = 5;
	int score0 = 84;
	int score1 = 92;
	int score2 = 76;
	int score3 = 81;
	int score4 = 56;

	int total_score1 = score0 + score1 + score2 + score3 + score4;

	double avg_score = static_cast<double>(total_score1) / num_students; // ������ avg_score�� double�� ���ϰ��� static_cast ����.
	cout << avg_score << endl;
	/* [����] double(total_score) / num_students != double(total_score / num_students)
	      --> total_score�� num_students���� (= ���� ��������) �� �������� �ʴ� ��쿣 ������ �ҽǵ� �� �ִ�. */

/**************** Topic 2 ****************/
	// (2) array�� ����ϴ� ���.
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
	// �ְ� �����ڸ� ã�� ����.
	int total_score3 = 0;
	int max_score = 0;
	
	for (int i = 0; i < numstudents; i++) 
	// < ��ſ� <=�� �ϸ� numstudents�� ������ �Ҵ����� �ʴ� �޸𸮸� ���Ƿ� ����ϴ� ���̱� ������ ��Ÿ�� ������ �߻��Ѵ�.
	{
		total_score3 += scores[i];

		max_score = (max_score < scores[i]) ? scores[i] : max_score;
		cout << max_score << endl; // = if ( max_score < scores[i]) max_score = scores[i];
	}

	return 0;
}