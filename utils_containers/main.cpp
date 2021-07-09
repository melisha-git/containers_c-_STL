#include "pair.hpp"
#include "make_pair.hpp"
#include "less.hpp"
#include <iostream>

int main() {
	ft::pair<int, int> k = ft::make_pair<int, int>(3, 2);
	std::cout << k.first << " " << k.second;
	ft::less<int> p;
	std::cout << p(4, 12);
}