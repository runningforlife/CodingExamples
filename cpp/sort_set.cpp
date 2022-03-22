#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	// get strings from std input
	set<string> coll((istream_iterator<string>(cin)), 
				     istream_iterator<string>());

	copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
}
