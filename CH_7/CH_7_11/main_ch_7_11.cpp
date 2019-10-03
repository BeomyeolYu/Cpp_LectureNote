/*
7.11강 "std::vector를 스택처럼 사용하기"

- 동적 할당 메모리를 직접 관리하는 것보다 std::vector을 사용하는 것이 편리하다.

1) vector를 stack으로 사용하는 이유: .reserve 해놓으면 capacity를 수시로 늘릴 필요가 없어 new & delete이 불필요하므로 속도가 빨라진다.
--> size만 늘리고 줄이는 형태로 사용할 수 있다.
--> 단점: reserve를 너무 크게 잡으면 메모리가 낭비될 수 있다 (최신 컴퓨터에서는 비교적 무리가 덜하다).

2) vector를 잘 사용하는 비법: 내부적으로 new와 delete을 최소한으로 사용하는 것.
--> heap은 메모리에 공간은 잡아오고(new) 반납하는(delete) 과정이 비교적 느리므로 많이 쓰지 않는 것이 좋다.
*/

#include <iostream>
#include <vector>
using namespace std;

void printStack(const std::vector<int> &stack)
{
	for (auto &e : stack)
		cout << e << " ";
	cout << endl;
}

int main()
{
/**************** Topic 1 ****************/
	std::vector<int> v1;		    // 정수형 vector 선언
	std::vector<int> v2{ 1, 2, 3 }; // + 초기화
	/* 내부적으로는 다음과 비슷하다 (동일하지는 않다).
	   int *v_ptr = new int[3]{1, 2, 3}; */

/**************** Topic 2 ****************/
	/* vector에는 size와 capacity가 있다.
	   capacity 개수만큼 메모리를 가지고 있으며, size는 '그중에서 몇 개만 사용한다'라는 의미이다. */

	v2.resize(2); // resize가 더 작은 경우

	for (auto &e : v2) // v2에 사이즈에 맞춰서 for-each 문에 반복되는 것이다.
		cout << e << " ";
	cout << endl;
		
	cout << v2.size() << " " << v2.capacity() << endl; 
	// resize의 큰 경우: capacity = size = 10
	// resize의 작은 경우: capacity는 3으로 유지하고 출력할 때는 size가 2이다.

	cout << v2[2] << endl;    // (1) vector는 0부터 시작하며 v2.resize(2)를 했으므로 v2[2]는 범위 밖이다 --> Runtime error 발생.
	cout << v2.at(2) << endl; // (2) Runtime error 발생.
	int *ptr = v2.data();
	cout << ptr[2] << endl;	  // (3) 강제로 int의 포인터를 가져와서 확인해보니 v2[2]에 3을 가지고 있는데 없는 척 한 것이다.
	// --> 더 작은 것으로 new & delete하면 속도가 느려지므로 메모리는 그대로 가지고 있는다. 즉, size는 2인데 capacity는 3인 것이다.

/**************** Topic 3 ****************/
	// capacity만 강제로 키우는 경우.
	v2.resize(10); // resize가 더 큰 경우

	for (auto &e : v2) 
		cout << e << " "; // 나머지가 0으로 채워진다.
	cout << endl;

	v2.reserve(1024); // .reserve = 메모리의 용량을 미리 확보해두겠다는 의미.
	cout << v2.size() << " " << v2.capacity() << endl;
	// --> resize 등을 통해 원소가 추가될 때, reserve로 충분한 공간이 남아있다면 새로 메모리를 받아오고 교체하는 작업이 필요 없으므로 속도가 빨라진다.

/**************** Topic 4 ****************/
	// stack처럼 사용하는 방법 
	std::vector<int> stack; // 재귀 호출에 의한 stack overflow을 막기 위해 vector를 stack으로 사용하는 경우가 있다.
	// v2.reserve(1024);

	// Stack은 말 그대로 쌓는다는 의미이다. 쌓는 것을 push, 꺼내는 것을 pop 한다 라고도 부른다.
	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(7);
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
}