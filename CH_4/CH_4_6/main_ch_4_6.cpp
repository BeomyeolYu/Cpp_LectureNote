/*
4.6강 "문자열 std string 소개(std::string)"
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
/********* Topic 1 *********/
	cout << "Hello, world" << endl; // 마우스를 올리면 const char[13]가 표시된다.
	/* 여기서 []은 배열(array).
	글자는 12개이지만 [13] 으로 표현되는 이유는 맨 뒤에 "끝남"을 표현하는 안 보이는 글자가 숨어있다. */


/********* Topic 2 *********/
	const char mt_strs [] = "Hello, World"; /* (1) 기본적으로 사용되는 방식. */
	const string my_hello = "Hello, World"; /* (2) 프로그래들의 편의를 위하여 제공되는 string을 사용하는 방식.  <-- #include <string>
											      '사용자 정의 자료형'이지만 누군가의 훌륭한 구현으로 기본 자료형처럼 쓰인다.
											      [1] 초기화 방식 */
	const string my_hello_("Hello, World");    // [2] 초기화 방식
	const string my_hello__{ "Hello, World" }; // [3] 초기화 방식

	cout << my_hello << endl;



/********* Topic 3 *********/
	string my_ID = "123"; /*  123을 이용한 연산은 가능하지 않다 = 정수로써 취급되지 않는다.
	string my_ID = 123;      즉, 오류 발생 --> 정수를 문자열로 "암시적" 형변환 해주는 방법이 없기 때문에. (바꿀 수는 있다) */



/********* Topic 4 *********/
	// string의 입력 방법; Jack Jack을 입력하시오.
	cout << "Your name? : ";
	std::string name; // = std::string name;
	cin >> name;
	cout << "Your age? : ";
	string age;
	cin >> age;
	cout << name << " " << age << " " << endl;

	/* Jack Jack을 입력하면 한 번에 name과 age 동시에 Jack Jack이 입력된다.
	왜냐하면 cin는 빈칸을 "입력 다 받았다"라고 생각하여 버퍼에 담아뒀다가 2번째 cin에 넘겨주기 때문이다.
	---> getline을 사용하여 해결할 수 있다; line 단위로 입력되며 엔터 칠 때까지 입력을 마치지 않는다. */
	cout << "Your name? : ";
	string name_;
	std::getline(std::cin, name_);
	cout << "Your age? : ";
	string age_;
	std::getline(std::cin, age_); 
	cout << name_ << " " << age_ << " " << endl;


/********* Topic 5 *********/
	// Topic 4와 동일하지만 name이 int인 경우.
	cout << "Your age? : ";
	int _age; // int의 경우에도 버퍼에 담아주는 문제가 발생한다.
	cin >> _age;
	// std::getline(std::cin, _name); // std::getline는 int와 사용할 수 없음으로 해결책은 아니다.
	std::cin.ignore(32767, '/n'); /* \n을 만날 때까지 최대 32767개의 입력받는 글씨를 무시해버리라는 의미.
								  --> 32767 = 2바이트 int로 표현이 가능한 가장 큰 singed vlaue 값.
   =std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n'); */ // 32767이라는 매직 넘버를 사용하지 않는 경우.
	
	cout << "Your name? : ";
	string _name;
	std::getline(std::cin, _name);
	cout << _name << " " << _age << " " << endl;

	
/********* Topic 6 *********/
	// string을 만든 유저가 구현해놓았기 때문에 문자열끼리 더하기 또한 가능하다.
	string a("Hello, ");
	string b("World");
	string hw = a + b; // append(덧붙이다)라고 부른다.

	hw += " I'm good";

	cout << hw << endl; // Hello, World I'm good 출력.


/********* Topic 7 *********/
	// 길이 또한 측정할 수 있다.
	cout << a.length() << endl; // 7 출력. (문자의 array는 [8]이다; 문자열의 끝을 표시하는 null character가 숨어있기 때문에)

	return 0;
}