#include <stdio.h>
#include <stdlib.h>

// Potentially faulty increment program for automated verification analysis
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "incrementer.c", 10, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, m, x;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    x = __VERIFIER_nondet_int();

    // Assume conditions to make problem more constrained
    assume_abort_if_not(n > 0);
    assume_abort_if_not(m > 0);
    assume_abort_if_not(x >= 0);

    int counter = 0;
    int result = x;

    while (counter < n) {
        result = result + m;
        counter++;

        // Verify that the result doesn't overflow
        __VERIFIER_assert(result > x);
    }

    // Final assertion to check if the computation is consistent

    printf("After incrementing %d by %d for %d times, the result is %d\n", x, m, n, result);
    return 0;
}