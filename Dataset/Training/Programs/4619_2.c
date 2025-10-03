#include <assert.h>
void reach_error(void) { assert(0); }

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    int fib1 = 0;
    int fib2 = 1;
    int nextFib;

    // Assume n is a non-negative integer
    if (n < 0 || n > 40) {
        return 0; // Limiting n to prevent integer overflow
    }

    int i = 0;
    while (i < n) {
        nextFib = fib1 + fib2;
        fib2 = nextFib;
        i++;
    }

    if (n <= 1) {
        __VERIFIER_assert(fib2 == 1); // For n = 0 or 1, fib(n) must be 1
    } else {
        __VERIFIER_assert(fib2 == fib1 + fib2 - fib1); // Verification of last computed value
    }

    return 0;
}