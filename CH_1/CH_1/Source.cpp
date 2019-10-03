#include <iostream>
int	main(void)
{
	int x = 2; //2 같은 것들을 literal(리터럴) 이라고 부름.
	// x와 y는 변수라고 부름.
	// x라는 이름으로 "메모리" 설정. 즉 x라는 공간에 정수형 2를 설정.
	// 참고) 정보를 기록해두는 메모리, 실제로 연산을 수행하는 CPU.
	int y = x + 3; // Expressions: (표현)식

	std::cout << y; // #include <iostream>의 도움으로 기능 사용 가능.
	// cout, endl등 iostream 라이브러리에서 불러온 것임.
	std::cout << y << std::endl; // "std::endl": 줄바꿈
	// "std": namespace 
	// "std::"의 의미: namespace안에 들어있는 cout에 접근할 수 있게됨.
	// "<<": stream 또는 output operator(출력 연산자)라고 부름.

	std::cout << 1 + 2 << std::endl;

	return 0;
}