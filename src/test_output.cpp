#include <iostream>
#include "output.h"

int main() {
    std::cout << pesanStatus(NORMAL) << '\n';
    std::cout << pesanStatus(CONSTANT_JAMMING) << '\n';
    std::cout << pesanStatus(PERIODIC_JAMMING) << '\n';
    std::cout << pesanStatus(STATUS_TIDAK_DIKENAL) << '\n';

    return 0;
}