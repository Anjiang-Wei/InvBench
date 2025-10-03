#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom-example.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = 0;
    c = 0;

    assume_abort_if_not(a >= 0 && a <= 100);

    // Initialize a counter to track the number of operations
    int counter = 0;
    while (a > 0) {
        // Perform some operations
        b += a;
        c += b;

        // Every two steps, reduce `a`
        if (counter % 2 == 0) {
            a -= 1;
        } else {
            a -= 2;
        }

        // Increment the counter
        counter++;
    }

    // Final assertion to check the sum `c` after processing
    __VERIFIER_assert(c >= 0);

    printf("Computation complete: c = %d, counter = %d\n", c, counter);
    return 0;
}