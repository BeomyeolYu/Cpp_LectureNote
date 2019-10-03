/*
8.15강 "실행 시간 측정하기"

- 최적화의 시작점이며 특히 실시간으로 작동하는 애플리케이션에서 중요하다.
- Debug mode보다 Release mode에서 실행 속도가 월등하게 빠르다.
  --> 실제 프로그램은 Release mode로 배포하기 때문에 Release mode에서 속도를 측정하여야 한다.
- 많은 요소에 따라 차이가 많이 나므로 시간을 측정할 때는 최소 3번 수행한다.
  --> Ex, 안티 바이러스 프로그램이 실행 중인지, 노래가 켜져 있는지 등
*/

#include <iostream>
#include <vector> // sorting 하는 시간을 측정하기 위함.
#include <algorithm>
#include <random>
#include <chrono> // 크로노스

using namespace std;

class Timer // chrono를 복잡하게 사용하는 것이 어렵게 느껴질 수 있으나, class Timer를 일단 한번 만들어 놓으면 추후에는 사용하기만 하면 된다.
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now(); // 시작하는 시간 start_time을 member variable로 선언하여 현재 시간을 측정(clock_t::now()).

public:
	void elapesd()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now(); // 끝난 시간을 측정(clock_t::now()).

		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl; 
		// --> end_time - start_time를 초로 변경하여(<second_t>) 출력한다(.count()).
	}
};

int main()
{
	// 난수 생성
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(10); // vector<int> vec(100000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	std::shuffle(begin(vec), end(vec), mersenne_engine); // vec를 shuffle 한다.

	for (auto &e : vec) cout << e << " "; // shuffle이 잘 되었는지 출력.
	cout << endl;

	Timer timer;					 // timer 시작.
	std::sort(begin(vec), end(vec)); // sorting.
	timer.elapesd();				 // timer가 잰 시간을 출력.

	for (auto &e : vec) cout << e << " "; // sorting이 잘 되었는지 결과를 확인.
	cout << endl;

	return 0;
}