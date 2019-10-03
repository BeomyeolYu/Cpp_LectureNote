/*
7.15�� "����� �μ�(command line arguments)"

- main() �ȿ��� parameter�� ���� �� ������, ��ǥ������ 2������ �ִ�.
- x86 prompt�� �̿��Ͽ� ��ũ��Ʈ �۾��� ������ �� �ִ�.
1. cd B:\Drive\OneDrive - �泲���б�\������Ʈ\00 ���ο���\01 C++\repos\CH_7\Debug
2. CH_7_15.exe

-  Boost C++ Libraries�� ����� ���� �ִ� --> ��ǥ�� ������ ������ �� �ִ�.
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) // int argc: ����, char *argv[]: ���� �����
{
	for (int count = 0; count < argc; ++count)
	{
		std::string argv_singel = argv[count]; // string���� casting.

		if (count == 1)
		{
			int input_number = std::stoi(argv_singel); // �ʿ��� ������ Ÿ������ casting. Ex) int
				cout << input_number + 1 << endl;
		}
		else
			cout << argv_singel << endl;
	}
	
	return 0;
}