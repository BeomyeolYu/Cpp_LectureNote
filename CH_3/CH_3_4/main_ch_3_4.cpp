/*
3.4강 "sizeof, 쉼표(Comma operator) 연산자, 조건부 연산자(Conditional operator)"

- 조건부 연산자는 3항 연산자라고도 불림.
*/

#include <iostream>
using namespace std;

int getPrice(bool onSale)
{
	if (onSale)
		return 10;
	else
		return 100;
}

int main()
{
/********* Topic 1 *********/
	/* 
	- sizeof는 데이터 형의 크기를 확인할 때 사용되며, 단위는 byte (1 btye = 8 bits).
	- sizeof는 함수로 생각할 수도 있으나 연산자(operator)임.

	- 구조체(struct), 클래스 등을 구현할 때 자신만의 코드에서 편리하게 사용하고자 하는 자료형을 만들 수 있음.
	  이때, 사용자가 만든 자료형에도 sizeof를 사용할 수 있음.
	- 또한 네트워킹 또는 메모리 관리에 필수적으로 사용됨.
	*/
	float t;

	cout << sizeof(float) << endl; // 4 bytes.
	cout << sizeof(t) << endl;	   // 4 bytes.
	cout << sizeof t << endl;      // 4 bytes.

/********* Topic 2 *********/
	/* 
	- Comma operator는 주의가 필요함.
	- 좌변을 먼저 평가하고 우변을 평가한 후 우변의 연산 결과를 리턴함.
	- 쉼표 연산자는 어떤 연산을 한다기보다는 두 연산식을 하나로 묶는 역할만 하며, 이 연산자를 사용하면 두 개의 표현식을 하나로 합칠 수 있음.
	- 복잡한 반복문에서 주로 사용됨.
	*/

	int x = 3;
	int y = 10;
	int z = (++x, ++y); // Comma 앞의 것을 먼저 계산한 후 뒤의 것을 계산하여 z에 대입.
	/*
	++x;
	++y;
	int z = y;
	와 같고, 일반적으로 이와 같이 프로그래밍함. 꼭 필요한 경우가 아니라면 풀어서 직관적으로 코딩하는 것이 더 좋을 수 있음.
	*/
	cout << x << " " << y << " " << z << endl; // 4 11 11 출력.

	int a = 1, b = 10; // 선언에 사용되는 comma는 연산자가 아닌 구분 기호임. ex, sum(1, 2)
	int c;
	c = a, b;		   // 이대로만 둔다면 (c = a), b;와 같음.
	cout << c << endl; // b인 10을 기대했지만 1이 출력됨. 왜냐하면 comma 연산자가 대입 연산자보다 우선순위가 낮아 c = a가 실행된 것임.
	
	int d = (++a, a + b); // a에 1을 더하여 2가 되고(좌변), 2와 10을 더하여(우변) 12가 출력됨.
	cout << d << endl; 


/********* Topic 3 *********/
	/*
	- Conditional operator은 arithmetic if라고도 불림.
	- 단순 비교와 같이 간단한 경우에는 사용하기 유용하나, 복잡한 조건에 대해서는 함수로 프로그래밍 하는 것이 좋음.
	*/
	bool onSale = true;
	const int price = (onSale == true) ? 10 : 100; // 참 일 때는 :의 좌측, 거짓 일 때는 우측 값 반환.
	/* =
	int price;
	if (onSale)
		price = 10;
	else
		price = 100;
	*/
	cout << price << endl;

	// if 문을 사용하여 함수로 짤 수도 있음.
	const int price1 = getPrice(onSale);


/********* Topic 4 *********/
	int n = 5;
	//cout << (x % 2 == 0) ? "even" : "odd" << endl; // 연산자의 우선순위로 인한 오류가 발생함.
	cout << ((x % 2 == 0) ? "even" : "odd") << endl; // 적절한 괄호 사용이 요구됨.

	return 0;
}