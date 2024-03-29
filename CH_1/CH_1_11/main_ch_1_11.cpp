/*
1.11강 "헤더(Header) 파일 만들기"
- 함수가 복잡하거나 복잡한 코드를 작성할 때, 여러 파일로 분할하고 헤더 파일을 만드는 법.
- 주로 프로그래머들은 1)헤더 파일로 함수 전체를 먼저 만들고, 2)함수의 Body를 .cpp 파일로 분리함.
- 컴파일러의 처리 방식, 가독성, 유지보수, 은닉성 등의 이유로 헤더 파일에 함수를 구현한 '정의' 부분을 넣는 것은 좋지 않음.
- 즉 헤더 파일에 선언(=선언부), .cpp파일에 정의(=구현부)로 나누는 것이 좋음.

- <>로 선언하는 것은 .h가 없고 컴파일러 설치할 때 함께 설치되는 것이라(경로도 다름) 특별 처리. 표준적으로 사용되는 것.
- "Close All But This" 기능
- "Open Containing Folder" 기능
*/
#include <iostream>
// #include "add.h" // Method 2
#include "MyHeaders/add.h" // Method 3: 헤더 파일을 다른 폴더로 이동한 경우에는 기존의 헤더 파일을 remove 하고 경로와 함께 헤더 파일을 선언.

using namespace std;

/*
int add(int a, int b) // Method 1: add.cpp 함수 파일을 선언.
- 함수 하나 때문에 파일을 만드는 경우는 거의 없고 비슷한 기능을 하는 함수들을 묶어서 하나의 파일러 만듦.
- 혹은 객체 지향에서 class 일 때 사용함.
- 그러나 매번 함수를 정보를 선언해주기 번거롭기 때문에 헤더 파일을 만든다.
*/
int main()
{
	cout << add(1, 2) << endl;

	return 0;
}
