#include "vector.class.hpp"
#include <vector>

void testSwap() {
    std::vector<int> v1(12,4);
    std::vector<int> v2(10, 7);
    ft::Vector<int> g1(12, 4);
    ft::Vector<int> g2(10, 7);
    for (int i = 0; i < 3; i++) {
        v1.push_back(8);
        g1.push_back(8);
    }
    std::cout << "==----SWAP TEST----=" << std::endl;
    std::cout << "==----Default vector before v1----==" << std::endl;
    std::cout << "size: " << v1.size() << "\t" << "capacity: " << v1.capacity() << std::endl;
    std::cout << "front: " << v1.front() << "\t" << "back: " << v1.back() << std::endl;
    std::cout << "==----Default vector before v2----==" << std::endl;
    std::cout << "size: " << v2.size() << "\t" << "capacity: " << v2.capacity() << std::endl;
    std::cout << "front: " << v2.front() << "\t" << "back: " << v2.back() << std::endl;
    v1.swap(v2);
    std::cout << "==----Default vector after v1----==" << std::endl;
    std::cout << "size: " << v1.size() << "\t" << "capacity: " << v1.capacity() << std::endl;
    std::cout << "front: " << v1.front() << "\t" << "back: " << v1.back() << std::endl;
    std::cout << "==----Default vector after v2----==" << std::endl;
    std::cout << "size: " << v2.size() << "\t" << "capacity: " << v2.capacity() << std::endl;
    std::cout << "front: " << v2.front() << "\t" << "back: " << v2.back() << std::endl;
    std::cout << "==----My vector before g1----==" << std::endl;
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
}

void testModifies() {
    std::vector<int> v1(12,4);
    ft::Vector<int> g1(12, 4);
    v1.assign(14, 2);
    g1.assign(14, 2);
    std::cout << "==----ASSIGN TEST----=" << std::endl;
    std::cout << "==----Default vector----==" << std::endl;
    std::cout << "size: " << v1.size() << "\t" << "capacity: " << v1.capacity() << std::endl;
    std::cout << "front: " << v1.front() << "\t" << "back: " << v1.back() << std::endl;
    std::cout << "==----My vector----==" << std::endl;
    std::cout << "size: " << g1.size() << "\t" << "capacity: " << g1.capacity() << std::endl;
    std::cout << "front: " << g1.front() << "\t" << "back: " << g1.back() << std::endl;
}

void testFrontAndBack() {
    std::vector<const int> v1(12,4);
    std::vector<const int> v2(v1);
    ft::Vector<const int> g1(12, 4);
    ft::Vector<const int> g2(g1);
    std::cout << "==----FRONT AND END TEST----=" << std::endl;
    std::cout << "==----Default vector----==" << std::endl;
    std::cout << v1.front() << "\t" << v1.back() << std::endl;
    std::cout << "==----My vector----==" << std::endl;
    std::cout << g1.front() << "\t" << g1.back() << std::endl;
}

void testElementAccess() {
    std::vector<int> v1;
    ft::Vector<int> g1;
    std::cout << "==----AT TEST----==" << std::endl;
    std::cout << "==----Default vector----==" << std::endl;
    try {
        std::cout << v1.at(0) << std::endl;
    }
    catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==----My vector----==" << std::endl;
    try {
        std::cout << g1.at(0) << std::endl;
    }
    catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
}

void testPushBack() {
    std::vector<int> v1;
    std::cout << "DEFAULT VECTOR PUSH BACK TEST\n";
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);

    }
    for (int i = 0; i < 10; i++) {
        std::cout << v1[i] << std::endl;
    }
    std::cout << v1.size() << "\t" << v1.capacity() << std::endl;

    std::cout << std::endl;
    /*
     * MY VECTOR TEST
    */
    std::cout << "MY VECTOR PUSH BACK TEST\n";
    std::cout << std::endl;

    ft::Vector<int> g1;
    for (int i = 0; i < 10; i++) {
        g1.push_back(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << g1[i] << std::endl;
    }
    std::cout << g1.size() << "\t" << g1.capacity() << std::endl;
}

void testVector() {
    std::vector<int> v1(12,4);
    std::cout << "DEFAULT VECTOR TEST\n";
    try {
        v1.reserve(100);
    }
    catch (std::length_error &le) {
        std::cout << le.what() << std::endl;
    }
    v1.resize(14);
    std::cout << v1.size() << "\t" << v1.capacity() << std::endl;
    for (int i = 0; i < v1.size(); i++) {
        std::cout << v1[i];
    }

    std::cout << std::endl;
    /*
     * MY VECTOR TEST
     */
    std::cout << "MY VECTOR TEST";
    std::cout << std::endl;

    ft::Vector<int> g1(12,4);
    try {
        g1.reserve(100);
    }
    catch (std::length_error &le) {
        std::cout << le.what() << std::endl;
    }
    g1.resize(14);
    std::cout << g1.size() << "\t" << g1.capacity() << std::endl;
    for (int i = 0; i < g1.size(); i++) {
        std::cout << g1[i];
    }
    std::cout << std::endl;
    /*
     * CLEAR
     */
    std::cout << "CLEAR TEST";
    std::cout << std::endl;
    v1.clear();
    std::cout << v1.size() << "\t" << v1.capacity() << std::endl;
    if (v1.empty()) {
        std::cout << "Default vector is clear\n";
    }
    g1.clear();
    std::cout << g1.size() << "\t" << g1.capacity() << std::endl;
    if (g1.empty()) {
        std::cout << "My vector is clear\n";
    }
}

void testIteratorVector() {
    std::cout << "==----TEST ITERATOR VECTOR----==\n";
    std::cout << "My vector\n";
    ft::Vector<int> g1;
    for (int i = 0; i < 12; i++) {
        g1.push_back(i + 1);
    }
    ft::Vector<int>::iterator ite = g1.begin();
    std::cout << *ite << std::endl;
    ite = ite + 4;
    if (ite > g1.begin())
        std::cout << "BIG\n";
    std::cout << *ite << std::endl;
    ite -= 4;
    if (ite <= g1.begin())
        std::cout << "SMALL\n";
    std::cout << *ite << std::endl;
    std::cout << "Default vector\n";
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
}

int main() {
//    testVector();
//    testPushBack();
//    testElementAccess();
//    testFrontAndBack();
//    testModifies();
//    testSwap();
//    testIteratorVector();
    ft::Vector<int> g1;
    for (int i = 0; i < 12; i++) {
        g1.push_back(i + 4);
    }
    ft::Vector<int>::iterator it = g1.begin();
    ft::Vector<int>::iterator ite = g1.end();
    for (; it < ite; ++it) {
        std::cout << *it;
    }
//    while (1);
    return 0;
}
