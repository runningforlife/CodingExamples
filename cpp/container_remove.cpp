#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>

int main(void) {
	std::string str1 = "text with some    spaces ";
	str1.erase(std::remove(str1.begin(), str1.end(), ' '), str1.end());

	std::cout << str1 << std::endl;

	std::string str2 = "Text\n with \t some\t whitespaces\n\n";
	str2.erase(std::remove_if(str2.begin(), str2.end(), 
				[](unsigned char x) {return std::isspace(x);}), str2.end());

	std::cout << str2 << std::endl;
}
