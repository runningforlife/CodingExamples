#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

int main(void)
{
	std::vector<std::string> str_list = {"wlan0", "eth1"};
	str_list.push_back("eth0");
	str_list.push_back("dummy0");
	str_list.push_back("usb0");
	str_list.push_back("usb1");

	std::sort(str_list.begin(), str_list.end());

	/*for (std::vector<std::string>::iterator *it = str_list.begin(); it != str_list.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;*/
	for (const auto &str : str_list) {
		std::cout << str << ' ';
	}
	std::cout << std::endl;

	std::sort(str_list.begin(), str_list.end(),
		[](std::string &s1, std::string &s2) { return s1.begin() > s2.begin(); });

	/*for (std::vector<std::string>::iterator *it = str_list.begin(); it != str_list.end(); ++it) {
		std::cout << *it << ' ';
	}*/
	for (const std::string &str : str_list) {
		std::cout << str << ' ';
	}
	std::cout << std::endl;
}
