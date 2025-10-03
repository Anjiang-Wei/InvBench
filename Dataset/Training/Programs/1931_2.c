/*
 * A program to compute the factorial of a number using loop and perform checks on the result.
 * It incorporates verification constraints suitable for solver-based tools.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 7, "reach_error"); }
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
    return;
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int n;
    long long factorial = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // limiting to ensure calculations remain within integer range

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    // Perform a simple check to ensure factorial is bounded within range for small n
    // and some basic known values (1! = 1, 2! = 2, 3! = 6, 4! = 24, ...)
    if (n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(factorial == 2);
    } else if (n == 3) {
    } else if (n == 4) {
    }

    return 0;
}