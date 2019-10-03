/*
7.15강 "명령줄 인수(command line arguments)"

- main() 안에도 parameter를 넣을 수 있으며, 대표적으로 2가지가 있다.
- x86 prompt를 이용하여 스크립트 작업을 수행할 수 있다.
1. cd B:\Drive\OneDrive - 충남대학교\프로젝트\00 개인연구\01 C++\repos\CH_7\Debug
2. CH_7_15.exe

-  Boost C++ Libraries를 사용할 수도 있다 --> 준표준 정도로 생각할 수 있다.
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) // int argc: 개수, char *argv[]: 실제 내용들
{
	for (int count = 0; count < argc; ++count)
	{
		std::string argv_singel = argv[count]; // string으로 casting.

		if (count == 1)
		{
			int input_number = std::stoi(argv_singel); // 필요한 데이터 타입으로 casting. Ex) int
				cout << input_number + 1 << endl;
		}
		else
			cout << argv_singel << endl;
	}
	
	return 0;
}