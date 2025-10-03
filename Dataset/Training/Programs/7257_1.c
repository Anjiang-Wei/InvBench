/* Program to calculate the sum of squares up to a certain number and verify properties */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_of_squares.c", 3, "reach_error"); }
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
    int n, sum = 0;
    int i = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Constraint for demonstration

    while (i <= n) {
        sum = sum + i * i;
        i = i + 1;
    }

    // Ensure sum is not negative
    __VERIFIER_assert(sum >= 0);

    return 0;
}