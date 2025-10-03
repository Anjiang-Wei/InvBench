#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define MAX_SIZE 1000000

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    unsigned int n = 0, index = 0;
    unsigned int prime_count = 0, even_count = 0, odd_count = 0;

    n = rand() % (MAX_SIZE + 1); // Random number between 0 and MAX_SIZE
    assume_abort_if_not(n <= MAX_SIZE);

    while (index < n) {
        if (is_prime(index)) {
            prime_count++;
        } else if (index % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }

        index++;
        __VERIFIER_assert((prime_count + even_count + odd_count) == index);
    }

    printf("For n = %u:\n", n);
    printf("Prime count: %u\n", prime_count);
    printf("Even count: %u\n", even_count);
    printf("Odd count: %u\n", odd_count);

    return 0;
}