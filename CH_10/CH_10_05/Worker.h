#pragma once

// #include "Timer.h" 
/* --> Worker class를 선언할 때, class level에서는 Timer class의 정보가 불필요하다: Dependencies relationship
   --> Worker.cpp에 선언되어있으면 된다. */

class Worker
{
public:
	void doSomething();
};
