#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

inline int is_prime(int num) {
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

    // Precondition: n should be a natural number (non-negative)
    if (n < 0) {
        return 0;
    }

    int countPrimes = 0;
    int num = 2;

    while (countPrimes < n) {
        if (is_prime(num)) {
            countPrimes++;
        }
        num++;
    }

    // Postcondition: There should be exactly n primes identified.
    __VERIFIER_assert(countPrimes == n);

    return 0;
}