#include <iostream>

int main() {
    //int a = 10;
    //int b(20);
    //int c{30};
    int *p;

    p = new int(42.2);

    std::cout << *p << '\n';
    //std::cout << "a = " << a << "  b = " << b << "  c = " << c << '\n';
}
