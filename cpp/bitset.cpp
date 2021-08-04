#include <bitset>
#include <iostream>
#include <string>

using std::string;
using std::bitset;
using std::cin;
using std::cout;
using std::endl;


int main()
{
    int value = 119;
    bitset<32> bs(value);

    string str("1001001111");
    bitset<32> bs1(str);
    cout << "the bitset of " << value << " is " << bs << endl;
    cout << "the bitset of " << str  << " is " << bs1 << endl;

    return 0; 
}
