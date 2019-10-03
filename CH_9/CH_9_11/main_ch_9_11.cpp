/*
9.11�� "���� ������ �����ε�, ���� ����(Deep copy) vs. ���� ����(Shallow copy)"

- ���� �Ҵ�� �޸𸮿� ���� ������ ������ ����ν� ������ �ִ� Ŭ������ ���,
  ���縦 �ϰų� ������ �� �� ���� ����� ���� ����Ŀ� ���� ���� ������ �����ε� �Ǵ� ���� ������ ������ ��ٷο�����.

- �ֱٿ��� std::string �� ���̺귯���� ������� ���� �� ������ ���Ͽ� ���������� ����� ���� ���� ������, �̷��� ������ �������� �����ؾ� �Ѵ�.
*/

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class MyString
{
// private
public: // �ּҸ� Ȯ���ϱ� ���Ͽ� public���� �����Ͽ���. --> ��� �������� private���� �����ϴ� ���� ĸ��ȭ�� ����.
	char *m_data = nullptr;
	int m_length = 0;

	std::string data; 

public:
	MyString(const char *source = "") // ���ڿ��� �޾Ƶ��δ�.
	{
		assert(source);	// ���ڿ��� ����ٸ� assert�� �ܾ�.

		m_length = std::strlen(source) + 1; // + 1: ���� �� �� null character�� �߰��ϱ� ����.
		m_data = new char[m_length];		// ���� ����ŭ m_data�� ���� �Ҵ�. 

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	~MyString()
	{
		delete[] m_data; // �Ҹ��ڿ��� �޸𸮸� ����� <-- �޸� ������ ���� ���� new�� delete�� ���̴�.
	}

	char * getSring() { return m_data; }
	int getLength() { return m_length; }
};

class MyString1
{
public: 
	char *m_data = nullptr;
	int m_length = 0;

public:
	MyString1(const char *source = "") 
	{
		assert(source);	

		m_length = std::strlen(source) + 1; 
		m_data = new char[m_length];		

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	MyString1(const MyString1 &source) // �ڱ� �ڽ��� parameter�� copy constructor.
	{
		cout << "Copy constructor" << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr) // (1) source�� �޸𸮸� ������ ���� ���,
		{
			m_data = new char[m_length]; // (2) �޸� �ּҸ� ���� �Ҵ�ް�,

			for (int i = 0; i < m_length; ++i) // �߰��� source�� ������ �ִ� ���� �����Ѵ�. --> Deep copy
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr; // ���� �������� m_data = 0;��� ǥ���Ѵ�.
	}
	
	MyString1& operator = (const MyString1 & source) // Assingment operator
	{
		// shallow copy
		/* this->m_data = source.m_data;
		   this->m_length = source.m_length; */ // �ڵ����� �̿� ���� ����������, ���� �Ҵ�� �޸𸮰� �����Ǿ� ���� ���� ��ó�� ���α׷����� �ϸ� �� �ȴ�. 

		cout << "Assingment operator" << endl;

		if (this == &source) // prevent self-assignment
			return *this;    // --> copy constructor������ �߻����� �ʴ� ����, ���� �����ڴ� �ڽ��� �ڽſ� ������ �� �ֱ� ������ �̸� ������� �Ѵ�.
	
		delete[] m_data; // constructor�� �ڽ��� ó�� �����Ǵ� ���̱� ������ ������ ���� �޸𸮸� ������ ���� ���ɼ��� ������, assignment operator�� ������ ������ ���� ���� �ֱ� ������ delete.

		// Deep copy
		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i) 
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}

	~MyString1()
	{
		delete[] m_data; 
	}

	char * getSring() { return m_data; }
	int getLength() { return m_length; }
};


int main()
{
/**************** Topic 1 ****************/
	// Shallow copy: �ּҰ��� �����Ѵ�.
	MyString hello("Hello"); // �����ڿ��� �޸𸮸� �޴´�.

	cout << (int*)hello.m_data << endl; // new�� ���� �Ҵ���� �޸��� �ּ� ��� --> char type�� ���ڷ� �������� int�� casting.
	cout << hello.getSring() << endl;

	{
		MyString copy = hello; // scope�ȿ� local variable�� �����Ͽ� copy --> ���� �����ڰ� �ƴ� default ���� �����ڰ� ȣ��ȴ� --> point�� ��� �ּҸ� ����.
		cout << (int*)copy.m_data << endl; 
		cout << copy.getSring() << endl;
		// new�� ���� �޸𸮸� �����Ͽ����Ƿ� ���� �ּ��̳� heap���� �޸𸮰� �� ������̴�.
	} // copy�� scope�� ����� ������� --> delete[]�� ���� �޸� ����.

	cout << hello.getSring() << endl; // �޸𸮰� ������ ���¿��� getSring�� �����ϴ� ����������������? ���� �߻�. 

	// ���: ���� �޸� �Ҵ��� ����ϴ� ��쿡�� ����� �����Ͱ� �����Ƿ� copy constructor�� assignment operator�� �����ε��� �� ���ǰ� �ʿ��ϴ�.


/**************** Topic 2 ****************/
	// Deep copy: �޸� �ּҸ� ���� �Ҵ�ް� �����Ѵ�.
	MyString1 hello1("Hello"); 
	cout << (int*)hello1.m_data << endl;
	cout << hello1.getSring() << endl;
	{
		MyString1 copy1 = hello1;
		cout << (int*)copy1.m_data << endl; // Shallow copy�� �ּҰ� �����ϳ� Deep copy�� �ٸ���.
		cout << copy1.getSring() << endl;	
	} 
	cout << hello1.getSring() << endl; 


/**************** Topic 3 ****************/
	// ���� ������ �����ε� ���� copy constructor�� ������ ���������� �������� �����Ѵ�.
	// --> Ư�� ȣ��Ǵ� ��찡 �ٸ���.

	// Copy constructor�� ȣ��Ǵ� ���.
	MyString1 str1 = hello1; // Assingment operator�� ���ӿ��� copy constructor�� ����ȴ�.
	MyString1 str2(hello1);  // ���� ���������� copy constructor�� ȣ����� �и��ϰ� ���̵��� ���α׷����ϸ� ����.

	// Assingment operator�� ȣ��Ǵ� ���.
	MyString1 str3; // ���⼭ �켱 �����ڰ� ȣ��Ǿ�����,
	str3 = hello1;  // ���Ը� �Ǵ� ��쿡 copy constructor�� ȣ��ȴ�.

	return 0;
}