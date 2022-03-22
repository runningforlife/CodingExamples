#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;

vector<string> getStrList() {
	vector<string> vs{"abc", "dbd", "baba"};

	return vs;
};

int main()
{
    vector<string> vstr;
    string word;
    /*while (cin >> word) {
	vstr.push_back(word);
        cout << word << std::endl;
    }*/

    cout << "the size of vstr is " << vstr.size() << std::endl;
    for (vector<string>::size_type idx = 0; idx != vstr.size(); ++idx) {
    	cout << vstr[idx] << std::endl;
    }

    for (vector<string>::const_iterator it = vstr.begin(); it != vstr.end(); 
          ++it) {
	cout << *it << std::endl;
    }

    //vector<string>::iterator mid = (vstr.begin() + vstr.end())/2;
    //cout << "the middle of vstr is " << *mid << std::endl;

	std::vector<string> vs = getStrList();
	vs.push_back("urikine");
	for (vector<string>::iterator it = vs.begin(); it != vs.end(); ++it) {
		cout << *it << std::endl;
	}

    return 0;
}
