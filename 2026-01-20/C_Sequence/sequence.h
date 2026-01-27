
#ifndef SEQUENCE_H_
#define SEQUENCE_H_

typedef struct {
    int *data;
    int capacity;
    int size;
} Sequence;

Sequence create_sequence(int n);

void append(Sequence *seq, int elem);

int get(const Sequence *seq, int index);

void dispose_sequence(Sequence *seq);


#endif
