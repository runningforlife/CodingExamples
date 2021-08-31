#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>

//using namespace std;

void print_val(std::string str) {
	std::cout << ' ' << str;
}

std::string upper_string(std::string str) {
	std::string res;

	for (std::string::size_type i = 0; i < str.size(); ++i) {
		char ch = str.at(i);
		if (!std::isupper(ch)) {
			res.append(1, std::toupper(ch));
		}
	}

	return res;
}

int main(void) 
{
	std::list<std::string> strlist = {"china", "usa", "england", "france", "italy", "germany", "japan"};
	std::vector<std::string> countries;

	countries.resize(strlist.size());

	std::copy(strlist.begin(), strlist.end(), countries.begin());
	
	//print elements of vector
	std::for_each(countries.begin(), countries.end(), print_val);
	std::cout << std::endl;

	std::vector<std::string> upperNames(countries.size());
    //transform striing to upper case
	std::transform(countries.begin(), countries.end(), upperNames.begin(), upper_string);

	std::for_each(upperNames.begin(), upperNames.end(), print_val);
	std::cout << std::endl;
}
