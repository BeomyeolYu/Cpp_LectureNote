/*
1.3강 "변수와의 첫 만남"

(1) 객체(objects): 컴퓨터는 CPU와 메모리로 일하며 정보는 메모리에 저장됨.
				  "객체가 존재한다"의 뜻: 메모리에 정보가 저장되어 있다. 
(2) 변수(variables): 메모리에 담겨있는 객체를 사용하기 위한 "이름".
				    메모리가 아파트라면 아파트에 편지를 배달하기 위한 주소가 필요함.
				    변수는 숫자 주소를 사람이 인식할 수 있는 문자로 표현한 것임.
(3) 초기화(initialization)와 대입(assignment)은 구분해주어야 함.
(4) 초기화를 안 했을 시 Debug 모드에서는 런타임 에러가 발생함.
	Release 모드에서는 0과 같은 임의의 값을 배정해줘서 에러는 안 뜸.
	그러나 이로 인해 큰 문제를 초래할 수도 있기 때문에 변수 초기화 에러는 항상 잡아주는 것이 좋음.

	또한 메모리 관리는 OS가 해주는데, 새로운 집이라고 갔더니 쓰레기가 가득 차 있는 경우가 있듯이
	새로 할당한 메모리가 다른 프로그램에서 사용하여 garbage가 되어있을 수도 있다.
	그러므로 반드시 초기화를 해주어야 한다.
*/

// 컴퓨터 프로그래밍은 결국 숫자를 다루는 것임.(이진수)
#include <iostream> 

int	main(void)
{
	int x; 
	/* 뜻: x라는 정수형(integer type) 변수를 선언.
	즉 "x는 숫자를 담을 수 있는 공간을 메모리에 차지하고 있다."
	x는 메모리 공간의 이름(=주소)이며 x도 객체다.
	크기는 123과 같은 정수 하나를 담을 수 있는 크기.*/
	
	/* 
	표현 1) 
	int x = 123; // initialization
	또는 int x(123);

	표현 2) 
	int x;
	x = 123; // assignment. (등호 =는 같다는 의미가 아니라 대입해준다는 뜻.)
	뜻: x라는 정수형 변수에 123을 대입해준다.
	x라는 변수 이름이 가리키고 있는 메모리 공간에 123이라는 정수를 저장해놓는다. 
	*/

	x = 123;
	/* Left-values과 Right-values(l-value, r-value)
	L-values는 메모리의 주소를 가지고 있는 것.
	R-values는 메모리 어딘가에 임시적으로 저장되는 것.
	x의 주소를 가져오긴 쉽지만 123의 주소는 가져오기 어려움.
	즉, 프로그램 주소를 프로그래머가 직접적으로 접근할 수 있느냐 없느냐의 차이.
	x = x + 2; 인 경우에도 l-value, r-value 구분은 동일함. */

	std::cout << x << std::endl;
	// std::cout << &x << std::endl; x가 어디에 지정되어 있는지 주소를 알 수 있음.
	// & = ampersand

	return 0;

	/* Quiz
	int x = 1;
	x = x + 2;
	std::cout << x << std::endl; // #1 (3)

	int y = x;
	std::cout << y << std::endl; // #2 (3)

	// is (x + y) l-values or r-value?
	std::cout << x + y << std::endl; // #3 (r-value)

	std::cout << x << std::endl; // #4 (3)

	int z;
	std::cout << z << std::endl; // #5 (Error or 0)

	return 0;
	*/
}

