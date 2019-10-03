/*
10.4강 "제휴 관계(Association)"

- Composition 및 Aggregation Relationship은 어느 한쪽이 확실히 주가 되고 다른 한쪽이 부품이 된다.
- Association Relationship은 둘 다 주가 될 수도 있고 부품이 될 수도 있는 제휴 관계.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Doctor; // forward declaration이 보일 경우 Patient와 Doctor 서로가 서로의 정보가 필요한(=대등한) Association Relationship라고 짐작해볼 수 있다.

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
	Doctor * doctor; // reflexive association: Doctor도 Doctor를 만나야 하는 경우.

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

// Association Relationship일 경우에는 일부 함수를 뒤로 빼야 할 수도 있다. 
// --> forward declaration이 존재하나 class Doctor에 m_name이 있는지 없는지는 알 수 없다.
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

	// 환자와 의사가 서로 등록된다.
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
	// 'Usea-a'의 의미: 서로가 서로를 사용하는 입장.

	// '용도 외엔 무관'의 의미: 모든 기능을 수행할 때 서로의 모든 정보가 필요한 것이 아니다.
	//                        또한 환자가 모두 나으면 특정 의사를 만날 필요가 없다 (= 필요에 의해서 관계가 생긴다).

	// '다른 클래스에도 속할 수 있는가?'의 의미: Doctor 말고도 물리치료사에게도 속할 수 있다.

	return 0;
}
