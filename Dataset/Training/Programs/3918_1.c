#include <stdio.h>
#include <stdlib.h>

// External function declarations for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

unsigned int multiply_modulo(unsigned int a, unsigned int b, unsigned int mod) {
    return (a * b) % mod;
}

int main() {
    unsigned int a = __VERIFIER_nondet_uint();
    unsigned int b = __VERIFIER_nondet_uint();
    unsigned int mod = 1000;
    unsigned int counter = 0;

    // Assume to bound the values
    if (a > 1000 || b > 1000) {
        return 0;
    }

    unsigned int result = 1;

    // Main computation loop
    while (counter < 10) {
        result = multiply_modulo(result, a, mod);

        // Conditional logic based on b
        if (b % 2 == 0) {
            result = (result + b) % mod;
        } else {
            result = (result * a) % mod;
        }

        counter++;

        // Assertions to check properties
        __VERIFIER_assert(result < 1000);

        // Variant on loop increment based on parity of b
        if (b % 2 == 0) {
            b++;
        } else {
            b--;
        }
    }

    // Final assertions ensuring constraints on result

    return 0;
}