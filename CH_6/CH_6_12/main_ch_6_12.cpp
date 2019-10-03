/*
6.12강 "동적 할당 배열(Dynamically Allocating Arrays)"

- 정적 배열은 컴파일 타임에 사이즈가 정해져 있어야만 사용할 수 있었다.
- 동적으로 할당한 변수는 반드시 해제해줘야 한다.
  (1) delete : 동적 할당 변수 해제
  (2) delete[] : 동적 할당 배열 해제
- 동적 할당 배열은 런타임에 배열의 사이즈를 결정을 하고,
  사용할 때 메모리를 OS로부터 받아오기 때문에 좀 더 유동적으로 사용할 수 있다.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// 정적 할당 배열
	const int length_s = 5;
	int array_s[length_s];

/**************** Topic 2 ****************/
	// 동적 할당 배열
	int length_d;
	cin >> length_d; // length of array.

	int *array_d = new int[length_d];    // 초기화를 안 해주면 쓰레기 값이 들어간다.
  //int *array_d = new int[length_d](0); // 나머지를 모두 0으로 초기화.
  //int *array_d = new int[length_d]{11, 22, 33, 44, 55, 66}; // cin의 값이 초기화한 값보다 크면 나머지는 0으로 초기화.
  /* 단, cin보다 선언이 많으면 에러가 발생한다. --> 만약 cin으로 5를 입력했는데 초기화는 6개를 했다면,
	  OS로부터 배정받지 않은 메모리를 사용하려고 해서 다른 프로그램에서 사용하고 있는 메모리와 충돌이 일어난다.
	  즉, 싱글룸 5개만 예약해놓고 사람은 6명이 간 것과 동일하다. */
	array_d[0] = 1;
	array_d[1] = 2;

	for (int i = 0; i < length_d; ++i)
	{
		cout << array_d[i] << endl;
		cout << (uintptr_t)&array_d[i] << endl;
	}
	delete[] array_d;// new를 선언할 때는 delete을 함께 사용하는 습관을 들여아한다.

/**************** Topic 3 ****************/
	// 정적 할당 배열에서는 []를 비워도 자동으로 array 사이즈를 인식한다.
	int fixedArray[] = { 1, 2, 3, 4, 5 };
	// 동적 할당 배열에서는 []를 정의해주어야 한다.
	int *array = new int[5]{ 1, 2, 3, 4, 5 };

	delete[] array;

	return 0;
}