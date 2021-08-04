#include<iostream>
#include<tuple>
#include<string>

using namespace std;

int main(void)
{
	tuple<string, int, int> t;

	tuple<int, float, string> t1(34, 6.3, "nicola");

	cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

	auto t2 = make_tuple(22, 55.0, "nijina");

	get<1>(t1) = get<1>(t2);

	cout << "value after changed: " << endl;
	
	cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;
}
