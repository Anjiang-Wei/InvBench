#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    int n, counter = 0;
    long long a = 0, b = 1, fibonacci = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1);

    // Compute Fibonacci numbers and add constraints for verification
    while (counter++ < n) {
        fibonacci = a + b;
        a = b;
        b = fibonacci;

        // Partial Fibonacci verification: b should never be less than a
        __VERIFIER_assert(b >= a);
    }

    printf("The %d-th Fibonacci number is: %lld\n", n, fibonacci);

    return 0;
}