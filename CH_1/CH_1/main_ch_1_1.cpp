// 1.1강 "프로그램의 구조"

// (1) 프로그램을 실행한다는 것은 운영체제(Operating system; OS)을 통해서 하는 것임.
// OS: "무엇을 해드릴까요?"
// Programmer: (컴파일 된 코드를 보여주면서) "이거 해주세요"
// OS: (컴퓨터가 가지고 있는 CPU 등을 사용하여 실행해준다.)
// 이때 함수를 이용함. 함수에 무엇을 넣었느냐에 따라 달라짐. 

// (2) "main"이라는 이름의 함수의 의미: OS가 프로그램을 시작할 때 main을 찾아서 실행함.
// 즉 main이라는 이름을 갖는 function이 무조건 있어야 함. main옆 괄호에는 빈칸 또는 void를 넣음.

// (3) C++는 빈칸 혹은 빈줄 모두 IDE가 무시한다.

// (4) "return": main 함수를 실행하는 OS에게 출력해달라고 요청. "나 잘 끝났어요"
// 함수에서 기능을 수행하는 부분을 statement(명령문)라고 지칭한다. 이 경우에는 reture statement라고 부름.

#include <iostream> // "#include": preprocessor directive(전처리기)
//"iostream": 라이브러리의 일종, "i"nput "o"utput "stream"; 즉 입출력을 가능하게 해주는 기능을 내 프로그램에 포함.

int	main(void)
{
	int x = 2; 
	// 2와 같은 것들을 literal(리터럴) 이라고 부름.
	// x와 y는 변수라고 부름.
	// x라는 이름으로 "메모리" 설정. 즉 x라는 공간에 정수형 2를 설정.
	// 참고) 정보를 기록해두는 것을 메모리, 실제로 연산을 수행하는 것을 CPU라고 부름.
	int y = x + 3; // expressions: (표현)식

	std::cout << y; // #include <iostream>의 도움으로 출력 기능 사용 가능.
	// cout, endl등 iostream 라이브러리에서 불러온 것임.
	std::cout << y << std::endl; // "std::endl": 줄바꿈
	// "std": namespace 
	// "std::"의 의미: namespace안에 들어있는 cout에 접근할 수 있게됨.
	// "<<": stream 또는 output operator(출력 연산자)라고 부름.

	std::cout << 1 + 2 << std::endl;

	return 0;
}

// 복습 퀴즈
// 1. 표현식(expressions)과 명령문(statements)의 차이는 뭘까?
// 2. 함수와 라이브러리의 차이는 뭘까?
// 3. C++에서 문장을 끝내는 기호는 뭘까?
// 4. 문법 오류란 무엇인가?