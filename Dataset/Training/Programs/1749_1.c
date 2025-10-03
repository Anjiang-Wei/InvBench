/*
 * New Benchmark Program
 * This program computes the factorial of an integer n,
 * and checks a property related to the sum of factorial results.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_check.c", 11, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

// A simple function to calculate factorial
long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // To prevent overflow in factorial calculations

    long long sum_factorials = 0;
    for (int i = 0; i <= n; i++) {
        sum_factorials += factorial(i);
    }

    // Check a property related to sum of factorial results
    if (n >= 1) {
        __VERIFIER_assert(sum_factorials > n); // Ensure that the sum of factorials is greater than n for n >= 1
    }

    return 0;
}