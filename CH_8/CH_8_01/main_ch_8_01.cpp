/*
8.1강 "객체지향 프로그래밍(Object Oriented Programming)과 클래스(Class)"

- Object(객체): 변수(데이터) 들과 그와 관련된 메서드(함수)들이 모여서 이룬 하나의 꾸러미이다.
- JAVA는 객체 지향부터 시작하는 언어이다.
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

void print(const Friend &fr) // 함수의 이름이 같아도 parameter가 다르면 overloading 되므로 오류가 없다.
{
	cout << fr.name << " " << fr.address << " " << fr.age << " " << fr.height << " "
		<< fr.weight << endl;
}

// print func.도 Friend_라는 struct의 member가 되었으므로 동일한 struct의 member들을 직접적으로 접근할 수 있다.
struct Friend_ // 데이터와 기능이 묶여 있는 것을 object라고 부른다. 
{
	string name;
	string address;
	int	   age;
	double height;
	double weight;

	void print() // 위의 const Friend &fr와 fr.를 통한 간접적인 접근이 불필요하다.
	{
		cout << name << " " << address << " " << age << " " << height << " "
			<< weight << endl;
	}
	// --> struct에도 func.을 넣을 수는 있으나 더 많은 객체 지향 프로그래밍 기법들을 사용할 수 있게 해주는 것이 class이다.
};
 
// 일반적으로 strct는 데이터를 묶을 때, class는 기능을 묶을 때 사용한다.
// strct의 대표적인 차이: access specifier의 유무.
class Friend_c
{
public: // access specifier(접근 지정자): pubuic, private, protected 3 종류가 있다.
	string m_name;   // 교과서 스타일: member라는 의미의 m_을 관례적으로 붙인다.
	string address_; // 구글 스타일
	int	   _age;     // 오픈소스 스타일: _가 앞에 있어 member 찾기 쉽다.
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
	string name; // <-- 하나하나를 member variable이라고 부른다.
	string address;
	int	   age;
	double height;
	double weight;
	// ...

	// 친구가 한 명만 있는 경우
	print(name, address, age, height, weight);
	// --> 더 많은 친구들에 대한 데이터를 저장할 때는 array나 동적 할당 배열 등을 써야 한다.


/**************** Topic 2 ****************/
	// (1) vector를 사용하여 친구 목록 정리.
	vector<string> name_vec;
	vector<string> addr_vec;
	vector<int>	   age_vec;
	vector<double> height_vec;
	vector<double> weight_vec;

	// 친구가 한 명만 있는 경우
	print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);
	// --> 친구가 많을 경우 매번 index를 지정해주기 번거롭고 코드가 길어진다.


/**************** Topic 3 ****************/
	// (2) Struct 사용.
	Friend JJ;

	// copy initialization
	JJ.name = "Jack Jack"; // .는 member selection operator
	JJ.age = 2;
	JJ.address = "Uptown";

	// 또는 uniform initialization <-- 순서를 맞춰주지 않으면 오류 발생.
	Friend jj{ "Jack Jack", "Uptown", 2, 30, 10 };

	print(jj.name, jj.address, jj.age, jj.height, jj.weight);
	// --> Struct를 이용해도 동일한 친구가 추가되면 print(so.name, so.address, ...) 해야 한다.


/**************** Topic 4 ****************/
	// (3) print func.의 parameter를 하나하나 받는 것이 아니라 하나의 struct로 받는 방법.
	print(jj);
	// --> Topic 3에 비해서 깔끔하지만 print func.의 fr.이 반복된다.


/**************** Topic 5 ****************/
	// (4) print func.을 struct로 만든다.
	Friend_ jj_{ "Jack Jack", "Uptown", 2, 30, 10 };
	jj_.print();


/**************** Topic 6 ****************/
	// Friend_c를 class로 정의하는 것만으로는 작업 가능한 메모리를 갖지 않는다.
	// jj_c를 선언해줘야 메모리가 할당된다. --> instantiation
	Friend_c jj_c{ "Jack Jack", "Uptown", 2, 30, 10 }; // class의 instance(인스턴스)라고 부른다.
	
	jj_c.print();
	cout << &jj_c << endl; // 프로그래밍에서 실존의 여부는 메모리 주소가 있느냐 없느냐이다.


/**************** Topic 7 ****************/
	// 친구가 100명일 경우.
	vector<Friend_c> my_friends;
	my_friends.resize(100);

	for (auto &element : my_friends)
		element.print();

	return 0;
}