#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

// Define a function to verify a condition
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Initialize variables
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0;

    // Precondition: a >= 0 and b >= 0
    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    // Loop until a becomes zero
    while (a > 0) {
        if (b > 0) {
            // Increment c if b is positive
            c += a;
            // Decrement b
            b--;
        } else {
            // Decrement a if b is non-positive
            a--;
        }
    }

    // Postcondition: c should be a multiple of original value of a
    __VERIFIER_assert(c >= 0);

    // Output the values of c for further analysis
    printf("c: %d\n", c);

    return 0;
}