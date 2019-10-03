/*
5.1�� "���� �帧 ����(Control flow)"

- ���α׷����̶� ���� CPU���� �� ���� ������ �ִ� ���̴�.
*/

/*
1. �ߴ�(Halt)
2. ����(Jump): goto, break, continue
3. ���� �б�(Conditional branches): if, switch
4. �ݺ�(Loops): while, do while, for
5. ���� ó��(Exceptions): try, catch, throw
*/

#include <iostream>
using namespace std;

int main()
{
/**************** Topic 1 ****************/
	// �ߴ�(Halt)
	cout << "I love you" << endl;

	exit(0); /* �ߴ�(1): ����ϰ� ������. 
						1) �ϵ���� ���õ� �ڵ� ���� ��쿡 ������ �������ϴ� ���. 
						2) ������ϴ� ���. */

	return 0; // �ߴ�(2): ���� �ǹ̷� return ������ �ڵ嵵 �ּ����� �ٶ� �� �ִ�.
	cout << "I love you" << endl;
}