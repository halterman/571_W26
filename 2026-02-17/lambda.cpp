#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector v {10, 23, 36, 45};
    int x = 10;
    std::cout << "Now x = " << x << '\n';
    std::for_each(std::begin(v), std::end(v), [&x](int n) { std::cout << x * n << ' '; x = 9; });
    std::cout << '\n';
    std::cout << "Then x = " << x << '\n';
}
