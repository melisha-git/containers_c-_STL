#include "vector.class.hpp"
#include <vector>
#include <cstdlib>

void defaultSwap() {
	std::vector<int> v1(12,4);
	std::vector<int> v2(10, 7);
	std::cout << "\x1b[34m==----SWAP TEST----=" << std::endl;
	for (int i = 0; i < 3; i++) {
		v1.push_back(8);
	}
	std::cout << "\x1b[31m==----Default vector before v1----==" << std::endl;
	std::cout << "size: " << v1.size() << "\t" << "capacity: " << v1.capacity() << std::endl;
	std::cout << "front: " << v1.front() << "\t" << "back: " << v1.back() << std::endl;
	std::cout << "\x1b[31m==----Default vector before v2----==" << std::endl;
	std::cout << "size: " << v2.size() << "\t" << "capacity: " << v2.capacity() << std::endl;
	std::cout << "front: " << v2.front() << "\t" << "back: " << v2.back() << std::endl;
	v1.swap(v2);
	std::cout << "==----Default vector after v1----==" << std::endl;
	std::cout << "size: " << v1.size() << "\t" << "capacity: " << v1.capacity() << std::endl;
	std::cout << "front: " << v1.front() << "\t" << "back: " << v1.back() << std::endl;
	std::cout << "==----Default vector after v2----==" << std::endl;
	std::cout << "size: " << v2.size() << "\t" << "capacity: " << v2.capacity() << std::endl;
	std::cout << "front: " << v2.front() << "\t" << "back: " << v2.back() << std::endl;
	std::cout << std::endl;
}

void testSwap() {
	ft::vector<int> g1(12, 4);
	ft::vector<int> g2(10, 7);
	for (int i = 0; i < 3; i++) {
		g1.push_back(8);
	}
	std::cout << "\x1b[32m==----My vector before g1----==" << std::endl;
	std::cout << "size: " << g1.size() << "\t" << "capacity: " << g1.capacity() << std::endl;
	std::cout << "front: " << g1.front() << "\t" << "back: " << g1.back() << std::endl;
	std::cout << "==----My vector before g2----==" << std::endl;
	std::cout << "size: " << g2.size() << "\t" << "capacity: " << g2.capacity() << std::endl;
	std::cout << "front: " << g2.front() << "\t" << "back: " << g2.back() << std::endl;
	g1.swap(g2);
	std::cout << "==----My vector after g1----==" << std::endl;
	std::cout << "size: " << g1.size() << "\t" << "capacity: " << g1.capacity() << std::endl;
	std::cout << "front: " << g1.front() << "\t" << "back: " << g1.back() << std::endl;
	std::cout << "==----My vector after g2----==" << std::endl;
	std::cout << "size: " << g2.size() << "\t" << "capacity: " << g2.capacity() << std::endl;
	std::cout << "front: " << g2.front() << "\t" << "back: " << g2.back() << std::endl;
	std::cout << std::endl;
}

void defaultTestModifies() {
	std::vector<int> v1(12,4);
	std::cout << "\x1b[34m==----ASSIGN TEST----=" << std::endl;
	v1.assign(14, 2);
	std::cout << "\x1b[31m==----Default vector----==" << std::endl;
	std::cout << "size: " << v1.size() << "\t" << "capacity: " << v1.capacity() << std::endl;
	std::cout << "front: " << v1.front() << "\t" << "back: " << v1.back() << std::endl;
	std::cout << std::endl;
}

void testModifies() {
	ft::vector<int> g1(12, 4);
	std::cout << "\x1b[32m==----My vector----==" << std::endl;
	g1.assign(14, 2);
	std::cout << "size: " << g1.size() << "\t" << "capacity: " << g1.capacity() << std::endl;
	std::cout << "front: " << g1.front() << "\t" << "back: " << g1.back() << std::endl;
	std::cout << std::endl;
}

void defaultTestVector() {
	std::cout << "\x1b[34m==----TEST VECTOR----=" << std::endl;
	std::vector<int> v1(12,4);
	std::cout << "\x1b[31mDEFAULT VECTOR TEST\n";
	try {
		v1.reserve(100);
	}
	catch (std::length_error &le) {
		std::cout << le.what() << std::endl;
	}
	v1.resize(14);
	std::cout << v1.size() << "\t" << v1.capacity() << std::endl;
	for (size_t i = 0; i < v1.size(); i++) {
		std::cout << v1[i];
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void testVector() {
	std::cout << "\x1b[32mMY VECTOR TEST";
	std::cout << std::endl;

	ft::vector<int> g1(12,4);
	try {
		g1.reserve(100);
	}
	catch (std::length_error &le) {
		std::cout << le.what() << std::endl;
	}
	g1.resize(14);
	std::cout << g1.size() << "\t" << g1.capacity() << std::endl;
	for (size_t i = 0; i < g1.size(); i++) {
		std::cout << g1[i];
	}
	std::cout << std::endl;
	std::cout << std::endl;
}


void defaultClearTest() {
	std::vector<int> v1(12,4);
	v1.resize(14);
	std::cout << "\x1b[34mCLEAR TEST";
	std::cout << std::endl;
	v1.clear();
	if (v1.empty()) {
		std::cout << "\x1b[31mDefault vector is clear\n";
	}
	std::cout << v1.size() << "\t" << v1.capacity() << std::endl;
	std::cout << std::endl;
}

void clearTest() {
	ft::vector<int> g1(12,4);
	g1.resize(14);
	g1.clear();
	if (g1.empty()) {
		std::cout << "\x1b[32mMy vector is clear\n";
	}
	std::cout << g1.size() << "\t" << g1.capacity() << std::endl;
	std::cout << std::endl;
}

void defaultTestPushBack() {
	std::cout << "\x1b[34mPUSH BACK TEST\n";
	std::vector<int> v1;
	std::cout << "\x1b[31mDEFAULT VECTOR PUSH BACK TEST\n";
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << v1[i] << std::endl;
	}
	std::cout << v1.size() << "\t" << v1.capacity() << std::endl;
}

void testPushBack() {
	std::cout << std::endl;
	std::cout << "\x1b[32mMY VECTOR PUSH BACK TEST\n";
	ft::vector<int> g1;
	for (int i = 0; i < 10; i++) {
		g1.push_back(i);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << g1[i] << std::endl;
	}
	std::cout << g1.size() << "\t" << g1.capacity() << std::endl;
	std::cout << std::endl;
}

void defaultTestElementAccess() {
	std::vector<int> v1;
	std::cout << "\x1b[34m==----AT TEST----==" << std::endl;
	std::cout << "\x1b[31m==----Default vector----==" << std::endl;
	try {
		std::cout << v1.at(0) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void testElementAccess() {
	ft::vector<int> g1;
	std::cout << "\x1b[32m==----My vector----==" << std::endl;
	try {
		std::cout << g1.at(0) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void defaultTestFrontAndBack() {
	std::vector<const int> v1(12,4);
	std::vector<const int> v2(v1);
	std::cout << "\x1b[34m==----FRONT AND BACK TEST----=" << std::endl;
	std::cout << "\x1b[31m==----Default vector----==" << std::endl;
	std::cout << v1.front() << "\t" << v1.back() << std::endl;
	std::cout << std::endl;
}

void testFrontAndBack() {
	ft::vector<const int> g1(12, 4);
	ft::vector<const int> g2(g1);
	std::cout << "\x1b[32m==----My vector----==" << std::endl;
	std::cout << g1.front() << "\t" << g1.back() << std::endl;
	std::cout << std::endl;
}

void defaultTestIteratorVector() {
	std::cout << "\x1b[34m==----TEST ITERATOR VECTOR----==\n";
	std::cout << "\x1b[31mDefault vector\n";
	std::vector<int> v1;
	for (int i = 0; i < 12; i++) {
		v1.push_back(i + 1);
	}
	std::vector<int>::iterator it = v1.begin();
	std::cout << it[0] << std::endl;
	it = it + 4;
	if (it > v1.begin())
		std::cout << "BIG\n";
	std::cout << it[0] << std::endl;
	it -= 4;
	if (it <= v1.begin())
		std::cout << "SMALL\n";
	std::cout << it[0] << std::endl;
	std::cout << std::endl;
}

void testIteratorVector() {
	std::cout << "\x1b[32mMy vector\n";
	ft::vector<int> g1;
	for (int i = 0; i < 12; i++) {
		g1.push_back(i + 1);
	}
	ft::vector<int>::iterator ite = g1.begin();
	std::cout << *ite << std::endl;
	ite = ite + 4;
	if (ite > g1.begin())
		std::cout << "BIG\n";
	std::cout << *ite << std::endl;
	ite -= 4;
	if (ite <= g1.begin())
		std::cout << "SMALL\n";
	std::cout << *ite << std::endl;
	std::cout << std::endl;
}

void defaultTestIteratorTwo() {
	std::cout << "\x1b[34m==----TEST ITERATOR VECTOR TWO----==\n";
	std::cout << "\x1b[31mDefault vector\n";
	std::vector<int> v1;
	for (int i = 0; i < 12; i++) {
		v1.push_back(i + 4);
	}
	std::vector<int>::iterator itv = v1.begin();
	std::vector<int>::iterator itev = v1.end();
	for (; ++itv != itev;) {
		std::cout << *itv << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void testIteratorTwo() {
	std::cout << "\x1b[32mMy vector\n";
	ft::vector<int> g1;
	for (int i = 0; i < 12; i++) {
		g1.push_back(i + 4);
	}
	ft::vector<int>::iterator it = g1.begin();
	ft::vector<int>::iterator ite = g1.end();
	for (; ++it != ite;) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void defaultTestAssignIterator() {
	std::cout << "\x1b[34m==----TEST ASSIGN ITERATOR----==\n";
	std::vector<int> v1;
	std::vector<int> v2(14, 5);
	for (int i = 0; i < 12; i++) {
		v1.push_back(i);
	}
	std::cout << "\x1b[31mDEFAULT vector 1 before\n";
	for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); ++it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "\x1b[31mDEFAULT vector 2 before\n";
	for (std::vector<int>::iterator it = v2.begin(); it < v2.end(); ++it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	v1.assign(v2.begin(), v2.end());
	std::cout << "\x1b[31mDEFAULT vector 1 after\n";
	for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); ++it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "\x1b[31mDEFAULT vector 2 after\n";
	for (std::vector<int>::iterator it = v2.begin(); it < v2.end(); ++it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "size = " << v1.size() << " cap = " << v1.capacity() << "\x1b[0m" <<std::endl;
	std::cout << std::endl;
}

void testAssignIterator() {
	ft::vector<int> g1;
	ft::vector<int> g2(14, 5);
	for (int i = 0; i < 12; i++) {
		g1.push_back(i);
	}
	std::cout << "\x1b[32mMy vector 1 before\n";
	for (ft::vector<int>::iterator it = g1.begin(); it < g1.end(); ++it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "\x1b[32mMy vector 2 before\n";
	for (ft::vector<int>::iterator it = g2.begin(); it < g2.end(); ++it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	g1.assign(g2.begin(), g2.end());
	std::cout << std::endl;
	std::cout << "\x1b[32mMy vector 1 after\n";
	for (ft::vector<int>::iterator it = g1.begin(); it < g1.end(); ++it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "\x1b[32mMy vector 2 after\n";
	for (ft::vector<int>::iterator it = g2.begin(); it < g2.end(); ++it) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "size = " << g1.size() << " cap = " << g1.capacity() << std::endl;
	std::cout << std::endl;
}

void defaultTestInsertIterator() {
	std::cout << "\x1b[34m==----TEST INSERT ITERATOR----==\n";
	std::vector<int> v1;
	std::cout << "\x1b[31mDEFAULT vector before\n";
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		std::cout << v1[i];
	}
	std::cout << std::endl;
	std::cout << "\x1b[31mDEFAULT vector after\n";
	std::vector<int>::iterator it = v1.end();
	v1.insert(it, it - 4, it);
	for (size_t i = 0; i < v1.size(); i++) {
		std::cout << v1[i];
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void testInsertIterator() {
	ft::vector<int> g1;
	std::cout << "\x1b[32mMy vector before\n";
	for (int i = 0; i < 10; i++) {
		g1.push_back(i);
		std::cout << g1[i];
	}
	std::cout << std::endl;
	std::cout << "\x1b[32mMy vector after\n";
	ft::vector<int>::iterator ite = g1.end();
	g1.insert(ite, (ite - 4), ite);
	for (size_t i = 0; i < g1.size(); i++) {
		std::cout << g1[i];
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void defaultTestEraseIterator() {
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	std::vector<int>::iterator it = v1.end();
	v1.insert(it, it - 4, it);
	std::cout << "\x1b[34m==----TEST ERASE ITERATOR----==\n";
	std::cout << "\x1b[31mDEFAULT vector\n";
	it = v1.end() - 2;
	std::cout << "erase return: " << *(v1.erase(it - 3, it + 2)) << std::endl;
	for (size_t i = 0; i < v1.size(); i++) {
		std::cout << v1[i];
	}
	std::cout << std::endl;
	std::cout << "\x1b[31mDEFAULT vector size\n";
	std::cout << "size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
	std::cout << std::endl;
}

void testEraseIterator() {
	ft::vector<int> g1;
	for (int i = 0; i < 10; i++) {
		g1.push_back(i);
	}
	ft::vector<int>::iterator ite = g1.end();
	g1.insert(ite, (ite - 4), ite);
	std::cout << "\x1b[32mMy vector\n";
	ite = g1.end() - 2;
	ft::vector<int>::iterator itr = g1.erase(ite - 3, ite + 2);
	std::cout << "erase return: " << *itr << std::endl;
	for (size_t i = 0; i < g1.size(); i++) {
		std::cout << g1[i];
	}
	std::cout << std::endl;
	std::cout << "\x1b[32mMy vector size\n";
	std::cout << "size = " << g1.size() << " cap = " << g1.capacity() << std::endl;
	std::cout << std::endl;
}

void defaultTestRelationalOperators() {
	std::cout << "\x1b[34m==----TEST RELATION OPERATORS----==\n";
	std::vector<int> v1(34, 6);
	std::vector<int> v2(34, 6);
	v1.push_back(4);
	v2.push_back(3);
	std::cout << "\x1b[31mDEFAULT vector\n";
	if (v1 >= v2) {
		std::cout << "v1 >= v2\n";
	}
	std::cout << std::endl;
}

void testRelationalOperators() {
	ft::vector<int> g1(34,6);
	ft::vector<int> g2(34, 6);
	g1.push_back(4);
	g2.push_back(3);
	std::cout << "\x1b[32mMY vector\n";
	if (g1 >= g2) {
		std::cout << "g1 >= g2\n";
	}
	std::cout << std::endl;
}

void defaultTestReverseIterators() {
	std::cout << "\x1b[34m==----REVERSE ITERATOR TEST----==\n";
	std::vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}
	std::cout << "\x1b[31mDEFAULR VECTOR\n";
	std::vector<int>::reverse_iterator it = v.rbegin();
	for (; it < v.rend(); ++it) {
		std::cout << *it;
	}
	std::cout << std::endl;
	std::cout << it[-4];
	std::cout << std::endl;
	std::cout << std::endl;
}

void testReverseIterators() {
	ft::vector<int> g;
	for (int i = 0; i < 5; i++) {
		g.push_back(i);
	}
	ft::vector<int>::reverse_iterator ite = g.rbegin();
	std::cout << "\x1b[32mMY VECTOR\n";
	for (;ite < g.rend(); ++ite) {
		std::cout << *ite;
	}
	std::cout << std::endl;
	std::cout << ite[-4];
	std::cout << std::endl;
	std::cout << std::endl;
}

void defaultTestBoolVector() {
	std::vector<bool> vb;
	std::cout << "\x1b[34m==----TEST BOOL VECTOR----==\n";
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			vb.push_back(1);
		} else {
			vb.push_back(0);
		}
	}
	vb[3] = true;
	vb.flip();
	vb.swap(vb[0], vb[1]);
	std::cout << "\x1b[31mDEFAULR VECTOR\n";
	std::cout << "size = " << vb.size() << " cap = " << vb.capacity() << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << vb.at(i);
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void testBoolVector() {
	ft::vector<bool> myVb;

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			myVb.push_back(1);
		} else {
			myVb.push_back(0);
		}
	}
	myVb[3] = true;
	myVb.flip();
	myVb.swap(myVb[0], myVb[1]);
	std::cout << "\x1b[32mMY VECTOR\n";
	std::cout << "size = " << myVb.size() << " cap = " << myVb.capacity() << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << myVb.at(i);
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
