/*
11.9�� "���� ��� (Muliple Inheritance)"

- �ټ��� class�κ��� ����� �޴� ���.
- ���̾Ƹ�� ����� ���´� ������ �ʿ䰡 �ִ�; ���������� �ذ��� �� �ִ�.
  --> A�� ��ӹ��� B1�� B2�� �ְ�, C�� B1�� B2�� ��ӹ޴� ���
  :        --> B1 --> 
    A --> |          |--> C
           --> B2 -->
*/

#include <iostream>
using namespace std;

class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;

public:
	NetworkDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void networking() {}
};

class USBNetworkingDevice : public USBDevice, public NetworkDevice // ���� ����� ��� ���.
{
public:
	USBNetworkingDevice(long usb_id, long net_id) // �����ڸ� ���� �� ��ӹ޴� �ɹ����� ��� �ٷ�� �Ѵ�.
		: USBDevice(usb_id), NetworkDevice(net_id) 
	{}

	// ��쿡 ���� �ϳ��� IP�����ε� ������ ���
	//USBNetworkingDevice(long id) 
	//	: USBDevice(id), NetworkDevice(id)
	//{}
};


int main()
{
/**************** Topic 1 ****************/
	USBNetworkingDevice my_device(3.14, 6.022);

	my_device.plugAndPlay();
	my_device.networking();

	//my_device.getID(); // getID �Լ��� USBDevice�� NetworkDevice�� ��� �ֱ� ������ ���� �߻�.
	// --> �ذ� ���.
	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();

	return 0;
}
