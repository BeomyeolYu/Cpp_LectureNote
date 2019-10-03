/*
10.4�� "���� ����(Association)"

- Composition �� Aggregation Relationship�� ��� ������ Ȯ���� �ְ� �ǰ� �ٸ� ������ ��ǰ�� �ȴ�.
- Association Relationship�� �� �� �ְ� �� ���� �ְ� ��ǰ�� �� ���� �ִ� ���� ����.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Doctor; // forward declaration�� ���� ��� Patient�� Doctor ���ΰ� ������ ������ �ʿ���(=�����) Association Relationship��� �����غ� �� �ִ�.

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;

public:
	Patient(string name_in)
		: m_name(name_in)
	{}

	void addDoctor(Doctor * new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	void meetDoctor(); /*
	{
		for (auto & ele : m_doctors)
		{
			cout << "Meet doctor: " << ele->m_name << endl;
		}
	} */

	friend class Doctor;
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients;
	Doctor * doctor; // reflexive association: Doctor�� Doctor�� ������ �ϴ� ���.

public:
	Doctor(string name_in)
		: m_name(name_in)
	{}

	void addPatient(Patient * new_patient)
	{
		m_patients.push_back(new_patient);
	}

	void meetPatient()
	{
		for (auto & ele : m_patients)
		{
			cout << "Meet patient: " << ele->m_name << endl;
		}
	}

	friend class Patient;
};

// Association Relationship�� ��쿡�� �Ϻ� �Լ��� �ڷ� ���� �� ���� �ִ�. 
// --> forward declaration�� �����ϳ� class Doctor�� m_name�� �ִ��� �������� �� �� ����.
void Patient::meetDoctor()
{
	for (auto & ele : m_doctors)
	{
		cout << "Meet doctor: " << ele->m_name << endl;
	}
}

int main()
{
/**************** Topic 1 ****************/
	Patient *p1 = new Patient("Jack Jack");
	Patient *p2 = new Patient("Dash");
	Patient *p3 = new Patient("Violet");

	Doctor *d1 = new Doctor("Doctor K");
	Doctor *d2 = new Doctor("Doctor L");

	// ȯ�ڿ� �ǻ簡 ���� ��ϵȴ�.
	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	// patients meet doctors
	p1->meetDoctor();

	// doctors meet patients
	d1->meetPatient();

	// deletes
	delete p1, p2, p3;
	delete d1, d2;


/**************** Topic 2 ****************/
	// 'Usea-a'�� �ǹ�: ���ΰ� ���θ� ����ϴ� ����.

	// '�뵵 �ܿ� ����'�� �ǹ�: ��� ����� ������ �� ������ ��� ������ �ʿ��� ���� �ƴϴ�.
	//                        ���� ȯ�ڰ� ��� ������ Ư�� �ǻ縦 ���� �ʿ䰡 ���� (= �ʿ信 ���ؼ� ���谡 �����).

	// '�ٸ� Ŭ�������� ���� �� �ִ°�?'�� �ǹ�: Doctor ���� ����ġ��翡�Ե� ���� �� �ִ�.

	return 0;
}
