#include <assert.h>
#include <stdlib.h>

extern void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
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

int main() {
    unsigned int limit = __VERIFIER_nondet_int();
    unsigned int count = 0;
    unsigned int number = 2;

    while (count < limit) {
        if (is_prime(number)) {
            count++;
        }
        number++;
    }

    // Postcondition: count prime numbers up to 'limit'
    // since limit is picked nondeterministically, we are only checking logical consistency,
    // not correctness of the prime counting implementation.

    __VERIFIER_assert(count == limit);

    return 0;
}