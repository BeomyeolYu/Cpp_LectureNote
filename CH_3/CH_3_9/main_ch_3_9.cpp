/*
3.9�� "��Ʈ �÷���(Bit flags)�� ��Ʈ ����ũ(Bit masks) ����"
*/

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
/********* Topic 1 *********/
	// (1) ��Ʈ �÷���(Bit flags)
	// Game item simulation
	bool item_1_flag = false;
	bool item_2_flag = false;
	bool item_3_flag = false;
	bool item_4_flag = false;

	// event!
	item_1_flag = true;

	// die! item_2 lost!
	item_2_flag = false;

	if (item_3_flag == true)
	{
		// open the door!
	}

	if (item_3_flag == true && item_4_flag == false)
	{
		// Item rank up! item_3 -> item_4
		item_3_flag = false;
		item_4_flag = true;
	}


/********* Topic 2 *********/
	/* But we want to make 8 items
	-> �ϳ��� bit�� bool Ÿ������ ������ �� ����. 
	-> 1 byte char�� 8���� ���������� Ȱ��. */ 

	const unsigned char opt0 = 1 << 0; // 0�� option, left shift operator
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;
	// opt4, 5, 6, 7�� ������ ������� �ø� �� ����.

	cout << "opt0 " << bitset<8>(opt0) << endl; // 00000001
	cout << "opt1 " << bitset<8>(opt1) << endl; // 00000010
	cout << "opt2 " << bitset<8>(opt2) << endl; // 00000100
	cout << "opt3 " << bitset<8>(opt3) << endl; // 00001000
	cout << endl;

	unsigned char items_flag = 0;
	cout << "No item " << bitset<8>(items_flag) << endl;

	// get an item0
	items_flag |= opt0; // |= : ��Ʈ OR ���� ������, items_flag = items_flag | opt0;
	cout << "Item0 obtained " << bitset<8>(items_flag) << endl;
	// get an item3
	items_flag |= opt3; 
	cout << "Item3 obtained " << bitset<8>(items_flag) << endl;
	// lose an item3
	items_flag &= ~opt3; // &= : Bitwise AND, ~ : Bitwise NOT = ����(complement)
	cout << "Item3 lost " << bitset<8>(items_flag) << endl;
	// get an item2 and 3
	items_flag |= (opt2 | opt3);
	cout << "(opt2 | opt3) " << bitset<8>((opt2 | opt3)) << endl;
	cout << "Item2,3 obtained " << bitset<8>(items_flag) << endl;
	cout << endl;
	// has an item2 and does not have item1
	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		// 00001101 items_flag
		// 00000100 opt2 (XOR)
		// 00001001 items_flag
		// 00000010 opt1 (XOR)
		// 00001011 items_flag
		items_flag ^= opt2; // ^ : Bitwise XOR
		items_flag ^= opt1;
		// = items_flag ^= (opt2 | opt1);
	}
	cout << "has an item2 and does not have item1 " << bitset<8>(items_flag) << endl;


	// serch an item1
	if (items_flag & opt1) { cout << "My character has an item1 " << endl; }
	else { cout << "Not have an item1 " << endl; }
	// serch an item0
	if (items_flag & opt0) { cout << "My character has an item0 " << endl; }
	cout << endl;


/********* Topic 3 *********/
	// (2) ��Ʈ ����ũ(Bit masks)
	// RGB color table�� ���� Red, Blue, Green���� �и��Ͽ� ����.
	const unsigned int red_mask = 0xFF0000; // FF = ���� ū ��(1111 1111)
	cout << "Red mask:   " << std::bitset<32>(red_mask) << endl; // 2������ ���
	const unsigned int green_mask = 0x00FF00;
	cout << "Green mask: " << std::bitset<32>(green_mask) << endl;
	const unsigned int blue_mask = 0x0000FF;
	cout << "Blue mask:  " << std::bitset<32>(blue_mask) << endl;

	unsigned int pixel_color = 0xDAA520; // golden rod(#DAA520) in RGB color table(#RRGGBB), 16����
	cout << "Golden rod: " << std::bitset<32>(pixel_color) << endl;

	// shift�� ������ �̿��Ͽ� �ڸ����� ������� ��.
	// �̶�, unsigned int red, std::bitset<32>�� �����ϰ� ����Ͽ� Ȯ��.
	unsigned char red = (pixel_color & red_mask) >> 16;
	cout << "Red:    " << std::bitset<8>(red) << ", Red(decimal):    " << int(red) << endl; // 00100 000 ����, 10�����δ� 32(<=255) ���.
	unsigned char green = (pixel_color & green_mask) >> 8;
	cout << "Green:  " << std::bitset<8>(green) << ", Green(decimal):  " << int(green) << endl; // 00100 000 ����, 10�����δ� 32(<=255) ���.
	unsigned char blue = pixel_color & blue_mask;
	cout << "Blue:   " << std::bitset<8>(blue) << ", Blue(decimal)    " << int(blue) << endl; // 00100 000 ����, 10�����δ� 32(<=255) ���.


	return 0;
}