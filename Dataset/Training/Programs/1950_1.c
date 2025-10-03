#include <stdio.h>
#include <stdlib.h>

// Function declarations for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "generated_program.c", 6, "reach_error");
}

// Function to simulate a non-deterministic unsigned integer
extern unsigned int __VERIFIER_nondet_uint(void);

// A function to simulate constraints
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    unsigned int n, m, sum, product;

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 10);

    m = __VERIFIER_nondet_uint();
    assume_abort_if_not(m >= 0 && m <= 10);

    sum = 0;
    product = 1;

    for (unsigned int i = 0; i < n; i++) {
        sum += i;
        product *= (i + 1);

        // Emulating a complex check
        if (sum > 100) {
            break;
        }
    }

    while (product < 10000) {
        product *= m + 1;
    }

    // This assertion enforces a relationship between sum and product
    __VERIFIER_assert(sum < product);

    printf("Final sum: %u, Final product: %u\n", sum, product);

    return 0;
}