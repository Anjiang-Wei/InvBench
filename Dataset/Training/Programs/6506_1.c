#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// A simple deterministic pseudorandom number generator
unsigned int custom_rand(unsigned int seed) {
    return (seed * 1103515245 + 12345) % 0x80000000;
}

int main() {
    unsigned int seed = 42;                       // Initial seed for pseudorandom number generation
    unsigned int n = custom_rand(seed) % 100 + 1; // Generate a number between 1 and 100
    unsigned int count = 0, number;

    // Start the loop to count numbers divisible by 3
    for (unsigned int i = 0; i < n; i++) {
        number = custom_rand(seed + i); // Generate a new "random" number
        if (number % 3 == 0) {
            count++;
        }
    }

    // Check if count is less than or equal to n
    // This is a simple condition, as it should be logically true
    __VERIFIER_assert(count <= n);

    printf("Out of %u numbers, %u were divisible by 3.\n", n, count);
    return 0;
}