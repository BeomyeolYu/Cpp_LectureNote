/*
10.1강 "객체들의 관계(Object Relationship)"

- 객체 지향 프로그래밍을 할 때는 먼저 프로그램이 수행해야 하는 기능들을 정의하고, 
  그 기능을 수행할 때 어떤 객체들이 어떤 임무를 나눠서 할 것인가 또는 어떻게 도움을 주고받을 것인지 설계해야 한다.
  객체들 간의 관계에서는 패턴이 존재하며, 설계에 따라 다양한 클래스들을 구현함으로써 프로그래밍 언어로 객체들을 만든다.
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// 대표적인 네 가지의 관계: [Capture1 참고], [Capture2 참고]
	// 검정 글씨: class, 파란 글씨: member, ls-a는 상속에서 자세하게 다룬다.

	/*	1) Composition: 
	- '육체' 없이는 '두뇌'가 존재할 수 없다 = 육체가 죽으면 두뇌도 죽는다.
	- 두뇌가 육체의 전부를 알고 있지는 없는다.	*/

	/*	2) Aggregation: 
	- Composition보다는 느슨한 관계.
	- '사람'이 사라지거나 소유권을 잃어도 '자동차'는 여전히 존재한다. */

	/*	3) Association:
	- 단순히 사용하는 관계.
	- 한 명의 '환자'가 여러 '의사'를 만나기도 하고, 한 명의 '의사'가 여러 '환자'를 만나기도 한다. */

	/*	4) Dependency :
	- 가장 느슨한 관계로 일시적으로 사용된다. 
	- '나'의 다리가 나은 후에는 '목발'이 필요 없다.	 */

	return 0;
}
