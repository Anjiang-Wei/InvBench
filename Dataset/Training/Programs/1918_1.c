#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
Fibonacci Sequence
Compute the first N Fibonacci numbers, and verify
some property at the end related to their sum.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2 && n <= 20); // Assume a reasonable range for n

    // Initial Fibonacci numbers
    int a = 0;
    int b = 1;
    int c;
    int sum = a + b;
    int i;

    // Loop through n times to calculate Fibonacci sequence
    for (i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        sum += c;
    }

    // Postcondition property - The sum should always be greater than or equal to the last number
    __VERIFIER_assert(sum >= b);

    return 0;
}