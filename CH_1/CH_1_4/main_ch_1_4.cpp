/*
1.4강 "입출력 스트림과의 첫 만남 cin, cout"

입출력 스트림을 이용해서 내가 원하는 내용을 콘솔 창에 출력하고,
사용자로부터 입력을 받기도 하는 방법을 알아봄.

cin = console-in
cout = console-out
endl = end-of-line
*/

#include <iostream> // cout, cin, endl; ...
#include <cstdio>	// printf

int main()
{
	using namespace std; // std를 반복해서 쓰기 번거로울 때, { }사이에서는 std를 안 써도 실행됨.

	// 1장. cout
	int x = 1024;
	double pi = 3.141592;

	std::cout << "I love this lecture!\n"; // << std::endl;
	// std = namespace.
	// << = output operator.
	// \n = new line. (std::endl와 거의 비슷하지만 같지는 않음.)
	std::cout << "x is " << x << "pi is" << pi << std::endl;

	std::cout << "abc" << "\t" << "def" << std::endl;
	// \t = tab, 자동으로 줄맞춤을 해줌.
	std::cout << "ab" << "\t" << "cdef" << std::endl;

	cout << "\a";
	// \a = audio 소리 출력.

	// 2장. cin
	//int x; // x가 처음에는 아무런 값이 없거나 garbage 값으로 초기화되어 있음.
	
	//int x = 1;
	//cout << "Before your input, x was " << x << endl;
	
	cin >> x;
	// >> = input operator.
	// 입력받는다 = 데이터를 저장한다.
	cout << "Your input is " << x << endl; // 입력한 값을 저장하여 출력함.

	return 0;
}