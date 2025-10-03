#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
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

int main() {
    int N = 30;
    int count = 0;
    int sum_of_primes = 0;

    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            sum_of_primes += i;
            count++;
        }
    }

    // Constraint: sum of all primes less than or equal to N should be a positive number.
    __VERIFIER_assert(sum_of_primes > 0);

    // Constraint: The number of primes counted should be correct for known N.
}