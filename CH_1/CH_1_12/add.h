#pragma once // 이것이 header guard.
// 헤더 파일에 함수의 모든 것이 들어있으면 문제가 생길 수 있는데 header guard가 이를 막아줌. (?)

// #pragma once를 정식으로 기술하면,
// #ifndef MY_ADD // = if not define; 이름은 적당히 지으면 됨.
// #define MY_ADD // "MY_ADD가 정의되어 있으면 #~#사이를 다시 include 하지 마라."

int add(int a, int b)
{
	return a + b;
}

// #endif