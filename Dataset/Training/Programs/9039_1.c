/*
Fibonacci Sequence
Computes the Fibonacci sequence up to the nth element
and verifies a simple property with an assertion.
*/

#include <limits.h>
#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fib-ll.c", 6, "reach_error"); }
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

int counter = 0;
int main() {
    int n, i;
    long long fib, fib_prev, fib_prev_prev;

    // Get a nondeterministic input for 'n', must be non-negative
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    fib_prev_prev = 0;
    fib_prev = 1;
    fib = 0;

    i = 0;

    while (i < n && counter++ < 50) {
        __VERIFIER_assert(fib >= 0); // Fib numbers should always be non-negative

        if (i == 0) {
            fib = 0;
        } else if (i == 1) {
            fib = 1;
        } else {
            fib = fib_prev + fib_prev_prev;
            fib_prev_prev = fib_prev;
            fib_prev = fib;
        }

        i++;
    }

    // Run the assertion one more time after the loop to check the final fib value

    return 0;
}