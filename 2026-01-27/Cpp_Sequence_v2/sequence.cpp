#include <cstdlib>
#include <iostream>
#include "sequence.h"

Sequence::Sequence(int n): data(new int[n]), capacity(n), size(0) {
    std::cout << "Created Sequence object " << data << '\n';
}

Sequence::Sequence(const Sequence& other): data(new int[other.capacity]), 
                                           capacity(other.capacity), size(other.size) {
    for (int i = 0; i < size; i++) 
        data[i] = other.data[i];
    std::cout << "Initializing Sequence object " << data << '\n';
    
}

Sequence::~Sequence() {
    std::cout << "Destroyed Sequence object " << data << '\n';
    delete [] data;
}

Sequence& Sequence::operator=(const Sequence& other) {
    if (this != &other) {
        std::cout << "Performing assignment\n";
        std::cout << "Destroyed Sequence object " << data << '\n';
        delete [] data;
        capacity = other.capacity;
        data = new int[capacity];
        size = other.size;
        for (int i = 0; i < size; i++) 
            data[i] = other.get(i);
        std::cout << "Created Sequence object " << data << '\n';
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

