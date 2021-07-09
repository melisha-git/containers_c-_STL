#include "map.class.hpp"
#include <iostream>
#include <map>

int main() {
	std::map<char, int> k;
	ft::map<char, int> p;

	p['A'] = 1;
	p['B'] = 2;
	p['C'] = 3;
	p['D'] = 4;
	ft::map<char, int> q(p);
	p.print();
	std::cout << std::endl << std::endl;
	q['a'] = 5;
	q['b'] = 6;
	q['c'] = 7;
	q['d'] = 8;
	q.print();

	std::cout << std::endl << std::endl;
	p.swap(q);
	p.print();
	std::cout << std::endl << std::endl;
	q.erase('B');
	q.print();
	std::cout << std::endl << std::endl;
//	while (1);
	return 0;
}