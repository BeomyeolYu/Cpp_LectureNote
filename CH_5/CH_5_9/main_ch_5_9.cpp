/*
5.9�� "���� �����(random numbers); Random Number Generation"
-��ǻ�ʹ� ��Ȯ�� ��길 ���ϰ� ������ ����(random number)�� ������ ���� �ɷ��� ����.
*/

#include <iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime>   // std::time()
#include <random>

using namespace std;

/* ���� �ѹ� ������ ������ �����ϴ� �Լ� --> �����δ� ���̺귯�� ���.
   --> ������ �����ϴ� �Լ���⺸�ٴ� ����س��� �Լ�. */
static unsigned int PRNG() // Pseudo Random Number Generator(Pseudo: ������, ��¥��; ������)
{
	static unsigned int seed = 5523; // seed number

	seed = 8253729 * seed + 2396403; // seed number �ϰ� ���� ū ���ڸ� ���ϰ� �����ְ�,
	return seed % 32768;			 // �����༭ ������ �����.
}
/* seed number�� static���� �����ϴ� ����: static�� ������ ������(=����)�� ������ ���Ŀ��� �ش� ���� �����ϴ� ������ ���� ������ �� ���� �ʱ�ȭ�Ǹ� ���α׷� ���� ���� ���ӵȴ�.
   --> for ���� ���鼭 seed�� unsigned int seed = 5523;�� ���� �ݺ������� �ʱ�ȭ�Ǹ� �� �ǰ� ������ ���Ǿ� �ٲ�� seed ���� ����ϱ� ���Ͽ� static ������ ����. */

// Ư���� ���� ���� ������ ������ �����ϴ� �Լ�.
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main()
{
/**************** Topic 1 ****************/
	for (int count = 1; count <= 100; ++count) // ���� 100���� ���.
	{
		cout << PRNG() << "\t";

		if (count % 5 == 0) cout << endl;
	}


/**************** Topic 2 ****************/
	// #include <cstdlib>���̺귯�� Ȱ��: seed number�� Topic 1�� ���� ������ ��� ���� ����.
	// Ctrl+F5�� ������ ���ο� â���� ����.
	std::srand(5323); //���� s-�� seed number
	for (int count = 1; count <= 100; ++count) // ���� 100���� ���.
	{
		cout << std::rand() << "\t";

		if (count % 5 == 0) cout << endl;
	}


/**************** Topic 3 ****************/
	// seed number�� �ٲٴ� ��� --> std::time()�� �̿�.
	// ������� ���� seed number�� �����ؾ߸� �Ѵ�. --> seed number�� ��ȭ�ϸ� Ư�� ������ �߻��ϱ⵵ �ϰ� �� �ϱ⵵ �ϱ� ������.
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int count = 1; count <= 100; ++count) // ���� 100���� ���.
	{
		cout << std::rand() << "\t";

		if (count % 5 == 0) cout << endl;
	}


/**************** Topic 4 ****************/
	// Ư���� ���� ���� ������ ���� ������ �����ϴ� �Լ�.
	for (int count = 1; count <= 100; ++count) // ���� 100���� ���.
	{
		cout << getRandomNumber(5, 8) << "\t";
		// = cout << rand() % 4 + 5 << "\t"; 
		if (count % 5 == 0) cout << endl;
	}


/**************** Topic 5 ****************/
	// rand()�� ��� ū ���� ���� ���е��� ������ ���� �� �־ C++ 11���� �߰��� #include <random>�� ����ϴ� ���� ����.
	// (1)  random_device�� �����.
	std::random_device rd; 
	// (2) random_device�� �־ �����⸦ �����.
	std::mt19937 mersenne(rd()); // 32 bits ���� ���� (cf) std:: mt19937_64 = 64 bits ���� ���� 
								 // create a mersenne  twister = seed�� �������� �ʵ��� time�� ������ �Ͱ� ���� ���.
	// (3) �����Ⱑ � ������ ������ ���Ѵ�.
	std::uniform_int_distribution<> dice(1, 6); //1���� 6���Ϸ� ������ Ȯ�� ����
	// (4) ������ ������� �����⿡�� ���� ����.
	for (int count = 1; count <=20; ++count)
	cout << dice(mersenne) << endl;



	return 0;
}