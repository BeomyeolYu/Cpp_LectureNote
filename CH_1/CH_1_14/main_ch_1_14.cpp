/*
1.14강 "전처리기(Preprocessor)와의 첫 만남"
Defines the entry point for the console application.
주의! define의 효력 범위: 특정 파일 안에서 define 한 매크로는 동일한 파일 안에서만 효과를 발휘함. 
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MY_NUMBER "Hello, World"
/*#define MY_NUMBER 33
코드 내에서 주로 사용되는 Preprocessor인 #define.
대문자로 쓴 보라색은 매크로이며 코드에서 매크로를 만나면 우측에 있는 값으로 교체함.
(매크로의 우측 값을 바꿔주면 빌드를 다시 해주어야 함.)
매크로는 하드 코딩할 때 쓰이며, 최근엔 컴퓨터 성능이 좋아져서 매크로 대신에 function을 주로 만든다.
*/

// 에러가 발생하면 괄호를 적절하게 씌워야 함.
// #define MAX(a, b) (a>b) ? a : b		     --- [1]
// #define MAX(a, b) ((a>b) ? a : b)	     --- [2]
#define MAX(a, b) (((a)>(b)) ? (a) : (b)) // --- [3]

//#define LIKE_APPLE 해볼 것.
#define LIKE_APPLE // Preprocessor 안에서(#ifdef~#endif) 사용될 때는 우측 값이 필요 없음.

int main()
{
	cout << MY_NUMBER << endl;

	// cout << MAX(1 , 2) << endl;    --- (1) : [1]를 사용하면 에러 발생; [2]로 매크로 변경.
	// cout << MAX(1 + 3, 2) << endl; --- (2) : [2]를 사용하면 에러 발생; [3]으로 매크로 변경.
	cout << MAX(1 + 3, 2) << endl;
	// = cout << srd::max(1 + 3, 2) << endl; 간단한 기능은 standard lib에 미리 정의되어 있다.

// 멀티 플랫폼을 프로그래밍할 때 사용됨. ex, "OS가 window일 때 A 코드를 실행하고, linux일 때는 B 코드를 실행하라."
#ifdef LIKE_APPLE // Preprocessor 중 하나인 #ifdef: "If defined"
	cout << "Apple" << endl;
#endif

#ifndef LIKE_APPLE
	cout << "Orange" << endl; // Preprocessor 중 하나인 #ifndef: "If not defined"
#endif

	return 0;
}