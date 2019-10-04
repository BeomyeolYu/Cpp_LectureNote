/*
8.8강 "클래스 코드와 헤더 파일"

- 헤더 파일을 이용하여 클래스 코드를 정리하는 방법.
- 클래스 코드를 .cpp파일에서 직접 생성하기보다는 헤더 파일을 이용하여 class의 선언과 정의를 분리하는 경우가 많다. 
- 일반적으로 header file의 이름을 class의 이름과 동일하게 생성한다.
*/

#include "Calc.h"

int main()
{
	Calc cal(10);
	cal.add(10).sub(1).mult(2).prit(); 

	Calc(10).add(10).sub(1).mult(2).prit();

	return 0;
}