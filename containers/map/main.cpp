#include "map.class.hpp"
#include <iostream>
#include <map>

int main() {
	std::map<char, int>::iterator k;
	ft::map<int, int> p;
//	typedef std::iterator_traits<int*> traits;

	p[8] = 8;
	p[3] = 3;
	p[10] = 10;
	p[14] = 14;
	p[13] = 13;
	p[1] = 1;
	p[6] = 6;
	p[4] = 4;
	ft::map<int, int> q;
//	q.insert(p.begin(), p.end());
//	p[7] = 7;
	p.erase(p.begin(), p.end());
//	q.print();
//	std::cout << std::endl << std::endl;
	p.print();
	std::cout << std::endl << std::endl;
//	ft::map<int, int>::iterator t = p.begin();
//	ft::map<int, int>::iterator i = p.end();
//	std::cout << t->first << t->second << std::endl;
//	std::cout << i->first << i->second << std::endl;
	while (1);
	return 0;
}