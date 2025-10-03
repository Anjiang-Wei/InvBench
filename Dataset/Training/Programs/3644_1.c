/*
   Example Program for Verification Tools

   This program generates a sequence of Fibonacci numbers up to a given limit
   and ensures that each computed Fibonacci number is greater than or equal
   to its predecessor using an assertion mechanism.

   The program is suitable for verification tools as it contains loops
   and conditional statements to simulate real-world logic with constraints.
*/

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verifier.c", 15, "reach_error"); }

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
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit <= 30);

    int a = 0, b = 1;
    int fibonacci = 0;

    for (int i = 0; i < limit; i++) {
        __VERIFIER_assert(fibonacci >= a); // Ensure correctness of Fibonacci sequence

        int next_fib = a + b;
        a = b;
        b = next_fib;
        fibonacci = a;
    }

    return 0;
}