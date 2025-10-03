// New C program inspired by previously provided examples

#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int();

// A new program that performs a computation and checks some key properties.

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Basic assumptions for constraint satisfaction
    if (!(a > 0 && a < 100 && b > 0 && b < 100 && c > 0 && c < 100)) {
        return 0;
    }

    int sum = 0;
    int product = 1;

    // Loop iterates "a" times, demonstrating basic computation
    for (int i = 0; i < a; i++) {
        sum += b;
        product *= c;

        // Logical assertions to ensure computation validity
        __VERIFIER_assert(product > 0);
    }

    // Post loop assertions to verify conditions met

    return 0;
}