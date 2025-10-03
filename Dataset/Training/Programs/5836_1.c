#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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
    long long sum = 0;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Precondition assumptions
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(c >= 0);

    int i = 0;
    while (i < c) {
        sum += (a * i + b);
        i++;

        // Constraint: sum should not become negative.
        // We will fight overflows and invalid situations here.
        __VERIFIER_assert(sum >= 0);
    }

    // Another constraint to be verified
    // Intentionally set an unreachable state for verification purposes
    if (c > 10) {
    }

    printf("Sum: %lld\n", sum);
    return 0;
}