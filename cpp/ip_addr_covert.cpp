#include <arpa/inet.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
	struct in_addr addr;

	if (argc != 2) {
		std::cerr << "wrong arguments" << std::endl;
		exit(-1);
	}

	if (inet_aton(argv[1], &addr) == 0) {
		std::cerr << "invalid address" << std::endl;
		exit(-1);
	}
	std::cout << "host byte order:0x" << std::setfill('0') << std::setw(8) << std::hex << addr.s_addr;
	std::cout << std::endl;
	std::cout << "network byte order:0x" << std::setfill('0') << std::setw(8) << std::hex << htonl(addr.s_addr);
	std::cout << std::endl;
}
