#include <stdio.h>
#include <stdlib.h>

// Verification utilities
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 5, "reach_error"); }

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

extern int __VERIFIER_nondet_int(void);

// New example program
int main() {
    int n, a, b;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // Ensure positive n

    a = 1; // a starts from 1
    b = 1; // b starts from 1, Fibonacci sequence starting point

    int i;
    for (i = 2; i < n; i++) {
        int temp = a + b;
        a = b;
        b = temp; // Generate Fibonacci sequence for 'n' terms
    }

    // This asserts the n-th Fibonacci number is at least 1
    __VERIFIER_assert(b >= 1);

    printf("The %d-th Fibonacci number is: %d\n", n, b);

    return 0;
}