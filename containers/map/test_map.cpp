#include <iostream>
#include "map.class.hpp"
#include <map>

void testMap() {
	std::map<int, int> v1;
    v1[1] = 8;
    v1[2] = 2;
    v1[3] = 3;
    v1[10] = 10;
	std::cout << "\x1b[31mDEFAULT VECTOR TEST\n";
	std::cout << v1.size() << std::endl;
    std::cout << std::endl;
	/*
	 * MY VECTOR TEST
	 */
	std::cout << "\x1b[32mMY VECTOR TEST";
	std::cout << std::endl;

	ft::map<int, int> g1;
    g1[1] = 8;
    g1[2] = 2;
    g1[3] = 3;
    g1[10] = 10;
	std::cout << g1.size() << std::endl;
	std::cout << std::endl;
	/*
	 * CLEAR
	 */
	std::cout << "\x1b[34mCLEAR TEST";
	std::cout << std::endl;
	v1.clear();
	if (v1.empty()) {
		std::cout << "\x1b[31mDefault vector is clear\n";
	}
	std::cout << v1.size() << std::endl;
	g1.clear();
	if (g1.empty()) {
		std::cout << "\x1b[32mMy vector is clear\n";
	}
	std::cout << g1.size() << std::endl;
}