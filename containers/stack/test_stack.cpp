#include <iostream>
#include <stack>
#include "stack.class.hpp"

void defaultTestStack() {
	std::cout << "\x1b[34m==----TEST STACK----==\n";
	std::stack<int> ds;
	ds.push(3);
	ds.push(4);
	ds.push(5);
	ds.push(3);
	ds.push(4);
	ds.push(5);
	std::cout << "\x1b[31mDEFAULT STACK TEST\n";
	for (size_t i = 0; i < ds.size();) {
		std::cout << ds.top();
		ds.pop();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::stack<int> ds2;
	std::cout << "\x1b[31mDEFAULT STACK TEST TWO\n";
	if (ds2 <= ds && ds2 >= ds)
		std::cout << "equal\n";
	std::cout << std::endl;
}

void testStack() {
	ft::stack<int> ms;

	ms.push(3);
	ms.push(4);
	ms.push(5);
	ms.push(3);
	ms.push(4);
	ms.push(5);
	std::cout << "\x1b[32mMY STACK TEST\n";
	for (size_t i = 0; i < ms.size();) {
		std::cout << ms.top();
		ms.pop();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	ft::stack<int> ms2;
	std::cout << "\x1b[32mMY STACK TEST TWO\n";
	if (ms2 <= ms && ms2 >= ms)
		std::cout << "equal\n";
	std::cout << std::endl;
}