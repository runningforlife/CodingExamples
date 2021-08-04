#include<string>
#include<iostream>

using std::string;

int main() {

    string hollywood("once upon at HollyWood");
    string oscar = "oscar award";

    std::cout << hollywood << "," << oscar << std::endl;

    string str1("sunny");
    string str2("SUNNY");

    if (str1 == str2) {
		std:: cout << str1 << " is equal to " << str2 << std::endl;
    } else {
		std:: cout << str1 << " is not  equal to " << str2 << std::endl;
    }

	char *strp1 = const_cast<char *>(str1.c_str());
	
	string str3 = str1;
	char *strp2 = const_cast<char *>(str3.c_str());

	std::cout << "strp1 addr: " << &strp1 << std::endl;
	std::cout << "strp2 addr: " << &strp2 << std::endl;

	str3[2] = 'r';
	std::cout << "str3 value: " << str3 << std::endl;
	std::cout << "strp1 addr: " << &strp1 << std::endl;
	std::cout << "strp2 addr: " << &strp2  << std::endl;
}
