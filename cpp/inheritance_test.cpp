#include<iostream>
#include<string>

using std::string;
using std::cout;

class Tool {
public:

	Tool(string name): m_name(name) {
		cout << "tool " << m_name << " constructor" << std::endl;
	}

	Tool() {
		cout << "tool constructor" << std::endl;
	}

	~Tool() {
		cout << "tool destructor" << std::endl;
	}

	string getName() {
		return this->m_name;
	}

	virtual void hit() = 0;

	virtual void printToolName() {
		cout << "I am the tool base" << std::endl;
	}

private:
	string m_name;
};

class Hammer: public Tool {
public:
	Hammer(): Tool("hammer") {
		cout << "a hammer is constructed" << std::endl;
	}

	~Hammer() {
		cout << "a hammer is deconstructed" << std::endl;
	}

	void hit() override {
		cout << "hammer hit" << std::endl;
	}

	void printToolName() override {
		cout <<"this is a " << getName() << std::endl;
	}
};

int main(void) {
	Hammer hammer;

	hammer.printToolName();
	hammer.hit();
}
