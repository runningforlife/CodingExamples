#include<iostream>
#include<string>
#include<unordered_map>
#include<list>
#include<set>

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

	set<string> c1 = {"change", "your", "mind", "do", "hard", "thing"};
	//set<string, greater<string> > c2(c1);	
	set<string, greater<string> > c2(c1.begin(), c1.end());

	for (set<string>::iterator it = c1.begin(); it != c1.end(); ++it) {
		cout << ' ' << *it;
	}
	cout << endl;

	for (set<string>::iterator it = c2.begin(); it != c2.end(); ++it) {
		cout << ' ' << *it;
	}
	cout << endl;
}
