#include <iostream>

class Widget {
    int data;
public:
    explicit Widget(int n) : data(n) {}
    void print() const {
        std::cout << data << '\n';
    }
};

void f(Widget wid) {
    wid.print();
}

int main() {
    //Widget w(3); 
    f(3);
}
