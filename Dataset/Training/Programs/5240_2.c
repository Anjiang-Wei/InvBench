// Monotonic Counter Example with Parity Check

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "parity_check.c", 5, "reach_error");
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
    int n, counter, parity;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 1000);

    counter = 0;
    parity = 0;

    while (1) {
        // Ensure that parity is always 0 (even) or 1 (odd)

        if (!(counter < n)) {
            break;
        }

        counter++;
        parity = 1 - parity; // Toggle the parity for each increment
    }

    // Check if parity matches the expected value after the loop
    // If n is even, parity should be 0; if n is odd, parity should be 1
    __VERIFIER_assert(parity == n % 2);

    printf("Final counter value: %d, Parity: %d\n", counter, parity);
    return 0;
}