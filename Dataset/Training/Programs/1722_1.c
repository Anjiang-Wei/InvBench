extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 30); // Constraint: n is a small non-negative integer

    int fib_sum = 0;
    for (int i = 0; i <= n; i++) {
        fib_sum += fibonacci(i);
    }

    // Check that the computed sum is non-negative
    __VERIFIER_assert(fib_sum >= 0);

    // Additional constraint: check if the sum is a multiple of 2 or 3
    if (fib_sum % 2 == 0 || fib_sum % 3 == 0) {
    }

    return 0;
}