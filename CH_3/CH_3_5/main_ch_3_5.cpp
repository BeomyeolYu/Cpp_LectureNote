/*
3.5강 "관계 연산자 (Relational Operators)"

- Ex, >  <  ==  != 등
- tip. 주석은 영어로 적는 것이 좋음.
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
/********* Topic 1 *********/
	//while (true)
	//{
		int x, y;
		cin >> x >> y;
		cout << "Your input values are : " << x << " " << y << endl;

		if (x == y)
			cout << "equal" << endl;
		if (x != y)
			cout << "not equal " << endl;
		if (x > y)
			cout << "x is greater than y" << endl;
		if (x < y)
			cout << "x is less than y" << endl;
		if (x >= y)
			cout << "x is greater than y or equal to y" << endl;
		if (x <= y)
			cout << "x is less than y or equal to y" << endl;
	//}

/********* Topic 2 *********/
	/*
	int 끼리의 연산엔 큰 오류가 발생하지 않음.
	그러나 주의할 점! 
	부동소수점(floating point numbers)끼리의 연산에서 큰 오류가 발생할 수 있음.
	*/

	double d1(100 - 99.99); // = 0.001.
	double d2(10 - 9.99);	// = 0.001.
	cout << d1 << endl;		// 0.001 출력.
	cout << d2 << endl;		// 0.001 출력.

	if (d1 == d2)
		cout << "equal" << endl;
	else
	{
		cout << "not equal" << endl; // not equal이 출력됨.

		if (d1 > d2) cout << "d1 > d2" << endl;
		else // if(d1 < d2) because d1 != d2
			cout << "d1 < d2" << endl;	
	}

	cout << std::abs(d1 - d2) << endl; // 5.32907e-15의 아주 미세한 오차가 발생 <= 수치해석학과 연관된 결과.
	/* 수치 오차를 어떻게 대응할 수 있는가? Ex) 오차의 한계를 직접 결정해준다. */
	const double epsilon = 1e-10; // 그러나, epsilon은 각 전문 분야의 domain knowledge에 따라 변함.

	if (std::abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;

	return 0;
}