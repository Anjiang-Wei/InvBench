#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void reach_error(void);
int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int);
void __VERIFIER_assert(int);

void reach_error() {
    printf("Error reached!\n");
    abort();
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int __VERIFIER_nondet_int() {
    return rand() % 100; // Random number generation simulating nondeterministic input
}

int main() {
    int x, y, z;
    int counter = 0;

    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = 0;

    // Ensure x and y are within a reasonable range
    assume_abort_if_not(x >= 0 && x <= 50);
    assume_abort_if_not(y >= 0 && y <= 50);

    // Loop to simulate complex condition accumulation
    while (counter < x + y) {
        if (counter % 2 == 0) {
            z += 2;
        } else {
            z++;
        }
        counter++;
    }

    // Postcondition: ensure z is at least the sum of max(x, y)
    // This checks for a reasonable outcome given how z increases
    __VERIFIER_assert(z >= (x > y ? x : y));

    return 0;
}