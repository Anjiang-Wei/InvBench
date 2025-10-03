#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

_Bool __VERIFIER_nondet_bool();

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int count = 0;
    int num = 2;
    int primes[10];

    // Find the first 10 prime numbers
    while (count < 10) {
        if (is_prime(num)) {
            primes[count] = num;
            count++;
        }
        num++;
    }

    // Verify that we found 10 prime numbers
    __VERIFIER_assert(count == 10);

    // Print the found prime numbers
    for (int i = 0; i < 10; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}