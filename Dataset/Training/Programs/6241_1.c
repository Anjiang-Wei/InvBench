#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1; // 2 is a prime number
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int upperBound = 50; // limiting the inputs for practical verification

    if (n < 0 || n > upperBound) {
        return 0;
    }

    while (n > 0) {
        int randomNum = __VERIFIER_nondet_int();
        if (randomNum > 0 && randomNum <= upperBound && is_prime(randomNum)) {
            sum += randomNum;
        }
        n--;
    }

    // Postcondition: sum is non-negative
    __VERIFIER_assert(sum >= 0);

    return 0;
}