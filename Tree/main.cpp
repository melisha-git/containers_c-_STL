#include "tree.class.hpp"
#include <iostream>
#include <utility>
#include <map>

void test() {
	std::map<char,int> mymap;
    tree<char, int> k;
    tree<char, int> k2;
    k['a'] = 3;
	k['b'] = 3;
	k['c'] = 3;
	k['d'] = 3;

	std::cout << k.count('a');
	k2['A'] = 5;
	k2['B'] = 5;
	k2['C'] = 5;
	k2['D'] = 5;
}

int main() {
    test();
//    while (1);
    return 0;
}
