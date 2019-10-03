// (1) Window Desktop Project
// Precompiled Header: 실무에서는 사용되기도 하나 리눅스나 다른 OS 용 코드로 변환 시에 번거로움이 있음.
// Empty Project: 해제하면 가장 기본적인 .cpp 파일 하나가 생성됨.

// (2) Main이 되는 Project를 생성할 때는 파일 이름에 "main_"을 명명해주는 것이 좋음.

// (3) Debug-> Start Debugging 시에는 우측의 Search Solution Explorer에서 굵은 글씨로 작성된  
// 프로젝트의 .exe파일이 Debug Mode 또는 Release Mode로 실행됨.
// --> Bold charater로 바꾸기 위해서는 프로젝트를 우클릭하여 Set as Startup Project 선택.

// (4) 콘솔 창이 켜졌다가 금방 꺼지는 경우에는 Project 우글릭 후 Properties에서
// Linker-System-SubSystem을 Console로 설정. (상단의 Configuraion에서 각 모드에 대하여 동일.)

// (5) 폴더를 정리할때도 솔루션 파일은 지우면 안된다.
#include <iostream>

int main()
{
	std::cout << "This is cahpter11" << std::endl;

	return 0;
}