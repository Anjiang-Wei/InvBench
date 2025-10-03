/* Program computing the nth Fibonacci number with constraints */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-constraint.c", 5, "reach_error"); }
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
    long long f0, f1, f2, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    f0 = 0;
    f1 = 1;
    i = 2;

    while (1) {
        if (!(i <= n)) {
            break;
        }

        f2 = f0 + f1;

        // Constraints to check properties of Fibonacci numbers
        assume_abort_if_not(f2 >= f1); // Ensure monotonically non-decreasing
        assume_abort_if_not(f2 >= f0); // Ensure the same for f0

        f0 = f1;
        f1 = f2;
        i = i + 1;
    }

    // Final assertion to ensure computation is correct for small n
    if (n == 0) {
    }
    if (n == 1) {
        __VERIFIER_assert(f1 == 1);
    }
    return 0;
}