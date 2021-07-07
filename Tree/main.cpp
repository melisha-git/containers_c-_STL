#include "tree.class.hpp"

void test() {
    tree<int> k;
    k[6];
    k[2];
    k[18];
    k[9];
    k[15];
    k[20];
    k[3];
    k.print();
    std::cout << std::endl << std::endl;
    return ;
}

int main() {
    test();
    while (1);
    return 0;
}
