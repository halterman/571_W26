#include <cstdlib>
#include "sequence.h"

Sequence::Sequence(int n) {
    data = new int[n];
    capacity = n;
    size = 0;
}

Sequence::~Sequence() {
    delete [] data;
}

Sequence& Sequence::operator=(const Sequence& other) {
    if (this != &other) {
        delete [] data;
        capacity = other.capacity;
        data = new int[capacity];
        size = other.size;
        for (int i = 0; i < size; i++) 
            data[i] = other.get(i);
        }
    return *this;
}


void Sequence::append(int elem) {
    if (size < capacity)
        data[size++] = elem;
}

int Sequence::get(int index) const {
    if (0 <= index && index < size)
        return data[index];
    else {
        exit(1);
    }
}

