/* use file stream to copy data from file1 to file2 */
#include<iostream>
#include<fstream>
#include<string>


int main(void) {
	std::string in_file;
	std::string out_file;
	char buf[256];

	std::cout << "Enter input file name:"; std::cin >> in_file;
	std::cout << "Enter output file name:"; std::cin >> out_file;

	std::ifstream ins(in_file.c_str(), std::ifstream::binary);
	std::ofstream outs(out_file.c_str(), std::ofstream::binary);

	while (ins.getline(buf, 256)) {
		//outs.write(buf, 256);
		//outs.write("\n", 1);
		outs << buf << '\n';
		std::cout << buf << std::endl;
	}

	outs.flush();
	ins.close();
	outs.close();
	std::cout << "write file done" << std::endl;

	return 0;
}
