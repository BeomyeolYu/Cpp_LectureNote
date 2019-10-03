/*
1.12강 "헤더 가드(guard)가 필요한 이유"
- 복잡한 프로그램을 만들 때 매우 중요함.
- 결론은 "그냥 헤더 가드를 쓰면 된다."
- head만 적힌 .h 파일과 body가 적힌 .cpp 파일로 분리되어 있을 때 둘 중에 하나가 없으면 링킹 에러(linking Error)가 발생.
*/
#include <iostream>
#include "my_work.h"
#include "add.h" // header guard가 없는 경우, my_work.h에 add.h가 선언되어 있으므로 이것을 또 선언하면 이중 선언 에러가 발생.

using namespace std;

int main()
{
	doSomething();

	return 0;
}
