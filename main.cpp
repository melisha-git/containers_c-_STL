#include "vector.class.hpp"
#include <vector>
#include <cstdlib>

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
void clearConsole();
void testRelationalOperators();
void testReverseIterators();

int main() {
	void (*arrayFnc[]) () = {testVector, testPushBack, testElementAccess,  testFrontAndBack, testModifies, testSwap,
							 testIteratorVector,  testIteratorTwo, testAssignIterator, testInsertIterator, testRelationalOperators, testReverseIterators};
	size_t size = sizeof(arrayFnc) / sizeof(arrayFnc[0]);
    for (size_t i = 0; i < size; i++) {
    	arrayFnc[i] ();
    	clearConsole();
    }
//	testReverseIterators();
//    while(1);
    return 0;
}
