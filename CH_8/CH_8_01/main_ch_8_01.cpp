/*
8.1�� "��ü���� ���α׷���(Object Oriented Programming)�� Ŭ����(Class)"

- Object(��ü): ����(������) ��� �׿� ���õ� �޼���(�Լ�)���� �𿩼� �̷� �ϳ��� �ٷ���.
  [����] JAVA�� ��ü ������� �����ϴ� ����̴�.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Features of friends: name, address, age, height, weight, ...
void print(const string &name, const string	&address, const int &age,
	const double &height, const double &weight)
{
	cout << name << " " << address << " " << age << " " << height << " "
		<< weight << endl;
}

struct Friend
{
	string name;
	string address;
	int	   age;
	double height;
	double weight;
};

void print(const Friend &fr) // �Լ��� �̸��� ���Ƶ� parameter�� �ٸ��� overloading �ǹǷ� ������ ����.
{
	cout << fr.name << " " << fr.address << " " << fr.age << " " << fr.height << " "
		<< fr.weight << endl;
}

// print func.�� Friend_��� struct�� member�� �Ǿ����Ƿ� ������ struct�� member���� ���������� ������ �� �ִ�.
struct Friend_ // �����Ϳ� ����� ���� �ִ� ���� object��� �θ���. 
{
	string name;
	string address;
	int	   age;
	double height;
	double weight;

	void print() // ���� const Friend &fr�� fr.�� ���� �������� ������ ���ʿ��ϴ�.
	{
		cout << name << " " << address << " " << age << " " << height << " "
			<< weight << endl;
	}
	// --> struct���� func.�� ���� ���� ������ �� ���� ��ü ���� ���α׷��� ������� ����� �� �ְ� ���ִ� ���� class�̴�.
};

// �Ϲ������� strct�� �����͸� ���� ��, class�� ����� ���� �� ����Ѵ�.
// strct�� ��ǥ���� ����: access specifier�� ����.
class Friend_c
{
public: // access specifier(���� ������): pubuic, private, protected 3 ������ �ִ�.
	string m_name;   // ������ ��Ÿ��: member��� �ǹ��� m_�� ���������� ���δ�.
	string address_; // ���� ��Ÿ��
	int	   _age;     // ���¼ҽ� ��Ÿ��: _�� �տ� �־� member ã�� ����.
	double height;
	double weight;

	void print()
	{
		cout << m_name << " " << address_ << " " << _age << " " << height << " "
			<< weight << endl;
	}
};

int main()
{
/**************** Topic 1 ****************/
	string name = "Jack Jack"; // <-- �ϳ��ϳ��� member variable�̶�� �θ���.
	string address = "Uptown";
	int	   age = 25;
	double height = 180;
	double weight = 80;
	// ...

	// ģ���� �� �� �ִ� ���.
	print(name, address, age, height, weight);
	// --> �� ���� ģ���鿡 ���� �����͸� ������ ���� array�� ���� �Ҵ� �迭 ���� ��� �Ѵ�.

/**************** Topic 2 ****************/
	// (1) vector�� ����Ͽ� ģ�� ��� ����.
	vector<string> name_vec{ "Jack Jack" };
	vector<string> addr_vec{ "Uptown" };
	vector<int>	   age_vec{ 25 };
	vector<double> height_vec{ 180 };
	vector<double> weight_vec{ 80 };

	// ģ���� �� �� �ִ� ���
	print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);
	// --> ģ���� ���� ��� �Ź� index�� �������ֱ� ���ŷӰ� �ڵ尡 �������.

/**************** Topic 3 ****************/
	// (2) Struct ���.
	Friend JJ;

	// copy initialization
	JJ.name = "Jack Jack"; // .�� member selection operator
	JJ.age = 20;
	JJ.address = "Uptown";

	// �Ǵ� uniform initialization <-- ������ �������� ������ ���� �߻�.
	Friend jj{ "Jack Jack", "Uptown", 2, 30, 10 };

	print(jj.name, jj.address, jj.age, jj.height, jj.weight);
	// --> Struct�� �̿��ص� ������ ģ���� �߰��Ǹ� print(so.name, so.address, ...)�� �ؾ� �Ѵ�.

/**************** Topic 4 ****************/
	// (3) print func.�� parameter�� �ϳ��ϳ� �޴� ���� �ƴ϶� �ϳ��� struct�� �޴� ���.
	print(jj);
	// --> Topic 3�� ���ؼ� ��������� print func.�� fr.�� �ݺ��ȴ�.

/**************** Topic 5 ****************/
	// (4) print func.�� struct�� �����.
	Friend_ jj_{ "Jack Jack", "Uptown", 2, 30, 10 };
	jj_.print();

/**************** Topic 6 ****************/
	// Friend_c�� class�� �����ϴ� �͸����δ� �۾� ������ �޸𸮸� ���� �ʴ´�.
	// jj_c�� ��������� �޸𸮰� �Ҵ�ȴ�. --> instantiation
	Friend_c jj_c{ "Jack Jack", "Uptown", 2, 30, 10 }; // class�� instance(�ν��Ͻ�)��� �θ���.

	jj_c.print();
	cout << &jj_c << endl; // ���α׷��ֿ��� ������ ���δ� �޸� �ּҰ� �ִ��� �������̴�.

/**************** Topic 7 ****************/
	// ģ���� 100���� ���.
	vector<Friend_c> my_friends;
	my_friends.resize(100);

	for (auto &element : my_friends)
		element.print();

	return 0;
}