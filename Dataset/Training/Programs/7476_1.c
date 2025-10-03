#include <stdio.h>
#include <stdlib.h>

// External definitions for nondeterministic values and error handling which
// can be utilized by verification tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prop_example.c", 7, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Assume a reasonable limit for n to prevent overflow in computations
    if (n <= 0 || n > 1000) {
        return 1;
    }

    int a = 0, b = 1;
    int sum_even = 0, sum_odd = 0;

    // Iterating for n steps
    for (int i = 0; i < n; ++i) {
        int c = a + b;

        if (c % 2 == 0) { // Even term logic
            sum_even += c;
        } else { // Odd term logic
            sum_odd += c;
        }

        // Proceeding with the next Fibonacci number
        a = b;
        b = c;
    }

    // Ensuring sum of even and odd terms follows a specific condition for assertion
    __VERIFIER_assert(sum_even <= 2 * sum_odd + 1);

    printf("Sum of even terms: %d\n", sum_even);
    printf("Sum of odd terms: %d\n", sum_odd);

    return 0;
}