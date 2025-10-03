#include <stdio.h>
#include <stdlib.h>

/*
Fibonacci-like Sequence Verification Program
Generates a sequence similar to Fibonacci and checks specific properties within the loop.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci_like.c", 9, "reach_error"); }

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
    int initial1 = __VERIFIER_nondet_int();
    int initial2 = __VERIFIER_nondet_int();
    int length = __VERIFIER_nondet_int();

    // Ensure non-negative starting values and length
    assume_abort_if_not(initial1 >= 0);
    assume_abort_if_not(initial2 >= 0);
    assume_abort_if_not(length > 2);

    long long fib1 = initial1;
    long long fib2 = initial2;
    long long fib_next;

    // Define a reasonable range for the sequence
    assume_abort_if_not(length <= 50);

    for (int i = 3; i <= length; i++) {
        fib_next = fib1 + fib2;

        // Check conditions on the computed sequence
        __VERIFIER_assert(fib_next >= fib2);

        fib1 = fib2;
        fib2 = fib_next;
    }

    // At the end, verify a property of the final sequence elements

    return 0;
}