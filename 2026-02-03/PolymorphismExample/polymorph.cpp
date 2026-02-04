#include <cstdlib>

class Rectangle {
protected:
    int length;
    int width;
public:
    Rectangle(int length, int width): length(length), width(width) {}
    virtual int area() const;
    virtual void lengthen(int amt);
};

int Rectangle::area() const {
    return length * width;
}

void Rectangle::lengthen(int amt) {
    length += amt;
}

class MyRect: public Rectangle {
public:
    MyRect(int length, int width): Rectangle(length, width) {}
    void lengthen(int amt) override;
};

void MyRect::lengthen(int amt) {
    length += 2*amt;
}

int main() {
    Rectangle *r = new Rectangle(10, 5);
    Rectangle *c = new MyRect(3, 7);
    r->lengthen(8);
    c->area();

    Rectangle *a;
    if (rand() % 2 == 0)
        a = new Rectangle(8, 7);
    else
        a = new MyRect(10, 30);
    a->lengthen(4);    // Which lengthen method gets called?

}
