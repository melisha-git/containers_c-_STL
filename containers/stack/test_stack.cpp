#include <iostream>
#include <stack>
#include "stack.class.hpp"

void testStack() {
	std::stack<int> ds;
	ft::stack<int> ms;

	ds.push(3);
	ms.push(3);
	ds.push(4);
	ms.push(4);
	ds.push(5);
	ms.push(5);
	ds.push(3);
	ms.push(3);
	ds.push(4);
	ms.push(4);
	ds.push(5);
	ms.push(5);
	std::cout << "\x1b[31mDEFAULT STACK TEST\n";
	for (int i = 0; i < ds.size();) {
		std::cout << ds.top();
		ds.pop();
	}
	std::cout << std::endl;
	std::cout << "\x1b[32mMY STACK TEST\n";
	for (int i = 0; i < ms.size();) {
		std::cout << ms.top();
		ms.pop();
	}
	std::cout << std::endl;
	std::stack<int> ds2;
	ft::stack<int> ms2;
	std::cout << "\x1b[31mDEFAULT STACK TEST\n";
	if (ds2 <= ds && ds2 >= ds)
		std::cout << "equal\n";
	std::cout << "\x1b[32mMY STACK TEST\n";
	if (ms2 <= ms && ms2 >= ms)
		std::cout << "equal\n";
}