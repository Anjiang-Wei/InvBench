#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main(void) {
    unsigned int a = 1;
    unsigned int b = 2;
    unsigned int c = 1000;
    unsigned int counter = 0;

    // This loop performs a series of multiplications and additions
    while (counter < 10) {
        a *= 2; // Double 'a' in each iteration
        b += 3; // Increment 'b' by 3 in each iteration
        c -= a; // Subtract 'a' from 'c' in each iteration

        counter++;

        // Ensure that 'c' never falls below 0
    }

    // Check condition at the end of the loop
    __VERIFIER_assert(a < 4096); // 'a' should not exceed this value

    // Output the results
    printf("a: %u, b: %u, c: %u\n", a, b, c);
    return 0;
}