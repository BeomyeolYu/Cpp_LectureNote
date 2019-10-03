/*
6.4강 "배열과 선택 정렬(selection sort)"

- 배열과 선택 정렬(selection sort)의 기본 개념.
  : 가장 작은 값이 [1st]에 들어오기를 바라면서 mapping 후 swapping(=교환)한다.

- 예시) [3 5 2 1	4]인 array의 selection sort.
			        	value		index
	(1) 3 5	2 1	4         1           3     <-- index 0번부터 시작한다. 
	--> 최소인 index 3번(1)을 1st인 index 0번(3)과 서로 바꿔준다.

	(2) 1 5	2 3	4         2           2     <-- index 1번부터 시작한다.
	--> 최소인 index 2번(2)과 2nd인 index 1번(5)를 서로 바꿔준다.

	(3) 1 2	5 3	4         3           3     <-- index 2번부터 시작한다.
	--> 최소인 index 4번(3)과 3rd인 index 2번(5)를 서로 바꿔준다.

	(4) 1 2	3 5	4         4           4     <-- index 3번부터 시작한다.

	(5) 1 2	3 4	5                           <-- index 4번부터 시작한다.
*/

#include <iostream>
using namespace std;

void printArray(const int array[], const int length)
{
	for (int index = 0; index < length; ++index)
		cout << array[index] << " ";
	cout << endl;
}

int main()
{
	// 예시) [3 5 2 1 4]인 array의 selection sort의 구현.
	const int length = 5;
	 
	int array[length] = { 3, 5, 2, 1, 4 };

	printArray(array, length); // 초기 조건.

	/* swap 구문 --> std::swap(...)
	int temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	printArray(array, length); */

	for (int startIndex = 0; startIndex < length - 1; startIndex++)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex +1; currentIndex < length; currentIndex++)
		{
			if (array[smallestIndex] > array[currentIndex])
			{
				smallestIndex = currentIndex;
			}
		}
		// swap two values in the array.
		// std::swap(array[smallestIndex], array[startIndex]);
		{
			int temp = array[smallestIndex];
			array[smallestIndex] = array[startIndex];
			array[startIndex] = temp;
		}
		printArray(array, length);
	}

	/* MY HOMEWORK!!
	for (int i = 0; i < length-1; i++)
	{
		int j = 0;
		int marker = 0;
		int min_value = 10;
		int temp = array[i];
		j = i;
		for (j; j < length; j++)
		{
			if (array[j] < min_value)
			{
				min_value = array[j];
				marker = j;
			}
		}
		array[marker] = temp;
		cout << "temp " << temp << endl;
		array[i] = min_value;
		cout << "min_value " << min_value << endl;
		printArray(array, length);
	}
	*/

	return 0;
}