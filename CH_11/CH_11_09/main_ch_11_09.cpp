/*
11.9강 "다중 상속 (Muliple Inheritance)"

- 다수의 class로부터 상속을 받는 방법.
- 다이아몬드 상속의 형태는 주의할 필요가 있다; 다형성으로 해결할 수 있다.
  --> A를 상속받은 B1과 B2가 있고, C가 B1과 B2를 상속받는 경우
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

class USBNetworkingDevice : public USBDevice, public NetworkDevice // 다중 상속을 방법 방법.
{
public:
	USBNetworkingDevice(long usb_id, long net_id) // 생성자를 만들 때 상속받는 맴버들을 모두 다뤄야 한다.
		: USBDevice(usb_id), NetworkDevice(net_id) 
	{}

	// 경우에 따라서 하나의 IP만으로도 가능한 경우
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

	//my_device.getID(); // getID 함수가 USBDevice와 NetworkDevice에 모두 있기 때문에 에러 발생.
	// --> 해결 방법.
	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();

	return 0;
}
