#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 8, "reach_error"); }

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

// Function to simulate nondeterministic integer generation
extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, n;
    long long sum_even = 0;
    long long sum_odd = 0;

    // Simulating user or environment inputs
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(a < b);

    // Calculating sum to simulate meaningful processing
    for (n = a; n <= b; n++) {
        if (n % 2 == 0) {
            sum_even += n;
        } else {
            sum_odd += n;
        }
    }

    // Verifier check, condition based on program logic
    __VERIFIER_assert(sum_odd >= 0);

    printf("Sum of even numbers: %lld\n", sum_even);
    printf("Sum of odd numbers: %lld\n", sum_odd);

    return 0;
}