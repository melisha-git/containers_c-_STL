#include "tree.class.hpp"
#include <iostream>
#include <utility>
#include <map>

void test() {
	ft::tree<char, int> mytree;
	std::map<char,int> mymap;
	mytree['B'] = 100;
	mytree['c'] = 300;
	mytree['b'] = 100;
	mytree['A'] = 400;
	mytree['a'] = 200;
	mytree['Z'] = 600;

	mymap['B'] = 100;
	mymap['c'] = 300;
	mymap['b'] = 100;
	mymap['A'] = 400;
	mymap['a'] = 200;
	mymap['Z'] = 600;

	ft::tree<char,int>::iterator ite = mytree.begin();
	mytree.print();
	std::cout << std::endl << std::endl;
	std::cout << ite->first << "=" << ite->second << std::endl;
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

int main() {
    test();
//    while (1);
    return 0;
}
