/*
1.14�� "��ó����(Preprocessor)���� ù ����"
Defines the entry point for the console application.
����! define�� ȿ�� ����: Ư�� ���� �ȿ��� define �� ��ũ�δ� ������ ���� �ȿ����� ȿ���� ������. 
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MY_NUMBER "Hello, World"
/*#define MY_NUMBER 33
�ڵ� ������ �ַ� ���Ǵ� Preprocessor�� #define.
�빮�ڷ� �� ������� ��ũ���̸� �ڵ忡�� ��ũ�θ� ������ ������ �ִ� ������ ��ü��.
(��ũ���� ���� ���� �ٲ��ָ� ���带 �ٽ� ���־�� ��.)
��ũ�δ� �ϵ� �ڵ��� �� ���̸�, �ֱٿ� ��ǻ�� ������ �������� ��ũ�� ��ſ� function�� �ַ� �����.
*/

// ������ �߻��ϸ� ��ȣ�� �����ϰ� ������ ��.
// #define MAX(a, b) (a>b) ? a : b		     --- [1]
// #define MAX(a, b) ((a>b) ? a : b)	     --- [2]
#define MAX(a, b) (((a)>(b)) ? (a) : (b)) // --- [3]

//#define LIKE_APPLE �غ� ��.
#define LIKE_APPLE // Preprocessor �ȿ���(#ifdef~#endif) ���� ���� ���� ���� �ʿ� ����.

int main()
{
	cout << MY_NUMBER << endl;

	// cout << MAX(1 , 2) << endl;    --- (1) : [1]�� ����ϸ� ���� �߻�; [2]�� ��ũ�� ����.
	// cout << MAX(1 + 3, 2) << endl; --- (2) : [2]�� ����ϸ� ���� �߻�; [3]���� ��ũ�� ����.
	cout << MAX(1 + 3, 2) << endl;
	// = cout << srd::max(1 + 3, 2) << endl; ������ ����� standard lib�� �̸� ���ǵǾ� �ִ�.

// ��Ƽ �÷����� ���α׷����� �� ����. ex, "OS�� window�� �� A �ڵ带 �����ϰ�, linux�� ���� B �ڵ带 �����϶�."
#ifdef LIKE_APPLE // Preprocessor �� �ϳ��� #ifdef: "If defined"
	cout << "Apple" << endl;
#endif

#ifndef LIKE_APPLE
	cout << "Orange" << endl; // Preprocessor �� �ϳ��� #ifndef: "If not defined"
#endif

	return 0;
}