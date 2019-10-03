/*
12.5강 "동적 바인딩과 정적 바인딩(Binding)"

- 가상 함수를 이용하는 다형성이 내부적으로는 어떻게 작동하는지 알기위한 개념.
- 정적 바인딩의 속도가 더 빠르다 --> virtual이 느린 이유.
- 동적 바인딩을 쓰면 프로그램이 더 유연해진다. (다형성은 유연한 프로그래밍)
*/

#include <iostream>
using namespace std;

int add(int x, int y)
{
	return x + y;
}
int subtract(int x, int y)
{
	return x - y;
}
int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0: add, 1: subtract, 2: multiply" << endl;
	cin >> op;

/**************** Topic 1 ****************/
	// static binding (early binding): 모든 변수명, 함수명 등이 빌드타임에 깔끔하게 정리된 것.
	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;
/**************** Topic 2 ****************/
	// function pointer의 주소(func_ptr)가 컴파일 타임이 아닌 런타입에 결정된다.
	int(*func_ptr)(int, int) = nullptr;

	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subtract; break;
	case 2: func_ptr = multiply; break;
	}

	cout << func_ptr(x, y) << endl;
	
	return 0;
}