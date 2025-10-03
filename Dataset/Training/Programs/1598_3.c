/*
  Fibonacci Sequence Verification
  This program calculates Fibonacci numbers up to a nondeterministically chosen limit.
  It uses assertions to verify properties of Fibonacci numbers.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
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
    int limit, i, fib1, fib2, fib_next;

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0);

    fib1 = 0;
    fib2 = 1;

    i = 2; // Starting count from the 2nd Fibonacci number (index 1)
    while (i <= limit) {
        fib_next = fib1 + fib2;

        // Assertion to verify the properties of Fibonacci numbers

        // Property: Fib(n) <= 2^n

        fib1 = fib2;
        fib2 = fib_next;
        i++;
    }

    // Final assertions to verify the properties post loop
    __VERIFIER_assert(fib1 <= fib2);

    printf("Fibonacci sequence computed up to term %d.\n", limit);
    return 0;
}