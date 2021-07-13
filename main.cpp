#include <string>
#include <iostream>
#include <map>
#include <vector>

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
void testBoolVector();
void testMap();

void clearConsole() {
	std::cout << "\x1b[0m";
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "/*************************************************/" << std::endl;
		std::cout << "/*                                               */" << std::endl;
		std::cout << "/* Введите в параметры запуска 'vector' или 'map'*/" << std::endl;
		std::cout << "/*                                               */" << std::endl;
		std::cout << "/*************************************************/" << std::endl;
		return 0;
	}
	std::string test = argv[1];
	if (test == "vector") {
		void (*arrayFnc[])() = {testVector, testPushBack, testElementAccess, testFrontAndBack, testModifies, testSwap,
								testIteratorVector, testIteratorTwo, testAssignIterator, testInsertIterator,
								testRelationalOperators, testReverseIterators, testBoolVector};
		size_t size = sizeof(arrayFnc) / sizeof(arrayFnc[0]);
		for (size_t i = 0; i < size; i++) {
			arrayFnc[i]();
			clearConsole();
		}
	}
	if (test == "map") {
		void (*arrayFnc[])() = {testMap};
		size_t size = sizeof(arrayFnc) / sizeof(arrayFnc[0]);
		for (size_t i = 0; i < size; i++) {
			arrayFnc[i]();
			clearConsole();
		}
	}
    return 0;
}
