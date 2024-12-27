#include <iostream>
#include "matrix.h"

int main() {
    Matrix m1(2, 3);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(0, 2, 3);
    m1.set(1, 0, 4);
    m1.set(1, 1, 5);
    m1.set(1, 2, 16);

    Matrix m2(3, 2);
    m2.set(0, 0, 1);
    m2.set(0, 1, 2);
    m2.set(1, 0, 3);
    m2.set(1, 1, 4);
    m2.set(2, 0, 5);
    m2.set(2, 1, 6);

    m1.print( std::cout, 0 );
    m2.print( std::cout, 0 );
    Matrix m3 = m1 * m2;
    m3.print( std::cout, 0 );
    return 0;
}