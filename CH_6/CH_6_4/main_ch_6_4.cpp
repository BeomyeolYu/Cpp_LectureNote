/*
6.4�� "�迭�� ���� ����(selection sort)"

- �迭�� ���� ����(selection sort)�� �⺻ ����.
  : ���� ���� ���� [1st]�� �����⸦ �ٶ�鼭 mapping �� swapping(=��ȯ)�Ѵ�.

- ����) [3 5 2 1	4]�� array�� selection sort.
			        	value		index
	(1) 3 5	2 1	4         1           3     <-- index 0������ �����Ѵ�. 
	--> �ּ��� index 3��(1)�� 1st�� index 0��(3)�� ���� �ٲ��ش�.

	(2) 1 5	2 3	4         2           2     <-- index 1������ �����Ѵ�.
	--> �ּ��� index 2��(2)�� 2nd�� index 1��(5)�� ���� �ٲ��ش�.

	(3) 1 2	5 3	4         3           3     <-- index 2������ �����Ѵ�.
	--> �ּ��� index 4��(3)�� 3rd�� index 2��(5)�� ���� �ٲ��ش�.

	(4) 1 2	3 5	4         4           4     <-- index 3������ �����Ѵ�.

	(5) 1 2	3 4	5                           <-- index 4������ �����Ѵ�.
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
	// ����) [3 5 2 1 4]�� array�� selection sort�� ����.
	const int length = 5;
	 
	int array[length] = { 3, 5, 2, 1, 4 };

	printArray(array, length); // �ʱ� ����.

	/* swap ���� --> std::swap(...)
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