#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int __VERIFIER_nondet_int();

int is_prime(int number) {
    if (number <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int limit = __VERIFIER_nondet_int();
    int prime_sum = 0;
    int num_checked = 0;

    // Verification conditions for practical purposes
    if (limit < 0 || limit > 100) {
        return 0;
    }

    for (int i = 0; i < limit; i++) {
        num_checked++;
        int current_number = __VERIFIER_nondet_int();
        if (current_number < 0 || current_number > 100) {
            continue;
        }

        if (is_prime(current_number)) {
            prime_sum += current_number;
        }
    }

    // Perform a simple assertion check
    __VERIFIER_assert(prime_sum >= 0);
    printf("Sum of prime numbers: %d\n", prime_sum);
    printf("Numbers checked: %d\n", num_checked);

    return 0;
}