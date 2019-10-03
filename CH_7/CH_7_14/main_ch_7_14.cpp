/*
7.14�� "�ܾ��ϱ�(assert)"

- ������� �� �� assert�� ���ؼ� runtime�� �����Ϸ��� ������ ���� �� �ִ�.
- Release ��忡���� �۵��� �� �Ѵ�. (Property -> C/C++ -> Perprocessor -> Perprocessor Definitions���� ���� ����)
  --> ���α׷��� ������ ������ ���ƾ� �ϴ� Release ��忡���� assert ������ �����Ѵ�.
*/

#include <iostream>
#include <cassert> // assert.h
#include <array>
using namespace std;

// ���� ��� printValue��� API�� ������� (�ٸ� ���α׷��ӵ��� ������ �𸣰� ����Ѵ�).
void printValue(const std::array<int, 5> &my_array, const int &ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1);

	cout << my_array[ix] << endl;
}

int main()
{
/**************** Topic 1 ****************/
	// () �ȿ� �ʿ��� ������ ������ �ȴ�. --> runtime�� üũ�Ѵ�.
	assert(false); 

/**************** Topic 2 ****************/
	int number = 5;

	// ...

	assert(number == 5); /* �߰� ������ ��ϴ��� �� ���α׷��� number�� 5���� ���� �۵� �� ���̴�.
						    --> runtime�� üũ�Ѵ�. */

/**************** Topic 3 ****************/
	std::array<int, 5> my_array{ 1, 2, 3, 4, 5 };

	printValue(my_array, 100); // 100�� ����Ϸ��� ����ڰ� ���� �� �ִ�.
	// assert�� �ɾ��ָ� runtime ������ �߻��ϱ� ������ ��� �߸��Ǿ����� �� �� �ִ� --> runtime�� üũ�Ѵ�.

/**************** Topic 4 ****************/
	// compile time�� ������ �߻���Ű�� static assert
	/* compile time���� x�� ���� �ٲ� ���� �ִ� ������ ��� �Ұ����ϴ�.
	   int x = 5;
	   x = 10;
	   static_assert(x = 5); 
	   
	--> const int x = 5�� ��쿡�� ��� �����ϴ�. */
	const int x = 5;
	static_assert(x == 5, "x should be 5"); // ����� �����ϴ�.

	return 0;
}