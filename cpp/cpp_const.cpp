/* how to use const in C++ */
#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

class Person {
public:
	Person(string name, string prof, int age): mPhoneNo(99999) {
		this->mName = name;
		this->mProf = prof;
		this->mAge = age;
	}

	Person(): mName("Bob"), mProf("SE"), mAge(30), mPhoneNo(99999) {
		std::cout << "person constructor" << std::endl;
		//mPhoneNo = -1;
	}

	~Person() {
		std::cout << "person destructor" << std::endl;
	}
	
	string getName() const {
		//this->mProf = "HWE";
		return this->mName;
	}

	string getProfession() const {
		return this->mProf;
	}

	int getAge() const {
		return this->mAge;
	}

	void setAge(int age) {
		this->mAge = age;
	}

	void setPhoneNumber(int phoneNo) {
		//this->mPhoneNo = phoneNo;
	}

private:
	string mName;
	string mProf;
	int mAge;
	const int mPhoneNo;
};

class Abc {
public:
	void say_hi() {
		std::cout << "hello, world!!!" << std::endl;
		//std::cout << this->empty << std::endl;
	}

private:
	string empty = "empty";
};

constexpr int sum(const vector<int>& vi) { return 0;}; //just examples, donot make any sense
constexpr int square(int x) { return x * x;};

int main(void) {
	Person p;

	std::cout << "the profession of " << p.getName() << " is " << p.getProfession() << std::endl;

	Abc *ptr = nullptr;
	ptr->say_hi();

	const int im = 17;
	int var = 10;

	
	constexpr double m1 = 1.6 * square(im);
	//constexpr double m2 = 1.6 * square(var); // 不允许使用非const变量
	
	vector<int> vi = {4, 58, 8 , 9};
	const int si = sum(vi);
	constexpr int sii = sum(vi);	
}
