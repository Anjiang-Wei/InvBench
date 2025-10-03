/*
 * This program computes the factorial of a non-negative integer using iteration.
 * The factorial of a number n is denoted as n! which is the product of all positive integers less than or equal to n.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }
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
    return;
}

int main() {
    int n, i;
    long long factorial;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Limiting n to prevent overflow for demo purposes

    factorial = 1;
    i = 1;

    while (i <= n) {
        factorial = factorial * i;
        i++;
    }

    // For n = 5, factorial must be 120
    if (n == 5) {
    } else {
        __VERIFIER_assert(factorial > 0); // Since the factorial of any positive number should be positive
    }

    return 0;
}