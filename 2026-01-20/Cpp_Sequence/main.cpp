#include <iostream>
#include "sequence.h"

void f() {
    Sequence s(5);
    s.append(10);
    s.append(20);
    s.append(30);
    s.append(40);
    for (int i = 0; i < 4; i++) 
        std::cout << s.get(i) << ' ';
    std::cout << '\n';

    Sequence t(3);
    t.append(15);
    t.append(25);
    t.append(35);
    s = t;
    for (int i = 0; i < 3; i++) 
        std::cout << s.get(i) << ' ';
    std::cout << '\n';
}

int main() {
    f();
    printf("Program complete\n");
}
