#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "vector.class.hpp"

void testSwap();
void testModifies();
void testVector();
void testPushBack();
void testElementAccess();
void testFrontAndBack();
void testIteratorVector();
void testIteratorTwo();
void testAssignIterator();
void testInsertIterator();
void testRelationalOperators();
void testReverseIterators();

void clearConsole() {
	std::cout << "\x1b[0m";
}

int main(int argc, char **argv) {
	std::vector<bool> vb;
	ft::Vector<bool> myVb;

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			vb.push_back(1);
			myVb.push_back(1);
		} else {
			vb.push_back(0);
			myVb.push_back(0);
		}
	}

	vb[3] = true;
	myVb[3] = true;
	vb.flip();
	myVb.flip();
	vb.swap(vb[0], vb[1]);
	myVb.swap(myVb[0], myVb[1]);
	std::cout << "size = " << vb.size() << " cap = " << vb.capacity() << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << vb.at(i);
	}
	std::cout << std::endl;
	std::cout << "size = " << myVb.size() << " cap = " << myVb.capacity() << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << myVb.at(i);
	}
	std::cout << std::endl;
//	if (argc == 1) {
//		return 0;
//	}
//	std::string test = argv[1];
//	if (test == "vector") {
//		void (*arrayFnc[])() = {testVector, testPushBack, testElementAccess, testFrontAndBack, testModifies, testSwap,
//								testIteratorVector, testIteratorTwo, testAssignIterator, testInsertIterator,
//								testRelationalOperators, testReverseIterators};
//		size_t size = sizeof(arrayFnc) / sizeof(arrayFnc[0]);
//		for (size_t i = 0; i < size; i++) {
//			arrayFnc[i]();
//			clearConsole();
//		}
//	}
    return 0;
}
