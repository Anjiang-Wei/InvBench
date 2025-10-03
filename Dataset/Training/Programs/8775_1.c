#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to mimic nondeterministic integer generation
int __VERIFIER_nondet_int();

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Loop to calculate sum and product of non-negative numbers
    while (a < 10 && b < 10 && c < 10) {
        if (a >= 0) {
            sum += a;
        }
        if (b >= 0) {
            sum += b;
        }
        if (c >= 0) {
            sum += c;
        }

        if (a % 2 == 0) {
            product *= 2;
        }
        if (b % 2 == 0) {
            product *= 2;
        }
        if (c % 2 == 0) {
            product *= 2;
        }

        a++;
        b++;
        c++;
    }

    // Constraint to ensure product is power of 2
    __VERIFIER_assert((product & (product - 1)) == 0);

    // Print final values
    printf("Final sum: %d\n", sum);
    printf("Final product (power of 2): %d\n", product);

    return 0;
}