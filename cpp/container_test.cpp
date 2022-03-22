#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
#include<set>

using namespace std;

typedef std::map<string, string> mapType;
typedef std::multimap<string, string> multiMapType;
typedef std::unordered_map<string, string> unorderMapType;

int main(void) {

	mapType map1;
	multiMapType map2;
	unorderMapType map3;

	map1["test"] = "auto";
	map1["test"] = "test";
	map1["mtest"] = "manual";
	map1["itest"] = "integration";

	map2.insert(std::pair<string, string>("mtest", "manual"));
	map2.insert(std::pair<string, string>("atest", "auto"));
	map2.insert(std::pair<string, string>("utest", "unit"));
	map2.insert(std::pair<string, string>("atest", "auto1"));

	map3["utest"] = "unit";
	map3["atest"] = "auto";
	map3["itest"] = "integration";
	map3["atest"] = "auto1";
	
	for (const auto &elem : map1) {
		cout << elem.first << ":" << elem.second << endl;
	}

	for (const auto &elem : map2) {
		cout << elem.first << ":" << elem.second << endl;
	}

	for (const auto &elem : map3) {
		cout << elem.first << ":" << elem.second << endl;
	}

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
