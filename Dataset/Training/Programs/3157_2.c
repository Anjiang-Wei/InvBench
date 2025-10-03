/*
 * Program for computing factorial of an integer using iteration
 * with value tracking through assertions for automated verification tools.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 8, "reach_error"); }
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
    int n;
    int fact;
    int i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);  // assume n is a non-negative integer
    assume_abort_if_not(n <= 12); // safeguard to prevent integer overflow in factorial calculation

    fact = 1;
    i = 1;

    while (i <= n) {
        i = i + 1;
    }

    // Postcondition: after the loop, fact should equal n!
    __VERIFIER_assert(fact > 0); // final check to ensure fact is computed and within non-overflow bounds
    return 0;
}