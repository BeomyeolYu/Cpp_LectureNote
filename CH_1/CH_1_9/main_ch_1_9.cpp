/*
1.9강 "기본적인 서식 맞추기"
프로그래머의 효율을 위해서, 결국은 사람이 봤을 때 얼마나 편안한가 또한 얼마나 여백을 잘 사용했는가.
그룹에서의 규칙을 따르는 것이 좋으며 전체를 통일하는 것이 좋음.
*/
#include <iostream>

using namespace std;

int add(int x, int y) 
{ 
return x + y; // 여백(indenting)을 안 주면 프로그래머 사이에서 몰상식한 사람으로 통함.
	return x + y; // indenting: Tab 한 번 또는 스페이스 4번
}

int main()
{
	// Visual Studio는 엔터를 인식하지 않으나 잘 끊어야 함.
	// 단, " "사이의 여백은 무시하지 않는다.
	// Case 1
	cout << "Hello" << ", World"   // 이어진 문장이지만 ;이 필요해 보임.
		<< " Hello Home" << endl; 
	// Case 2
	cout << "Hello" << ", World" << // 줄바꿈 할때는 operator를 뒤에 남겨놓는 것이 좋음.
		" Hello Home" << endl; 
	
	int my_v		= 1;
	int z			= 4;
	int num_apples	= 123; // Tab key로 literal들을 줄 맞춤.
	/* 하드 코딩(hard coding): 프로그래머가 코드에서 변숫값을 literal 같이 고정된 값으로 직접 대입해주는 방식.
	 소프트 코딩(soft coding): 프로그램 실행 중에 사용자가 입력이나 외부 파일, 인터넷 통신 등으로 데이터를 가져오는 방식. 
	 "부드럽고 유연한 프로그래머가 되시길 바래요!"
	*/

	// This is important.
	int x = 1 + 2; 

	// 주석이 위에 있을 때는 줄을 띄어주는 센스.
	int	y = 3 + 4;

	return 0;
}
