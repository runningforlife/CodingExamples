/* simple template usage examples */
#include <iostream>
#include <string>

template <typename T>
int compare(const T &v1, const T &v2) {

    if (v1 > v2) return 1;
    if (v1 < v2) return -1;

    return 0;
}


int main(void) {

    std::cout << compare(1, 0) << std::endl;

    std::string str("adbcda");
    std::string str1("dbabab");
    std::cout << compare(str, str1) << std::endl;

    return 0;
}
