/*
5.8강 "break, continue"

- 예상치 못한 곳에서 break 되거나 continue 될 수 있기 때문에 사용 시에 꼭 검증이 선행되어야 한다.
- 기본으로 switch 문에서 사용된다.
*/

#include <iostream>
using namespace std;

void breakOrReturn()
{
	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'b')
			break;

		if (ch == 'r')
			return; // 함수 종료 = Hello가 출력 안 된다.
	}

	cout << "Hello" << endl;
}

int main()
{
/**************** Topic 1 ****************/
	int count = 0;
	while (true)
	{
		cout << count << endl;
		if (count == 10) break; // break의 기본 쓰임: 코드 블록을 탈출한다.
		count++;
	}


/**************** Topic 2 ****************/
	//break는 while 문을 종료하고, return은 함수를 종료한다.
	breakOrReturn();


/**************** Topic 3 ****************/
	// continue를 사용하여 홀수만 출력을 하는 for 문.
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0) continue; /*for 문이 돌다가 if 문을 만족하는 경우에 continue가 실행되어 
								  하단부의 코드를 실행하지 않고 i를 증가시키는 부분으로 바로 이동한다. */
		cout << i << endl;
	}


/**************** Topic 4 ****************/
	// continue가 do-while 문과 함께 사용될 때는 주의가 필요하다.
	int count(0);
	do
	{
		if (count == 5)
			continue;

		cout << count << endl;
	 // count++; // 쓰면 안 되는 이유.
	}/*  while (count < 10); // 증감문을 중괄호 안에 넣으면 continue 이하가 무시되기 때문에 중괄호 외부에 증감. 
							--> 조건은 그대로이기 때문에 무한 루프에 빠진다. */
	while (++count < 10); // 해결 방법: while 문에 증감까지 추가할 수도 있다.


/**************** Topic 5 ****************/
	// break를 쓰면 조건을 걸어주기 더 쉬움을 보여주는 예제: 특정한 키를 받았을 때 반복문을 빠져나온다.
	// 방법 1) flag를 사용하는 방법
	bool escape_flag = false;
	while (!escape_flag)
	{
		char ch; // while 문안에서도 변수를 선언할 수 있으나 코드가 복잡해질수록 연산이 느려질 수도 있다 --> 밖으로 빼주는 것이 좋다.
		cin >> ch;

		cout << ch << " " << count << endl;

		if (ch == 'x')
			escape_flag = true;
	}

	// 방법 2) break를 사용하는 방법
	while (true)
	{
		char ch;
		cin >> ch;

		cout << ch << " " << count << endl;

		if (ch == 'x')
			break;
	}

	return 0;
}