#include <iostream>
#include "map.class.hpp"
#include <map>
#include <algorithm>

void testMap() {
	/*
	 * DEFAULT VECTOR TEST
	 */
	std::map<int, int> v1;
    v1.insert(std::pair<int, int>(8, 8));
    v1.insert(std::pair<int, int>(2, 2));
    v1.insert(std::pair<int, int>(3, 3));
    v1.insert(std::pair<int, int>(10, 10));
	std::cout << "\x1b[31mDEFAULT MAP TEST\n";
	std::cout << v1.size() << std::endl;
    std::cout << std::endl;
	/*
	 * MY VECTOR TEST
	 */
	std::cout << "\x1b[32mMY MAP TEST";
	std::cout << std::endl;

	ft::map<int, int> g1;
    g1.insert(ft::pair<int, int>(8, 8));
    g1.insert(ft::pair<int, int>(2, 2));
    g1.insert(ft::pair<int, int>(3, 3));
    g1.insert(ft::pair<int, int>(10, 10));
	std::cout << g1.size() << std::endl;
	std::cout << std::endl;
	/*
	* CLEAR
	*/
	std::cout << "\x1b[34mCLEAR TEST";
	std::cout << std::endl;
	v1.clear();
	if (v1.empty()) {
		std::cout << "\x1b[31mDefault map is clear\n";
	}
	std::cout << v1.size() << std::endl;
	g1.clear();
	if (g1.empty()) {
		std::cout << "\x1b[32mMy map is clear\n";
	}
	std::cout << g1.size() << std::endl;
}

void testMapFindErase() {
	/*
	 * DEFAULT VECTOR TEST
	*/
	std::map<int, int> v1;
    v1.insert(std::pair<int, int>(8, 8));
    v1.insert(std::pair<int, int>(2, 2));
    v1.insert(std::pair<int, int>(3, 3));
    v1.insert(std::pair<int, int>(10, 10));
	std::cout << "\x1b[31mDEFAULT MAP TEST\n";
	std::cout << v1.size() << std::endl;
	/*
	 * MY VECTOR TEST
	 */
	std::cout << "\x1b[32mMY MAP TEST";
	std::cout << std::endl;

	ft::map<int, int> g1;
    g1.insert(ft::pair<int, int>(8, 8));
    g1.insert(ft::pair<int, int>(2, 2));
    g1.insert(ft::pair<int, int>(3, 3));
    g1.insert(ft::pair<int, int>(10, 10));
	std::cout << g1.size() << std::endl;
	std::cout << std::endl;
	/*
	* FIND AND ERASE
	*/
	std::cout << "\x1b[32mMY MAP TEST\n";
	std::map<int, int>::iterator it;
	it = v1.find(10);
	ft::map<int, int>::iterator ite;
	ite = g1.find(10);
	v1.erase(it);
	g1.erase(ite);
	ite = g1.begin();
	for (; ite != g1.end(); ++ite) {
		std::cout << ite->first << ite->second;
	}
	std::cout << std::endl;
	ft::map<int, int>::reverse_iterator iter = g1.rbegin();
	for (; iter != g1.rend(); ++iter) {
		std::cout << iter->first << iter->second;
	}
	std::cout << std::endl;
	std::cout << g1.size() << std::endl;
	std::cout << "\x1b[31mDEFAULT MAP TEST\n";
	it = v1.begin();
	for (; it != v1.end(); ++it) {
		std::cout << it->first << it->second;
	}
	std::cout << std::endl;
	std::map<int, int>::reverse_iterator itr = v1.rbegin();
	for (; itr != v1.rend(); ++itr) {
		std::cout << itr->first << itr->second;
	}
	std::cout << std::endl;
	std::cout << v1.size() << std::endl;
}

template<typename T>
bool is_equals(T f) {
	if (f.second >= 4)
		return 1;
	return 0;
}

void testMapAlgorithm() {
	std::map<char, int> dv;
	ft::map<char, int> mv;
	dv['G'] = 1;
	dv['E'] = 2;
	dv['D'] = 3;
	dv['U'] = 4;
	dv['F'] = 5;
	dv['T'] = 6;
	dv['S'] = 7;
	std::cout << "\x1b[31mDEFAULT COUNT_IF MAP TEST\n";
	std::cout << std::count_if(dv.begin(), dv.end(), is_equals<std::pair<int, int> >) << std::endl;
	mv['G'] = 1;
	mv['E'] = 2;
	mv['D'] = 3;
	mv['U'] = 4;
	mv['F'] = 5;
	mv['T'] = 6;
	mv['S'] = 7;
	std::cout << "\x1b[32mMY COUNT_IF MAP TEST\n";
	std::cout << std::count_if(mv.begin(), mv.end(), is_equals<ft::pair<int, int> >) << std::endl;
	std::cout << "\x1b[31mDEFAULT FIND MAP TEST\n";
	std::cout << dv.find('A')->first << dv.find('A')->second << std::endl;
	std::cout << "\x1b[32mMY FIND MAP TEST\n";
	std::cout << mv.find('A')->first << mv.find('A')->second << std::endl;
}