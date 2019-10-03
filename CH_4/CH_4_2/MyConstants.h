#pragma once

namespace Constants
{
	// 메모리 주소가 다수가 되는 경우.
	// const double pi(3.145192); // <----- extern 없음.
	// const double gravity(9.8);

	//.cpp 파일에서 초기화를 해주면 하나의 obj 파일에 들어가므로. h에서는 선언만 해준다 -> 메모리 주소가 하나가 된다.
	extern const double pi;		  // <----- extern 있음.
	extern const double gravity;
}