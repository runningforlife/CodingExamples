#include<iostream>
#include<string>
#include<unordered_map>
#include<list>
using namespace std;

int main(void) {
	std::unordered_map<string, double> prod_price {{"apple", 5.6}, 
											{"orange", 3.8}};

	for (pair<const string, double>&elem : prod_price) {
		elem.second *= elem.second;
	}

	for (const auto& elem: prod_price) {
		cout << elem.first << ":" << elem.second << endl;
	}

	list<string> words = {"we", "peopele", "can", "create", "history", "for", "our",  "own"};
	for (auto pos = words.cbegin(); pos != words.cend(); ++pos) {
		cout << *pos << " ";
	}
	cout << endl;
}
