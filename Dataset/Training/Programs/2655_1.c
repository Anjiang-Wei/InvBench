#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 1);

    int total_primes = 0;
    int current_number = 2;

    while (current_number <= n) {
        if (is_prime(current_number)) {
            total_primes++;
        }
        current_number++;
    }

    // Checking if at least one prime number exists within the bounds 2 to n
    __VERIFIER_assert(total_primes >= 1);

    return 0;
}