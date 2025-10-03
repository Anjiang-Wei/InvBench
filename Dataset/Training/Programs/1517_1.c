#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }
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

int SIZE = 100000;
int __VERIFIER_nondet_int();

int main() {
    unsigned int n = 0, i = 0, even_count = 0, odd_count = 0, prime_count = 0;
    n = __VERIFIER_nondet_int();
    if (!(n <= SIZE)) {
        return 0;
    }

    while (i < n) {
        int value = i;

        // Check even or odd
        if (value % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }

        // Check prime number
        int is_prime = 1;
        if (value <= 1) {
            is_prime = 0;
        } else {
            for (int j = 2; j * j <= value; j++) {
                if (value % j == 0) {
                    is_prime = 0;
                    break;
                }
            }
        }

        if (is_prime) {
            prime_count++;
        }

        i++;
    }

    printf("Even: %u, Odd: %u, Prime: %u\n", even_count, odd_count, prime_count);

    // Some constraint condition for verification
    __VERIFIER_assert(even_count + odd_count == n);

    return 0;
}