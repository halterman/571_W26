#include <stdio.h>
#include "sequence.h"

void f() {
    Sequence s = create_sequence(5);
    append(&s, 10);
    append(&s, 20);
    append(&s, 30);
    append(&s, 40);
    for (int i = 0; i < 4; i++) 
        printf("%d ", get(&s, i));
    printf("\n");
    dispose_sequence(&s);
}

int main() {
    f();
    printf("Program complete\n");
}
