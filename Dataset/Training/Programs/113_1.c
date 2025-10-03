#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int limit = 30; // Set a limit for finding prime numbers
    int counter = 0;

    for (int num = 1; num <= limit; num++) {
        int result = is_prime(num);
        if (result) {
            counter++;
        }
    }

    __VERIFIER_assert(counter > 0); // Assert that there is at least one prime number in the range

    printf("Number of primes between 1 and %d: %d\n", limit, counter);

    return 0;
}