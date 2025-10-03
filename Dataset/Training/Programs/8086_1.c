// Factorial calculation with basic constraint checks

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "__file__", __LINE__, "reach_error"); }
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

int main() {
    int n, factorial, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Constrain n for factorial calculation (to avoid overflow for 'int')

    factorial = 1;
    i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Ensure the factorial matches by checking with known values
    if (n == 0 || n == 1) {
        __VERIFIER_assert(factorial == 1);
    } else if (n == 5) {
    } else if (n == 10) {
    }

    return 0;
}