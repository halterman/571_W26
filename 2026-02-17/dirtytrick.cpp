#include <iostream>
#define private public  //  Make private members public
#include "sequence.h"   //  Can now access private members
#undef private      //  Revert to normal private semantics

int main() {
    Sequence w;
    w.x = 2;
    std::cout << w.x << '\n';
}


