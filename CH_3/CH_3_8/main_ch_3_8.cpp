/*
3.8�� "��Ʈ ���� ������(Bitwise Operators)"

- ������ bit���� �����ϴ� ������.
  (int������ ��, float������ ���� Ÿ�Գ����� �����̶�� �� �� ����.)
- �޸𸮸� �Ƴ��� ���� �ӵ��� ������ �ϱ� ���Ͽ� �����.
- unsigned�� ����ϴ� ���� �Ϲ�����.
*/

#include <iostream>
#include <bitset>     // <- #include

int main()
{
	using namespace std;
/********* Topic 1 *********/
	/* 
	<< : left shift
	>> : right shift
	  -> cin, cout������ ���Ӱ��� �ٸ�. ���⼱ Bitwise Operators�� �ƴϸ� Bitwise Operators�� default��.
	  -> ��ȣ�� ������ ������ �ֱ� ������ '���� �ε�'�Ͽ� �����.
	~ : Bitwise NOT (logical not = !a)
	& : Bitwise AND
	| : Bitwise OR
	^ : Bitwise XOR
	*/


/********* Topic 2 *********/
	unsigned int a = 3;
	cout << std::bitset<4>(a) << endl; // a�� ���������� ��� 2������ ǥ���Ǵ��� ������. 4 bits�� Ȯ��.

	// left shift
	unsigned int b = a << 1;
	cout << std::bitset<4>(b) << " in decimal " << b << endl; // 0011(=3)���� ���������� �� ĭ�� �̵��ϰ� ���ڸ��� 0���� ä�� 0110(=6)�� ���.

	// 8 bits = 1 btye
	cout << std::bitset<8>(a) << " in decimal " << a << endl;			   // 3 ���
	cout << std::bitset<8>(a << 1) << " in decimal " << (a << 1) << endl;  // 6(=3*2^1) ���
	cout << std::bitset<8>(a << 2) << " in decimal " << (a << 2) << endl;  // 12(=3*2^2) ���
	cout << std::bitset<8>(a << 3) << " in decimal " << (a << 3) << endl;  // 24(=3*2^3) ���
	cout << std::bitset<8>(a << 4) << " in decimal " << (a << 4) << endl;  // 48(=3*2^4) ���
	// left shift�� ���� ���̴� ����: � ���� 2�� ������ ���� ��, ���ϱ� �Ǵ� power ���� ����� ��캸�� ������ �ξ� ������.


/********* Topic 3 *********/
	// right shift
	unsigned int i = 1012;
	// 16 bits
	cout << std::bitset<16>(i) << " in decimal " << i << endl;			    // 1024 ���
	cout << std::bitset<16>(i >> 1) << " in decimal " << (i >> 1) << endl;  // 512 ���
	cout << std::bitset<16>(i >> 2) << " in decimal " << (i >> 2) << endl;  // 256 ���
	cout << std::bitset<16>(i >> 3) << " in decimal " << (i >> 3) << endl;  // 128 ���
	cout << std::bitset<16>(i >> 4) << " in decimal " << (i >> 4) << endl;  // 64 ���
	// ���� �ӵ��� �ξ� ��������, 2���� ǥ���̹Ƿ� �Ϲ������� �����ϴ� ������, ���ϱ�� ����� �� ����.


/********* Topic 4 *********/
	// ~ : Bitwise NOT = ����(complement)
	cout << std::bitset<16>(i) << " in decimal " << i << endl;	    // 0000001111110100(=1024) ���
	cout << std::bitset<16>(~i) << " in decimal " << (~i) << endl;  // 1111110000001011(=4294966283) ���; 10���� ǥ�������� ��Ģ���� ã��� ��ƴ�.


/********* Topic 5 *********/
	// ������ ǥ��: �տ� 0b�� ���δ�.
	unsigned int n = 0b1100;
	unsigned int m = 0b0110;
	cout << " n is (in decimal) " << n << " m is (in decimal) " << m << endl;
	
	/* '1100' ��
	   '0110' ���̿� bit ������ AND, OR, XOR�� �Ǵ�.

	Ex,  1100
	AND  0110
	-----------
	     0100
	*/

	// &: Bitwise AND
	cout << std::bitset<4>(n & m) << " in decimal " << (n & m) << endl; // 0100 ���.

	// | : Bitwise OR
	cout << std::bitset<4>(n | m) << " in decimal " << (n | m) << endl; // 1110 ���.

	// ^ : Bitwise XOR
	cout << std::bitset<4>(n ^ m) << " in decimal " << (n ^ m) << endl; // 1010 ���.


/********* Topic 6 *********/
	/*
	Bitwise Operators�� ������ ���·� �ٿ��� ����� �� ����.
	(1) a = a & b ��
	(2) a &= b    �� ����.
	*/


	return 0;
}