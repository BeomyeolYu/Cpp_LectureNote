#include <iostream>

int main()
{
	std::cout << "Hello, world!" << std::endl;
	// (1) Solution Configurations
	// Debug Mode는 디버깅에 도움이 되는 내용이 포함되어있어 용량이 큼.
	// Release Mode는 배포용이기 때문에 용량이 최소화.
	// Release의 실행 속도가 Debug보다 훨씬 빠르므로 그래픽스 등을 실행할 때는 Release로 선택.

	// (2) Solution Platforms
	// x86 = 32bit: 메모리 사용에 제한이 있음 (과거에 유용).
	// x64 = 64bit: 컴퓨터 성능이 비약적으로 발전하여 x64로 주로 사용.
	return 0;
}