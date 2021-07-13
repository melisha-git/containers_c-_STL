#include "map.class.hpp"
#include <iostream>
#include <map>

int main() {
	std::map<int, int> k;
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
	k[8] = 8;
	k[3] = 3;
	k[10] = 10;
	k[14] = 14;
	k[13] = 13;
	k[1] = 1;
	k[6] = 6;
	k[4] = 4;
	std::cout << k.equal_range(1).first->first << k.equal_range(1).second->first << std::endl;
	std::cout << p.equal_range(1).first->first << p.equal_range(1).second->first << std::endl;
//	ft::map<int, int>::iterator t = p.find(6);
//	p.erase(t);
//	ft::map<int, int> q(p.begin(), p.end());
//	q.insert(p.begin(), p.end());
//	p[7] = 7;
	p.print();
//	std::cout << std::endl << std::endl;
//	std::cout << std::endl << std::endl;
//	ft::map<int, int>::iterator i = p.end();
//	q.print();
//	std::cout << t->first << t->second << std::endl;
//	std::cout << i->first << i->second << std::endl;
//	while (1);
	return 0;
}
