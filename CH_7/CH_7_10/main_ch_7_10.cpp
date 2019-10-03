/*
7.10강 "스택과 힙(the stack and the heap)"
- 포인터나 메모리 동적 할당을 공부할 때, 컴퓨터가 내부에서 CPU와 메모리를 어떻게 사용하는지 구체적으로 안다면 이해도를 높일 수 있다.
*/

/* [Capture1.jpg 참고]
1. 우리가 컴퓨터에게 "작성한 프로그램을 실행해주세요"라고 말하면 우리의 OS(운영체제)는 메모리(= 프로그램을 실행시킬 자리)를 할당해준다.
   여기서, 메모리는 segment라고 불리는 각각의 역할이 다른 여러 구역들로 나뉜다.
2. 다음으로 Code segment에 우리가 작성한 프로그램이 저장이 된다 (= 프로그램이 자리를 잡는다).
3. 프로그램 다음으로 오래 지속되는 것이 전역 변수이다. --> BSS 및 Data segment에 저장된다. 
- BSS에는 초기화가 안되었거나 0으로 초기화된 golbal/static variable이 저장된다.
- Data segment는 초기화가 된 golbal/static variable이 저장된다.
4. 마지막으로 실제 프로그램이 실행되면서 자세히 알아봐야 할 곳은 stack과 heap이다.
*/

/* l
[Capture2.jpg 참고]
1) Stack 메모리의 개요: Stack은 '순차적으로 쌓여져있는 형태'를 지니며, 현재 실행시켜야 하는 것이 가장 위에 있다. 
- OS는 main 함수를 우선 실행하며, golbal variable g_i 및 local variable a, b가 선언되어 있다.
- first라는 함수를 선언하며, first 함수 내부에서 second 함수가 실행된다.

[Capture2-1.jpg 참고]
1. 먼저 golbal variable가 메모리에 자리를 잡는다. 이는 가장 먼저 생겼다가 가장 늦게 사라진다.

[Capture2-2.jpg 참고]
2. Stack은 말 그대로 쌓는다는 의미이다. 쌓는 것을 'push 한다'라고 부른다.
- 처음에 main 함수가 실행되면 Stack frame 안에 main 함수 자체와 main 함수 안에 있는 local variable들이 저장된다. 
- 이외에도 Stack frame안에는 실행이 끝난 다음에 어디로 돌아가면 되는지 등 몇 가지 정보가 더 들어있다.

[Capture2-3.jpg 참고]
3. main 함수가 진행되다가 first 함수를 만나면 first 함수의 stack frame이 생겨나서 위에 쌓인다. 이 frame 안에는 parameter인 x와 local variable인 y가 저장된다.

[Capture2-4.jpg 참고]
4. first 함수가 또다시 second 함수를 호출한다. parameter인 x가 저장된다. 
second 함수의 실행이 끝나면 위에서부터 역순으로 제거한다. 빼는 것을 'pop한다'라고 부른다.

2) Stack의 장점: 비교적 속도가 빠르며, local variable등을 빠른 속도로 접근해서 사용할 수 있다.
3) Stack의 단점: [Capture3.jpg 참고] 빠른 것이 장점이나 저장할 수 있는 사이즈가 작다.
Ex. Array가 너무 큰 경우 메모리 할당을 못한다. --> Stack의 사이즈가 작은 상태에서 static array와 같이 큰 local variable의 메모리를 잡으려고 하면 stack overflow가 발생한다.
Ex. '재귀 호출'과 같이 함수가 내부에서 자기 자신을 호출을 하는 등 여러 번 함수를 재호출하는 경우 stack이 쌓이다가 어느 순간 stack overflow가 발생한다. 
*/

/* 동적 메모리 할당 1
1) heap 메모리의 개요: local variable들을 stack에 저장이 되며 속도는 빠르나 stack overflow가 발생할 수 있다.
--> 이를 보완해주기 위해 Heap 메모리를 추가로 사용 (heap 메모리의 'heap'은 'heap 자료구조'와는 무관함).

[Capture4-1.jpg 참고]
1. main 함수가 실행되고 stack frame에 포인터 변수가 저장된다. 포인터 또한 주소를 저장하는 하나의 변수임을 기억.

[Capture4-2.jpg 참고]
2. 다음 줄에서 동적 메모리가 할당되면 heap에 요구한 사이즈만큼의 메모리가 잡힌다. 포인터 변수는 heap안에 잡혀있는 메모리의 첫 주소를 가지고 있으며 언제든지 접근할 수 있다.

[Capture4-3.jpg 참고]
3. heap 메모리를 delete로 지우면 OS로 반납이 된다. 이때 heap 메모리는 반납이 되었으나 int *ptr은 heap 메모리의 주소를 값으로 가지고 있다. 그래서 delete 이후에 ptr을 사용하면 오류가 발생한다.

[Capture4-4.jpg 참고]
4. 만약 delete 후에도 ptr을 사용해야 한다면 null pointer로 assignment를 해주어야 한다.

2) heap의 장점: heap은 사이즈가 커서 큰 데이터를 저장할 공간을 확보할 수 있다.
3) heap의 단점: stack은 계층적으로 쌓이기 때문에 메모리의 위치를 예측해볼 수 있으나 heap은 메모리가 어디에 생길지 예측을 하기 힘들다.
*/

/* 동적 메모리 할당 2
[Capture5-1.jpg 참고]
1. initArray라는 함수에서 동적 할당을 수행하여 stack과 heap에 메모리가 할당되었다.

[Capture5-2.jpg 참고]
2. initArray라는 함수를 나왔는데 delete을 안 할 경우 heap에 메모리는 잡혀있으나 주소를 알 방도가 없다 --> 사용할 수 없다.
--> 반복된다면 heap에 쓸 수 없는 메모리가 꽉 차거나 메모리 누수로 인한 메모리 잠식 현상으로 큰 문제가 발생한다.
*/

#include <iostream>
using namespace std;

int main()
{
	return 0;
}