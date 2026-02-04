#ifndef SEQUENCE_H_
#define SEQUENCE_H_

class Sequence {
    int *data;
    int capacity;
    int size;
public:
    Sequence(int n);
    Sequence(const Sequence& other);
    ~Sequence();
    Sequence& operator=(const Sequence& other);
    void append(int elem);
    int get(int index) const;
};

#endif

