/*
2.7강 "문자형(Char type)"

- 문자로 숫자로 표현하는 방법: ASCII TABLE 참고.
  (1~32번까지는 unprintable character로 화면에 출력이 안됨.)
*/

#include <iostream>
#include <limits>

int main()
{
	using namespace std;

	/******* Topic 1 *******/
	char c1(65);  // same as c1 = 65; c1{65};
	char c2('A'); // 한 글자를 표현할 때는 작은따옴표, 문자열을 표현할 때는 큰따옴표. "Hello, World".

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl; // = casting.
	/*
	(Type) casting: 형 변환

	프로그래밍을 하다 보면 형이 다른 변수끼리 대입을 하는 연산이 필요로 하게 됨.
	예를 들어 double형 변수의 값을 int형 변수에 대입하거나, float형 변수에 double형 변수의 값을 대입하는 것 등.

	 int a;
	 double b;
	 b = 2.4;
	 a = b; **** Error ****
	-> Casting
	 b = 2.4;
	 a = (int)b;
	*/

	/******* Topic 2 *******/
	// C-style casting
	cout << (char)65 << endl;
	cout << (int)'A' << endl;

	// Cpp-style casting
	cout << char(65) << endl; // 65를 char로 바꾼다는 개념보다는 65로 초기화된 char를 char(65)로 새로 만든다는 의미.
	cout << int('A') << endl;

	// 위의 2개는 강제로 변환을 하는 개념이 강하고 Static cast는 기본형들을 변환할 때 컴파일러에게 문제가 없는지 미리 체크 좀 해주세요의 개념이 강하다.
	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;

	/******* Topic 3 *******/
	// static_cast에 변수를 넣을 수도 있음.
	// static_cast를 해도 원래 변수의 저장된 값이 바뀌지는 않음.
	char ch(97);
	cout << ch << endl;
	cout << static_cast<int>(ch) << endl;
	cout << ch << endl;

	/******* Topic 4 *******/
	// c1의 사이즈가 1글자만 받을 수 있기 때문에 3글자(abc)를 입력해도 받을 수 없음.
	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;
	// 남은 2글자는 string opeator는 buffer라는 임시 저장소에 남아있다. 이 경우 다음과 같이 추가하면 됨.
	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;
	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;

	/******* Topic 5 *******/
	cout << sizeof(char) << endl; // 1
	cout << (int)std::numeric_limits<char>::max() << endl; // 127
	cout << (int)std::numeric_limits<char>::lowest() << endl; // -128

	cout << sizeof(unsigned char) << endl;  // 1
	cout << (int)std::numeric_limits<unsigned char>::max() << endl; // 255
	cout << (int)std::numeric_limits<unsigned char>::lowest() << endl; // 0

	/******* Topic 6 *******/
	cout << int('/n') << endl; // new line = 10(ASCII TABLE)
	cout << "This is the first line \n second line";

	cout << int('/t') << endl; // tab = 9(ASCII TABLE)
	cout << "This is the first line \t second line";

	cout << int('/a') << endl; // audio 
	cout << "This is the first line \a second line";

	return 0;
}