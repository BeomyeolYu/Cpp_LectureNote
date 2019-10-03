/*
5.6강 "반복문 do-while"

- while 문은 조건에 따라서 실행이 아예 안될 수도 있지만 do-while 문은 무조건 한 번은 실행하고 조건을 살핀다.
- 수학적으로 알고리즘을 작성할 때 반드시 한 번은 실행해야 하는 경우 사용된다.
*/

#include <iostream>
using namespace std;

int main()
{
	int selection; // must be declared outside do-while loop.

	// 입력받은 숫자를 판별할 때, 무조건 처음 한 번은 숫자를 입력받아야만 하므로 do-while 문 사용.
	do
	{
		cout << "1. add" << endl;
		cout << "2. sub" << endl;
		cout << "3. mult" << endl;
		cout << "4. div" << endl;

		cin >> selection;
	} while (selection <= 0 || selection >= 5); // 조건이 참이면 do-while 문을 탈출하고 거짓이면 다시 do를 반복.
	{
		cout << "You selected " << selection << endl;
	}

	return 0;
}