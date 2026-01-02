//  The tightly coupled counter and progress bar

#include <memory>
#include "GL/SGL.h"


using namespace sgl;

//  Represents a conceptual progress bar
class Bar {
    int length;  //  Current bar length 
    int limit;   //  Maximum possible length
public:
    Bar(int max) : length(0), limit(max)  {}
    void set_length(int len) {  
        if (len <= limit)  //  Do not exceed
           length = len;   //  maximum length
    }
    int get_length() const {
        return length;
    }
    int get_limit() const {
        return limit;
    }
};


//  A simple counter
class Counter {
    int current_value;
    Bar *bar;    //  Counter depends on Bar
public:
    Counter(Bar *b) : current_value(0), bar(b) {}
    int get() const {
        return current_value;
    }
    void inc() {  //  Increment
        if (current_value < 100)
            bar->set_length(++current_value);
    }
    void dec() {  //  Decrement
        if (current_value > 0)
            bar->set_length(--current_value);
    }
};


//  GUI to test our classes
class BarWindow: public Window {
    Bar bar;
    Counter counter;
public:
    BarWindow(int lim) : Window("Callback", 100, 100, 100, 400, 0.0, 100.0, 0.0, 100.0), 
                         bar(Bar(lim)), counter(&bar) {}
    void paint() override {
        //  Draw the bar
        set_color(BLACK);
        draw_rectangle(10.0, 10.0, 30.0, 80.0);
        set_color(RED);
        fill_rectangle(10.0, 10.0, 30.0, 
                      static_cast<double>(bar.get_length())/bar.get_limit() * 80.0);
        set_color(BLACK);
        draw_text(std::to_string(counter.get()).c_str(), 50.0, 10.0, 18);
    }
    void key_pressed(int key, double x, double y) override {
        switch (key) {
            case UP_KEY:
                counter.inc();
                break;
            case DOWN_KEY:
                counter.dec();
                break;
            default:
                break;
        }
        Window::key_pressed(key, x, y);
        repaint();
    }
};



int main() {
    std::make_unique<BarWindow>(100)->run();
}


