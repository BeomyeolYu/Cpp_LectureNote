/*
6.6강 "C언어 스타일의 배열 문자열"
*/

#include <iostream>
#include <cstring> 

using namespace std;

int main()
{
/**************** Topic 1 ****************/
	char myString[] = "string"; // 마우스를 올리면 char myString[7] = 6글자 + null character(\0)

	// null character(\0)가 포함되어 있다는 증거.
	for (int i = 0; i < 7; ++i)
	{
		cout << myString[i] << endl; // 마지막에 안 보이는 글자가 하나 있다.
		// ASCII
		cout << (int)myString[i] << endl; // 마지막에 0이 출력된다 --> 115는 s, 0은 NUL in ASCII table.
		// sizeof
		cout << sizeof(myString) / sizeof(myString[0]) << endl; // null character를 포함하여 사이즈가 7이다.
	}

/**************** Topic 2 ****************/
	// cin을 이용한 문자열 입력.
	char cinString[255]; // 몇 글자가 입력될지 모르기 때문에 보통 큰 글자를 잡는다. 
	
	cin.getline(cinString, 255); // buffer 방지.
	cinString[0] = 'A';  // 첫 번째 글자가 무조건 A로 바뀐다.
	cinString[10] = '\0'; /* char의 배열로 된 문자열을 출력할 때는 전부 일시에 출력되는 것이 아니라,
						    null character가 나오기 전까지만 출력되는 것이다(=출력 중단). */
	int ix = 0;
	while (true) // cinString에 들어있는 문자열을 모두 출력하는 구문.
	{
		if (cinString[ix] == '\0') break; /* 할당된 255개의 공간을 모두 보다가 null을 만나면 빠져나와라.
										   --> 빈칸(32)과 null(0)은 주소가 다르다. */
		cout << cinString[ix] << " " << (int)cinString[ix] << endl;
		++ix;
	}

/**************** Topic 3 ****************/
	// #include <cstring>을 이용한 전통적인 c언어 스타일 코딩.
	char source[] = "Copy this! ";
	char dest[50]; // destination <--목표, 최대 50글자가 들어올 수 있다.
	
	strcpy(dest, source); /* strcpy = string copy; source에 있는 것을 destination에 복사에 넣는 함수.
						    --> 그래서 마우스를 올리면 source에는 const가 붙어있다. */
	cout << source << endl;
	cout << dest << endl;

	/* 그러나 source보다 dest이 작으면 (ex, char dest[5];) 메모리를 침범하므로 Runtime error가 발생한다.
	   이를 방지하기 위하여 최근엔 strcpy_s을 반강제적으로 사용하도록 권면하고 있다. */
	strcpy_s(dest, 50, source); // s = secured, 최대 복사해 넣을 수 있는 메모리를 입력해야 한다.

/**************** Topic 4 ****************/
	// 추가적인 c언어 스타일 함수.
	
	/* strcat(): cat = concatenate(스트링 연결)
	   string2를 string1에 연결하고 널 문자로 결과 스트링을 종료. */
	strcat(dest, source);
	cout << source << endl;
	cout << dest << endl;

	/* strcmp(): cmp = compare
	   if 문의 조건으로 사용할 때 매우 주의가 필요함. 
	   --> cout < 0: string1이 string2보다 작음: 
		   cout = 0: string1이 string2와 같음 = if 문의 false
	       cout > 0: string1이 string2보다 큼 = if 문의 ture   
    */
	cout << strcmp(dest, source) << endl; // 1 출력
	
	return 0;
}