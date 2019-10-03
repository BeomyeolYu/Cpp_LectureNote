/*
10.5강 "의존 관계(Dependencies)"
- Timer class에 대한 정보를 Worker class가 몰라도 된다.
*/

#include "Worker.h"
using namespace std;


int main()
{
	Worker().doSomething();

	/* '멤버의 존재를 클래스가 관리'한다 YES에서 사실은 멤버로 존재하는 것이 아니라 일시적으로 생겼다가 사라지는 존재이다.
	즉 보통은 멤버로 들어가지 않는 경우가 많다.
	'존재를 클래스가 관리'한다는 측면에서 생각하면 된다. */

	return 0;
}