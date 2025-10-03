#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
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
    int limit;
    long long sum, factorial, n;

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 0 && limit <= 10); // restrict limit for computational feasibility

    // Initialization
    factorial = 1;
    sum = 0;
    n = 1;

    while (1) {
        __VERIFIER_assert(sum == ((n - 1) * n) / 2); // Verify sum of first n-1 integers

        if (!(n <= limit)) {
            break;
        }

        factorial *= n; // Compute factorial of n
        sum += n;       // Compute the sum of first n natural numbers
        n++;
    }

    printf("Final sum of first %d numbers: %lld\n", limit, sum);
    printf("Factorial of %d: %lld\n", limit, factorial);

    return 0;
}