#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "generated.c", 3, "reach_error");
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
    }
    return;
}

int main() {
    int n, sum = 0, i = 0, prev = 1, current = 1, next;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 1 && n < 46); // Ensure 'n' is within bounds to prevent overflow

    // Compute Fibonacci series sum up to 'n'
    while (i < n) {
        if (i == 0) {
            sum = sum + prev;
        } else if (i == 1) {
            sum = sum + current;
        } else {
            next = prev + current;
            prev = current;
            current = next;
            sum = sum + current;
        }
        i++;
    }

    // Ensure the computed Fibonacci sum is within a reasonable range
    __VERIFIER_assert(sum > 0 && sum < 754011380475);

    printf("Sum of first %d Fibonacci numbers: %d\n", n, sum);
    return 0;
}