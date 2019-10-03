/*
5.9강 "난수 만들기(random numbers); Random Number Generation"
-컴퓨터는 정확한 계산만 잘하고 임의의 숫자(random number)를 스스로 만들 능력이 없다.
*/

#include <iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime>   // std::time()
#include <random>

using namespace std;

/* 랜덤 넘버 생성의 원리를 설명하는 함수 --> 실제로는 라이브러리 사용.
   --> 난수를 생성하는 함수라기보다는 계산해내는 함수. */
static unsigned int PRNG() // Pseudo Random Number Generator(Pseudo: 허위의, 가짜의; 모조의)
{
	static unsigned int seed = 5523; // seed number

	seed = 8253729 * seed + 2396403; // seed number 하고 아주 큰 숫자를 곱하고 더해주고,
	return seed % 32768;			 // 나눠줘서 난수를 만든다.
}
/* seed number를 static으로 선언하는 이유: static은 생성된 스코프(=범위)가 종료한 이후에도 해당 값을 유지하는 변수로 정적 변수는 한 번만 초기화되며 프로그램 수명 내내 지속된다.
   --> for 문이 돌면서 seed가 unsigned int seed = 5523;에 의해 반복적으로 초기화되면 안 되고 이전에 계산되어 바뀌는 seed 값을 사용하기 위하여 static 변수로 선언. */

// 특정한 정수 범위 내에서 난수를 생성하는 함수.
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main()
{
/**************** Topic 1 ****************/
	for (int count = 1; count <= 100; ++count) // 난수 100개를 출력.
	{
		cout << PRNG() << "\t";

		if (count % 5 == 0) cout << endl;
	}


/**************** Topic 2 ****************/
	// #include <cstdlib>라이브러리 활용: seed number가 Topic 1가 같기 때문에 결과 또한 같다.
	// Ctrl+F5를 누르면 새로운 창에서 빌드.
	std::srand(5323); //앞의 s-는 seed number
	for (int count = 1; count <= 100; ++count) // 난수 100개를 출력.
	{
		cout << std::rand() << "\t";

		if (count % 5 == 0) cout << endl;
	}


/**************** Topic 3 ****************/
	// seed number를 바꾸는 방법 --> std::time()을 이용.
	// 디버깅할 때는 seed number를 고정해야만 한다. --> seed number가 변화하면 특정 오류가 발생하기도 하고 안 하기도 하기 때문에.
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int count = 1; count <= 100; ++count) // 난수 100개를 출력.
	{
		cout << std::rand() << "\t";

		if (count % 5 == 0) cout << endl;
	}


/**************** Topic 4 ****************/
	// 특정한 정수 범위 내에서 정수 난수를 생성하는 함수.
	for (int count = 1; count <= 100; ++count) // 난수 100개를 출력.
	{
		cout << getRandomNumber(5, 8) << "\t";
		// = cout << rand() % 4 + 5 << "\t"; 
		if (count % 5 == 0) cout << endl;
	}


/**************** Topic 5 ****************/
	// rand()의 경우 큰 값에 대한 정밀도에 문제가 생길 수 있어서 C++ 11부터 추가된 #include <random>을 사용하는 것이 좋다.
	// (1)  random_device를 만든다.
	std::random_device rd; 
	// (2) random_device를 넣어서 생성기를 만든다.
	std::mt19937 mersenne(rd()); // 32 bits 난수 생성 (cf) std:: mt19937_64 = 64 bits 난수 생성 
								 // create a mersenne  twister = seed가 고정되지 않도록 time을 연동한 것과 같은 방법.
	// (3) 생성기가 어떤 분포를 따를지 정한다.
	std::uniform_int_distribution<> dice(1, 6); //1부터 6이하로 동일한 확률 분포
	// (4) 지정한 분포대로 생성기에서 난수 생성.
	for (int count = 1; count <=20; ++count)
	cout << dice(mersenne) << endl;



	return 0;
}