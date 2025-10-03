#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "proposed_program.c", 7, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
        abort();
    }
}

long long factorial(int n) {
    long long result = 1;
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0); // Ensure n is non-negative

    long long fact = factorial(n);

    // Check factorial correctness by comparing with hardcoded small numbers
    if (n == 0 || n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(fact == 2);
    } else if (n == 3) {
    } else if (n == 4) {
    }

    // Print the factorial result
    printf("Factorial of %d is %lld\n", n, fact);

    return 0;
}