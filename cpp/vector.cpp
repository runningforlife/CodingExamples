#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;

int main()
{
    vector<string> vstr;
    string word;
    while (cin >> word) {
	vstr.push_back(word);
        cout << word << std::endl;
    }

    cout << "the size of vstr is " << vstr.size() << std::endl;
    for (vector<string>::size_type idx = 0; idx != vstr.size(); ++idx) {
    	cout << vstr[idx] << std::endl;
    }

    for (vector<string>::const_iterator it = vstr.begin(); it != vstr.end(); 
          ++it) {
	cout << *it << std::endl;
    }

    #vector<string>::iterator mid = (vstr.begin() + vstr.end())/2;
    #cout << "the middle of vstr is " << *mid << std::endl;

    return 0;
}
