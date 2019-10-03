/*
8.15�� "���� �ð� �����ϱ�"

- ����ȭ�� �������̸� Ư�� �ǽð����� �۵��ϴ� ���ø����̼ǿ��� �߿��ϴ�.
- Debug mode���� Release mode���� ���� �ӵ��� �����ϰ� ������.
  --> ���� ���α׷��� Release mode�� �����ϱ� ������ Release mode���� �ӵ��� �����Ͽ��� �Ѵ�.
- ���� ��ҿ� ���� ���̰� ���� ���Ƿ� �ð��� ������ ���� �ּ� 3�� �����Ѵ�.
  --> Ex, ��Ƽ ���̷��� ���α׷��� ���� ������, �뷡�� ���� �ִ��� ��
*/

#include <iostream>
#include <vector> // sorting �ϴ� �ð��� �����ϱ� ����.
#include <algorithm>
#include <random>
#include <chrono> // ũ�γ뽺

using namespace std;

class Timer // chrono�� �����ϰ� ����ϴ� ���� ��ư� ������ �� ������, class Timer�� �ϴ� �ѹ� ����� ������ ���Ŀ��� ����ϱ⸸ �ϸ� �ȴ�.
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now(); // �����ϴ� �ð� start_time�� member variable�� �����Ͽ� ���� �ð��� ����(clock_t::now()).

public:
	void elapesd()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now(); // ���� �ð��� ����(clock_t::now()).

		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl; 
		// --> end_time - start_time�� �ʷ� �����Ͽ�(<second_t>) ����Ѵ�(.count()).
	}
};

int main()
{
	// ���� ����
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(10); // vector<int> vec(100000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	std::shuffle(begin(vec), end(vec), mersenne_engine); // vec�� shuffle �Ѵ�.

	for (auto &e : vec) cout << e << " "; // shuffle�� �� �Ǿ����� ���.
	cout << endl;

	Timer timer;					 // timer ����.
	std::sort(begin(vec), end(vec)); // sorting.
	timer.elapesd();				 // timer�� �� �ð��� ���.

	for (auto &e : vec) cout << e << " "; // sorting�� �� �Ǿ����� ����� Ȯ��.
	cout << endl;

	return 0;
}