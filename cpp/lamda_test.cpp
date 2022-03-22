/* simple examples using lamda/function objects */
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std::placeholders;

class LargerThan {
private:
	int val;
	std::string delim;

public:
	LargerThan(int i, std::string d): val(i), delim(d) {}

	bool operator() (int v) {
		if (v > val) std::cout << v << delim;
	}
};

int main(void)
{
	auto func_add = [](int &a, int &b){return a + b;};
	
	int a = 3, b = 5;
	int c = func_add(a, b);

	std::cout << a << " + " << b << " is " << c << std::endl;

	std::vector<int> vi = {1, 5, 6, 24, 52, 24, 576, 89, 82};

	for_each(vi.begin(), vi.end(), [](int &a) { if (a > 10) std::cout << a << " ";});
	std::cout << std::endl;

	// using function objects
	for_each(vi.begin(), vi.end(), LargerThan(10, ","));
	std::cout <<  std::endl;

	// using bind adapters
	auto gt10 = std::bind(std::greater<int>(), _1, 10);
	for (auto it = vi.begin(); it != vi.end(); ++it) {
		if (gt10(*it)) {
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;

	// = default capture variables by value
	for_each(vi.begin(), vi.end(), [=](int &elem){ elem += *vi.begin();});
	for (auto it = vi.begin(); it != vi.end(); ++it) {
		std::cout << *it << std::endl;
	}

	for_each(vi.begin(), vi.end(), [&](int &elem) { elem += *vi.begin();});
	for (auto it = vi.begin(); it != vi.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
