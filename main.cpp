#include <string>
#include <iostream>
#include <ctime>
#include "test_header.hpp"

struct s_time {
	unsigned int start_time_default;
	unsigned int end_time_default;
	unsigned int search_default_time;
	unsigned int my_end_time;
	unsigned int my_start_time;
	unsigned int search_my_time;
	s_time() {
		start_time_default = 0;
		end_time_default = 0;
		search_default_time = 0;
		my_end_time = 0;
		my_start_time = 0;
		search_my_time = 0;
	}
};

void clearConsole() {
	std::cout << "\x1b[0m";
}

void performance(void (**arrayFnc)(), s_time &timing, const size_t & size) {
	for (size_t i = 0; i < size; i++) {
		if (i % 2 == 0) {
			timing.my_start_time = clock();
			arrayFnc[i]();
			timing.my_end_time = clock();
			timing.search_my_time += timing.my_end_time - timing.my_start_time;
		} else {
			timing.start_time_default = clock();
			arrayFnc[i]();
			timing.end_time_default = clock();
			timing.search_default_time += timing.end_time_default - timing.start_time_default;
		}
		clearConsole();
	}
}

int main(int argc, char **argv) {
	std::string test = argv[argc - 1];
	s_time timing;
	if (test == "vector") {
		void (*arrayFnc[])() = {defaultSwap, testSwap, defaultTestModifies, testModifies, defaultTestVector, testVector, defaultClearTest, clearTest,
								defaultTestPushBack, testPushBack, defaultTestElementAccess, testElementAccess, defaultTestFrontAndBack, testFrontAndBack,
								defaultTestIteratorVector, testIteratorVector, defaultTestIteratorTwo, testIteratorTwo, defaultTestAssignIterator, testAssignIterator,
								defaultTestInsertIterator, testInsertIterator, defaultTestEraseIterator, testEraseIterator,
								defaultTestRelationalOperators, testRelationalOperators, defaultTestReverseIterators, testReverseIterators, defaultTestBoolVector, testBoolVector};
		size_t size = sizeof(arrayFnc) / sizeof(arrayFnc[0]);
		performance(arrayFnc, timing, size);
	} else if (test == "map") {
		void (*arrayFnc[])() = {defaultTestMap, testMap, defaultTestClearMap, testClearMap, defaultTestMapFindErase, testMapFindErase, defaultTestMapAlgorithm, testMapAlgorithm};
		size_t size = sizeof(arrayFnc) / sizeof(arrayFnc[0]);
		performance(arrayFnc, timing, size);
	} else if (test == "stack") {
		void (*arrayFnc[])() = {defaultTestStack, testStack};
		size_t size = sizeof(arrayFnc) / sizeof(arrayFnc[0]);
		performance(arrayFnc, timing, size);
	} else {
		std::cout << "/**********************************************************/" << std::endl;
		std::cout << "/*                                                        */" << std::endl;
		std::cout << "/* Enter in launch parameters 'vector', 'map' or 'stack'  */" << std::endl;
		std::cout << "/*                                                        */" << std::endl;
		std::cout << "/**********************************************************/" << std::endl;
		std::cout << std::endl;
	}
	double defTime = ((double)timing.search_default_time)/CLOCKS_PER_SEC;
	double myTime = ((double)timing.search_my_time)/CLOCKS_PER_SEC;
	std::cout << "MY TIME = " << myTime << " seconds\n";
	std::cout << "DEFAULT TIME = " << defTime << " seconds\n";
	if (myTime != 0 && defTime != 0)
		std::cout << "Difference = " << (myTime / defTime) << std::endl;
    return 0;
}
