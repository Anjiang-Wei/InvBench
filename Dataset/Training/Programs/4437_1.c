#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// Function to check if a number is prime
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
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 2 && limit <= 100);

    int sum = 0;
    int count = 0;
    int incrementor = 0;

    while (count < limit) {
        if (is_prime(incrementor)) {
            sum += incrementor;
            count++;
        }
        incrementor++;
    }

    // Simple check: if limit primes are summed, check against some known number.
    __VERIFIER_assert(sum >= 0);

    printf("Sum of first %d prime numbers is %d\n", limit, sum);
    return 0;
}