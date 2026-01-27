#include <stdlib.h>
#include "sequence.h"

Sequence create_sequence(int n) {
    Sequence s;
    s.data = malloc(n * sizeof *s.data);
    s.capacity = n;
    s.size = 0;
    return s;
}

// Note: We really need to check for buffer overflow here.
void append(Sequence *seq, int elem) {
    seq->data[seq->size++] = elem;
}

// Note: We really need to check for out-bounds-access.
int get(const Sequence *seq, int index) {
    return seq->data[index];
}

void dispose_sequence(Sequence *seq) {
    free(seq->data);
}
