#include <stdio.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int __VERIFIER_nondet_int();

int main() {
    unsigned int x = 0;
    unsigned int y = 2;
    unsigned int z = 10;

    while (x < z) {
        x += 1;
        y *= 2; // Double y in each iteration

        if (x == z / 2) {
            __VERIFIER_assert(y == 1 << (x + 1));
        }
    }

    printf("Final values: x = %u, y = %u\n", x, y);

    return 0;
}