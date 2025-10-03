#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// error function used by verification tools
void reach_error() { __assert_fail("0", "example.c", 10, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

// Custom assert for error checking
void __VERIFIER_assert(int cond) {
    if (!cond) {
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
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N < 1000); // Some reasonable upper limit for testing

    int num_primes = 0;
    int sum = 0;

    for (int k = 1; k <= N; ++k) {
        int num = __VERIFIER_nondet_int();
        assume_abort_if_not(num >= 0 && num <= 10000); // Restrict values

        if (is_prime(num)) {
            num_primes++;
            sum += num;
        }
    }

    // Ensure sum does not overflow
    __VERIFIER_assert(sum >= 0);
    if (num_primes > 0) {
        // Average can only be calculated if there's at least one prime number
        int avg = sum / num_primes;
    }

    return 0;
}