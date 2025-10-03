#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
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
    int limit = __VERIFIER_nondet_int();

    // Assume the limit is positive and reasonably small for demonstration purposes
    assume_abort_if_not(limit > 0 && limit <= 100);

    int sum_of_primes = 0;
    int number = 2;
    int count = 0;

    while (count < limit) {
        if (is_prime(number)) {
            sum_of_primes += number;
            count++;
        }
        number++;
    }

    __VERIFIER_assert(sum_of_primes > 0); // Ensure sum has been computed
    return 0;
}