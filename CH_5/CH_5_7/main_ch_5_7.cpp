/*
5.7강 "반복문 for"

- 반복 횟수가 정해졌을 때 쓰인다.
- 가장 많이 쓰이는 반복문이며, while 문과 호환이 가능하다.
*/

#include <iostream>
using namespace std;

int pow(int base, int exponent)
{
	int result = 1;

	for (int count = 0; count < exponent; ++count)
		result *= base;

	return result;
}

int main()
{
/**************** Topic 1 ****************/
	for (int count = 0; count < 10; ++count) // iteration
	{ // 코드가 한 줄인 경우엔 중괄호가 없어도 괜찮다.
		cout << count << endl;
	}
	// cout << count << endl; // 오류 발생; for 문 실행 후 count는 사라진다.


/**************** Topic 2 ****************/
	// count를 for 문 이후에도 지속적으로 유지하는 방법.
	int count = 0; // 번수를 외부에 선언해준다.
	for (; count < 10; ++count) // 이때 가장 앞 부분은 빈칸으로 비워준다.
	{ 
		cout << count << endl; //  count = 9인 상태.
	}
	cout << count << endl; // 9가 아닌 10이 출력된다!! 
	/* 주의! count는 10인 상태로 count < 10;와 마주하며 false이기 때문에 for 문을 탈출하는 것이다.
	   statements(cout << count << endl;) 다음에 Inc/Dec가 실행됨을 유의. */


/**************** Topic 3 ****************/
	//// for 문을 무한 루프로 활용.
	//for (; ; ++count) // = for (;true; ++count) = while(true) 
	//{
	//	cout << count << endl;
	//}


/**************** Topic 4 ****************/
	// for 문을 활용한 함수 짜기.
	cout << pow(2, 4) << endl;


/**************** Topic 5 ****************/
	// 감소하는 경우 with unsigned int.
	for (unsigned int count = 9; count >= 0; count -= 1)
	{
		cout << count << endl;
	}
	/* Zero 다음에 overflow 현상으로 4294967295가 된다.
	   이는 count >= 0이므로 for 문이 Zero 이후에도 끝나지 않는다. */

/**************** Topic 6 ****************/
	// for 문 내에서 다수의 변수를 정의하여 활용할 수 있다.
	for (int i = 0, j = 0; i < 10; ++i, j -= 2)
	{
		cout << i << " " << j << endl;
	}
	

/**************** Topic 7 ****************/
	// 외부 for 문의 변수를 내부의 for 문에서도 사용할 수 있다. 
	 for (int j = 0; j < 9; ++j)
		 for (int i = 0; i < 9; ++i)
		 {
			 cout << i << " " << j << endl;
		 }

	return 0;
}