/* an example showing how to use stream iterators */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	//outstream with delim \n
	ostream_iterator<int> iWriter(cout, "\n");
	*iWriter = 40; ++iWriter;
	*iWriter = 89; ++iWriter;
	*iWriter = -8; ++iWriter;

	vector<int> coli = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	copy(coli.begin(), coli.end(), ostream_iterator<int>(cout));
	cout << endl;

	copy(coli.begin(), coli.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	//input stream
	istream_iterator<int> iReader(cin);

	istream_iterator<int> iReaderEof;

	while (iReader != iReaderEof) {
		cout << "get value: " << *iReader << endl;
		++iReader;
	}
}
