/*
5.10강 "std::cin 더 잘 쓰기"

- ignore(), clear(), fail(): 콘솔에서 텍스트 입력을 받을 때 유용하게 사용할 수 있다.
- 프로그래머가 의도하지 않은 대로 사용자가 사용했을 때 어떻게 대응할 것인가?
*/

#include <iostream>
using namespace std;

int getInt()
{
	while (true) // while 문을 활용해줌으로써 올바른 입력을 해줄 때까지 return을 실행하지 않는다 = 함수를 종료하지 않는다.
	{
		cout << "Enter an integer number : ";
		int x;
		cin >> x;

		// 입력값이 엄청 큰 경우에 ignore의 숫자보다 큰 숫자가 입력되면 buffer에 끊임없이 저장된다.
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			cout << "Invaild number, please try again" << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); // buffer 비워주기; 적당히 큰 숫자를 지정.
			return x;
		}
	}
}

char getOperator()
{
	while (true)
	{
		cout << "Enter an operator (+, -) : "; // TODO: more operators *, /, etc. (Ex, TODO: Add any drawing code here...)
		  char op;
		  cin >> op;
		  std::cin.ignore(32767, '\n');

		  if (op == '+' || op == '-')
			  return op;
		  else
			  cout << "Invalid operator, please try again" << endl;
	}
}

void printResult(int x, char op, int y)
{
	if (op == '+') cout << x + y << endl;
	else if (op == '-') cout << x - y << endl;
	else
	{
		cout << "Invalid operator" << endl;
	}
}


int main()
{
/**************** Topic 1 ****************/
	int x = getInt(); /* 만약 사용자가 숫자를 2개 입력하면 두 번째 숫자가 buffer에 남겨져 저장되여 getOperator에서 자동으로 입력된다. 
					  -->buffer를 비워주면 된다. */
	char op = getOperator();
	int y = getInt();

	printResult;


	return 0;
}