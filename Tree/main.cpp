#include "tree.class.hpp"
#include <iostream>
#include <utility>
#include <map>

void test() {
	std::map<char,int> mymap;
    tree<char, int> k;
    tree<char, int> k2;
	mymap['a'] = 3;
	mymap['b'] = 3;
	mymap['A'] = 5;
	mymap['B'] = 5;
	mymap.erase('A');
	std::cout << mymap['a'];
	std::cout << mymap['b'];
	std::cout << mymap['B'];
	std::cout << mymap['A'];
	std::cout << std::endl << std::endl;
	k['a'] = 3;
	k['b'] = 3;
	k['A'] = 5;
	k['B'] = 5;
	std::cout << k.erase('A');
//    tree<char, int> k3(k);
//	k2 = k;
	k.print();
//	std::cout << std::endl << std::endl;
//	k2.print();
//	std::cout << std::endl << std::endl;
//	k3.print();
//	std::cout << std::endl << std::endl;
//	std::cout << "k.size() = " << k.size() << std::endl;
//	std::cout << "k2.size() = " << k2.size() << std::endl;
//	std::cout << "k3.size() = " << k3.size() << std::endl;
    return ;
}

int main() {
    test();
//    while (1);
    return 0;
}
