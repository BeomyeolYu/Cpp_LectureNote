/*
8.6�� "�Ҹ���(destructor)"

- �������� �ݴ�Ǵ� ����.
- �����ڰ� ������ ���� ������ �ϱ⺸�ٴ� ��ü�� ������� �� ������ �Ǵ� �Լ��� �ǹ��ϵ�,
  �Ҹ��� ���� �ı��� �Ѵٴ� �ǹ̺��ٴ� ������ ������ ��� ����� ��(= ��ü�� �޸𸮸� ������ ��) ȣ���� �Ǵ� �Լ��� �ǹ��Ѵ�.
- �޸� ���� Ȯ��: Debug - Windows - Show Diagnostic Tools
*/

#include <iostream>
using namespace std;
class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in) // ������
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	~Simple() // �Ҹ���: parameter�� ����.
	{
		cout << "Destructor " << m_id << endl;
	}
};

class IntArray // array class
{
private:
	int *m_arr = nullptr; /* ���� �Ҵ� array�� �����Ͽ�����, �޸� ������ �����Ǵ� ��쿡�� vector�� ����ϸ� �ȴ�.
						     --> vector�� �Ҹ��ڿ��� ���ο� �޸𸮸� �ݳ��ϴ� ������ �̹� ������ �Ǿ��ִ�. */
	unsigned int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor " << endl;
	}

	~IntArray()
	{
		if (m_arr != nullptr) // ������ġ: nullptr�� delete�� ��쿡 ������ ����⵵ �ϹǷ� if ���� �ɾ�д�.
			delete[] m_arr;   /* �Ҹ����� �ֿ� �뵵: my_int_arr�� �۾� ����{}�� �����,
							     ������ �Ҹ��� ~IntArray�� ȣ���ؼ� delete�� �����Ͽ� �޸� ������ ���´�. */
	}
};


int main()
{
/**************** Topic 1 ****************/
	// Destructor�� Constructor�� �������� �������: �޸𸮸� �����ϱ� ���� �Ҹ��ڸ� ���� ����.
	Simple s1(0);
	Simple s2(1);
	

/**************** Topic 2 ****************/
	// ���� �Ҵ��� ��� Constructor�� ������ ������ �������: delete �������� �޸� ������ ��û�ϸ� �Ҹ��ڸ� ���� �����ϰ� �޸𸮸� ����.
	Simple *s3 = new Simple(0);
	Simple s4(1);
	delete s3;


/**************** Topic 3 ****************/
	// while ���ȿ��� array�� ������ ������ �� delete�� ������ �޸� ������ �����.
	while (true)
	{
		IntArray my_int_arr(10000);
		//delete[] my_int_arr.m_arr; 
		/* --> �޸� ������ ���� ���Ͽ� delete ���.
	       --> �׷��� delete�� .m_arr�� ������ �� ���� �Ӹ� �ƴ϶� ���α׷��Ӱ� �׻� delete ���� �ۼ��ϱ� ���ŷӴ�.
	       --> �Ҹ��� ���. */
	}
	

	return 0;
}