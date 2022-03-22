#include<string>
#include<regex>
#include<iostream>
#include<string.h>

int main(void)
{
	std::regex reg("[0-9]-1-1/1.1");

	if (std::regex_search("adga(3-1-1/1.1adb", reg)) {
		std::cout << "reg match" << std::endl;
	}

	char buf[] = "zip_log_done";
	char buf1[] = "zip_log_done:xxxxx";

	if (!strncmp(buf, buf1, 1024)) {
		std::cout << "buf is not equal to buf1" << std::endl;
	} else {
		std::cout << "buf is equal to buf1" << std::endl;
	}
}
