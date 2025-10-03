// Implementation of a simple prime number checker using trial division
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prime_checker.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Constraints: the number `n` must be positive and within a reasonable range.
    assume_abort_if_not(n > 1);
    assume_abort_if_not(n < 65536);

    int i;
    int is_prime = 1; // Assume `n` is prime until proven otherwise

    // Check for factors from 2 to sqrt(n) using trial division
    for (i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            is_prime = 0; // `n` is not prime if any factor is found
            break;
        }
    }

    // Assert that if `is_prime` is 1, then no factors were found
    if (is_prime) {
        __VERIFIER_assert(n > 0); // A positive prime number is confirmed
    }

    return 0;
}